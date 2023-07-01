---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5927\u6D41"
    links:
    - https://snuke.hatenablog.com/entry/2019/05/07/013609
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/max-flow-dinic.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @title \u6700\u5927\u6D41\n * @see \u87FB\u672C p.194 \n */\n#pragma\
    \ once\n#include <vector>\n#include <queue>\n\nstruct max_flow {\n  struct edge\
    \ { int to, cap, rev; };\n  int INF_ = 1<<30;\n  int V;\n  std::vector<std::vector<edge>>\
    \ G; // \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n \
    \ std::vector<int> level; // s\u304B\u3089\u306E\u8DDD\u96E2\n  std::vector<int>\
    \ iter; // \u3069\u3053\u307E\u3067\u8ABF\u3079\u7D42\u308F\u3063\u305F\u304B\n\
    \  max_flow(int V): V(V), G(V), level(V), iter(V) {}\n  void add_edge(int from,\
    \ int to, int cap) {\n    G[from].push_back((edge){to, cap, (int)G[to].size()});\n\
    \    G[to].push_back((edge){from, 0, (int)G[from].size()-1});\n  }\n\n  // s\u304B\
    \u3089\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u8A08\u7B97\u3059\u308B\n  void bfs(int\
    \ s) {\n    level.assign(V, -1);\n    std::queue<int> q;\n    level[s] = 0;\n\
    \    q.push(s);\n    while (!q.empty()) { \n      int v = q.front(); q.pop();\n\
    \      for (int i = 0; i < (int)G[v].size(); ++i) { \n        edge &e = G[v][i];\n\
    \        if (e.cap > 0 && level[e.to] < 0) { \n          level[e.to] = level[v]\
    \ + 1;\n          q.push(e.to);\n        }\n      }\n    }\n  }\n\n  // \u5897\
    \u52A0\u30D1\u30B9\u3092\u63A2\u3059\n  int dfs(int v, int t, int f) { \n    if\
    \ (v == t) return f;\n    for (int &i = iter[v]; i < (int)G[v].size(); ++i) {\n\
    \      edge &e = G[v][i];\n      if (e.cap > 0 && level[v] < level[e.to]) { \n\
    \        int d = dfs(e.to, t, std::min(f, e.cap));\n        if (d > 0) {\n   \
    \       e.cap -= d;\n          G[e.to][e.rev].cap += d;\n          return d;\n\
    \        }\n      }\n    }\n    return 0;\n  }\n\n  // s\u304B\u3089t\u3078\u306E\
    \u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\n  int run(int s, int t) {\n    int\
    \ flow = 0;\n    while (true) {\n      bfs(s);\n      if (level[t] < 0) return\
    \ flow;\n      // FIXME: \u3053\u3053\u6BCE\u56DE\u521D\u671F\u5316\u3057\u306A\
    \u3044\u65B9\u6CD5\u3082\u3042\u308A\u305D\u3046\uFF1F\n      // https://snuke.hatenablog.com/entry/2019/05/07/013609\n\
    \      iter.assign(V, 0);\n      int f;\n      while ((f = dfs(s, t, INF_)) >\
    \ 0) {\n        flow += f;\n      }\n    }\n    return flow;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/max-flow-dinic.hpp
  requiredBy: []
  timestamp: '2020-08-30 21:41:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.test.cpp
documentation_of: graph/max-flow-dinic.hpp
layout: document
redirect_from:
- /library/graph/max-flow-dinic.hpp
- /library/graph/max-flow-dinic.hpp.html
title: "\u6700\u5927\u6D41"
---
