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


# :heavy_check_mark: test/aoj/GRL_2_A.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_2_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-22 12:07:03+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/union-find-tree.cpp.html">datastructure/union-find-tree.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/mst-kruskal.cpp.html">graph/mst-kruskal.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "../../graph/mst-kruskal.cpp"

using edge = Edge<int>;
int main() {
  vector<edge> edges;
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    edges.emplace_back(x, y, w);
  }
  int ans = kruscal(V, edges);
  cout << ans << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_2_A.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#line 1 "test/aoj/../../graph/mst-kruskal.cpp"
#include <algorithm>
#include <iostream>
#include <vector>
#line 1 "test/aoj/../../graph/template.cpp"
#include <vector>

using namespace std;

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
using Edges = vector< Edge< T > >;
template< typename T >
using Graph = vector< Edges< T > >;
#line 1 "test/aoj/../../graph/../datastructure/union-find-tree.cpp"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class UnionFind {
public:
  vector<int> data; // sizeとparを同時に管理する
  UnionFind(int size) : data(size, -1) {}

  int find(int x) {
    return data[x] < 0 ? x : data[x] = find(data[x]);
  }

  void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
      if (data[py] < data[px]) swap(px, py);
      data[px] += data[py]; data[py] = px;
    }
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int size(int x) {
    return -data[find(x)];
  }
};
#line 6 "test/aoj/../../graph/mst-kruskal.cpp"

template< typename T >
T kruscal(int V, Edges< T > &edges) {
  // 最小全域木の重みを返す
  UnionFind uf(V);
  T weight = 0;
  sort(edges.begin(), edges.end());
  for (auto e : edges) {
    if (uf.same(e.from, e.to)) continue;
    uf.unite(e.from, e.to);
    weight += e.cost;
  }
  return weight;
}
#line 3 "test/aoj/GRL_2_A.test.cpp"

using edge = Edge<int>;
int main() {
  vector<edge> edges;
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    edges.emplace_back(x, y, w);
  }
  int ans = kruscal(V, edges);
  cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

