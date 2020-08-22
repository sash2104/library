// @title 01-BFS
#include "template.cpp"

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template < typename T >
struct BinBFS {
  using P = std::pair<T, int>; // <始点からの距離, 点のid>
  const T INF; // 十分に大きいがoverflowしない値として、型Tの最大値の半分を使う
  const int V; // 頂点数
  Graph<T> g;
  std::vector<T> dist; // 始点からの距離
  std::vector<bool> visit; // すでに探索済みの点か
  BinBFS(Graph<T> &g): INF(std::numeric_limits<T>::max()/2), V(g.size()), g(g), dist(V), visit(V) {}
  BinBFS(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2), V(V), g(g), dist(V), visit(V) {}
  void init(int s) {
    std::fill(dist.begin(), dist.end(), INF);
    std::fill(visit.begin(), visit.end(), false);
    dist[s] = T(); // 始点の距離を0で初期化
    std::deque<P> q;
    q.push_front({dist[s], s});
    while (!q.empty()) {
      P node = q.front(); q.pop_front();
      int from = node.second;
      if (visit[from]) continue;
      visit[from] = true;
      for (auto &e : g[from]) {
        if (visit[e.to]) continue;
        T d = node.first + e.cost;
        if (d >= dist[e.to]) continue;
        if (e.cost == 0) {
          q.push_front({d, e.to});
        }
        else {
          q.push_back({d, e.to});
        }
        dist[e.to] = d;
      }
    }
  }
};
