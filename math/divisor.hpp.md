---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/aoj/notest.1562.cpp
    title: test/aoj/notest.1562.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D04\u6570\u5217\u6319"
    links: []
  bundledCode: "#line 1 \"math/divisor.hpp\"\n// @title \u7D04\u6570\u5217\u6319\n\
    #include <algorithm>\n#include <vector>\n\nusing ll = long long;\n\nstd::vector<ll>\
    \ divisor(ll n) { \n  std::vector<ll> ret;\n  for (ll i = 1; (ll)i*i <= n; ++i)\
    \ { \n    if (n % i == 0) {\n      ret.push_back(i);\n      if (i*i != n) { ret.push_back(n/i);\
    \ }\n    }\n  }\n  std::sort(ret.begin(), ret.end());\n  return ret;\n};\n"
  code: "// @title \u7D04\u6570\u5217\u6319\n#include <algorithm>\n#include <vector>\n\
    \nusing ll = long long;\n\nstd::vector<ll> divisor(ll n) { \n  std::vector<ll>\
    \ ret;\n  for (ll i = 1; (ll)i*i <= n; ++i) { \n    if (n % i == 0) {\n      ret.push_back(i);\n\
    \      if (i*i != n) { ret.push_back(n/i); }\n    }\n  }\n  std::sort(ret.begin(),\
    \ ret.end());\n  return ret;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.hpp
  requiredBy:
  - test/aoj/notest.1562.cpp
  timestamp: '2021-04-15 20:33:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor.hpp
layout: document
redirect_from:
- /library/math/divisor.hpp
- /library/math/divisor.hpp.html
title: "\u7D04\u6570\u5217\u6319"
---
