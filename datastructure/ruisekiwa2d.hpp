#ifndef __RUISEKIWA2D
#define __RUISEKIWA2D
/**
 * @title 二次元累積和
 * @brief 縦H横Wの範囲の矩形に対しaddをN回したとき、前処理 $O(N+HW)$、取得$O(1)$
 * @see https://atcoder.jp/contests/typical90/submissions/23946854
 */

#include <cassert>
#include <iostream>
#include <vector>

struct Ruisekiwa2D {
    int W, H;
    std::vector<std::vector<int>> v;
    Ruisekiwa2D(int W, int H): W(W), H(H), v(H, std::vector<int>(W)) {}
    void add(int sx, int sy, int tx, int ty, int c) {
        // x = [sx,tx], y = [sy,ty] の範囲の長方形にcを加える
        // @see https://imoz.jp/algorithms/imos_method.html
        assert(sx < tx && sy < ty);
        v[sy][sx] += c;
        v[sy][tx] -= c;
        v[ty][sx] -= c;
        v[ty][tx] += c;
    }
    void build() {
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                if (0 < y) v[y][x] += v[y - 1][x];
                if (0 < x) v[y][x] += v[y][x - 1];
                if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];
            }
        }
    }
    int get(int x, int y) {
        return v[y][x];
    }
    void show(int sx, int sy, int tx, int ty) {
        // x = [sx,tx], y = [sy,ty] の範囲の長方形を表示する
        for (int y = sy; y < ty; ++y) {
            for (int x = sx; x < tx; ++x) {
                std::cerr << v[y][x] << ' ';
            }
            std::cerr << std::endl;
        }
    }
};

#endif // __RUISEKIWA2D