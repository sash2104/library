---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.segtree.test.cpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u52A0\u7B97\u30FB\u533A\
      \u9593\u548C)"
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u52A0\u7B97\
      \u30FB\u4E00\u70B9\u53D6\u5F97)"
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
    links: []
  bundledCode: "#line 1 \"monoid/add.hpp\"\n\n\n\nnamespace monoid {\ntemplate <class\
    \ T>\nstruct add {\n  typedef T value_t;\n  T identity() const { return T(); }\n\
    \  T merge(T a, T b) const { return a+b; }\n};\n} // namespace monoid\n\n\n"
  code: "#ifndef __MONOID__ADD\n#define __MONOID__ADD\n\nnamespace monoid {\ntemplate\
    \ <class T>\nstruct add {\n  typedef T value_t;\n  T identity() const { return\
    \ T(); }\n  T merge(T a, T b) const { return a+b; }\n};\n} // namespace monoid\n\
    \n#endif // __MONOID__ADD"
  dependsOn: []
  isVerificationFile: false
  path: monoid/add.hpp
  requiredBy: []
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_B.segtree.test.cpp
  - test/aoj/DSL_2_E.test.cpp
documentation_of: monoid/add.hpp
layout: document
redirect_from:
- /library/monoid/add.hpp
- /library/monoid/add.hpp.html
title: monoid/add.hpp
---
