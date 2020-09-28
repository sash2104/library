---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4
  bundledCode: "#line 2 \"datastructure/median-set2.hpp\"\n\n#include <cassert>\n\
    #include <algorithm>\n#include <vector>\n\nusing namespace std;\n// @see : https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4\n\
    // \u96C6\u5408\u306E\u4E2D\u592E\u5024\u306E\u53D6\u5F97, \u96C6\u5408\u3078\u306E\
    \u8981\u7D20\u306E\u8FFD\u52A0, \u524A\u9664\u304CO(logQ)\u7A0B\u5EA6\u3067\u884C\
    \u3048\u308B\u30C7\u30FC\u30BF\u69CB\u9020\nstruct MedianSet2 {\n  vector<int>\
    \ data;\n  int m; // \u4E2D\u592E\u5024\n  int n; // \u8981\u7D20\u6570\n  int\
    \ loss; // (\u4E2D\u592E\u5024\u3068\u5404\u8981\u7D20\u3068\u306E\u5DEE\u5206\
    \u306E\u7D76\u5BFE\u5024)\u306E\u548C\n  MedianSet2() : m(0), n(0), loss(0), data(26,\
    \ 0) {}\n\n  int add(int x)  {\n    ++n; ++data[x];\n    int nm = (n+1)/2;\n \
    \   int c = 0;\n    for (int i = 0; i < 26; ++i) {\n      if (data[i] == 0) continue;\n\
    \      c += data[i];\n      if (c >= nm) { m = i; break; }\n    }\n    int nloss\
    \ = 0;\n    for (int i = 0; i < 26; ++i) {\n      nloss += data[i]*abs(i-m);\n\
    \    }\n    int dloss = nloss-loss;\n    loss = nloss;\n    return dloss;\n  }\n\
    \n  int remove(int x) {\n    --n; --data[x];\n    if (n == 0) { m = loss = 0;\
    \ return 0; }\n    int nm = (n+1)/2;\n    int c = 0;\n    for (int i = 0; i <\
    \ 26; ++i) {\n      if (data[i] == 0) continue;\n      c += data[i];\n      if\
    \ (c >= nm) { m = i; break; }\n    }\n    int nloss = 0;\n    for (int i = 0;\
    \ i < 26; ++i) {\n      nloss += data[i]*abs(i-m);\n    }\n    int dloss = nloss-loss;\n\
    \    loss = nloss;\n    return -dloss;\n  }\n\n  int get() { return m; }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <algorithm>\n#include <vector>\n\
    \nusing namespace std;\n// @see : https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4\n\
    // \u96C6\u5408\u306E\u4E2D\u592E\u5024\u306E\u53D6\u5F97, \u96C6\u5408\u3078\u306E\
    \u8981\u7D20\u306E\u8FFD\u52A0, \u524A\u9664\u304CO(logQ)\u7A0B\u5EA6\u3067\u884C\
    \u3048\u308B\u30C7\u30FC\u30BF\u69CB\u9020\nstruct MedianSet2 {\n  vector<int>\
    \ data;\n  int m; // \u4E2D\u592E\u5024\n  int n; // \u8981\u7D20\u6570\n  int\
    \ loss; // (\u4E2D\u592E\u5024\u3068\u5404\u8981\u7D20\u3068\u306E\u5DEE\u5206\
    \u306E\u7D76\u5BFE\u5024)\u306E\u548C\n  MedianSet2() : m(0), n(0), loss(0), data(26,\
    \ 0) {}\n\n  int add(int x)  {\n    ++n; ++data[x];\n    int nm = (n+1)/2;\n \
    \   int c = 0;\n    for (int i = 0; i < 26; ++i) {\n      if (data[i] == 0) continue;\n\
    \      c += data[i];\n      if (c >= nm) { m = i; break; }\n    }\n    int nloss\
    \ = 0;\n    for (int i = 0; i < 26; ++i) {\n      nloss += data[i]*abs(i-m);\n\
    \    }\n    int dloss = nloss-loss;\n    loss = nloss;\n    return dloss;\n  }\n\
    \n  int remove(int x) {\n    --n; --data[x];\n    if (n == 0) { m = loss = 0;\
    \ return 0; }\n    int nm = (n+1)/2;\n    int c = 0;\n    for (int i = 0; i <\
    \ 26; ++i) {\n      if (data[i] == 0) continue;\n      c += data[i];\n      if\
    \ (c >= nm) { m = i; break; }\n    }\n    int nloss = 0;\n    for (int i = 0;\
    \ i < 26; ++i) {\n      nloss += data[i]*abs(i-m);\n    }\n    int dloss = nloss-loss;\n\
    \    loss = nloss;\n    return -dloss;\n  }\n\n  int get() { return m; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/median-set2.hpp
  requiredBy: []
  timestamp: '2020-08-30 21:34:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/median-set2.hpp
layout: document
redirect_from:
- /library/datastructure/median-set2.hpp
- /library/datastructure/median-set2.hpp.html
title: datastructure/median-set2.hpp
---
