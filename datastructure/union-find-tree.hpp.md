---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/mst-kruskal.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6728 (\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union-Find
    links: []
  bundledCode: "#line 1 \"datastructure/union-find-tree.hpp\"\n/**\n * @title Union-Find\n\
    \ */\n#include <vector>\n\nclass UnionFind {\npublic:\n  std::vector<int> data;\
    \ // size\u3068par\u3092\u540C\u6642\u306B\u7BA1\u7406\u3059\u308B\n  UnionFind(int\
    \ size) : data(size, -1) {}\n  int find(int x) { return data[x] < 0 ? x : data[x]\
    \ = find(data[x]); }\n  void unite(int x, int y) {\n    int px = find(x);\n  \
    \  int py = find(y);\n    if (px != py) {\n      if (data[py] < data[px]) std::swap(px,\
    \ py);\n      data[px] += data[py]; data[py] = px;\n    }\n  }\n  bool same(int\
    \ x, int y) { return find(x) == find(y); }\n  int size(int x) { return -data[find(x)];\
    \ }\n};\n"
  code: "/**\n * @title Union-Find\n */\n#include <vector>\n\nclass UnionFind {\n\
    public:\n  std::vector<int> data; // size\u3068par\u3092\u540C\u6642\u306B\u7BA1\
    \u7406\u3059\u308B\n  UnionFind(int size) : data(size, -1) {}\n  int find(int\
    \ x) { return data[x] < 0 ? x : data[x] = find(data[x]); }\n  void unite(int x,\
    \ int y) {\n    int px = find(x);\n    int py = find(y);\n    if (px != py) {\n\
    \      if (data[py] < data[px]) std::swap(px, py);\n      data[px] += data[py];\
    \ data[py] = px;\n    }\n  }\n  bool same(int x, int y) { return find(x) == find(y);\
    \ }\n  int size(int x) { return -data[find(x)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/union-find-tree.hpp
  requiredBy:
  - graph/mst-kruskal.hpp
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_A.test.cpp
  - test/aoj/GRL_2_A.test.cpp
documentation_of: datastructure/union-find-tree.hpp
layout: document
redirect_from:
- /library/datastructure/union-find-tree.hpp
- /library/datastructure/union-find-tree.hpp.html
title: Union-Find
---
