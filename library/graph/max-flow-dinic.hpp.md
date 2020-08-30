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


# :heavy_check_mark: 最大流

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/max-flow-dinic.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:41:04+09:00


* see: <a href="蟻本 p.194">蟻本 p.194</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_6_A.test.cpp.html">test/aoj/GRL_6_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 最大流
 * @see 蟻本 p.194 
 */
#pragma once
#include <vector>
#include <queue>

struct max_flow {
  struct edge { int to, cap, rev; };
  int INF_ = 1<<30;
  int V;
  std::vector<std::vector<edge>> G; // グラフの隣接リスト表現
  std::vector<int> level; // sからの距離
  std::vector<int> iter; // どこまで調べ終わったか
  max_flow(int V): V(V), G(V), level(V), iter(V) {}
  void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
  }

  // sからの最短距離を計算する
  void bfs(int s) {
    level.assign(V, -1);
    std::queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) { 
      int v = q.front(); q.pop();
      for (int i = 0; i < (int)G[v].size(); ++i) { 
        edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) { 
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }

  // 増加パスを探す
  int dfs(int v, int t, int f) { 
    if (v == t) return f;
    for (int &i = iter[v]; i < (int)G[v].size(); ++i) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) { 
        int d = dfs(e.to, t, std::min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  // sからtへの最大流を求める
  int run(int s, int t) {
    int flow = 0;
    while (true) {
      bfs(s);
      if (level[t] < 0) return flow;
      // FIXME: ここ毎回初期化しない方法もありそう？
      // https://snuke.hatenablog.com/entry/2019/05/07/013609
      iter.assign(V, 0);
      int f;
      while ((f = dfs(s, t, INF_)) > 0) {
        flow += f;
      }
    }
    return flow;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/max-flow-dinic.hpp: line 5: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

