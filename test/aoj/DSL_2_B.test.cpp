#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../../monoid/add.hpp"
#include "../../datastructure/segment-tree.cpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  SegmentTree<monoid::sum<int>> st(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y; --x;
    if (c == 0) st.update(x, st.query(x, x+1)+y);
    else cout << st.query(x, y) << endl;
  }
}
