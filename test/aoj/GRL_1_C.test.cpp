#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../../graph/warshall-floyd.hpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E;
  cin >> V >> E;
  Graph<ll> g(V);
  for (int i = 0; i < E; ++i) {
    int x, y; ll d;
    cin >> x >> y >> d;
    g[x].emplace_back(x, y, d);
  }
  WarshallFloyd<ll> wf(g);
  if (wf.has_negative_cycle()) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (j > 0) cout << " ";
      if (wf.dist[i][j] == wf.INF) cout << "INF";
      else cout << wf.dist[i][j];
    }
    cout << endl;
  }
}
