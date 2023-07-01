---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u52A0\u7B97\
      \u30FB\u533A\u9593\u548C)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"monoid/add_count.hpp\"\n\n\n#include <algorithm>\n#include\
    \ <utility>\n#include <limits>\n\nnamespace monoid {\ntemplate <class T>\nstruct\
    \ add_count {\n  typedef std::pair<T,T> value_t;\n  value_t identity() const {\
    \ return std::make_pair(T(),T()); }\n  value_t merge(value_t a, value_t b) const\
    \ { return std::make_pair(a.first+b.first, a.second+b.second); }\n};\n} // namespace\
    \ monoid\n\n\n"
  code: "#ifndef __MONOID__ADD__COUNT\n#define __MONOID__ADD__COUNT\n#include <algorithm>\n\
    #include <utility>\n#include <limits>\n\nnamespace monoid {\ntemplate <class T>\n\
    struct add_count {\n  typedef std::pair<T,T> value_t;\n  value_t identity() const\
    \ { return std::make_pair(T(),T()); }\n  value_t merge(value_t a, value_t b) const\
    \ { return std::make_pair(a.first+b.first, a.second+b.second); }\n};\n} // namespace\
    \ monoid\n\n#endif // __MONOID__ADD__COUNT"
  dependsOn: []
  isVerificationFile: false
  path: monoid/add_count.hpp
  requiredBy: []
  timestamp: '2021-04-15 20:24:09+09:00'
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
