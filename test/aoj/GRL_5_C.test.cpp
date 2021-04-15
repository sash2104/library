#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../graph/lca.hpp"
#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  Graph<int> graph(n);
  for (int i = 0; i < n; ++i) {
    int k; cin >> k;
    for (int j = 0; j < k; ++j) {
      int c; cin >> c;
      graph[i].emplace_back(i, c);
    }
  }
  LCA<int> lca(0, graph);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) { 
    int u, v;
    cin >> u >> v;
    cout << lca.get(u, v) << endl;
  }
}
