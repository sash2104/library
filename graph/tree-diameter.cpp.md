---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.cpp
    title: graph/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: "\u6728\u306E\u76F4\u5F84\u306E\u30C6\u30B9\u30C8"
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6728\u306E\u76F4\u5F84"
    links: []
  bundledCode: "#line 1 \"graph/tree-diameter.cpp\"\n/**\n * @brief \u6728\u306E\u76F4\
    \u5F84\n */\n\n#include <utility>\n#line 1 \"graph/template.cpp\"\n#include <vector>\n\
    \ntemplate< typename T >\nstruct Edge {\n  int from, to;\n  T cost;\n  Edge()\
    \ {}\n  Edge(int f, int t) : from(f), to(t), cost(1) {}\n  Edge(int f, int t,\
    \ T c) : from(f), to(t), cost(c) {}\n  friend bool operator < (const Edge& lhs,\
    \ const Edge& rhs) { return lhs.cost < rhs.cost; };\n  friend bool operator >\
    \ (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };\n  friend bool operator\
    \ <= (const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); };\n  friend bool\
    \ operator >= (const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };\n};\n\
    \ntemplate< typename T >\nusing Edges = std::vector< Edge< T > >;\ntemplate< typename\
    \ T >\nusing Graph = std::vector< Edges< T > >;\n#line 7 \"graph/tree-diameter.cpp\"\
    \n\nnamespace tree_diameter_\n{\ntemplate< typename T >\nstd::pair< T, int > dfs(const\
    \ Graph<T> &g, int idx, int par) {\n  std::pair< T, int > ret(0, idx);\n  for(auto\
    \ &e : g[idx]) {\n    if(e.to == par) continue;\n    auto cost = dfs(g, e.to,\
    \ idx);\n    cost.first += e.cost;\n    ret = max(ret, cost);\n  }\n  return ret;\n\
    }\n\n} // namespace tree_diameter\n\ntemplate< typename T >\nT tree_diameter(const\
    \ Graph<T> &g) {\n  auto p = tree_diameter_::dfs(g, 0, -1);\n  auto q = tree_diameter_::dfs(g,\
    \ p.second, -1);\n  return (q.first);\n}\n"
  code: "/**\n * @brief \u6728\u306E\u76F4\u5F84\n */\n\n#include <utility>\n#include\
    \ \"template.cpp\"\n\nnamespace tree_diameter_\n{\ntemplate< typename T >\nstd::pair<\
    \ T, int > dfs(const Graph<T> &g, int idx, int par) {\n  std::pair< T, int > ret(0,\
    \ idx);\n  for(auto &e : g[idx]) {\n    if(e.to == par) continue;\n    auto cost\
    \ = dfs(g, e.to, idx);\n    cost.first += e.cost;\n    ret = max(ret, cost);\n\
    \  }\n  return ret;\n}\n\n} // namespace tree_diameter\n\ntemplate< typename T\
    \ >\nT tree_diameter(const Graph<T> &g) {\n  auto p = tree_diameter_::dfs(g, 0,\
    \ -1);\n  auto q = tree_diameter_::dfs(g, p.second, -1);\n  return (q.first);\n\
    }"
  dependsOn:
  - graph/template.cpp
  isVerificationFile: false
  path: graph/tree-diameter.cpp
  requiredBy: []
  timestamp: '2020-11-29 07:11:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_A.test.cpp
documentation_of: graph/tree-diameter.cpp
layout: document
redirect_from:
- /library/graph/tree-diameter.cpp
- /library/graph/tree-diameter.cpp.html
title: "\u6728\u306E\u76F4\u5F84"
---
