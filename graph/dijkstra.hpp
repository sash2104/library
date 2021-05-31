#ifndef __GRAPH__DIJKSTRA
#define __GRAPH__DIJKSTRA
// @title Dijkstra
#include "template.hpp"

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template < typename T >
struct Dijkstra {
  using P = std::pair<T, int>; // <始点からの距離, 点のid>
  const T INF; // 十分に大きいがoverflowしない値として、型Tの最大値の半分を使う
  const int V; // 頂点数
  Graph<T> g;
  std::vector<T> dist; // 始点からの距離
  std::vector<bool> visit; // すでに探索済みの点か
  std::vector<int> prev; // 移動経路
  Dijkstra(Graph<T> &g): INF(std::numeric_limits<T>::max()/2), V(g.size()), g(g), dist(V), visit(V), prev(V) {}
  Dijkstra(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2), V(V), g(g), dist(V), visit(V), prev(V) {}
  void init(int s) {
    std::fill(dist.begin(), dist.end(), INF);
    std::fill(visit.begin(), visit.end(), false);
    std::fill(prev.begin(), prev.end(), -1);
    dist[s] = T(); // 始点の距離を0で初期化
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({dist[s], s});
    while (!pq.empty()) {
      P node = pq.top(); pq.pop();
      int from = node.second;
      if (visit[from]) continue;
      visit[from] = true;
      for (auto &e : g[from]) {
        if (visit[e.to]) continue;
        T d = node.first + e.cost;
        if (d >= dist[e.to]) continue;
        dist[e.to] = d;
        prev[e.to] = from;
        pq.push({d, e.to});
      }
    }
  }

  // 移動経路を取得
  std::vector<int> get_path(int t) {
    std::vector<int> path;
    for(; t != -1;t=prev[t]){
        path.push_back(t);
    }
    reverse(path.begin(), path.end());
    return path;
  }

};

#endif // __GRAPH__DIJKSTRA