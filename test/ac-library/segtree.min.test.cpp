#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <iostream>
#include "../../atcoder/segtree/min.hpp"
using namespace std;

// @title セグメント木、min (ac-library)
int main() {
  int n, q; cin >> n >> q;
  segtree::min::type<int> seg(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y;
    if (c == 0) seg.set(x, y);
    else cout << seg.prod(x, y+1) << endl;
  }
}
