#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include "../../datastructure/union-find-tree.hpp"

#include <iostream>
using namespace std;
int main() {
  int n, q; cin >> n >> q;
  UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y;
    if (c == 0) { uf.unite(x, y); }
    else {
      if (uf.same(x, y)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
}
