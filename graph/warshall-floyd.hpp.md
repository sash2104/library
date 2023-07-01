---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: warshall-floyd
    links: []
  bundledCode: "#line 1 \"graph/warshall-floyd.hpp\"\n\n\n// @title warshall-floyd\n\
    #line 1 \"graph/template.hpp\"\n\n\n\n#include <iostream>\n#include <vector>\n\
    \ntemplate< typename T >\nstruct Edge {\n  int from, to;\n  T cost;\n  Edge()\
    \ {}\n  Edge(int f, int t) : from(f), to(t), cost(1) {}\n  Edge(int f, int t,\
    \ T c) : from(f), to(t), cost(c) {}\n  friend bool operator < (const Edge& lhs,\
    \ const Edge& rhs) { return lhs.cost < rhs.cost; };\n  friend bool operator >\
    \ (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };\n  friend bool operator\
    \ <= (const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); };\n  friend bool\
    \ operator >= (const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };\n};\n\
    \ntemplate< typename T >\nusing Edges = std::vector< Edge< T > >;\ntemplate< typename\
    \ T >\nusing Graph = std::vector< Edges< T > >;\n\ntemplate< typename T >\nvoid\
    \ debug(Graph<T> &g, int n = -1) {\n    if (n == -1) n = g.size();\n    for (int\
    \ i = 0; i < n; ++i) {\n        std::cerr << i  << \"\\t\";\n        for (auto\
    \ &e: g[i]) {\n            std::cerr << e.to << \",\";\n        }\n        std::cerr\
    \ << std::endl;\n    }\n}\n\n\n#line 5 \"graph/warshall-floyd.hpp\"\n\n#include\
    \ <limits>\n#line 8 \"graph/warshall-floyd.hpp\"\n\ntemplate < typename T >\n\
    struct WarshallFloyd {\n  const T INF; // dijkstra\u3068INF\u306E\u5024\u3092\u63C3\
    \u3048\u308B\u305F\u3081\u3001\u578BT\u306E\u6700\u5927\u5024\u306E\u534A\u5206\
    \u3092\u4F7F\u3046\n  const int V; // \u9802\u70B9\u6570\n  Graph<T> g;\n  std::vector<std::vector<T>>\
    \ dist;\n  WarshallFloyd(Graph<T> &g): INF(std::numeric_limits<T>::max()/2), V(g.size()),\
    \ g(g), dist(V, std::vector<T>(V, INF)) { init(); }\n  WarshallFloyd(Graph<T>\
    \ &g, int V): INF(std::numeric_limits<T>::max()/2), V(V), g(g), dist(V, std::vector<T>(V,\
    \ INF)) { init(); }\n  void init() {\n    for (int i = 0; i < V; ++i) {\n    \
    \  dist[i][i] = 0;\n      for (auto &e: g[i]) dist[i][e.to] = e.cost;\n    }\n\
    \    for (int k = 0; k < V; ++k) {\n      for (int i = 0; i < V; ++i) {\n    \
    \    for (int j = 0; j < V; ++j) {\n          if (dist[i][k] == INF || dist[k][j]\
    \ == INF) continue;\n          T d = dist[i][k]+dist[k][j];\n          if (dist[i][j]\
    \ > d) dist[i][j] = d;\n        }\n      }\n    }\n  }\n  bool has_negative_cycle()\
    \ {\n    for (int i = 0; i < V; ++i) {\n      if (dist[i][i] < 0) return true;\n\
    \    }\n    return false;\n  }\n};\n\n\n"
  code: "#ifndef __GRAPH__WARSHALL__FLOYD\n#define __GRAPH__WARSHALL__FLOYD\n// @title\
    \ warshall-floyd\n#include \"template.hpp\"\n\n#include <limits>\n#include <vector>\n\
    \ntemplate < typename T >\nstruct WarshallFloyd {\n  const T INF; // dijkstra\u3068\
    INF\u306E\u5024\u3092\u63C3\u3048\u308B\u305F\u3081\u3001\u578BT\u306E\u6700\u5927\
    \u5024\u306E\u534A\u5206\u3092\u4F7F\u3046\n  const int V; // \u9802\u70B9\u6570\
    \n  Graph<T> g;\n  std::vector<std::vector<T>> dist;\n  WarshallFloyd(Graph<T>\
    \ &g): INF(std::numeric_limits<T>::max()/2), V(g.size()), g(g), dist(V, std::vector<T>(V,\
    \ INF)) { init(); }\n  WarshallFloyd(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2),\
    \ V(V), g(g), dist(V, std::vector<T>(V, INF)) { init(); }\n  void init() {\n \
    \   for (int i = 0; i < V; ++i) {\n      dist[i][i] = 0;\n      for (auto &e:\
    \ g[i]) dist[i][e.to] = e.cost;\n    }\n    for (int k = 0; k < V; ++k) {\n  \
    \    for (int i = 0; i < V; ++i) {\n        for (int j = 0; j < V; ++j) {\n  \
    \        if (dist[i][k] == INF || dist[k][j] == INF) continue;\n          T d\
    \ = dist[i][k]+dist[k][j];\n          if (dist[i][j] > d) dist[i][j] = d;\n  \
    \      }\n      }\n    }\n  }\n  bool has_negative_cycle() {\n    for (int i =\
    \ 0; i < V; ++i) {\n      if (dist[i][i] < 0) return true;\n    }\n    return\
    \ false;\n  }\n};\n\n#endif // __GRAPH__WARSHALL__FLOYD"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
documentation_of: graph/warshall-floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall-floyd.hpp
- /library/graph/warshall-floyd.hpp.html
title: warshall-floyd
---
