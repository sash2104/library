---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/union-find-tree.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: graph/mst-kruskal.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#line 1 \"graph/mst-kruskal.hpp\"\n/**\n * @title \u6700\u5C0F\u5168\u57DF\u6728\
    \ (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)\n */\n#include <algorithm>\n#line 1 \"\
    graph/template.hpp\"\n\n\n\n#include <iostream>\n#include <vector>\n\ntemplate<\
    \ typename T >\nstruct Edge {\n  int from, to;\n  T cost;\n  Edge() {}\n  Edge(int\
    \ f, int t) : from(f), to(t), cost(1) {}\n  Edge(int f, int t, T c) : from(f),\
    \ to(t), cost(c) {}\n  friend bool operator < (const Edge& lhs, const Edge& rhs)\
    \ { return lhs.cost < rhs.cost; };\n  friend bool operator > (const Edge& lhs,\
    \ const Edge& rhs) { return rhs < lhs; };\n  friend bool operator <= (const Edge&\
    \ lhs, const Edge& rhs) { return !(lhs > rhs); };\n  friend bool operator >= (const\
    \ Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };\n};\n\ntemplate< typename\
    \ T >\nusing Edges = std::vector< Edge< T > >;\ntemplate< typename T >\nusing\
    \ Graph = std::vector< Edges< T > >;\n\ntemplate< typename T >\nvoid debug(Graph<T>\
    \ &g, int n = -1) {\n    if (n == -1) n = g.size();\n    for (int i = 0; i < n;\
    \ ++i) {\n        std::cerr << i  << \"\\t\";\n        for (auto &e: g[i]) {\n\
    \            std::cerr << e.to << \",\";\n        }\n        std::cerr << std::endl;\n\
    \    }\n}\n\n\n#line 1 \"datastructure/union-find-tree.hpp\"\n/**\n * @title Union-Find\n\
    \ */\n#line 5 \"datastructure/union-find-tree.hpp\"\n\nclass UnionFind {\npublic:\n\
    \  std::vector<int> data; // size\u3068par\u3092\u540C\u6642\u306B\u7BA1\u7406\
    \u3059\u308B\n  UnionFind(int size) : data(size, -1) {}\n  int find(int x) { return\
    \ data[x] < 0 ? x : data[x] = find(data[x]); }\n  void unite(int x, int y) {\n\
    \    int px = find(x);\n    int py = find(y);\n    if (px != py) {\n      if (data[py]\
    \ < data[px]) std::swap(px, py);\n      data[px] += data[py]; data[py] = px;\n\
    \    }\n  }\n  bool same(int x, int y) { return find(x) == find(y); }\n  int size(int\
    \ x) { return -data[find(x)]; }\n};\n#line 7 \"graph/mst-kruskal.hpp\"\n\ntemplate<\
    \ typename T >\nT kruscal(int V, Edges< T > &edges) {\n  // \u6700\u5C0F\u5168\
    \u57DF\u6728\u306E\u91CD\u307F\u3092\u8FD4\u3059\n  UnionFind uf(V);\n  T weight\
    \ = 0;\n  std::sort(edges.begin(), edges.end());\n  for (auto e : edges) {\n \
    \   if (uf.same(e.from, e.to)) continue;\n    uf.unite(e.from, e.to);\n    weight\
    \ += e.cost;\n  }\n  return weight;\n}\n#line 3 \"test/aoj/GRL_2_A.test.cpp\"\n\
    \n#line 5 \"test/aoj/GRL_2_A.test.cpp\"\nusing namespace std;\n\nusing edge =\
    \ Edge<int>;\nint main() {\n  vector<edge> edges;\n  int V, E;\n  cin >> V >>\
    \ E;\n  for (int i = 0; i < E; ++i) {\n    int x, y, w;\n    cin >> x >> y >>\
    \ w;\n    edges.emplace_back(x, y, w);\n  }\n  int ans = kruscal(V, edges);\n\
    \  cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include \"../../graph/mst-kruskal.hpp\"\n\n#include <iostream>\nusing namespace\
    \ std;\n\nusing edge = Edge<int>;\nint main() {\n  vector<edge> edges;\n  int\
    \ V, E;\n  cin >> V >> E;\n  for (int i = 0; i < E; ++i) {\n    int x, y, w;\n\
    \    cin >> x >> y >> w;\n    edges.emplace_back(x, y, w);\n  }\n  int ans = kruscal(V,\
    \ edges);\n  cout << ans << endl;\n}\n"
  dependsOn:
  - graph/mst-kruskal.hpp
  - graph/template.hpp
  - datastructure/union-find-tree.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.test.cpp
- /verify/test/aoj/GRL_2_A.test.cpp.html
title: test/aoj/GRL_2_A.test.cpp
---
