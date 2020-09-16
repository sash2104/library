---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.segtree.test.cpp
    title: test/aoj/DSL_2_B.segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoid/add.hpp\"\n\nnamespace monoid {\ntemplate <class\
    \ T>\nstruct add {\n  typedef T value_t;\n  T identity() const { return T(); }\n\
    \  T merge(T a, T b) const { return a+b; }\n};\n} // namespace monoid\n"
  code: "#pragma once\n\nnamespace monoid {\ntemplate <class T>\nstruct add {\n  typedef\
    \ T value_t;\n  T identity() const { return T(); }\n  T merge(T a, T b) const\
    \ { return a+b; }\n};\n} // namespace monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/add.hpp
  requiredBy: []
  timestamp: '2020-01-01 14:13:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.segtree.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_E.test.cpp
documentation_of: monoid/add.hpp
layout: document
redirect_from:
- /library/monoid/add.hpp
- /library/monoid/add.hpp.html
title: monoid/add.hpp
---
