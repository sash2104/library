#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <iostream>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
// @title Disjoint Set Union (ac-library)

int main() {
  int n, q; cin >> n >> q;
  dsu d(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y;
    if (c == 0) { d.merge(x, y); }
    else {
      if (d.same(x, y)) { cout << 1 << endl; }
      else { cout << 0 << endl; }
    }
  }
}