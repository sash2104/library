#pragma once
#ifndef _DATASTRUCTURE_DOUBLING_
#define _DATASTRUCTURE_DOUBLING_
/**
 * @title ダブリング
 * @brief 要素数Mのある要素に対するN個先の要素取得を前処理 $O(M\log N)$、取得$O(\log N)$で行う
 * @see http://satanic0258.hatenablog.com/entry/2017/02/23/222647
 */
#include <vector>

struct Doubling {
    int N; // 要素数 
    // 辿る深さの最大値。最大でQ個先まで見る場合`2^K > Q`を満たすようにKを決める
    // Qがlong longの範囲であれば、K = 63とする
    // FIXME: K >= 64だと、getの(q>>k)がoverflowして取得する値がおかしくなる
    int K;
    const int EMPTY;
    // table[k][i]でi番目の要素の「2^k個先の要素」を指す
    // i番目の要素に対して「2^k個先の要素」が存在しないときは
    // `table[k][i] = EMPTY` となる
    std::vector<std::vector<int>> table;

    Doubling(const std::vector<int>& next, int k): N(next.size()), K(k), EMPTY(-1) {
        init(next);
    }
    Doubling(const std::vector<int>& next): N(next.size()), K(63), EMPTY(-1) {
        init(next);
    }

    void init(const std::vector<int>& next) {
        table.push_back(next);
        for (int k = 0; k < K; ++k) { 
            table.push_back(std::vector<int>(N));
            for (int i = 0; i < N; ++i) {
                if (table[k][i] == EMPTY) {
                    // 2^k個先に要素が無い場合2^(k+1)個先にも要素は無い
                    table[k+1][i] = EMPTY;
                }
                else {
                    // 「2^k個先の要素」の2^k個先の要素は2^(k+1)個先の要素
                    table[k+1][i] = table[k][table[k][i]];
                }
            }
        }

    }

    // p番目の要素のq個先の要素
    // NOTE: 大きい数で答えが合わなかったら、overflowを疑う
    int get(int p, unsigned long long q) const {
        for (int k = K-1; k >= 0; --k) {
            if (p == EMPTY) break;
            if ((q >> k) & 1ULL) {
                // k番目のビットが立っていたらpの位置を2^k先にする
                p = table[k][p];
            }
        }
        return p;
    }
};

#endif // _DATASTRUCTURE_DOUBLING_