#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "../../atcoder/segtree/add.hpp"
using namespace std;

// @title セグメント木、sum (ac-library)
using ll = long long;
int main() {
  int n, q; cin >> n >> q;
  segtree::add::type<ll> seg(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y; --x;
    if (c == 0) seg.set(x, seg.get(x) + y);
    else cout << seg.prod(x, y) << endl;
  }
}
