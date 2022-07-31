---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.bit.test.cpp
    title: "BIT\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: BIT (Binary-Indexed-Tree)
    links:
    - http://hos.ac/slides/20140319_bit.pdf
  bundledCode: "#line 1 \"datastructure/binary-indexed-tree.hpp\"\n/**\n * @title\
    \ BIT (Binary-Indexed-Tree)\n * @see http://hos.ac/slides/20140319_bit.pdf\n */\n\
    #include <cassert>\n#include <vector>\n\ntemplate <class T>\nstruct BinaryIndexedTree\
    \ {\n  int n;\n  std::vector<T> bit;\n  BinaryIndexedTree(int n): n(n), bit(n+1)\
    \ {}\n\n  void build(const std::vector<T> &v) {\n    for (int x = 1; x <= n; ++x)\
    \ bit[x] = v[x-1];\n    for (int x = 1; x < n; ++x) bit[x + (x & -x)] += bit[x];\n\
    \  }\n\n  void add(int a, T w) { // 0-indexed\n    assert(0 <= a && a < n);\n\
    \    for (int x = a+1; x <= n; x += x & -x) bit[x] += w; // 1-indexed\n  }\n\n\
    \  T sum(int a) { // [0, a)\n    assert(0 <= a && a <= n);\n    T ret = 0;\n \
    \   for (int x = a; x > 0; x -= x & -x) ret += bit[x]; // 1-indexed\n    return\
    \ ret;\n  }\n\n  T sum(int l, int r) { return sum(r)-sum(l); } // 0-indexed, [l,\
    \ r)\n};\n"
  code: "/**\n * @title BIT (Binary-Indexed-Tree)\n * @see http://hos.ac/slides/20140319_bit.pdf\n\
    \ */\n#include <cassert>\n#include <vector>\n\ntemplate <class T>\nstruct BinaryIndexedTree\
    \ {\n  int n;\n  std::vector<T> bit;\n  BinaryIndexedTree(int n): n(n), bit(n+1)\
    \ {}\n\n  void build(const std::vector<T> &v) {\n    for (int x = 1; x <= n; ++x)\
    \ bit[x] = v[x-1];\n    for (int x = 1; x < n; ++x) bit[x + (x & -x)] += bit[x];\n\
    \  }\n\n  void add(int a, T w) { // 0-indexed\n    assert(0 <= a && a < n);\n\
    \    for (int x = a+1; x <= n; x += x & -x) bit[x] += w; // 1-indexed\n  }\n\n\
    \  T sum(int a) { // [0, a)\n    assert(0 <= a && a <= n);\n    T ret = 0;\n \
    \   for (int x = a; x > 0; x -= x & -x) ret += bit[x]; // 1-indexed\n    return\
    \ ret;\n  }\n\n  T sum(int l, int r) { return sum(r)-sum(l); } // 0-indexed, [l,\
    \ r)\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/binary-indexed-tree.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.bit.test.cpp
documentation_of: datastructure/binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/datastructure/binary-indexed-tree.hpp
- /library/datastructure/binary-indexed-tree.hpp.html
title: BIT (Binary-Indexed-Tree)
---
