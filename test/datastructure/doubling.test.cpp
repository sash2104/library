// @title ダブリングの簡易的なテスト
// dummy problem
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include "../../datastructure/doubling.hpp"
using namespace std;

void test_get() {
    vector<int> next = {2,3,1,0};
    Doubling doubling(next);
    // 愚直解と一致することの確認
    vector<int> expected = next;
    for (int q = 1; q < 10000; ++q) { 
        for (int i = 0; i < next.size(); ++i) {
            assert(doubling.get(i,q) == expected[i]);
            expected[i] = next[expected[i]];
        }
    }
}

int main() {
    test_get();

    // dummy output
    cout << "Hello World" << endl;
}