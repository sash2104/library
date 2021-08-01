/**
 * @brief 掃き出し法 (binary行列)
 * original: https://github.com/drken1215/algorithm/blob/2eadcda21d142c36a50774bee10465caaa4f8022/MathAlgebra/matrix_binary.cpp
 * blog: https://drken1215.hatenablog.com/entry/2019/03/20/202800
 * 使用例: https://atcoder.jp/contests/typical90/submissions/24717118
 */
#include <cassert>
#include <iostream>
#include <vector>
#include <bitset>

const int MAX_ROW = 510; // to be set appropriately
const int MAX_COL = 510; // to be set appropriately
struct BitMatrix {
    int H, W;
    std::bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline std::bitset<MAX_COL>& operator [] (int i) {return val[i];}
    inline friend std::ostream& operator << (std::ostream& s, BitMatrix M) {
        s << std::endl;
        for (int i = 0; i < M.H; ++i) {
            for (int j = 0; j < M.W; ++j) s << M.val[i][j];
            s << std::endl;
        }
        return s;
    }
};

int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}

int linear_equation(BitMatrix &A, std::vector<int> &b, std::vector<int> &res) {
    int m = A.H, n = A.W;
    assert(m == (int)b.size());
    BitMatrix M(m, n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }
    int rank = GaussJordan(M, true);

    // check if it has no solution
    for (int row = rank; row < m; ++row) if (M[row][n]) return -1;

    // answer
    res.assign(n, 0);
    for (int i = 0; i < rank; ++i) res[i] = M[i][n];
    return rank;
}