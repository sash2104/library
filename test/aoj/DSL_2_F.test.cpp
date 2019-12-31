#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "../../monoid/min.hpp"
#include "../../monoid/fill.hpp"
#include "../../datastructure/lazy-segment-tree.cpp"

#include <iostream>
#include <climits>
using namespace std;

using p_bi = pair<bool, int>;

int main() {
  int n, q; cin >> n >> q;
  auto g=[](int a, p_bi b) -> int { return b.first ? b.second : a; };
  LazySegmentTree<monoid::min<int>, monoid::fill<int>> st(g);
  st.build(vector<int>(n, INT_MAX));
  for (int i = 0; i < q; ++i) {
    int c; cin >> c;
    if (c == 0) {
      int s, t, x; cin >> s >> t >> x;
      st.update(s, t+1, {true, x});
    }
    else {
      int s, t; cin >> s >> t;
      cout << st.query(s, t+1) << endl;
    }
  }
}
