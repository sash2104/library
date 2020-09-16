---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/aoj/notest.GRL_4_B.cpp
    title: test/aoj/notest.GRL_4_B.cpp
  - icon: ':heavy_check_mark:'
    path: graph/mst-kruskal.cpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/lca.cpp
    title: "LCA (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: Dijkstra
  - icon: ':heavy_check_mark:'
    path: graph/warshall-floyd.cpp
    title: warshall-floyd
  - icon: ':warning:'
    path: graph/topological-sort.cpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/strongly-connected-components.cpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/bin-bfs.cpp
    title: 01-BFS
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS_1_11_C.test.cpp
    title: test/aoj/ALDS_1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/template.cpp\"\n#include <vector>\n\ntemplate< typename\
    \ T >\nstruct Edge {\n  int from, to;\n  T cost;\n  Edge() {}\n  Edge(int f, int\
    \ t) : from(f), to(t), cost(1) {}\n  Edge(int f, int t, T c) : from(f), to(t),\
    \ cost(c) {}\n  friend bool operator < (const Edge& lhs, const Edge& rhs) { return\
    \ lhs.cost < rhs.cost; };\n  friend bool operator > (const Edge& lhs, const Edge&\
    \ rhs) { return rhs < lhs; };\n  friend bool operator <= (const Edge& lhs, const\
    \ Edge& rhs) { return !(lhs > rhs); };\n  friend bool operator >= (const Edge&\
    \ lhs, const Edge& rhs) { return !(lhs < rhs); };\n};\n\ntemplate< typename T\
    \ >\nusing Edges = std::vector< Edge< T > >;\ntemplate< typename T >\nusing Graph\
    \ = std::vector< Edges< T > >;\n"
  code: "#include <vector>\n\ntemplate< typename T >\nstruct Edge {\n  int from, to;\n\
    \  T cost;\n  Edge() {}\n  Edge(int f, int t) : from(f), to(t), cost(1) {}\n \
    \ Edge(int f, int t, T c) : from(f), to(t), cost(c) {}\n  friend bool operator\
    \ < (const Edge& lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };\n  friend\
    \ bool operator > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };\n\
    \  friend bool operator <= (const Edge& lhs, const Edge& rhs) { return !(lhs >\
    \ rhs); };\n  friend bool operator >= (const Edge& lhs, const Edge& rhs) { return\
    \ !(lhs < rhs); };\n};\n\ntemplate< typename T >\nusing Edges = std::vector< Edge<\
    \ T > >;\ntemplate< typename T >\nusing Graph = std::vector< Edges< T > >;\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/template.cpp
  requiredBy:
  - test/aoj/notest.GRL_4_B.cpp
  - graph/mst-kruskal.cpp
  - graph/lca.cpp
  - graph/dijkstra.cpp
  - graph/warshall-floyd.cpp
  - graph/topological-sort.cpp
  - graph/strongly-connected-components.cpp
  - graph/bin-bfs.cpp
  timestamp: '2020-01-01 21:05:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
  - test/aoj/GRL_3_C.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/GRL_5_C.test.cpp
  - test/aoj/ALDS_1_11_C.test.cpp
  - test/aoj/GRL_1_A.test.cpp
documentation_of: graph/template.cpp
layout: document
redirect_from:
- /library/graph/template.cpp
- /library/graph/template.cpp.html
title: graph/template.cpp
---
