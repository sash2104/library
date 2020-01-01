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


# :heavy_check_mark: test/aoj/GRL_5_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-01 21:05:07+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/lca.cpp.html">graph/lca.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../graph/lca.cpp"
#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  Graph<int> graph(n);
  for (int i = 0; i < n; ++i) {
    int k; cin >> k;
    for (int j = 0; j < k; ++j) {
      int c; cin >> c;
      graph[i].emplace_back(i, c);
    }
  }
  LCA<int> lca(0, graph);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) { 
    int u, v;
    cin >> u >> v;
    cout << lca.get(u, v) << endl;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_5_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#line 1 "test/aoj/../../graph/template.cpp"
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
#line 2 "test/aoj/../../graph/lca.cpp"

#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

template< typename T >
struct LCA {
  using graph = Graph<T>;
  int root;
  // n : 頂点数
  const int n;
  const int log2_n;
  graph g;
  vector<vector<int>> parent;
  vector<int> depth;

  LCA(int root, const graph &g) : root(root), n(g.size()), log2_n(log2(n)+1), g(g), parent(log2_n, vector<int>(n)), depth(n) {
    dfs(g, root, root, 1);
    for (int k = 0; k+1 < log2_n; ++k) {
      parent.push_back(vector<int>(n, root)); // 要素数n, 値rootで初期化
      for (int v = n-1; v >= 0; --v) {
        int par = parent[k][v];
        parent[k+1][v] = parent[k][par];
      }
    }
  }
  
  /** 
   * par : 親のid
   * d : 木の深さ (1から始める)
   */ 
  void dfs(const graph& g, int from, int par, int d) {
    parent[0][from] = par;
    depth[from] = d;
    for (auto &e: g[from]) {
      if (depth[e.to] > 0) continue;
      dfs(g, e.to, from, d+1);
    }
  }

  int get(int v1, int v2) {
    // 深さが同じになるまで片方を登らせる
    if (depth[v1] < depth[v2]) swap(v1, v2);
    for (int k = 0; k < log2_n; ++k) {
      if ((depth[v1]-depth[v2]) >> k & 1) {
        v1 = parent[k][v1];
      }
    }
    if (v1 == v2) return v1;

    // 親が同じになる直前まで登らせる
    for (int k = log2_n-1; k >= 0; --k) {
      int p_v1 = parent[k][v1];
      int p_v2 = parent[k][v2];
      if (p_v1 == p_v2) continue;
      v1 = p_v1;
      v2 = p_v2;
    }
    assert(parent[0][v1] == parent[0][v2]);
    return parent[0][v1];
  }
};
#line 4 "test/aoj/GRL_5_C.test.cpp"
#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  Graph<int> graph(n);
  for (int i = 0; i < n; ++i) {
    int k; cin >> k;
    for (int j = 0; j < k; ++j) {
      int c; cin >> c;
      graph[i].emplace_back(i, c);
    }
  }
  LCA<int> lca(0, graph);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) { 
    int u, v;
    cin >> u >> v;
    cout << lca.get(u, v) << endl;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

