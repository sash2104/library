#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
// @title 双対セグメント木 (区間変更・一点取得)

#include "../../monoid/fill.hpp"
#include "../../datastructure/dual-segment-tree.hpp"
#include <iostream>
#include <climits>
using namespace std;

using p_bi = pair<bool, int>;

int main() {
  int n, q; cin >> n >> q;
  DualSegmentTree<monoid::fill<int>> st;
  st.build(vector<p_bi>(n, {true, INT_MAX}));
  for (int i = 0; i < q; ++i) {
    int c; cin >> c;
    if (c == 0) {
      int s, t, x; cin >> s >> t >> x;
      st.update(s, t+1, {true, x});
    }
    else {
      int s; cin >> s;
      cout << st[s].second << endl;
    }
  }
}
