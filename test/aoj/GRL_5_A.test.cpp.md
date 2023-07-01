---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree-diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    document_title: "\u6728\u306E\u76F4\u5F84\u306E\u30C6\u30B9\u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "#line 1 \"test/aoj/GRL_5_A.test.cpp\"\n// @brief \u6728\u306E\u76F4\
    \u5F84\u306E\u30C6\u30B9\u30C8\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n\n#line 1 \"graph/tree-diameter.hpp\"\n\n\n// @title \u6728\u306E\u76F4\u5F84\
    \n\n#include <utility>\n#line 1 \"graph/template.hpp\"\n\n\n\n#include <iostream>\n\
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
    ,\";\n        }\n        std::cerr << std::endl;\n    }\n}\n\n\n#line 7 \"graph/tree-diameter.hpp\"\
    \n\nnamespace tree_diameter_\n{\ntemplate< typename T >\nstd::pair< T, int > dfs(const\
    \ Graph<T> &g, int idx, int par) {\n  std::pair< T, int > ret(0, idx);\n  for(auto\
    \ &e : g[idx]) {\n    if(e.to == par) continue;\n    auto cost = dfs(g, e.to,\
    \ idx);\n    cost.first += e.cost;\n    ret = max(ret, cost);\n  }\n  return ret;\n\
    }\n\n} // namespace tree_diameter\n\ntemplate< typename T >\nT tree_diameter(const\
    \ Graph<T> &g) {\n  auto p = tree_diameter_::dfs(g, 0, -1);\n  auto q = tree_diameter_::dfs(g,\
    \ p.second, -1);\n  return (q.first);\n}\n\n\n#line 5 \"test/aoj/GRL_5_A.test.cpp\"\
    \n\nusing namespace std;\n#line 8 \"test/aoj/GRL_5_A.test.cpp\"\n\nint main()\
    \ {\n  int N; cin >> N;\n  Graph< int > g(N);\n  for(int i = 1; i < N; i++) {\n\
    \    int x, y, z; cin >> x >> y >> z;\n    g[x].emplace_back(x, y, z);\n    g[y].emplace_back(y,\
    \ x, z);\n  }\n  cout << tree_diameter(g) << endl;\n}\n"
  code: "// @brief \u6728\u306E\u76F4\u5F84\u306E\u30C6\u30B9\u30C8\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\n\n#include\
    \ \"../../graph/tree-diameter.hpp\"\n\nusing namespace std;\n#include <iostream>\n\
    \nint main() {\n  int N; cin >> N;\n  Graph< int > g(N);\n  for(int i = 1; i <\
    \ N; i++) {\n    int x, y, z; cin >> x >> y >> z;\n    g[x].emplace_back(x, y,\
    \ z);\n    g[y].emplace_back(y, x, z);\n  }\n  cout << tree_diameter(g) << endl;\n\
    }"
  dependsOn:
  - graph/tree-diameter.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.test.cpp
- /verify/test/aoj/GRL_5_A.test.cpp.html
title: "\u6728\u306E\u76F4\u5F84\u306E\u30C6\u30B9\u30C8"
---
