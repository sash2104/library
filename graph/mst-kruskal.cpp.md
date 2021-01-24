---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/union-find-tree.cpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: graph/template.cpp
    title: graph/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5C0F\u5168\u57DF\u6728 (\u30AF\u30E9\u30B9\u30AB\u30EB\
      \u6CD5)"
    links: []
  bundledCode: "#line 1 \"graph/mst-kruskal.cpp\"\n/**\n * @title \u6700\u5C0F\u5168\
    \u57DF\u6728 (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)\n */\n#include <algorithm>\n\
    #line 1 \"graph/template.cpp\"\n#include <vector>\n\ntemplate< typename T >\n\
    struct Edge {\n  int from, to;\n  T cost;\n  Edge() {}\n  Edge(int f, int t) :\
    \ from(f), to(t), cost(1) {}\n  Edge(int f, int t, T c) : from(f), to(t), cost(c)\
    \ {}\n  friend bool operator < (const Edge& lhs, const Edge& rhs) { return lhs.cost\
    \ < rhs.cost; };\n  friend bool operator > (const Edge& lhs, const Edge& rhs)\
    \ { return rhs < lhs; };\n  friend bool operator <= (const Edge& lhs, const Edge&\
    \ rhs) { return !(lhs > rhs); };\n  friend bool operator >= (const Edge& lhs,\
    \ const Edge& rhs) { return !(lhs < rhs); };\n};\n\ntemplate< typename T >\nusing\
    \ Edges = std::vector< Edge< T > >;\ntemplate< typename T >\nusing Graph = std::vector<\
    \ Edges< T > >;\n#line 1 \"datastructure/union-find-tree.cpp\"\n/**\n * @title\
    \ Union-Find\n */\n#line 5 \"datastructure/union-find-tree.cpp\"\n\nclass UnionFind\
    \ {\npublic:\n  std::vector<int> data; // size\u3068par\u3092\u540C\u6642\u306B\
    \u7BA1\u7406\u3059\u308B\n  UnionFind(int size) : data(size, -1) {}\n  int find(int\
    \ x) { return data[x] < 0 ? x : data[x] = find(data[x]); }\n  void unite(int x,\
    \ int y) {\n    int px = find(x);\n    int py = find(y);\n    if (px != py) {\n\
    \      if (data[py] < data[px]) std::swap(px, py);\n      data[px] += data[py];\
    \ data[py] = px;\n    }\n  }\n  bool same(int x, int y) { return find(x) == find(y);\
    \ }\n  int size(int x) { return -data[find(x)]; }\n};\n#line 7 \"graph/mst-kruskal.cpp\"\
    \n\ntemplate< typename T >\nT kruscal(int V, Edges< T > &edges) {\n  // \u6700\
    \u5C0F\u5168\u57DF\u6728\u306E\u91CD\u307F\u3092\u8FD4\u3059\n  UnionFind uf(V);\n\
    \  T weight = 0;\n  std::sort(edges.begin(), edges.end());\n  for (auto e : edges)\
    \ {\n    if (uf.same(e.from, e.to)) continue;\n    uf.unite(e.from, e.to);\n \
    \   weight += e.cost;\n  }\n  return weight;\n}\n"
  code: "/**\n * @title \u6700\u5C0F\u5168\u57DF\u6728 (\u30AF\u30E9\u30B9\u30AB\u30EB\
    \u6CD5)\n */\n#include <algorithm>\n#include \"template.cpp\"\n#include \"../datastructure/union-find-tree.cpp\"\
    \n\ntemplate< typename T >\nT kruscal(int V, Edges< T > &edges) {\n  // \u6700\
    \u5C0F\u5168\u57DF\u6728\u306E\u91CD\u307F\u3092\u8FD4\u3059\n  UnionFind uf(V);\n\
    \  T weight = 0;\n  std::sort(edges.begin(), edges.end());\n  for (auto e : edges)\
    \ {\n    if (uf.same(e.from, e.to)) continue;\n    uf.unite(e.from, e.to);\n \
    \   weight += e.cost;\n  }\n  return weight;\n}\n"
  dependsOn:
  - graph/template.cpp
  - datastructure/union-find-tree.cpp
  isVerificationFile: false
  path: graph/mst-kruskal.cpp
  requiredBy: []
  timestamp: '2020-08-30 21:41:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
documentation_of: graph/mst-kruskal.cpp
layout: document
redirect_from:
- /library/graph/mst-kruskal.cpp
- /library/graph/mst-kruskal.cpp.html
title: "\u6700\u5C0F\u5168\u57DF\u6728 (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
---
