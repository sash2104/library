#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
// @title BITのテスト

#include "../../datastructure/binary-indexed-tree.hpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  BinaryIndexedTree<int> st(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y; --x;
    if (c == 0) st.add(x, y);
    else cout << st.sum(x, y) << endl;
  }
}
