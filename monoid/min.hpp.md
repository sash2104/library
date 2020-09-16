---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoid/min.hpp\"\n#include <algorithm>\n#include <limits>\n\
    \nnamespace monoid {\ntemplate <class T>\nstruct min {\n  typedef T value_t;\n\
    \  T identity() const { return std::numeric_limits<T>::max();}\n  T merge(T a,\
    \ T b) const { return std::min(a, b); }\n};\n} // namespace monoid\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n\nnamespace monoid\
    \ {\ntemplate <class T>\nstruct min {\n  typedef T value_t;\n  T identity() const\
    \ { return std::numeric_limits<T>::max();}\n  T merge(T a, T b) const { return\
    \ std::min(a, b); }\n};\n} // namespace monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/min.hpp
  requiredBy: []
  timestamp: '2020-01-01 01:17:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: monoid/min.hpp
layout: document
redirect_from:
- /library/monoid/min.hpp
- /library/monoid/min.hpp.html
title: monoid/min.hpp
---
