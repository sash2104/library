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


# :warning: graph/topological-sort.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/topological-sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-01 21:05:07+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">graph/template.cpp</a>


## Required by

* :warning: <a href="../test/aoj/notest.GRL_4_B.cpp.html">test/aoj/notest.GRL_4_B.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <stack>
#include "template.cpp"

template< typename G >
std::vector<int> topologicalSort(const G &g) {
  // トポロジカルソートした結果を返す
  const int V = g.size();
  std::vector<int> indegree(V); // 200000とかだと遅い？ 厳しそうならグローバル変数にする
  // 入次数の初期化. ほんとは読み込み時にやったほうが効率が良いけど許容する
  for (int v = 0; v < V; ++v) {
    for (auto& e: g[v]) ++indegree[e.to];
  }

  std::stack<int> st;
  for (int v = 0; v < V; ++v) {
    // 入次数0の点をstackにいれる
    if (indegree[v] == 0) st.push(v);
  }

  std::vector<int> order;
  while (!st.empty()) {
    int v = st.top(); st.pop();
    order.push_back(v);
    for (auto& e: g[v]) {
      --indegree[e.to];
      if (indegree[e.to] == 0) st.push(e.to);
    }
  }

  return order;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/topological-sort.cpp"
#include <vector>
#include <stack>
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
#line 4 "graph/topological-sort.cpp"

template< typename G >
std::vector<int> topologicalSort(const G &g) {
  // トポロジカルソートした結果を返す
  const int V = g.size();
  std::vector<int> indegree(V); // 200000とかだと遅い？ 厳しそうならグローバル変数にする
  // 入次数の初期化. ほんとは読み込み時にやったほうが効率が良いけど許容する
  for (int v = 0; v < V; ++v) {
    for (auto& e: g[v]) ++indegree[e.to];
  }

  std::stack<int> st;
  for (int v = 0; v < V; ++v) {
    // 入次数0の点をstackにいれる
    if (indegree[v] == 0) st.push(v);
  }

  std::vector<int> order;
  while (!st.empty()) {
    int v = st.top(); st.pop();
    order.push_back(v);
    for (auto& e: g[v]) {
      --indegree[e.to];
      if (indegree[e.to] == 0) st.push(e.to);
    }
  }

  return order;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

