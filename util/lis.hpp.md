---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_D.test.cpp
    title: "LIS\u306E\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)"
    links: []
  bundledCode: "#line 1 \"util/lis.hpp\"\n// @brief \u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217 (LIS)\n\n#include <vector>\n#include <algorithm>\ntemplate< typename\
    \ T >\nstd::vector<T> longest_increasing_subsequence(const std::vector< T > &a,\
    \ bool strict) {\n  std::vector< T > lis;\n  for(auto &p : a) {\n    typename\
    \ std::vector< T >::iterator it;\n    if(strict) it = std::lower_bound(lis.begin(),\
    \ lis.end(), p);\n    else it = std::upper_bound(std::begin(lis), std::end(lis),\
    \ p);\n    if(lis.end() == it) lis.emplace_back(p);\n    else *it = p;\n  }\n\
    \  return lis;\n}\n"
  code: "// @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)\n\n#include <vector>\n\
    #include <algorithm>\ntemplate< typename T >\nstd::vector<T> longest_increasing_subsequence(const\
    \ std::vector< T > &a, bool strict) {\n  std::vector< T > lis;\n  for(auto &p\
    \ : a) {\n    typename std::vector< T >::iterator it;\n    if(strict) it = std::lower_bound(lis.begin(),\
    \ lis.end(), p);\n    else it = std::upper_bound(std::begin(lis), std::end(lis),\
    \ p);\n    if(lis.end() == it) lis.emplace_back(p);\n    else *it = p;\n  }\n\
    \  return lis;\n}"
  dependsOn: []
  isVerificationFile: false
  path: util/lis.hpp
  requiredBy: []
  timestamp: '2020-12-12 21:19:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_1_D.test.cpp
documentation_of: util/lis.hpp
layout: document
redirect_from:
- /library/util/lis.hpp
- /library/util/lis.hpp.html
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)"
---
