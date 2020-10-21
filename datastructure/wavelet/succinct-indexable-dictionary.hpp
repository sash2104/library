#pragma once

#include <vector>

struct SuccinctIndexableDictionary {
    using u16 = unsigned short;
    using u32 = unsigned int;
    static int cw, bw;

    u32 length; // bit列の長さ
    u32 nchunk, nblock;
    std::vector<u16> bit;
    std::vector<u32> chunk;
    std::vector<std::vector<u16>> blocks;
    SuccinctIndexableDictionary() = default;
    SuccinctIndexableDictionary(int n) : length(n), nchunk((n+cw-1)/cw), nblock(cw/bw) {
        bit.assign(nchunk*nblock, 0);
        chunk.assign(nchunk+1, 0); // +1は先頭の0の分
        blocks.assign(nchunk, std::vector<u16>(nblock, 0));
    }

    // pos番目のbitを1にする
    void set(int pos) { 
        int bpos = pos / bw;
        int offset = pos % bw;
        bit[bpos] |= (1U<<offset);
    }

    // chunkとblocksを適切に埋める
    void build() {
        chunk[0] = 0;
        for (int i = 0; i < nchunk; ++i) {
            blocks[i][0] = 0;
            for (int j = 0; j < nblock - 1; ++j) {
                blocks[i][j+1] = blocks[i][j] + __builtin_popcount(bit[i*nblock+j]);
            }
            chunk[i+1] = chunk[i] + blocks[i][nblock-1] + __builtin_popcount(bit[(i+1)*nblock-1]);
        }
    }

    // pos番目のbitを返す
    bool operator[](int pos) const {
        int bpos = pos / bw;
        int offset = pos % bw;
        return (bool)((bit[bpos] >> offset) & 1);
    }

    // [0, pos) にある1の数を返す
    int rank(int pos) const {
        int cpos = pos / cw;
        int bpos = (pos % cw) / bw;
        int offset = pos % bw;
        // 余った部分から、必要な部分だけをbitmaskで抽出する
        u16 masked = (bit[cpos * nblock + bpos]) & ((1 << offset) - 1);
        return chunk[cpos] + blocks[cpos][bpos] + __builtin_popcount(masked);
    }

    // [0, pos) にあるb(0 or 1)の数を返す
    int rank(bool b, int pos) {
        return (b ? rank(pos) : pos - rank(pos));
    }

    // rank(idx)==numなる最小のidxを返す. 1がnum個未満なら-1を返す
    int select(int num) const {
        if (num == 0) return 0;
        if (rank(length) < num) return -1;

        int ok = length, ng = 0;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (rank(mid) >= num) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }
};

int SuccinctIndexableDictionary::cw = 1024;
int SuccinctIndexableDictionary::bw = 16;
