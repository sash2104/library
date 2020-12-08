// @brief 木の直径 (ReRooting)
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../../graph/rerooting.cpp"
#include "../../monoid/max.hpp"

using namespace std;
#include <iostream>

// rerootingで、各頂点について最も遠い頂点との距離をもとめる。答えはその最大値
int main() {
  int N; cin >> N;
  auto f=[](int value, int cost) -> int { 
    if (value < 0) return cost;
    return value+cost;
  };
  ReRooting<int, monoid::max<int>> rerooting(N, f);
  for(int i = 1; i < N; i++) {
    int x, y, z; cin >> x >> y >> z;
    rerooting.add_edge(x, y, z);
  }
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  auto ret = rerooting.solve();
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, ret[i]);
  }
  cout << ans << endl;
}