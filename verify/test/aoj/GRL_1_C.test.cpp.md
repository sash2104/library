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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/GRL_1_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-06 01:00:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/warshall-floyd.cpp.html">graph/warshall-floyd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../../graph/warshall-floyd.cpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E;
  cin >> V >> E;
  Graph<ll> g(V);
  for (int i = 0; i < E; ++i) {
    int x, y; ll d;
    cin >> x >> y >> d;
    g[x].emplace_back(x, y, d);
  }
  WarshallFloyd<ll> wf(g);
  if (wf.has_negative_cycle()) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (j > 0) cout << " ";
      if (wf.dist[i][j] == wf.INF) cout << "INF";
      else cout << wf.dist[i][j];
    }
    cout << endl;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_1_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
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
#line 2 "graph/warshall-floyd.cpp"

#include <limits>
#line 5 "graph/warshall-floyd.cpp"

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
#line 3 "test/aoj/GRL_1_C.test.cpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E;
  cin >> V >> E;
  Graph<ll> g(V);
  for (int i = 0; i < E; ++i) {
    int x, y; ll d;
    cin >> x >> y >> d;
    g[x].emplace_back(x, y, d);
  }
  WarshallFloyd<ll> wf(g);
  if (wf.has_negative_cycle()) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (j > 0) cout << " ";
      if (wf.dist[i][j] == wf.INF) cout << "INF";
      else cout << wf.dist[i][j];
    }
    cout << endl;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

