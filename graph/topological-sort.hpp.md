---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/aoj/notest.GRL_4_B.cpp
    title: test/aoj/notest.GRL_4_B.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
    links: []
  bundledCode: "#line 1 \"graph/topological-sort.hpp\"\n\n\n// @title \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 \n#include <vector>\n#include <stack>\n\
    #line 1 \"graph/template.hpp\"\n\n\n\n#include <iostream>\n#line 6 \"graph/template.hpp\"\
    \n\ntemplate< typename T >\nstruct Edge {\n  int from, to;\n  T cost;\n  Edge()\
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
    \ << std::endl;\n    }\n}\n\n\n#line 7 \"graph/topological-sort.hpp\"\n\ntemplate<\
    \ typename G >\nstd::vector<int> topologicalSort(const G &g) {\n  // \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3057\u305F\u7D50\u679C\u3092\u8FD4\
    \u3059\n  const int V = g.size();\n  std::vector<int> indegree(V); // 200000\u3068\
    \u304B\u3060\u3068\u9045\u3044\uFF1F \u53B3\u3057\u305D\u3046\u306A\u3089\u30B0\
    \u30ED\u30FC\u30D0\u30EB\u5909\u6570\u306B\u3059\u308B\n  // \u5165\u6B21\u6570\
    \u306E\u521D\u671F\u5316. \u307B\u3093\u3068\u306F\u8AAD\u307F\u8FBC\u307F\u6642\
    \u306B\u3084\u3063\u305F\u307B\u3046\u304C\u52B9\u7387\u304C\u826F\u3044\u3051\
    \u3069\u8A31\u5BB9\u3059\u308B\n  for (int v = 0; v < V; ++v) {\n    for (auto&\
    \ e: g[v]) ++indegree[e.to];\n  }\n\n  std::stack<int> st;\n  for (int v = 0;\
    \ v < V; ++v) {\n    // \u5165\u6B21\u65700\u306E\u70B9\u3092stack\u306B\u3044\
    \u308C\u308B\n    if (indegree[v] == 0) st.push(v);\n  }\n\n  std::vector<int>\
    \ order;\n  while (!st.empty()) {\n    int v = st.top(); st.pop();\n    order.push_back(v);\n\
    \    for (auto& e: g[v]) {\n      --indegree[e.to];\n      if (indegree[e.to]\
    \ == 0) st.push(e.to);\n    }\n  }\n\n  return order;\n}\n\n\n"
  code: "#ifndef __GRAPH__TOPOLOGICAL__SORT\n#define __GRAPH__TOPOLOGICAL__SORT\n\
    // @title \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 \n#include <vector>\n\
    #include <stack>\n#include \"template.hpp\"\n\ntemplate< typename G >\nstd::vector<int>\
    \ topologicalSort(const G &g) {\n  // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8\u3057\u305F\u7D50\u679C\u3092\u8FD4\u3059\n  const int V = g.size();\n\
    \  std::vector<int> indegree(V); // 200000\u3068\u304B\u3060\u3068\u9045\u3044\
    \uFF1F \u53B3\u3057\u305D\u3046\u306A\u3089\u30B0\u30ED\u30FC\u30D0\u30EB\u5909\
    \u6570\u306B\u3059\u308B\n  // \u5165\u6B21\u6570\u306E\u521D\u671F\u5316. \u307B\
    \u3093\u3068\u306F\u8AAD\u307F\u8FBC\u307F\u6642\u306B\u3084\u3063\u305F\u307B\
    \u3046\u304C\u52B9\u7387\u304C\u826F\u3044\u3051\u3069\u8A31\u5BB9\u3059\u308B\
    \n  for (int v = 0; v < V; ++v) {\n    for (auto& e: g[v]) ++indegree[e.to];\n\
    \  }\n\n  std::stack<int> st;\n  for (int v = 0; v < V; ++v) {\n    // \u5165\u6B21\
    \u65700\u306E\u70B9\u3092stack\u306B\u3044\u308C\u308B\n    if (indegree[v] ==\
    \ 0) st.push(v);\n  }\n\n  std::vector<int> order;\n  while (!st.empty()) {\n\
    \    int v = st.top(); st.pop();\n    order.push_back(v);\n    for (auto& e: g[v])\
    \ {\n      --indegree[e.to];\n      if (indegree[e.to] == 0) st.push(e.to);\n\
    \    }\n  }\n\n  return order;\n}\n\n#endif // __GRAPH__TOPOLOGICAL__SORT"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/topological-sort.hpp
  requiredBy:
  - test/aoj/notest.GRL_4_B.cpp
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological-sort.hpp
layout: document
redirect_from:
- /library/graph/topological-sort.hpp
- /library/graph/topological-sort.hpp.html
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---
