---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: warshall-floyd

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/warshall-floyd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:41:04+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">graph/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_C.test.cpp.html">test/aoj/GRL_1_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title warshall-floyd
 */
#include "template.cpp"

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/warshall-floyd.cpp"
/**
 * @title warshall-floyd
 */
#line 1 "graph/template.cpp"
#include <vector>

template< typename T >
struct Edge {
  int from, to;
  T cost;
  Edge() {}
  Edge(int f, int t) : from(f), to(t), cost(1) {}
  Edge(int f, int t, T c) : from(f), to(t), cost(c) {}
  friend bool operator < (const Edge& lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };
  friend bool operator > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };
  friend bool operator <= (const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); };
  friend bool operator >= (const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };
};

template< typename T >
using Edges = std::vector< Edge< T > >;
template< typename T >
using Graph = std::vector< Edges< T > >;
#line 5 "graph/warshall-floyd.cpp"

#include <limits>
#line 8 "graph/warshall-floyd.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

