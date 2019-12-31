#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include "../../monoid/add.hpp"
#include "../../monoid/min.hpp"
#include "../../datastructure/lazy-segment-tree.cpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  auto h=[](int a,int b){return a+b;};
  LazySegmentTree<monoid::min<int>, monoid::add<int>> st(h);
  st.build(vector<int>(n,0));
  for (int i = 0; i < q; ++i) {
    int c; cin >> c;
    if (c == 0) {
      int s, t, x; cin >> s >> t >> x;
      st.update(s, t+1, x);
    }
    else {
      int s, t; cin >> s >> t;
      cout << st.query(s, t+1) << endl;
    }
  }
}
