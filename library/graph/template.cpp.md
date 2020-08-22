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


# :heavy_check_mark: graph/template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-01 21:05:07+09:00




## Required by

* :heavy_check_mark: <a href="bin-bfs.cpp.html">01-BFS</a>
* :heavy_check_mark: <a href="dijkstra.cpp.html">graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="lca.cpp.html">graph/lca.cpp</a>
* :heavy_check_mark: <a href="mst-kruskal.cpp.html">graph/mst-kruskal.cpp</a>
* :heavy_check_mark: <a href="strongly-connected-components.cpp.html">graph/strongly-connected-components.cpp</a>
* :warning: <a href="topological-sort.cpp.html">graph/topological-sort.cpp</a>
* :heavy_check_mark: <a href="warshall-floyd.cpp.html">graph/warshall-floyd.cpp</a>
* :warning: <a href="../test/aoj/notest.GRL_4_B.cpp.html">test/aoj/notest.GRL_4_B.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS_1_11_C.test.cpp.html">test/aoj/ALDS_1_11_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_C.test.cpp.html">test/aoj/GRL_1_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_A.test.cpp.html">test/aoj/GRL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_3_C.test.cpp.html">test/aoj/GRL_3_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.test.cpp.html">test/aoj/GRL_5_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

