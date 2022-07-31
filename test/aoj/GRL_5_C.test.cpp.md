---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: "LCA (\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#line 1 \"graph/lca.hpp\"\n\n\n// @title LCA (\u6700\u5C0F\u5171\u901A\u7956\
    \u5148)\n#line 1 \"graph/template.hpp\"\n\n\n\n#include <iostream>\n#include <vector>\n\
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
    \ << std::endl;\n    }\n}\n\n\n#line 5 \"graph/lca.hpp\"\n\n#include <cassert>\n\
    #include <cmath>\n#line 9 \"graph/lca.hpp\"\n\nusing namespace std;\n\ntemplate<\
    \ typename T >\nstruct LCA {\n  using graph = Graph<T>;\n  int root;\n  // n :\
    \ \u9802\u70B9\u6570\n  const int n;\n  const int log2_n;\n  graph g;\n  vector<vector<int>>\
    \ parent;\n  vector<int> depth;\n\n  LCA(int root, const graph &g) : root(root),\
    \ n(g.size()), log2_n(log2(n)+1), g(g), parent(log2_n, vector<int>(n)), depth(n)\
    \ {\n    dfs(g, root, root, 1);\n    for (int k = 0; k+1 < log2_n; ++k) {\n  \
    \    parent.push_back(vector<int>(n, root)); // \u8981\u7D20\u6570n, \u5024root\u3067\
    \u521D\u671F\u5316\n      for (int v = n-1; v >= 0; --v) {\n        int par =\
    \ parent[k][v];\n        parent[k+1][v] = parent[k][par];\n      }\n    }\n  }\n\
    \  \n  /** \n   * par : \u89AA\u306Eid\n   * d : \u6728\u306E\u6DF1\u3055 (1\u304B\
    \u3089\u59CB\u3081\u308B)\n   */ \n  void dfs(const graph& g, int from, int par,\
    \ int d) {\n    parent[0][from] = par;\n    depth[from] = d;\n    for (auto &e:\
    \ g[from]) {\n      if (depth[e.to] > 0) continue;\n      dfs(g, e.to, from, d+1);\n\
    \    }\n  }\n\n  int get(int v1, int v2) {\n    // \u6DF1\u3055\u304C\u540C\u3058\
    \u306B\u306A\u308B\u307E\u3067\u7247\u65B9\u3092\u767B\u3089\u305B\u308B\n   \
    \ if (depth[v1] < depth[v2]) swap(v1, v2);\n    for (int k = 0; k < log2_n; ++k)\
    \ {\n      if ((depth[v1]-depth[v2]) >> k & 1) {\n        v1 = parent[k][v1];\n\
    \      }\n    }\n    if (v1 == v2) return v1;\n\n    // \u89AA\u304C\u540C\u3058\
    \u306B\u306A\u308B\u76F4\u524D\u307E\u3067\u767B\u3089\u305B\u308B\n    for (int\
    \ k = log2_n-1; k >= 0; --k) {\n      int p_v1 = parent[k][v1];\n      int p_v2\
    \ = parent[k][v2];\n      if (p_v1 == p_v2) continue;\n      v1 = p_v1;\n    \
    \  v2 = p_v2;\n    }\n    assert(parent[0][v1] == parent[0][v2]);\n    return\
    \ parent[0][v1];\n  }\n};\n\n\n#line 5 \"test/aoj/GRL_5_C.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n  int n; cin >> n;\n  Graph<int> graph(n);\n  for (int\
    \ i = 0; i < n; ++i) {\n    int k; cin >> k;\n    for (int j = 0; j < k; ++j)\
    \ {\n      int c; cin >> c;\n      graph[i].emplace_back(i, c);\n    }\n  }\n\
    \  LCA<int> lca(0, graph);\n  int q;\n  cin >> q;\n  for (int i = 0; i < q; ++i)\
    \ { \n    int u, v;\n    cin >> u >> v;\n    cout << lca.get(u, v) << endl;\n\
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include \"../../graph/lca.hpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n  int n; cin >> n;\n  Graph<int> graph(n);\n  for (int i = 0;\
    \ i < n; ++i) {\n    int k; cin >> k;\n    for (int j = 0; j < k; ++j) {\n   \
    \   int c; cin >> c;\n      graph[i].emplace_back(i, c);\n    }\n  }\n  LCA<int>\
    \ lca(0, graph);\n  int q;\n  cin >> q;\n  for (int i = 0; i < q; ++i) { \n  \
    \  int u, v;\n    cin >> u >> v;\n    cout << lca.get(u, v) << endl;\n  }\n}\n"
  dependsOn:
  - graph/lca.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---
