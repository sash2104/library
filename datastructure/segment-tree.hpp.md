---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\
      \u9593\u6700\u5C0F)"
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.segtree.test.cpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u52A0\u7B97\u30FB\u533A\
      \u9593\u548C)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\
      \u3001\u533A\u9593\u53D6\u5F97)"
    links: []
  bundledCode: "#line 1 \"datastructure/segment-tree.hpp\"\n\n\n/**\n * @title \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\u3001\u533A\u9593\u53D6\
    \u5F97)\n * \n */\n#include <cassert>\n#include <vector>\n\ntemplate <class Monoid>\n\
    struct SegmentTree {\n  typedef typename Monoid::value_t value_t;\n  const Monoid\
    \ monoid;\n  int n; // n_\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E2\u51AA\n  std::vector<value_t>\
    \ data;\n  SegmentTree(int n_): monoid() {\n    n = 1;\n    while (n < n_) n *=\
    \ 2;\n    data.assign(2*n-1, monoid.identity());\n  }\n\n  // k\u756A\u76EE\u306E\
    \u5024(0-indexed)\u3092a\u306B\u5909\u66F4\n  void update(int k, int a) { // 0-indexed\n\
    \    assert(0 <= k && k < n);\n    // \u8449\u306E\u7BC0\u70B9\n    data[k+n-1]\
    \ = a;\n    // \u767B\u308A\u306A\u304C\u3089\u66F4\u65B0\n    for (k = (k+n)/2;\
    \ k > 0; k /= 2) {  // 1-indexed\n      data[k-1] = monoid.merge(data[2*k-1],\
    \ data[2*k]);\n    }\n  }\n\n  value_t query(int l, int r) {  // 0-indexed, [l,\
    \ r)\n    assert(0 <= l && l <= r && r <= n);\n    value_t vl = monoid.identity(),\
    \ vr = monoid.identity();\n    for (l += n, r += n; l < r; l /= 2, r /= 2) { \
    \ // 1-indexed\n      if (l & 1) vl = monoid.merge(vl, data[(l++)-1]);\n     \
    \ if (r & 1) vr = monoid.merge(data[(--r)-1],vr);\n    }\n    return monoid.merge(vl,\
    \ vr);\n  }\n\n  value_t operator[](const int &k) {\n    return query(k, k + 1);\n\
    \  }\n};\n\n\n"
  code: "#ifndef _DATASTRUCTURE_SEGMENT_TREE\n#define _DATASTRUCTURE_SEGMENT_TREE\n\
    /**\n * @title \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\u3001\
    \u533A\u9593\u53D6\u5F97)\n * \n */\n#include <cassert>\n#include <vector>\n\n\
    template <class Monoid>\nstruct SegmentTree {\n  typedef typename Monoid::value_t\
    \ value_t;\n  const Monoid monoid;\n  int n; // n_\u4EE5\u4E0A\u306E\u6700\u5C0F\
    \u306E2\u51AA\n  std::vector<value_t> data;\n  SegmentTree(int n_): monoid() {\n\
    \    n = 1;\n    while (n < n_) n *= 2;\n    data.assign(2*n-1, monoid.identity());\n\
    \  }\n\n  // k\u756A\u76EE\u306E\u5024(0-indexed)\u3092a\u306B\u5909\u66F4\n \
    \ void update(int k, int a) { // 0-indexed\n    assert(0 <= k && k < n);\n   \
    \ // \u8449\u306E\u7BC0\u70B9\n    data[k+n-1] = a;\n    // \u767B\u308A\u306A\
    \u304C\u3089\u66F4\u65B0\n    for (k = (k+n)/2; k > 0; k /= 2) {  // 1-indexed\n\
    \      data[k-1] = monoid.merge(data[2*k-1], data[2*k]);\n    }\n  }\n\n  value_t\
    \ query(int l, int r) {  // 0-indexed, [l, r)\n    assert(0 <= l && l <= r &&\
    \ r <= n);\n    value_t vl = monoid.identity(), vr = monoid.identity();\n    for\
    \ (l += n, r += n; l < r; l /= 2, r /= 2) {  // 1-indexed\n      if (l & 1) vl\
    \ = monoid.merge(vl, data[(l++)-1]);\n      if (r & 1) vr = monoid.merge(data[(--r)-1],vr);\n\
    \    }\n    return monoid.merge(vl, vr);\n  }\n\n  value_t operator[](const int\
    \ &k) {\n    return query(k, k + 1);\n  }\n};\n\n#endif // _DATASTRUCTURE_SEGMENT_TREE"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segment-tree.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/DSL_2_B.segtree.test.cpp
documentation_of: datastructure/segment-tree.hpp
layout: document
redirect_from:
- /library/datastructure/segment-tree.hpp
- /library/datastructure/segment-tree.hpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\u3001\u533A\
  \u9593\u53D6\u5F97)"
---
