---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euclidean-algorithm.hpp
    title: "\u6700\u5927\u516C\u7D04\u6570\u30FB\u6700\u5C0F\u516C\u500D\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
  bundledCode: "#line 1 \"test/aoj/NTL_1_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \n\n#line 1 \"math/euclidean-algorithm.hpp\"\n// @title \u6700\u5927\u516C\u7D04\
    \u6570\u30FB\u6700\u5C0F\u516C\u500D\u6570\n#include <cassert>\n\nusing ll = long\
    \ long;\n\nll gcd(ll a, ll b) {\n  if (b == 0) return a;\n  return gcd(b, a %\
    \ b);\n}\n\nll lcm(ll a, ll b) {\n  return a*b / gcd(a, b);\n}\n\n#if 0\nint main()\
    \ {\n  assert(gcd(18, 24) == 6);\n  assert(lcm(18, 24) == 72);\n  // a\u3068b\u306E\
    \u9806\u5E8F\u304C\u9006\u3067\u3082ok\n  assert(gcd(7, 3) == 1);\n  // a\u3068\
    b\u306E\u9806\u5E8F\u304C\u9006\u3067\u3082ok\n  assert(lcm(7, 3) == 21);\n  //\
    \ int\u3092\u8D85\u3048\u308B\u7BC4\u56F2\u3067\u3082\u554F\u984C\u306A\u304F\u8A08\
    \u7B97\u3067\u304D\u308B\n  assert(gcd(123456789123456789, 987654321987654321)\
    \ == 9000000009);\n}\n#endif\n#line 4 \"test/aoj/NTL_1_C.test.cpp\"\n#include\
    \ <iostream>\n\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n\
    \  ll ans = 1;\n  for (int i = 0; i < n; ++i) {\n    ll a;\n    cin >> a;\n  \
    \  ans = lcm(ans, a);\n  }\n  cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \n\n#include \"../../math/euclidean-algorithm.hpp\"\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  ll ans = 1;\n  for\
    \ (int i = 0; i < n; ++i) {\n    ll a;\n    cin >> a;\n    ans = lcm(ans, a);\n\
    \  }\n  cout << ans << endl;\n}\n"
  dependsOn:
  - math/euclidean-algorithm.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_C.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_C.test.cpp
- /verify/test/aoj/NTL_1_C.test.cpp.html
title: test/aoj/NTL_1_C.test.cpp
---
