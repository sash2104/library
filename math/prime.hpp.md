---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS_1_1_C.test.cpp
    title: test/aoj/ALDS_1_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D20\u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"math/prime.hpp\"\n// @title \u7D20\u6570\u5224\u5B9A\u3001\
    \u7D20\u56E0\u6570\u5206\u89E3\n#include <cassert>\n#include <iostream>\n#include\
    \ <vector>\n#include <map>\n\nusing ll = long long;\n\nclass Prime {\n// n\u4EE5\
    \u4E0B\u306E\u7D20\u6570\u3092\u5217\u6319\u3059\u308B\npublic:\n  const int n;\n\
    \  std::vector<bool> is_prime;\n  std::vector<int> primes;\n  Prime(int size)\
    \ : n(size), is_prime(n+1, true) {\n    is_prime[0] = false;\n    is_prime[1]\
    \ = false;\n    for (int i = 2; i <= n; ++i) {\n      if (!is_prime[i]) continue;\n\
    \      primes.push_back(i);\n      int tmp = 2*i;\n      while (tmp <= n) {\n\
    \        is_prime[tmp] = false;\n        tmp += i;\n      }\n    }\n  }\n\n  bool\
    \ check(int x) { return is_prime[x]; }\n};\n\nstruct PrimeFactorization {\n  //\
    \ n*n\u4EE5\u4E0B\u306E\u6570\u306B\u3064\u3044\u3066\u306E\u7D20\u56E0\u6570\u5206\
    \u89E3\n  const int n;\n  Prime p;\n  PrimeFactorization(int n) : n(n), p(n) {}\n\
    \n  std::map<ll, int> calc(ll a) {\n    std::map<ll, int> ret;\n    ll tmp = a;\n\
    \    for (int i: p.primes) {\n      if (i > tmp) break;\n      int count = 0;\n\
    \      while (tmp % i == 0) { \n        ++count;\n        tmp /= i;\n      }\n\
    \      if (count > 0) ret[i] = count;\n    }\n    if (tmp > 1) ret[tmp] = 1;\n\
    \    return ret;\n  }\n};\n\nstruct FastPrimeFactorization {\n  /**\n   * @brief\
    \ n\u4EE5\u4E0B\u306E\u6570\u306B\u3064\u3044\u3066\u9AD8\u901F\u3067\u3001n*n\u4EE5\
    \u4E0B\u306E\u6570\u3067\u666E\u901A\u306B\u7D20\u56E0\u6570\u5206\u89E3\u3092\
    \u884C\u3046\n   * \n   */\n  int n;\n  std::vector<int> divides; // \u305D\u306E\
    \u6570\u3092\u5272\u308A\u5207\u308B\u6700\u5C0F\u306E\u7D20\u56E0\u6570\n  std::vector<int>\
    \ primes; // n\u4EE5\u4E0B\u306E\u7D20\u6570\n  FastPrimeFactorization(int n)\
    \ : n(n), divides(n+1) {\n    assert(n <= 2000000);\n    // \u30A8\u30E9\u30C8\
    \u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\u306B\u304B\u3051\u3001\u6700\u5C0F\u306E\
    \u7D20\u56E0\u6570\u3092divides\u306B\u66F8\u304D\u8FBC\u3093\u3067\u3044\u304F\
    \n    for (int i = 2; i <= n; ++i) {\n      if (divides[i] > 0) continue;\n  \
    \    primes.push_back(i);\n      int j = i;\n      while (j <= n) {\n        if\
    \ (divides[j] == 0) {\n          divides[j] = i;\n        }\n        j += i;\n\
    \      }\n    }\n    // for (int i = 0; i <= n; ++i) { \n    //   cout << i <<\
    \ \" \" << divides[i] << endl;\n    // }\n  }\n\n  std::map<ll, int> calc(ll a)\
    \ {\n    std::map<ll, int> ret;\n    // \u9AD8\u901F\u306B\u8A08\u7B97\u3067\u304D\
    \u306A\u3044\u90E8\u5206\u306F\u611A\u76F4\u306B\u3084\u308B\n    ll tmp = a;\n\
    \    for (int i: primes) {\n      if (tmp <= n || i > tmp) break;\n      int count\
    \ = 0;\n      while (tmp % i == 0) { \n        ++count;\n        tmp /= i;\n \
    \     }\n      if (count > 0) ret[i] = count;\n    }\n    if (tmp > n) {\n   \
    \   // n\u3088\u308A\u5927\u304D\u3044\u7D20\u6570\n      ret[tmp] = 1;\n    \
    \  return ret;\n    }\n    while (tmp > 1) {\n      int d = divides[tmp];\n  \
    \    ++ret[d];\n      tmp /= d;\n    }\n    return ret;\n  }\n};\n\n#if 0\nusing\
    \ namespace std;\nint main() {\n  FastPrimeFactorization pf(1000000);\n  // PrimeFactorization\
    \ pf(1000000);\n  std::map<ll, int> factors;\n\n\n  ll a = (ll)2*2*5*7*7*41;\n\
    \  factors = pf.calc(a);\n  cout << \"prime factors of \" << a << \" is ...\"\
    \ << endl;\n  for (auto it : factors) { \n    cout << it.first << \" \" << it.second\
    \ << endl;\n  }\n  cout << endl;\n\n  // \u6700\u5927\u6570\u4ED8\u8FD1\u3067\u306E\
    \u78BA\u8A8D\n  a = (ll)999983*999983;\n  factors = pf.calc(a);\n  cout << \"\
    prime factors of \" << a << \" is ...\" << endl;\n  for (auto it : factors) {\
    \ \n    cout << it.first << \" \" << it.second << endl;\n  }\n}\n#endif\n"
  code: "// @title \u7D20\u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\u89E3\n\
    #include <cassert>\n#include <iostream>\n#include <vector>\n#include <map>\n\n\
    using ll = long long;\n\nclass Prime {\n// n\u4EE5\u4E0B\u306E\u7D20\u6570\u3092\
    \u5217\u6319\u3059\u308B\npublic:\n  const int n;\n  std::vector<bool> is_prime;\n\
    \  std::vector<int> primes;\n  Prime(int size) : n(size), is_prime(n+1, true)\
    \ {\n    is_prime[0] = false;\n    is_prime[1] = false;\n    for (int i = 2; i\
    \ <= n; ++i) {\n      if (!is_prime[i]) continue;\n      primes.push_back(i);\n\
    \      int tmp = 2*i;\n      while (tmp <= n) {\n        is_prime[tmp] = false;\n\
    \        tmp += i;\n      }\n    }\n  }\n\n  bool check(int x) { return is_prime[x];\
    \ }\n};\n\nstruct PrimeFactorization {\n  // n*n\u4EE5\u4E0B\u306E\u6570\u306B\
    \u3064\u3044\u3066\u306E\u7D20\u56E0\u6570\u5206\u89E3\n  const int n;\n  Prime\
    \ p;\n  PrimeFactorization(int n) : n(n), p(n) {}\n\n  std::map<ll, int> calc(ll\
    \ a) {\n    std::map<ll, int> ret;\n    ll tmp = a;\n    for (int i: p.primes)\
    \ {\n      if (i > tmp) break;\n      int count = 0;\n      while (tmp % i ==\
    \ 0) { \n        ++count;\n        tmp /= i;\n      }\n      if (count > 0) ret[i]\
    \ = count;\n    }\n    if (tmp > 1) ret[tmp] = 1;\n    return ret;\n  }\n};\n\n\
    struct FastPrimeFactorization {\n  /**\n   * @brief n\u4EE5\u4E0B\u306E\u6570\u306B\
    \u3064\u3044\u3066\u9AD8\u901F\u3067\u3001n*n\u4EE5\u4E0B\u306E\u6570\u3067\u666E\
    \u901A\u306B\u7D20\u56E0\u6570\u5206\u89E3\u3092\u884C\u3046\n   * \n   */\n \
    \ int n;\n  std::vector<int> divides; // \u305D\u306E\u6570\u3092\u5272\u308A\u5207\
    \u308B\u6700\u5C0F\u306E\u7D20\u56E0\u6570\n  std::vector<int> primes; // n\u4EE5\
    \u4E0B\u306E\u7D20\u6570\n  FastPrimeFactorization(int n) : n(n), divides(n+1)\
    \ {\n    assert(n <= 2000000);\n    // \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u7BE9\u306B\u304B\u3051\u3001\u6700\u5C0F\u306E\u7D20\u56E0\u6570\u3092\
    divides\u306B\u66F8\u304D\u8FBC\u3093\u3067\u3044\u304F\n    for (int i = 2; i\
    \ <= n; ++i) {\n      if (divides[i] > 0) continue;\n      primes.push_back(i);\n\
    \      int j = i;\n      while (j <= n) {\n        if (divides[j] == 0) {\n  \
    \        divides[j] = i;\n        }\n        j += i;\n      }\n    }\n    // for\
    \ (int i = 0; i <= n; ++i) { \n    //   cout << i << \" \" << divides[i] << endl;\n\
    \    // }\n  }\n\n  std::map<ll, int> calc(ll a) {\n    std::map<ll, int> ret;\n\
    \    // \u9AD8\u901F\u306B\u8A08\u7B97\u3067\u304D\u306A\u3044\u90E8\u5206\u306F\
    \u611A\u76F4\u306B\u3084\u308B\n    ll tmp = a;\n    for (int i: primes) {\n \
    \     if (tmp <= n || i > tmp) break;\n      int count = 0;\n      while (tmp\
    \ % i == 0) { \n        ++count;\n        tmp /= i;\n      }\n      if (count\
    \ > 0) ret[i] = count;\n    }\n    if (tmp > n) {\n      // n\u3088\u308A\u5927\
    \u304D\u3044\u7D20\u6570\n      ret[tmp] = 1;\n      return ret;\n    }\n    while\
    \ (tmp > 1) {\n      int d = divides[tmp];\n      ++ret[d];\n      tmp /= d;\n\
    \    }\n    return ret;\n  }\n};\n\n#if 0\nusing namespace std;\nint main() {\n\
    \  FastPrimeFactorization pf(1000000);\n  // PrimeFactorization pf(1000000);\n\
    \  std::map<ll, int> factors;\n\n\n  ll a = (ll)2*2*5*7*7*41;\n  factors = pf.calc(a);\n\
    \  cout << \"prime factors of \" << a << \" is ...\" << endl;\n  for (auto it\
    \ : factors) { \n    cout << it.first << \" \" << it.second << endl;\n  }\n  cout\
    \ << endl;\n\n  // \u6700\u5927\u6570\u4ED8\u8FD1\u3067\u306E\u78BA\u8A8D\n  a\
    \ = (ll)999983*999983;\n  factors = pf.calc(a);\n  cout << \"prime factors of\
    \ \" << a << \" is ...\" << endl;\n  for (auto it : factors) { \n    cout << it.first\
    \ << \" \" << it.second << endl;\n  }\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS_1_1_C.test.cpp
documentation_of: math/prime.hpp
layout: document
redirect_from:
- /library/math/prime.hpp
- /library/math/prime.hpp.html
title: "\u7D20\u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\u89E3"
---
