---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u4E2D\u592E\u5024"
    links:
    - https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/median-list.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @title \u4E2D\u592E\u5024\n * @see https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4\n\
    \ * @brief \u96C6\u5408\u306E\u4E2D\u592E\u5024\u306E\u53D6\u5F97, \u96C6\u5408\
    \u3078\u306E\u8981\u7D20\u306E\u8FFD\u52A0, \u524A\u9664\u304CO(logQ)\u7A0B\u5EA6\
    \u3067\u884C\u3048\u308B\u30C7\u30FC\u30BF\u69CB\u9020\n */\n#pragma once\n\n\
    #include <cassert>\n#include <algorithm>\n#include <iostream>\n#include <map>\n\
    \nstruct MedianSet {\n  int l; // \u4E2D\u592E\u5024\u3088\u308A\u5C0F\u3055\u3044\
    \u8981\u7D20\u306E\u500B\u6570\n  int r; // \u4E2D\u592E\u5024\u3088\u308A\u5927\
    \u304D\u3044\u8981\u7D20\u306E\u500B\u6570\n  int m; // \u4E2D\u592E\u5024\n \
    \ int n; // \u8981\u7D20\u6570\n  int loss; // (\u4E2D\u592E\u5024\u3068\u5404\
    \u8981\u7D20\u3068\u306E\u5DEE\u5206\u306E\u7D76\u5BFE\u5024)\u306E\u548C\n  MedianSet()\
    \ : l(0), r(0), m(0), n(0), loss(0) {}\n  std::map<int, int> data; \n\n  void\
    \ update() { // l, r, m\u306E\u5024\u3092\u9069\u5207\u306A\u3082\u306E\u306B\u66F4\
    \u65B0\u3059\u308B\n    if (n == 0) { l = r = m = loss = 0; return; }\n    int\
    \ bm = m;\n    if (l >= data[m]+r) {\n      int nm = std::prev(data.find(m))->first;\n\
    \      r += data[m];\n      l -= data[nm];\n      m = nm;\n    }\n    else if\
    \ (r > data[m]+l) {\n      auto it = std::next(data.find(m));\n      int nm =\
    \ std::next(data.find(m))->first;\n      l += data[m];\n      r -= data[nm];\n\
    \      m = nm;\n    }\n    if (data[bm] == 0) data.erase(bm);\n  }\n\n  int add(int\
    \ x)  {\n    int bm = m, bl = l, br = r, bc = data[bm];\n    ++data[x]; ++n;\n\
    \    if (x < m) ++l;\n    else if (x > m) ++r;\n    update();\n    if (n == 1)\
    \ return 0;\n    // cerr << \"[!]\" << bl << \" \" << br << \" \" << bm << \"\
    \ \" << m << endl;\n    int dloss = (br-bl)*(bm-m)+abs(m-bm)*bc+abs(x-m);\n  \
    \  loss += dloss;\n    return dloss;\n  }\n\n  int remove(int x) {\n    int bm\
    \ = m, bl = l, br = r, bc = data[bm];\n    if (x < bm) --bl;\n    else if (x ==\
    \ bm) --bc;\n    else --br;\n    --data[x]; --n;\n    if (data[x] == 0) data.erase(x);\n\
    \    if (x < m) --l;\n    else if (x > m) --r;\n    update();\n    // cerr <<\
    \ \"[!]\" << bl << \" \" << br << \" \" << bm << \" \" << m << \" \" << x << endl;\n\
    \    int dloss = (br-bl)*(m-bm)-abs(m-bm)*bc+abs(x-bm);\n    loss -= dloss;\n\
    \    return dloss;\n  }\n\n  int get() { return m; }\n\n  void show() {\n    std::cerr\
    \ << m << \" \" << n << \" \" << loss << std::endl;\n    for (auto it: data) {\n\
    \      std::cerr << it.first << \" \" << it.second << std::endl;\n    }\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/median-list.hpp
  requiredBy: []
  timestamp: '2020-08-30 21:34:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/median-list.hpp
layout: document
redirect_from:
- /library/datastructure/median-list.hpp
- /library/datastructure/median-list.hpp.html
title: "\u4E2D\u592E\u5024"
---
