---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/divisor.hpp
    title: "\u7D04\u6570\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1562
  bundledCode: "#line 1 \"test/aoj/notest.1562.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1562\"\
    \n#line 1 \"math/divisor.hpp\"\n// @title \u7D04\u6570\u5217\u6319\n#include <algorithm>\n\
    #include <vector>\n\nusing ll = long long;\n\nstd::vector<ll> divisor(ll n) {\
    \ \n  std::vector<ll> ret;\n  for (ll i = 1; (ll)i*i <= n; ++i) { \n    if (n\
    \ % i == 0) {\n      ret.push_back(i);\n      if (i*i != n) { ret.push_back(n/i);\
    \ }\n    }\n  }\n  std::sort(ret.begin(), ret.end());\n  return ret;\n};\n#line\
    \ 3 \"test/aoj/notest.1562.cpp\"\n\n\nint main() {\n  int n; cin >> n;\n  for\
    \ (int i = 1; i <= (1<<n); ++i) {\n    vector<ll> divs = divisor(i);\n    if (divs.size()\
    \ == n) {\n      cout << i << endl;\n      return 0;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1562\"\
    \n#include \"../../math/divisor.hpp\"\n\n\nint main() {\n  int n; cin >> n;\n\
    \  for (int i = 1; i <= (1<<n); ++i) {\n    vector<ll> divs = divisor(i);\n  \
    \  if (divs.size() == n) {\n      cout << i << endl;\n      return 0;\n    }\n\
    \  }\n}\n"
  dependsOn:
  - math/divisor.hpp
  isVerificationFile: false
  path: test/aoj/notest.1562.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/aoj/notest.1562.cpp
layout: document
redirect_from:
- /library/test/aoj/notest.1562.cpp
- /library/test/aoj/notest.1562.cpp.html
title: test/aoj/notest.1562.cpp
---
