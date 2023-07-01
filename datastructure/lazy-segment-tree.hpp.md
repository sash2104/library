---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructure/dual-segment-tree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\u65B0\
      \u3001\u4E00\u70B9\u53D6\u5F97)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u5909\u66F4\
      \u30FB\u4E00\u70B9\u53D6\u5F97)"
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u52A0\u7B97\
      \u30FB\u4E00\u70B9\u53D6\u5F97)"
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\u65B0\
      \u30FB\u533A\u9593\u6700\u5C0F)"
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u52A0\u7B97\
      \u30FB\u533A\u9593\u548C)"
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u52A0\u7B97\
      \u30FB\u533A\u9593\u6700\u5C0F)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\
      \u66F4\u65B0\u3001\u533A\u9593\u53D6\u5F97)"
    links: []
  bundledCode: "#line 1 \"datastructure/lazy-segment-tree.hpp\"\n\n\n/**\n * @title\
    \ \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\u65B0\u3001\
    \u533A\u9593\u53D6\u5F97)\n */ \n#include <cassert>\n#include <functional>\n#include\
    \ <vector>\n\n// FIXME: coding style\u3092\u7D71\u4E00\u3059\u308B\n// FIXME:\
    \ \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\u308B\u95A2\u6570\
    \u3067\u3042\u308BG\u3092class\u5316\u3059\u308B\ntemplate <class Monoid, class\
    \ OperatorMonoid>\nstruct LazySegmentTree {\n  typedef typename Monoid::value_t\
    \ value_t;\n  typedef typename OperatorMonoid::value_t operator_t;\n  const Monoid\
    \ monoid;\n  const OperatorMonoid op_monoid;\n  using G = std::function< value_t(value_t,\
    \ operator_t) >;\n  const G g;\n  int n; // n_\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    2\u51AA\n  int height; // \u6728\u306E\u6DF1\u3055. n == pow(2, height)\n  std::vector<value_t>\
    \ data;\n  std::vector<operator_t> lazy;\n  LazySegmentTree(const G g): monoid(),\
    \ op_monoid(), g(g) {}\n\n  void init(int n_) {\n    n = 1;\n    height = 0;\n\
    \    while (n < n_) { n *= 2; ++height; }\n    data.assign(2*n, monoid.identity());\n\
    \    lazy.assign(2*n, op_monoid.identity());\n  }\n\n  void set(int k, value_t\
    \ x) {\n    data[k + n] = x;\n  }\n\n  void build(const std::vector<value_t> &v)\
    \ {\n    int n_=v.size();\n    init(n_);\n    for(int i=0;i<n_;i++) data[n+i]=v[i];\n\
    \    for(int i=n-1;i;i--)\n      data[i] = monoid.merge(data[(i<<1)|0], data[(i<<1)|1]);\n\
    \  }\n\n  inline void propagate(int k) {\n    if(lazy[k] != op_monoid.identity())\
    \ {\n      lazy[2 * k + 0] = op_monoid.merge(lazy[2 * k + 0], lazy[k]);\n    \
    \  lazy[2 * k + 1] = op_monoid.merge(lazy[2 * k + 1], lazy[k]);\n      data[k]\
    \ = reflect(k);\n      lazy[k] = op_monoid.identity();\n    }\n  }\n\n  inline\
    \ value_t reflect(int k) {\n    return lazy[k] == op_monoid.identity() ? data[k]\
    \ : g(data[k], lazy[k]);\n  }\n\n  inline void recalc(int k) {\n    while(k >>=\
    \ 1) data[k] = monoid.merge(reflect(2 * k + 0), reflect(2 * k + 1));\n  }\n\n\
    \  inline void thrust(int k) {\n    for(int i = height; i > 0; i--) propagate(k\
    \ >> i);\n  }\n\n  void update(int a, int b, operator_t x) { // 0-indexed, [a,\
    \ b)\n    assert(0 <= a && a <= b && b <= n);\n    thrust(a += n);\n    thrust(b\
    \ += n - 1);\n    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n     \
    \ if(l & 1) lazy[l] = op_monoid.merge(lazy[l], x), ++l;\n      if(r & 1) --r,\
    \ lazy[r] = op_monoid.merge(lazy[r], x);\n    }\n    recalc(a);\n    recalc(b);\n\
    \  }\n\n  value_t query(int a, int b) { // 0-indexed, [a, b)\n    assert(0 <=\
    \ a && a <= b && b <= n);\n    thrust(a += n);\n    thrust(b += n - 1);\n    value_t\
    \ vl = monoid.identity(), vr = monoid.identity();\n    for(int l = a, r = b +\
    \ 1; l < r; l >>= 1, r >>= 1) {\n      if(l & 1) vl = monoid.merge(vl, reflect(l++));\n\
    \      if(r & 1) vr = monoid.merge(reflect(--r), vr);\n    }\n    return monoid.merge(vl,\
    \ vr);\n  }\n\n  value_t operator[](const int &k) {\n    return query(k, k + 1);\n\
    \  }\n};\n\n\n"
  code: "#ifndef _DATASTRUCTURE_LAZY_SEGMENT_TREE\n#define _DATASTRUCTURE_LAZY_SEGMENT_TREE\n\
    /**\n * @title \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\
    \u65B0\u3001\u533A\u9593\u53D6\u5F97)\n */ \n#include <cassert>\n#include <functional>\n\
    #include <vector>\n\n// FIXME: coding style\u3092\u7D71\u4E00\u3059\u308B\n//\
    \ FIXME: \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\u9069\u7528\u3059\u308B\u95A2\
    \u6570\u3067\u3042\u308BG\u3092class\u5316\u3059\u308B\ntemplate <class Monoid,\
    \ class OperatorMonoid>\nstruct LazySegmentTree {\n  typedef typename Monoid::value_t\
    \ value_t;\n  typedef typename OperatorMonoid::value_t operator_t;\n  const Monoid\
    \ monoid;\n  const OperatorMonoid op_monoid;\n  using G = std::function< value_t(value_t,\
    \ operator_t) >;\n  const G g;\n  int n; // n_\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\
    2\u51AA\n  int height; // \u6728\u306E\u6DF1\u3055. n == pow(2, height)\n  std::vector<value_t>\
    \ data;\n  std::vector<operator_t> lazy;\n  LazySegmentTree(const G g): monoid(),\
    \ op_monoid(), g(g) {}\n\n  void init(int n_) {\n    n = 1;\n    height = 0;\n\
    \    while (n < n_) { n *= 2; ++height; }\n    data.assign(2*n, monoid.identity());\n\
    \    lazy.assign(2*n, op_monoid.identity());\n  }\n\n  void set(int k, value_t\
    \ x) {\n    data[k + n] = x;\n  }\n\n  void build(const std::vector<value_t> &v)\
    \ {\n    int n_=v.size();\n    init(n_);\n    for(int i=0;i<n_;i++) data[n+i]=v[i];\n\
    \    for(int i=n-1;i;i--)\n      data[i] = monoid.merge(data[(i<<1)|0], data[(i<<1)|1]);\n\
    \  }\n\n  inline void propagate(int k) {\n    if(lazy[k] != op_monoid.identity())\
    \ {\n      lazy[2 * k + 0] = op_monoid.merge(lazy[2 * k + 0], lazy[k]);\n    \
    \  lazy[2 * k + 1] = op_monoid.merge(lazy[2 * k + 1], lazy[k]);\n      data[k]\
    \ = reflect(k);\n      lazy[k] = op_monoid.identity();\n    }\n  }\n\n  inline\
    \ value_t reflect(int k) {\n    return lazy[k] == op_monoid.identity() ? data[k]\
    \ : g(data[k], lazy[k]);\n  }\n\n  inline void recalc(int k) {\n    while(k >>=\
    \ 1) data[k] = monoid.merge(reflect(2 * k + 0), reflect(2 * k + 1));\n  }\n\n\
    \  inline void thrust(int k) {\n    for(int i = height; i > 0; i--) propagate(k\
    \ >> i);\n  }\n\n  void update(int a, int b, operator_t x) { // 0-indexed, [a,\
    \ b)\n    assert(0 <= a && a <= b && b <= n);\n    thrust(a += n);\n    thrust(b\
    \ += n - 1);\n    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n     \
    \ if(l & 1) lazy[l] = op_monoid.merge(lazy[l], x), ++l;\n      if(r & 1) --r,\
    \ lazy[r] = op_monoid.merge(lazy[r], x);\n    }\n    recalc(a);\n    recalc(b);\n\
    \  }\n\n  value_t query(int a, int b) { // 0-indexed, [a, b)\n    assert(0 <=\
    \ a && a <= b && b <= n);\n    thrust(a += n);\n    thrust(b += n - 1);\n    value_t\
    \ vl = monoid.identity(), vr = monoid.identity();\n    for(int l = a, r = b +\
    \ 1; l < r; l >>= 1, r >>= 1) {\n      if(l & 1) vl = monoid.merge(vl, reflect(l++));\n\
    \      if(r & 1) vr = monoid.merge(reflect(--r), vr);\n    }\n    return monoid.merge(vl,\
    \ vr);\n  }\n\n  value_t operator[](const int &k) {\n    return query(k, k + 1);\n\
    \  }\n};\n\n#endif // _DATASTRUCTURE_LAZY_SEGMENT_TREE"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/lazy-segment-tree.hpp
  requiredBy:
  - datastructure/dual-segment-tree.hpp
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_E.test.cpp
documentation_of: datastructure/lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/datastructure/lazy-segment-tree.hpp
- /library/datastructure/lazy-segment-tree.hpp.html
title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\u65B0\
  \u3001\u533A\u9593\u53D6\u5F97)"
---
