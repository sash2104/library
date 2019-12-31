#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../../monoid/add.hpp"
#include "../../datastructure/dual-segment-tree.cpp"
#include <iostream>

using namespace std;

int main() {
  int n, q; cin >> n >> q;
  DualSegmentTree<monoid::add<int>> st;
  st.build(vector<int>(n, 0));
  for (int i = 0; i < q; ++i) {
    int c; cin >> c;
    if (c == 0) {
      int s, t, x; cin >> s >> t >> x;
      st.update(s, t+1, x);
    }
    else {
      int s; cin >> s;
      cout << st[s] << endl;
    }
  }
}
