---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS_1_14_B.test.cpp
    title: test/aoj/ALDS_1_14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
    links: []
  bundledCode: "#line 1 \"string/rolling-hash.hpp\"\n// @title \u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\n#include <iostream>\n#include <string>\n#include\
    \ <vector>\n\nusing ull = unsigned long long;\nstruct RollingHash {\n  static\
    \ const ull MASK30 = (1UL << 30) - 1;\n  static const ull MASK31 = (1UL << 31)\
    \ - 1;\n  static const ull MOD = (1UL << 61) - 1;\n  static const ull OFFSET =\
    \ MOD * ((1UL << 3) - 1);\n  static const unsigned int BASE = 10007;\n  std::vector<ull>\
    \ pows, hashed;\n  RollingHash(const std::string &s) {\n    int sz = (int) s.size();\n\
    \    pows.resize(sz+1, 0);\n    hashed.resize(sz+1, 0);\n    pows[0] = 1;\n  \
    \  for (int i = 0; i < sz; i++) {\n      pows[i+1] = CalcMod(Mul(pows[i], BASE));\n\
    \      hashed[i+1] = CalcMod(Mul(hashed[i], BASE) + s[i]);\n      // std::cerr\
    \ << s[i] << \" \" << i << \" \" << hashed[i+1] << std::endl;\n    }\n  }\n\n\
    \  // [l, r) \u306E\u533A\u9593\u306Ehash\u3092\u6C42\u3081\u308B\n  ull get(int\
    \ l, int r) {\n    return CalcMod(hashed[r] + OFFSET - Mul(hashed[l], pows[r-l]));\n\
    \  }\n\n  static ull Mul(ull l, ull r) { \n    ull lu = l >> 31;\n    ull ld =\
    \ l & MASK31;\n    ull ru = r >> 31;\n    ull rd = r & MASK31;\n    ull c = ld\
    \ * ru + lu * rd;\n    return ((lu * ru) << 1) + ld * rd + ((c & MASK30) << 31)\
    \ + (c >> 30);\n  }\n\n  static ull Mul(ull l, unsigned int r) { \n    ull lu\
    \ = l >> 31;\n    ull rd = r & MASK31;\n    ull c = lu * rd;\n    return (l &\
    \ MASK31) * rd + ((c & MASK30) << 31) + (c >> 30);\n  }\n\n  static ull CalcMod(ull\
    \ x) { \n    x = (x & MOD) + (x >> 61);\n    if (x >= MOD) x -= MOD;\n    return\
    \ x;\n  }\n\n};\n"
  code: "// @title \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\n\nusing ull = unsigned long\
    \ long;\nstruct RollingHash {\n  static const ull MASK30 = (1UL << 30) - 1;\n\
    \  static const ull MASK31 = (1UL << 31) - 1;\n  static const ull MOD = (1UL <<\
    \ 61) - 1;\n  static const ull OFFSET = MOD * ((1UL << 3) - 1);\n  static const\
    \ unsigned int BASE = 10007;\n  std::vector<ull> pows, hashed;\n  RollingHash(const\
    \ std::string &s) {\n    int sz = (int) s.size();\n    pows.resize(sz+1, 0);\n\
    \    hashed.resize(sz+1, 0);\n    pows[0] = 1;\n    for (int i = 0; i < sz; i++)\
    \ {\n      pows[i+1] = CalcMod(Mul(pows[i], BASE));\n      hashed[i+1] = CalcMod(Mul(hashed[i],\
    \ BASE) + s[i]);\n      // std::cerr << s[i] << \" \" << i << \" \" << hashed[i+1]\
    \ << std::endl;\n    }\n  }\n\n  // [l, r) \u306E\u533A\u9593\u306Ehash\u3092\u6C42\
    \u3081\u308B\n  ull get(int l, int r) {\n    return CalcMod(hashed[r] + OFFSET\
    \ - Mul(hashed[l], pows[r-l]));\n  }\n\n  static ull Mul(ull l, ull r) { \n  \
    \  ull lu = l >> 31;\n    ull ld = l & MASK31;\n    ull ru = r >> 31;\n    ull\
    \ rd = r & MASK31;\n    ull c = ld * ru + lu * rd;\n    return ((lu * ru) << 1)\
    \ + ld * rd + ((c & MASK30) << 31) + (c >> 30);\n  }\n\n  static ull Mul(ull l,\
    \ unsigned int r) { \n    ull lu = l >> 31;\n    ull rd = r & MASK31;\n    ull\
    \ c = lu * rd;\n    return (l & MASK31) * rd + ((c & MASK30) << 31) + (c >> 30);\n\
    \  }\n\n  static ull CalcMod(ull x) { \n    x = (x & MOD) + (x >> 61);\n    if\
    \ (x >= MOD) x -= MOD;\n    return x;\n  }\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS_1_14_B.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
