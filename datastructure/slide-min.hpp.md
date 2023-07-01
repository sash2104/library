---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.test.cpp
    title: test/aoj/DSL_3_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
    links: []
  bundledCode: "#line 1 \"datastructure/slide-min.hpp\"\n/**\n * @title \u30B9\u30E9\
    \u30A4\u30C9\u6700\u5C0F\u5024\n */\n#include <iostream>\n#include <deque>\n#include\
    \ <vector>\n\ntemplate <class T>\nstd::vector<int> slideMin(const std::vector<T>&\
    \ v, int k) {\n  /* v\u306E\u9023\u7D9A\u3059\u308Bk\u533A\u9593\u306E\u6700\u5C0F\
    \u5024\u306Eindex\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059 */\n  std::vector<int>\
    \ ret;\n  std::deque<int> dq;\n  int n = v.size();\n  for (int i = 0; i < n; ++i)\
    \ {\n    while (dq.size() && v[dq.back()] >= v[i]) dq.pop_back();\n    dq.push_back(i);\n\
    \    if (i - k + 1 >= 0) {\n      ret.push_back(dq.front());\n      if (dq.front()\
    \ <= i-k+1) dq.pop_front();\n    }\n  }\n  return ret;\n}\n\n#if 0\n#include <cassert>\n\
    int main() {\n  std::vector<int> v = {1, 3, 5, 4, 2};\n\n  int k = 3;\n  std::vector<int>\
    \ ret = slideMin(v, k);\n  assert(ret.size() == 3);\n  assert(ret[0] == 0);\n\
    \  assert(ret[1] == 1);\n  assert(ret[2] == 4);\n}\n#endif\n"
  code: "/**\n * @title \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n */\n#include\
    \ <iostream>\n#include <deque>\n#include <vector>\n\ntemplate <class T>\nstd::vector<int>\
    \ slideMin(const std::vector<T>& v, int k) {\n  /* v\u306E\u9023\u7D9A\u3059\u308B\
    k\u533A\u9593\u306E\u6700\u5C0F\u5024\u306Eindex\u306E\u30EA\u30B9\u30C8\u3092\
    \u8FD4\u3059 */\n  std::vector<int> ret;\n  std::deque<int> dq;\n  int n = v.size();\n\
    \  for (int i = 0; i < n; ++i) {\n    while (dq.size() && v[dq.back()] >= v[i])\
    \ dq.pop_back();\n    dq.push_back(i);\n    if (i - k + 1 >= 0) {\n      ret.push_back(dq.front());\n\
    \      if (dq.front() <= i-k+1) dq.pop_front();\n    }\n  }\n  return ret;\n}\n\
    \n#if 0\n#include <cassert>\nint main() {\n  std::vector<int> v = {1, 3, 5, 4,\
    \ 2};\n\n  int k = 3;\n  std::vector<int> ret = slideMin(v, k);\n  assert(ret.size()\
    \ == 3);\n  assert(ret[0] == 0);\n  assert(ret[1] == 1);\n  assert(ret[2] == 4);\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/slide-min.hpp
  requiredBy: []
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.test.cpp
documentation_of: datastructure/slide-min.hpp
layout: document
redirect_from:
- /library/datastructure/slide-min.hpp
- /library/datastructure/slide-min.hpp.html
title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---
