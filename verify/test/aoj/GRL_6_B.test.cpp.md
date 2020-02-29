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


# :heavy_check_mark: test/aoj/GRL_6_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_6_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-29 14:48:05+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/min-cost-flow.hpp.html">graph/min-cost-flow.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"
#include "../../graph/min-cost-flow.hpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E, F;
  cin >> V >> E >> F;
  min_cost_flow mcf(V);
  for (int i = 0; i < E; ++i) {
    int from, to, cap, cost;
    cin >> from >> to >> cap >> cost;
    mcf.add_edge(from, to, cap, cost);
  }
  cout << mcf.run(0, V-1, F) << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_6_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"
#line 2 "test/aoj/../../graph/min-cost-flow.hpp"
#include <algorithm>
#include <vector>
#include <queue>

struct min_cost_flow {
  struct edge { int to, cap, cost, rev; };
  using P = std::pair<int, int>;
  const int INF_ = 1<<30;
  int V; // 頂点数
  std::vector<std::vector<edge>> G; // グラフの隣接リスト表現
  std::vector<int> h; // ポテンシャル
  std::vector<int> dist; // 最短距離
  std::vector<int> prevv, preve; // 直前の頂点と辺

  min_cost_flow(int V) : V(V), G(V), h(V), dist(V), prevv(V), preve(V) {}

  void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
  }

  // sからtへの流量fの最小費用流を求める
  // 流せない場合は-1を返す
  int run(int s, int t, int f) { 
    int res = 0;
    std::fill(h.begin(), h.end(), 0);
    while (f > 0) { 
      std::priority_queue<P, std::vector<P>, std::greater<P>> q;
      std::fill(dist.begin(), dist.end(), INF_);
      dist[s] = 0;
      q.push({0, s});
      while (!q.empty()) { 
        P p = q.top(); q.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < (int)G[v].size(); ++i) { 
          edge &e = G[v][i];
          int d = dist[v] + e.cost + h[v] - h[e.to];
          if (e.cap > 0 && dist[e.to] > d) { 
            dist[e.to] = d;
            prevv[e.to] = v;
            preve[e.to] = i;
            q.push({dist[e.to], e.to});
          }
        }
      }
      if (dist[t] == INF_) {
        // これ以上流せない
        return -1;
      }
      for (int v = 0; v < V; ++v) h[v] += dist[v];

      // s-t間最短路に沿って目一杯流す
      int d = f;
      for (int v = t; v != s; v = prevv[v]) {
        d = std::min(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d*h[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};
#line 3 "test/aoj/GRL_6_B.test.cpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E, F;
  cin >> V >> E >> F;
  min_cost_flow mcf(V);
  for (int i = 0; i < E; ++i) {
    int from, to, cap, cost;
    cin >> from >> to >> cap >> cost;
    mcf.add_edge(from, to, cap, cost);
  }
  cout << mcf.run(0, V-1, F) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

