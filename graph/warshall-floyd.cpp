/**
 * @title warshall-floyd
 */
#include "template.hpp"

#include <limits>
#include <vector>

template < typename T >
struct WarshallFloyd {
  const T INF; // dijkstraとINFの値を揃えるため、型Tの最大値の半分を使う
  const int V; // 頂点数
  Graph<T> g;
  std::vector<std::vector<T>> dist;
  WarshallFloyd(Graph<T> &g): INF(std::numeric_limits<T>::max()/2), V(g.size()), g(g), dist(V, std::vector<T>(V, INF)) { init(); }
  WarshallFloyd(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2), V(V), g(g), dist(V, std::vector<T>(V, INF)) { init(); }
  void init() {
    for (int i = 0; i < V; ++i) {
      dist[i][i] = 0;
      for (auto &e: g[i]) dist[i][e.to] = e.cost;
    }
    for (int k = 0; k < V; ++k) {
      for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
          if (dist[i][k] == INF || dist[k][j] == INF) continue;
          T d = dist[i][k]+dist[k][j];
          if (dist[i][j] > d) dist[i][j] = d;
        }
      }
    }
  }
  bool has_negative_cycle() {
    for (int i = 0; i < V; ++i) {
      if (dist[i][i] < 0) return true;
    }
    return false;
  }
};
