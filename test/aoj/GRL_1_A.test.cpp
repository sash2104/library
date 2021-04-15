#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../../graph/dijkstra.hpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E, root;
  cin >> V >> E >> root;
  Graph<ll> g(V);
  for (int i = 0; i < E; ++i) {
    int x, y;
    ll d;
    cin >> x >> y >> d;
    g[x].emplace_back(x, y, d);
  }
  Dijkstra<ll> di(g);
  di.init(root);
  for (int i = 0; i < V; ++i) {
    if (di.dist[i] == di.INF) cout << "INF" << endl;
    else cout << di.dist[i] << endl;
  }
}
