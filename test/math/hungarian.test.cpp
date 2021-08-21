// @title ダブリングの簡易的なテスト
// dummy problem
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include "../../math/hungarian.hpp"
using namespace std;

void test_solve() {
    // M > Nでも動作することの確認として、0列目には絶対に使われない値を設定
    vector<vector<int>> A = {
        {99, 15, 6, 9, 8},
        {99, 3, 13, 7, 6},
        {99, 9, 10, 5, 11},
        {99, 3, 5, 7, 11},
    };
    Hungarian<int> hungarian(A);
    // A[0][2]+A[1][4]+A[2][3]+A[3][1]
    assert(20 == hungarian.solve());
    // 各行に割り当てられた列
    assert(2 == hungarian.get(0));
    assert(4 == hungarian.get(1));
    assert(3 == hungarian.get(2));
    assert(1 == hungarian.get(3));
}

int main() {
    test_solve();

    // dummy output
    cout << "Hello World" << endl;
}