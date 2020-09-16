---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"monoid/add_count.hpp\"\n#include <algorithm>\n#include <utility>\n\
    #include <limits>\n\nnamespace monoid {\ntemplate <class T>\nstruct add_count\
    \ {\n  typedef std::pair<T,T> value_t;\n  value_t identity() const { return std::make_pair(T(),T());\
    \ }\n  value_t merge(value_t a, value_t b) const { return std::make_pair(a.first+b.first,\
    \ a.second+b.second); }\n};\n} // namespace monoid\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <limits>\n\
    \nnamespace monoid {\ntemplate <class T>\nstruct add_count {\n  typedef std::pair<T,T>\
    \ value_t;\n  value_t identity() const { return std::make_pair(T(),T()); }\n \
    \ value_t merge(value_t a, value_t b) const { return std::make_pair(a.first+b.first,\
    \ a.second+b.second); }\n};\n} // namespace monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/add_count.hpp
  requiredBy: []
  timestamp: '2020-01-01 01:17:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_G.test.cpp
documentation_of: monoid/add_count.hpp
layout: document
redirect_from:
- /library/monoid/add_count.hpp
- /library/monoid/add_count.hpp.html
title: monoid/add_count.hpp
---
