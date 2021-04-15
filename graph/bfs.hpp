#ifndef __GRAPH__BFS
#define __GRAPH__BFS

// @title BFS
#include "template.hpp"

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template < typename T >
struct BFS {
  using P = std::pair<T, int>; // <始点からの距離, 点のid>
  const T INF; // 十分に大きいがoverflowしない値として、型Tの最大値の半分を使う
  const int V; // 頂点数
  Graph<T> g;
  std::vector<T> dist; // 始点からの距離
  std::vector<bool> visit; // すでに探索済みの点か
  BFS(Graph<T> &g): INF(std::numeric_limits<T>::max()/2), V(g.size()), g(g), dist(V), visit(V) {}
  BFS(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2), V(V), g(g), dist(V), visit(V) {}
  void init(int s) {
    std::fill(dist.begin(), dist.end(), INF);
    std::fill(visit.begin(), visit.end(), false);
    dist[s] = T(); // 始点の距離を0で初期化
    std::queue<P> q;
    q.push({dist[s], s});
    while (!q.empty()) {
      P node = q.front(); q.pop();
      int from = node.second;
      if (visit[from]) continue;
      visit[from] = true;
      for (auto &e : g[from]) {
        if (visit[e.to]) continue;
        T d = node.first + e.cost;
        if (d >= dist[e.to]) continue;
        q.push({d, e.to});
        dist[e.to] = d;
      }
    }
  }
};

#endif // __GRAPH__BFS