---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoid/max.hpp\"\n#include <algorithm>\n#include <limits>\n\
    \nnamespace monoid {\ntemplate <class T>\nstruct max {\n  typedef T value_t;\n\
    \  T identity() const { return std::numeric_limits<T>::min();}\n  T merge(T a,\
    \ T b) const { return std::max(a, b); }\n};\n} // namespace monoid\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n\nnamespace monoid\
    \ {\ntemplate <class T>\nstruct max {\n  typedef T value_t;\n  T identity() const\
    \ { return std::numeric_limits<T>::min();}\n  T merge(T a, T b) const { return\
    \ std::max(a, b); }\n};\n} // namespace monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: monoid/max.hpp
  requiredBy: []
  timestamp: '2020-03-08 10:49:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoid/max.hpp
layout: document
redirect_from:
- /library/monoid/max.hpp
- /library/monoid/max.hpp.html
title: monoid/max.hpp
---
