---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoid/fill.hpp\"\n#include <utility>\n\nnamespace monoid\
    \ {\ntemplate <class T>\nstruct fill {\n  typedef std::pair<bool, T> value_t;\n\
    \  value_t identity() const { return std::make_pair(false, T()); }\n  value_t\
    \ merge(value_t a, value_t b) const { return b.first ? b : a; }\n};\n} // namespace\
    \ monoid\n"
  code: "#pragma once\n#include <utility>\n\nnamespace monoid {\ntemplate <class T>\n\
    struct fill {\n  typedef std::pair<bool, T> value_t;\n  value_t identity() const\
    \ { return std::make_pair(false, T()); }\n  value_t merge(value_t a, value_t b)\
    \ const { return b.first ? b : a; }\n};\n} // namespace monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/fill.hpp
  requiredBy: []
  timestamp: '2020-01-01 01:17:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: monoid/fill.hpp
layout: document
redirect_from:
- /library/monoid/fill.hpp
- /library/monoid/fill.hpp.html
title: monoid/fill.hpp
---
