#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
// @title セグメント木 (一点更新・区間最小)

#include "../../monoid/min.hpp"
#include "../../datastructure/segment-tree.cpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  SegmentTree<monoid::min<int>> st(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y;
    if (c == 0) st.update(x, y);
    else cout << st.query(x, y+1) << endl;
  }
}
