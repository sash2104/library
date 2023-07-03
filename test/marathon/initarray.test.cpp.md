---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: util/marathon/initarray.hpp
    title: util/marathon/initarray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "InitArray\u30AF\u30E9\u30B9\u306E\u7C21\u6613\u7684\u306A\u30C6\
      \u30B9\u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/marathon/initarray.test.cpp\"\n// @title InitArray\u30AF\
    \u30E9\u30B9\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\u30C8\n// dummy problem\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#line 2 \"util/marathon/initarray.hpp\"\
    \n#include <array>\n\n// \u521D\u671F\u5316\u3092O(1)\u3067\u3067\u304D\u308B\u3084\
    \u3064\u3002BFS\u3092\u7E70\u308A\u8FD4\u3059\u3068\u304D\u306B\u4FBF\u5229\n\
    // @see https://topcoder-tomerun.hatenablog.jp/entry/2022/11/06/145156\n// @see\
    \ https://twitter.com/koyumeishi_/status/1589142265209188352\ntemplate<int N>\n\
    struct InitArray {\n  uint32_t epoch = 1;\n  std::array<uint32_t, N> arr = {};\n\
    \  void set(int i) { arr[i] = epoch; }\n  void reset() { epoch++; }\n  bool operator[](int\
    \ i) const {\n    return arr[i] == epoch;\n  }\n};\n#line 7 \"test/marathon/initarray.test.cpp\"\
    \nusing namespace std;\n\nstatic constexpr int n = 100;\nvoid test() {\n    InitArray<n>\
    \ visited;\n    for (int i = 0; i < n; ++i) {\n        visited.reset();\n    \
    \    visited.set(i);\n        for (int j = 0; j < n; ++j) {\n            assert\
    \ (visited[j] == (j==i));\n        }\n    }\n}\n\nint main() {\n    test();\n\n\
    \    // dummy output\n    cout << \"Hello World\" << endl;\n}\n"
  code: "// @title InitArray\u30AF\u30E9\u30B9\u306E\u7C21\u6613\u7684\u306A\u30C6\
    \u30B9\u30C8\n// dummy problem\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include \"../../util/marathon/initarray.hpp\"\
    \nusing namespace std;\n\nstatic constexpr int n = 100;\nvoid test() {\n    InitArray<n>\
    \ visited;\n    for (int i = 0; i < n; ++i) {\n        visited.reset();\n    \
    \    visited.set(i);\n        for (int j = 0; j < n; ++j) {\n            assert\
    \ (visited[j] == (j==i));\n        }\n    }\n}\n\nint main() {\n    test();\n\n\
    \    // dummy output\n    cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - util/marathon/initarray.hpp
  isVerificationFile: true
  path: test/marathon/initarray.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 22:51:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/marathon/initarray.test.cpp
layout: document
redirect_from:
- /verify/test/marathon/initarray.test.cpp
- /verify/test/marathon/initarray.test.cpp.html
title: "InitArray\u30AF\u30E9\u30B9\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\u30C8"
---
