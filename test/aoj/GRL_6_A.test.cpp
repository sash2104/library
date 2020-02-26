#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "../../graph/max-flow-dinic.hpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E;
  cin >> V >> E;
  max_flow mf(V);
  for (int i = 0; i < E; ++i) {
    int from, to, cap;
    cin >> from >> to >> cap;
    mf.add_edge(from, to, cap);
  }
  cout << mf.run(0, V-1) << endl;
}
