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


# :heavy_check_mark: test/aoj/GRL_3_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_3_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-01 21:05:07+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/strongly-connected-components.cpp.html">graph/strongly-connected-components.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include "../../graph/strongly-connected-components.cpp"
#include <iostream>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  Graph<int> graph(V);
  for (int i = 0; i < E; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x].emplace_back(x, y);
  }
  stronglyConnectedComponents<int> scc(graph);
  scc.build();
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) { 
    int u, v;
    cin >> u >> v;
    if (scc.same(u, v)) { cout << "1" << endl; }
    else { cout << "0" << endl; }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_3_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#line 1 "graph/strongly-connected-components.cpp"
#include <cassert>
#include <algorithm>
#include <vector>

#line 2 "graph/template.cpp"

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
#line 6 "graph/strongly-connected-components.cpp"
using namespace std;

template< typename T >
struct stronglyConnectedComponents {
  using graph = Graph<T>;
  const int V;
  graph g, rg;
  vector<bool> visit;
  vector<int> comp, order;
  vector<vector<int>> components;

  stronglyConnectedComponents(const graph &g) : V(g.size()), g(g), rg(V), visit(V, false), comp(V, -1) {
    // 辺の向きを逆にしたグラフを構築
    for (int v = 0; v < V; ++v) {
      for (auto &e : g[v]) { 
        rg[e.to].emplace_back(e.to, e.from);
      }
    }
  }

  // 同じ強連結成分に属していればtrueを返す
  bool same(int s, int t) {
    assert(comp[s] != -1 && comp[t] != -1);
    return comp[s] == comp[t];
  }

  void dfs(int sv) { 
    if (visit[sv]) return;
    visit[sv] = true;
    for (auto &e : g[sv]) { 
      dfs(e.to);
    }
    order.push_back(sv);
  }

  void rdfs(int sv, int cnt) { 
    if (comp[sv] != -1) return;
    comp[sv] = cnt;

    if (components.size() <= cnt) { 
      vector<int> v;
      components.push_back(v);
    }
    components[cnt].push_back(sv);

    for (auto &e : rg[sv]) { 
      rdfs(e.to, cnt);
    }
  }

  void build() {
    for(int i = 0; i < V; i++) { dfs(i); } 
    assert(order.size() == V);
    reverse(order.begin(), order.end()); // dfsでつけた番号を逆順にする
    int cnt = 0; // 強連結成分毎のid
    for (int v : order) { 
      if (comp[v] != -1) continue;
      rdfs(v, cnt);
      // 強連結成分の頂点をループの順に並び替え
      if (components[cnt].size() > 1) {
        reverse(components[cnt].begin()+1, components[cnt].end());
      }
      ++cnt;
    }
  }
};
#line 4 "test/aoj/GRL_3_C.test.cpp"
#include <iostream>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  Graph<int> graph(V);
  for (int i = 0; i < E; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x].emplace_back(x, y);
  }
  stronglyConnectedComponents<int> scc(graph);
  scc.build();
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) { 
    int u, v;
    cin >> u >> v;
    if (scc.same(u, v)) { cout << "1" << endl; }
    else { cout << "0" << endl; }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

