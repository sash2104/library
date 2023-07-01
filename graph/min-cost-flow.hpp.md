---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/min-cost-flow.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/**\n * @title \u6700\u5C0F\u8CBB\u7528\u6D41\n */\n#pragma once\n#include\
    \ <algorithm>\n#include <vector>\n#include <queue>\n\nstruct min_cost_flow {\n\
    \  struct edge { int to, cap, cost, rev; };\n  using P = std::pair<int, int>;\n\
    \  const int INF_ = 1<<30;\n  int V; // \u9802\u70B9\u6570\n  std::vector<std::vector<edge>>\
    \ G; // \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n \
    \ std::vector<int> h; // \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\n  std::vector<int>\
    \ dist; // \u6700\u77ED\u8DDD\u96E2\n  std::vector<int> prevv, preve; // \u76F4\
    \u524D\u306E\u9802\u70B9\u3068\u8FBA\n\n  min_cost_flow(int V) : V(V), G(V), h(V),\
    \ dist(V), prevv(V), preve(V) {}\n\n  void add_edge(int from, int to, int cap,\
    \ int cost) {\n    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});\n\
    \    G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});\n  }\n\n\
    \  // s\u304B\u3089t\u3078\u306E\u6D41\u91CFf\u306E\u6700\u5C0F\u8CBB\u7528\u6D41\
    \u3092\u6C42\u3081\u308B\n  // \u6D41\u305B\u306A\u3044\u5834\u5408\u306F-1\u3092\
    \u8FD4\u3059\n  int run(int s, int t, int f) { \n    int res = 0;\n    std::fill(h.begin(),\
    \ h.end(), 0);\n    while (f > 0) { \n      std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> q;\n      std::fill(dist.begin(), dist.end(), INF_);\n    \
    \  dist[s] = 0;\n      q.push({0, s});\n      while (!q.empty()) { \n        P\
    \ p = q.top(); q.pop();\n        int v = p.second;\n        if (dist[v] < p.first)\
    \ continue;\n        for (int i = 0; i < (int)G[v].size(); ++i) { \n         \
    \ edge &e = G[v][i];\n          int d = dist[v] + e.cost + h[v] - h[e.to];\n \
    \         if (e.cap > 0 && dist[e.to] > d) { \n            dist[e.to] = d;\n \
    \           prevv[e.to] = v;\n            preve[e.to] = i;\n            q.push({dist[e.to],\
    \ e.to});\n          }\n        }\n      }\n      if (dist[t] == INF_) {\n   \
    \     // \u3053\u308C\u4EE5\u4E0A\u6D41\u305B\u306A\u3044\n        return -1;\n\
    \      }\n      for (int v = 0; v < V; ++v) h[v] += dist[v];\n\n      // s-t\u9593\
    \u6700\u77ED\u8DEF\u306B\u6CBF\u3063\u3066\u76EE\u4E00\u676F\u6D41\u3059\n   \
    \   int d = f;\n      for (int v = t; v != s; v = prevv[v]) {\n        d = std::min(d,\
    \ G[prevv[v]][preve[v]].cap);\n      }\n      f -= d;\n      res += d*h[t];\n\
    \      for (int v = t; v != s; v = prevv[v]) {\n        edge &e = G[prevv[v]][preve[v]];\n\
    \        e.cap -= d;\n        G[v][e.rev].cap += d;\n      }\n    }\n    return\
    \ res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/min-cost-flow.hpp
  requiredBy: []
  timestamp: '2020-08-30 21:41:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_B.test.cpp
documentation_of: graph/min-cost-flow.hpp
layout: document
redirect_from:
- /library/graph/min-cost-flow.hpp
- /library/graph/min-cost-flow.hpp.html
title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
---
