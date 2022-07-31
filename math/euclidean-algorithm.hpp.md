---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_C.test.cpp
    title: test/aoj/NTL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5927\u516C\u7D04\u6570\u30FB\u6700\u5C0F\u516C\u500D\u6570"
    links: []
  bundledCode: "#line 1 \"math/euclidean-algorithm.hpp\"\n// @title \u6700\u5927\u516C\
    \u7D04\u6570\u30FB\u6700\u5C0F\u516C\u500D\u6570\n#include <cassert>\n\nusing\
    \ ll = long long;\n\nll gcd(ll a, ll b) {\n  if (b == 0) return a;\n  return gcd(b,\
    \ a % b);\n}\n\nll lcm(ll a, ll b) {\n  return a*b / gcd(a, b);\n}\n\n#if 0\n\
    int main() {\n  assert(gcd(18, 24) == 6);\n  assert(lcm(18, 24) == 72);\n  //\
    \ a\u3068b\u306E\u9806\u5E8F\u304C\u9006\u3067\u3082ok\n  assert(gcd(7, 3) ==\
    \ 1);\n  // a\u3068b\u306E\u9806\u5E8F\u304C\u9006\u3067\u3082ok\n  assert(lcm(7,\
    \ 3) == 21);\n  // int\u3092\u8D85\u3048\u308B\u7BC4\u56F2\u3067\u3082\u554F\u984C\
    \u306A\u304F\u8A08\u7B97\u3067\u304D\u308B\n  assert(gcd(123456789123456789, 987654321987654321)\
    \ == 9000000009);\n}\n#endif\n"
  code: "// @title \u6700\u5927\u516C\u7D04\u6570\u30FB\u6700\u5C0F\u516C\u500D\u6570\
    \n#include <cassert>\n\nusing ll = long long;\n\nll gcd(ll a, ll b) {\n  if (b\
    \ == 0) return a;\n  return gcd(b, a % b);\n}\n\nll lcm(ll a, ll b) {\n  return\
    \ a*b / gcd(a, b);\n}\n\n#if 0\nint main() {\n  assert(gcd(18, 24) == 6);\n  assert(lcm(18,\
    \ 24) == 72);\n  // a\u3068b\u306E\u9806\u5E8F\u304C\u9006\u3067\u3082ok\n  assert(gcd(7,\
    \ 3) == 1);\n  // a\u3068b\u306E\u9806\u5E8F\u304C\u9006\u3067\u3082ok\n  assert(lcm(7,\
    \ 3) == 21);\n  // int\u3092\u8D85\u3048\u308B\u7BC4\u56F2\u3067\u3082\u554F\u984C\
    \u306A\u304F\u8A08\u7B97\u3067\u304D\u308B\n  assert(gcd(123456789123456789, 987654321987654321)\
    \ == 9000000009);\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/euclidean-algorithm.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_C.test.cpp
documentation_of: math/euclidean-algorithm.hpp
layout: document
redirect_from:
- /library/math/euclidean-algorithm.hpp
- /library/math/euclidean-algorithm.hpp.html
title: "\u6700\u5927\u516C\u7D04\u6570\u30FB\u6700\u5C0F\u516C\u500D\u6570"
---
