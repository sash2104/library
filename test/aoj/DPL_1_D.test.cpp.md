---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: util/lis.hpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    document_title: "LIS\u306E\u30C6\u30B9\u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"test/aoj/DPL_1_D.test.cpp\"\n// @brief LIS\u306E\u30C6\u30B9\
    \u30C8\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n#line 1 \"util/lis.hpp\"\n// @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\
    \ (LIS)\n\n#include <vector>\n#include <algorithm>\ntemplate< typename T >\nstd::vector<T>\
    \ longest_increasing_subsequence(const std::vector< T > &a, bool strict) {\n \
    \ std::vector< T > lis;\n  for(auto &p : a) {\n    typename std::vector< T >::iterator\
    \ it;\n    if(strict) it = std::lower_bound(lis.begin(), lis.end(), p);\n    else\
    \ it = std::upper_bound(std::begin(lis), std::end(lis), p);\n    if(lis.end()\
    \ == it) lis.emplace_back(p);\n    else *it = p;\n  }\n  return lis;\n}\n#line\
    \ 4 \"test/aoj/DPL_1_D.test.cpp\"\n\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n  int n; cin >> n;\n  vector<int> la(n);\n  for (int i = 0; i\
    \ < n; ++i) {\n      cin >> la[i];\n  }\n  auto lis = longest_increasing_subsequence(la,\
    \ true);\n  cout << lis.size() << endl;\n}\n"
  code: "// @brief LIS\u306E\u30C6\u30B9\u30C8\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n#include \"../../util/lis.hpp\"\n\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n  int n; cin >> n;\n  vector<int> la(n);\n  for (int i = 0; i\
    \ < n; ++i) {\n      cin >> la[i];\n  }\n  auto lis = longest_increasing_subsequence(la,\
    \ true);\n  cout << lis.size() << endl;\n}"
  dependsOn:
  - util/lis.hpp
  isVerificationFile: true
  path: test/aoj/DPL_1_D.test.cpp
  requiredBy: []
  timestamp: '2020-12-12 21:19:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_D.test.cpp
- /verify/test/aoj/DPL_1_D.test.cpp.html
title: "LIS\u306E\u30C6\u30B9\u30C8"
---
