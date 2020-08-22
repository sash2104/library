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


# :heavy_check_mark: test/aoj/ALDS_1_11_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS_1_11_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-22 23:18:55+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/bin-bfs.cpp.html">01-BFS</a>
* :heavy_check_mark: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include "../../graph/bin-bfs.cpp"
#include <iostream>
using namespace std; 

int main() {
  int n; cin >> n;
  Graph<int> g(n);
  for (int i = 0; i < n; ++i) {
    int u, k; cin >> u >> k;
    --u;
    for (int j = 0; j < k; ++j) {
      int v; cin >> v; --v;
      g[u].emplace_back(u, v, 1);
    }
  }
  BinBFS<int> bfs(g);
  bfs.init(0);
  for (int i = 0; i < n; ++i) {
    int d = bfs.dist[i];
    if (d == bfs.INF) d = -1;
    cout << i+1 << " " << d << endl;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS_1_11_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#line 1 "graph/bin-bfs.cpp"
// @title 01-BFS
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
#line 3 "graph/bin-bfs.cpp"

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#line 10 "graph/bin-bfs.cpp"

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
#line 4 "test/aoj/ALDS_1_11_C.test.cpp"
#include <iostream>
using namespace std; 

int main() {
  int n; cin >> n;
  Graph<int> g(n);
  for (int i = 0; i < n; ++i) {
    int u, k; cin >> u >> k;
    --u;
    for (int j = 0; j < k; ++j) {
      int v; cin >> v; --v;
      g[u].emplace_back(u, v, 1);
    }
  }
  BinBFS<int> bfs(g);
  bfs.init(0);
  for (int i = 0; i < n; ++i) {
    int d = bfs.dist[i];
    if (d == bfs.INF) d = -1;
    cout << i+1 << " " << d << endl;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

