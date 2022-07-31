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
    \ T >\nint longest_increasing_subsequence(const std::vector<T> &a, bool strict,\
    \ std::vector<int> &len) {\n    std::vector<T> lis;\n    typename std::vector<T>::iterator\
    \ it;\n    for (int i = 0; i < a.size(); ++i) {\n        T p = a[i];\n       \
    \ if(strict) it = std::lower_bound(lis.begin(), lis.end(), p);\n        else it\
    \ = std::upper_bound(lis.begin(), lis.end(), p);\n\n        // a[0],...,a[i]\u307E\
    \u3067\u306E\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055\n   \
    \     int pos = distance(lis.begin(), it);\n        len.push_back(pos+1);\n\n\
    \        if(lis.end() == it) lis.emplace_back(p);\n        else *it = p;\n   \
    \ }\n    return lis.size();\n}\n"
  code: "// @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)\n\n#include <vector>\n\
    #include <algorithm>\ntemplate< typename T >\nint longest_increasing_subsequence(const\
    \ std::vector<T> &a, bool strict, std::vector<int> &len) {\n    std::vector<T>\
    \ lis;\n    typename std::vector<T>::iterator it;\n    for (int i = 0; i < a.size();\
    \ ++i) {\n        T p = a[i];\n        if(strict) it = std::lower_bound(lis.begin(),\
    \ lis.end(), p);\n        else it = std::upper_bound(lis.begin(), lis.end(), p);\n\
    \n        // a[0],...,a[i]\u307E\u3067\u306E\u6700\u9577\u5897\u52A0\u90E8\u5206\
    \u5217\u306E\u9577\u3055\n        int pos = distance(lis.begin(), it);\n     \
    \   len.push_back(pos+1);\n\n        if(lis.end() == it) lis.emplace_back(p);\n\
    \        else *it = p;\n    }\n    return lis.size();\n}"
  dependsOn: []
  isVerificationFile: false
  path: util/lis.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
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
