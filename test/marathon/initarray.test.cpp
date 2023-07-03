// @title InitArrayクラスの簡易的なテスト
// dummy problem
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <cassert>
#include <iostream>
#include "../../util/marathon/initarray.hpp"
using namespace std;

static constexpr int n = 100;
void test() {
    InitArray<n> visited;
    for (int i = 0; i < n; ++i) {
        visited.reset();
        visited.set(i);
        for (int j = 0; j < n; ++j) {
            assert (visited[j] == (j==i));
        }
    }
}

int main() {
    test();

    // dummy output
    cout << "Hello World" << endl;
}