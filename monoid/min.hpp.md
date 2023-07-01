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
    path: test/aoj/DSL_2_F.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\u65B0\
      \u30FB\u533A\u9593\u6700\u5C0F)"
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u52A0\u7B97\
      \u30FB\u533A\u9593\u6700\u5C0F)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"monoid/min.hpp\"\n\n\n#include <algorithm>\n#include <limits>\n\
    \nnamespace monoid {\ntemplate <class T>\nstruct min {\n  typedef T value_t;\n\
    \  T identity() const { return std::numeric_limits<T>::max();}\n  T merge(T a,\
    \ T b) const { return std::min(a, b); }\n};\n} // namespace monoid\n\n\n"
  code: "#ifndef _MONOID_MIN\n#define _MONOID_MIN\n#include <algorithm>\n#include\
    \ <limits>\n\nnamespace monoid {\ntemplate <class T>\nstruct min {\n  typedef\
    \ T value_t;\n  T identity() const { return std::numeric_limits<T>::max();}\n\
    \  T merge(T a, T b) const { return std::min(a, b); }\n};\n} // namespace monoid\n\
    \n#endif // _MONOID_MIN"
  dependsOn: []
  isVerificationFile: false
  path: monoid/min.hpp
  requiredBy: []
  timestamp: '2021-04-15 20:33:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_H.test.cpp
documentation_of: monoid/min.hpp
layout: document
redirect_from:
- /library/monoid/min.hpp
- /library/monoid/min.hpp.html
title: monoid/min.hpp
---
