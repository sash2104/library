---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.rerooting.test.cpp
    title: "\u6728\u306E\u76F4\u5F84 (ReRooting)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"monoid/max.hpp\"\n\n\n#include <algorithm>\n#include <limits>\n\
    \nnamespace monoid {\ntemplate <class T>\nstruct max {\n  typedef T value_t;\n\
    \  T identity() const { return std::numeric_limits<T>::min();}\n  T merge(T a,\
    \ T b) const { return std::max(a, b); }\n};\n} // namespace monoid\n\n\n"
  code: "#ifndef _MONOID_MAX\n#define _MONOID_MAX\n#include <algorithm>\n#include\
    \ <limits>\n\nnamespace monoid {\ntemplate <class T>\nstruct max {\n  typedef\
    \ T value_t;\n  T identity() const { return std::numeric_limits<T>::min();}\n\
    \  T merge(T a, T b) const { return std::max(a, b); }\n};\n} // namespace monoid\n\
    \n#endif // _MONOID_MAX"
  dependsOn: []
  isVerificationFile: false
  path: monoid/max.hpp
  requiredBy: []
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_A.rerooting.test.cpp
documentation_of: monoid/max.hpp
layout: document
redirect_from:
- /library/monoid/max.hpp
- /library/monoid/max.hpp.html
title: monoid/max.hpp
---
