---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bfs.hpp
    title: BFS
  - icon: ':heavy_check_mark:'
    path: graph/bin-bfs.hpp
    title: 01-BFS
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra
  - icon: ':warning:'
    path: graph/grid-graph.hpp
    title: "\u30B0\u30EA\u30C3\u30C9\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: "LCA (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: graph/mst-kruskal.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/rerooting.hpp
    title: "\u5168\u65B9\u4F4D\u6728DP (ReRooting)"
  - icon: ':heavy_check_mark:'
    path: graph/strongly-connected-components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':warning:'
    path: graph/topological-sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/tree-diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  - icon: ':heavy_check_mark:'
    path: graph/warshall-floyd.hpp
    title: warshall-floyd
  - icon: ':warning:'
    path: test/aoj/notest.GRL_4_B.cpp
    title: test/aoj/notest.GRL_4_B.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS_1_11_C.bfs.test.cpp
    title: test/aoj/ALDS_1_11_C.bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS_1_11_C.test.cpp
    title: test/aoj/ALDS_1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.rerooting.test.cpp
    title: "\u6728\u306E\u76F4\u5F84 (ReRooting)"
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: "\u6728\u306E\u76F4\u5F84\u306E\u30C6\u30B9\u30C8"
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/template.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <vector>\n\ntemplate< typename T >\nstruct Edge {\n  int from, to;\n  T cost;\n\
    \  Edge() {}\n  Edge(int f, int t) : from(f), to(t), cost(1) {}\n  Edge(int f,\
    \ int t, T c) : from(f), to(t), cost(c) {}\n  friend bool operator < (const Edge&\
    \ lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };\n  friend bool operator\
    \ > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };\n  friend bool operator\
    \ <= (const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); };\n  friend bool\
    \ operator >= (const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };\n};\n\
    \ntemplate< typename T >\nusing Edges = std::vector< Edge< T > >;\ntemplate< typename\
    \ T >\nusing Graph = std::vector< Edges< T > >;\n\ntemplate< typename T >\nvoid\
    \ debug(Graph<T> &g, int n = -1) {\n    if (n == -1) n = g.size();\n    for (int\
    \ i = 0; i < n; ++i) {\n        std::cerr << i  << \"\\t\";\n        for (auto\
    \ &e: g[i]) {\n            std::cerr << e.to << \",\";\n        }\n        std::cerr\
    \ << std::endl;\n    }\n}\n\n\n"
  code: "#ifndef __GRAPH__TEMPLATE\n#define __GRAPH__TEMPLATE\n\n#include <iostream>\n\
    #include <vector>\n\ntemplate< typename T >\nstruct Edge {\n  int from, to;\n\
    \  T cost;\n  Edge() {}\n  Edge(int f, int t) : from(f), to(t), cost(1) {}\n \
    \ Edge(int f, int t, T c) : from(f), to(t), cost(c) {}\n  friend bool operator\
    \ < (const Edge& lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };\n  friend\
    \ bool operator > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };\n\
    \  friend bool operator <= (const Edge& lhs, const Edge& rhs) { return !(lhs >\
    \ rhs); };\n  friend bool operator >= (const Edge& lhs, const Edge& rhs) { return\
    \ !(lhs < rhs); };\n};\n\ntemplate< typename T >\nusing Edges = std::vector< Edge<\
    \ T > >;\ntemplate< typename T >\nusing Graph = std::vector< Edges< T > >;\n\n\
    template< typename T >\nvoid debug(Graph<T> &g, int n = -1) {\n    if (n == -1)\
    \ n = g.size();\n    for (int i = 0; i < n; ++i) {\n        std::cerr << i  <<\
    \ \"\\t\";\n        for (auto &e: g[i]) {\n            std::cerr << e.to << \"\
    ,\";\n        }\n        std::cerr << std::endl;\n    }\n}\n\n#endif // __GRAPH_TEMPLATE"
  dependsOn: []
  isVerificationFile: false
  path: graph/template.hpp
  requiredBy:
  - graph/dijkstra.hpp
  - graph/lca.hpp
  - graph/rerooting.hpp
  - graph/topological-sort.hpp
  - graph/warshall-floyd.hpp
  - graph/grid-graph.hpp
  - graph/bin-bfs.hpp
  - graph/tree-diameter.hpp
  - graph/bfs.hpp
  - graph/strongly-connected-components.hpp
  - graph/mst-kruskal.hpp
  - test/aoj/notest.GRL_4_B.cpp
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_C.test.cpp
  - test/aoj/GRL_3_C.test.cpp
  - test/aoj/GRL_1_A.test.cpp
  - test/aoj/ALDS_1_11_C.test.cpp
  - test/aoj/GRL_5_A.rerooting.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/GRL_1_C.test.cpp
  - test/aoj/ALDS_1_11_C.bfs.test.cpp
  - test/aoj/GRL_5_A.test.cpp
documentation_of: graph/template.hpp
layout: document
redirect_from:
- /library/graph/template.hpp
- /library/graph/template.hpp.html
title: graph/template.hpp
---
