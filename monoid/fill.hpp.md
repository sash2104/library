---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u5909\u66F4\
      \u30FB\u4E00\u70B9\u53D6\u5F97)"
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\u65B0\
      \u30FB\u533A\u9593\u6700\u5C0F)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"monoid/fill.hpp\"\n\n\n#include <utility>\n\nnamespace monoid\
    \ {\ntemplate <class T>\nstruct fill {\n  typedef std::pair<bool, T> value_t;\n\
    \  value_t identity() const { return std::make_pair(false, T()); }\n  value_t\
    \ merge(value_t a, value_t b) const { return b.first ? b : a; }\n};\n} // namespace\
    \ monoid\n\n\n"
  code: "#ifndef _MONOID_FILL\n#define _MONOID_FILL\n#include <utility>\n\nnamespace\
    \ monoid {\ntemplate <class T>\nstruct fill {\n  typedef std::pair<bool, T> value_t;\n\
    \  value_t identity() const { return std::make_pair(false, T()); }\n  value_t\
    \ merge(value_t a, value_t b) const { return b.first ? b : a; }\n};\n} // namespace\
    \ monoid\n\n#endif // _MONOID_FILL"
  dependsOn: []
  isVerificationFile: false
  path: monoid/fill.hpp
  requiredBy: []
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_D.test.cpp
documentation_of: monoid/fill.hpp
layout: document
redirect_from:
- /library/monoid/fill.hpp
- /library/monoid/fill.hpp.html
title: monoid/fill.hpp
---
