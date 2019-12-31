#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../monoid/add_count.hpp"
#include "../../monoid/add.hpp"
#include "../../datastructure/lazy-segment-tree.cpp"

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
using P = pair<ll, ll>;

int main() {
  int n, q; cin >> n >> q;
  auto g=[](P a,ll b) -> P {return P(a.first+b*a.second, a.second);};
  LazySegmentTree<monoid::add_count<ll>, monoid::add<ll>> st(g);
  st.build(vector<P>(n,P(0,1)));
  for (int i = 0; i < q; ++i) {
    int c; cin >> c;
    if (c == 0) {
      int s, t, x; cin >> s >> t >> x;
      st.update(s-1, t, x);
    }
    else {
      int s, t; cin >> s >> t;
      cout << st.query(s-1, t).first << endl;
    }
  }
}
