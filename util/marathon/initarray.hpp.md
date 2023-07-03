---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/marathon/initarray.test.cpp
    title: "InitArray\u30AF\u30E9\u30B9\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://topcoder-tomerun.hatenablog.jp/entry/2022/11/06/145156
    - https://twitter.com/koyumeishi_/status/1589142265209188352
  bundledCode: "#line 2 \"util/marathon/initarray.hpp\"\n#include <array>\n\n// \u521D\
    \u671F\u5316\u3092O(1)\u3067\u3067\u304D\u308B\u3084\u3064\u3002BFS\u3092\u7E70\
    \u308A\u8FD4\u3059\u3068\u304D\u306B\u4FBF\u5229\n// @see https://topcoder-tomerun.hatenablog.jp/entry/2022/11/06/145156\n\
    // @see https://twitter.com/koyumeishi_/status/1589142265209188352\ntemplate<int\
    \ N>\nstruct InitArray {\n  uint32_t epoch = 1;\n  std::array<uint32_t, N> arr\
    \ = {};\n  void set(int i) { arr[i] = epoch; }\n  void reset() { epoch++; }\n\
    \  bool operator[](int i) const {\n    return arr[i] == epoch;\n  }\n};\n"
  code: "#pragma once\n#include <array>\n\n// \u521D\u671F\u5316\u3092O(1)\u3067\u3067\
    \u304D\u308B\u3084\u3064\u3002BFS\u3092\u7E70\u308A\u8FD4\u3059\u3068\u304D\u306B\
    \u4FBF\u5229\n// @see https://topcoder-tomerun.hatenablog.jp/entry/2022/11/06/145156\n\
    // @see https://twitter.com/koyumeishi_/status/1589142265209188352\ntemplate<int\
    \ N>\nstruct InitArray {\n  uint32_t epoch = 1;\n  std::array<uint32_t, N> arr\
    \ = {};\n  void set(int i) { arr[i] = epoch; }\n  void reset() { epoch++; }\n\
    \  bool operator[](int i) const {\n    return arr[i] == epoch;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: util/marathon/initarray.hpp
  requiredBy: []
  timestamp: '2023-07-03 22:51:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/marathon/initarray.test.cpp
documentation_of: util/marathon/initarray.hpp
layout: document
redirect_from:
- /library/util/marathon/initarray.hpp
- /library/util/marathon/initarray.hpp.html
title: util/marathon/initarray.hpp
---
