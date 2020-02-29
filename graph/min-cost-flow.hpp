#pragma once
#include <algorithm>
#include <vector>
#include <queue>

struct min_cost_flow {
  struct edge { int to, cap, cost, rev; };
  using P = std::pair<int, int>;
  const int INF_ = 1<<30;
  int V; // 頂点数
  std::vector<std::vector<edge>> G; // グラフの隣接リスト表現
  std::vector<int> h; // ポテンシャル
  std::vector<int> dist; // 最短距離
  std::vector<int> prevv, preve; // 直前の頂点と辺

  min_cost_flow(int V) : V(V), G(V), h(V), dist(V), prevv(V), preve(V) {}

  void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
  }

  // sからtへの流量fの最小費用流を求める
  // 流せない場合は-1を返す
  int run(int s, int t, int f) { 
    int res = 0;
    std::fill(h.begin(), h.end(), 0);
    while (f > 0) { 
      std::priority_queue<P, std::vector<P>, std::greater<P>> q;
      std::fill(dist.begin(), dist.end(), INF_);
      dist[s] = 0;
      q.push({0, s});
      while (!q.empty()) { 
        P p = q.top(); q.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < (int)G[v].size(); ++i) { 
          edge &e = G[v][i];
          int d = dist[v] + e.cost + h[v] - h[e.to];
          if (e.cap > 0 && dist[e.to] > d) { 
            dist[e.to] = d;
            prevv[e.to] = v;
            preve[e.to] = i;
            q.push({dist[e.to], e.to});
          }
        }
      }
      if (dist[t] == INF_) {
        // これ以上流せない
        return -1;
      }
      for (int v = 0; v < V; ++v) h[v] += dist[v];

      // s-t間最短路に沿って目一杯流す
      int d = f;
      for (int v = t; v != s; v = prevv[v]) {
        d = std::min(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d*h[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};
