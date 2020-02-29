#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"
#include "../../graph/min-cost-flow.hpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E, F;
  cin >> V >> E >> F;
  min_cost_flow mcf(V);
  for (int i = 0; i < E; ++i) {
    int from, to, cap, cost;
    cin >> from >> to >> cap >> cost;
    mcf.add_edge(from, to, cap, cost);
  }
  cout << mcf.run(0, V-1, F) << endl;
}
