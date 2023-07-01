---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/doubling.test.cpp
    title: "\u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\
      \u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30C0\u30D6\u30EA\u30F3\u30B0"
    links:
    - http://satanic0258.hatenablog.com/entry/2017/02/23/222647
    - https://atcoder.jp/contests/typical90/submissions/24345528
  bundledCode: "#line 1 \"datastructure/doubling.hpp\"\n\n\n/**\n * @title \u30C0\u30D6\
    \u30EA\u30F3\u30B0\n * @brief \u8981\u7D20\u6570M\u306E\u3042\u308B\u8981\u7D20\
    \u306B\u5BFE\u3059\u308BN\u500B\u5148\u306E\u8981\u7D20\u53D6\u5F97\u3092\u524D\
    \u51E6\u7406 $O(M\\log N)$\u3001\u53D6\u5F97$O(\\log N)$\u3067\u884C\u3046\n *\
    \ @see http://satanic0258.hatenablog.com/entry/2017/02/23/222647\n * @see https://atcoder.jp/contests/typical90/submissions/24345528\n\
    \ */\n#include <vector>\n\nstruct Doubling {\n    int N; // \u8981\u7D20\u6570\
    \ \n    // \u8FBF\u308B\u6DF1\u3055\u306E\u6700\u5927\u5024\u3002\u6700\u5927\u3067\
    Q\u500B\u5148\u307E\u3067\u898B\u308B\u5834\u5408`2^K > Q`\u3092\u6E80\u305F\u3059\
    \u3088\u3046\u306BK\u3092\u6C7A\u3081\u308B\n    // Q\u304Clong long\u306E\u7BC4\
    \u56F2\u3067\u3042\u308C\u3070\u3001K = 63\u3068\u3059\u308B\n    // FIXME: K\
    \ >= 64\u3060\u3068\u3001get\u306E(q>>k)\u304Coverflow\u3057\u3066\u53D6\u5F97\
    \u3059\u308B\u5024\u304C\u304A\u304B\u3057\u304F\u306A\u308B\n    int K;\n   \
    \ const int EMPTY;\n    // table[k][i]\u3067i\u756A\u76EE\u306E\u8981\u7D20\u306E\
    \u300C2^k\u500B\u5148\u306E\u8981\u7D20\u300D\u3092\u6307\u3059\n    // i\u756A\
    \u76EE\u306E\u8981\u7D20\u306B\u5BFE\u3057\u3066\u300C2^k\u500B\u5148\u306E\u8981\
    \u7D20\u300D\u304C\u5B58\u5728\u3057\u306A\u3044\u3068\u304D\u306F\n    // `table[k][i]\
    \ = EMPTY` \u3068\u306A\u308B\n    std::vector<std::vector<int>> table;\n\n  \
    \  Doubling(const std::vector<int>& next, int k): N(next.size()), K(k), EMPTY(-1)\
    \ {\n        init(next);\n    }\n    Doubling(const std::vector<int>& next): N(next.size()),\
    \ K(63), EMPTY(-1) {\n        init(next);\n    }\n\n    void init(const std::vector<int>&\
    \ next) {\n        table.push_back(next);\n        for (int k = 0; k < K; ++k)\
    \ { \n            table.push_back(std::vector<int>(N));\n            for (int\
    \ i = 0; i < N; ++i) {\n                if (table[k][i] == EMPTY) {\n        \
    \            // 2^k\u500B\u5148\u306B\u8981\u7D20\u304C\u7121\u3044\u5834\u5408\
    2^(k+1)\u500B\u5148\u306B\u3082\u8981\u7D20\u306F\u7121\u3044\n              \
    \      table[k+1][i] = EMPTY;\n                }\n                else {\n   \
    \                 // \u300C2^k\u500B\u5148\u306E\u8981\u7D20\u300D\u306E2^k\u500B\
    \u5148\u306E\u8981\u7D20\u306F2^(k+1)\u500B\u5148\u306E\u8981\u7D20\n        \
    \            table[k+1][i] = table[k][table[k][i]];\n                }\n     \
    \       }\n        }\n\n    }\n\n    // p\u756A\u76EE\u306E\u8981\u7D20\u306E\
    q\u500B\u5148\u306E\u8981\u7D20\n    // NOTE: \u5927\u304D\u3044\u6570\u3067\u7B54\
    \u3048\u304C\u5408\u308F\u306A\u304B\u3063\u305F\u3089\u3001overflow\u3092\u7591\
    \u3046\n    int get(int p, unsigned long long q) const {\n        for (int k =\
    \ K-1; k >= 0; --k) {\n            if (p == EMPTY) break;\n            if ((q\
    \ >> k) & 1ULL) {\n                // k\u756A\u76EE\u306E\u30D3\u30C3\u30C8\u304C\
    \u7ACB\u3063\u3066\u3044\u305F\u3089p\u306E\u4F4D\u7F6E\u30922^k\u5148\u306B\u3059\
    \u308B\n                p = table[k][p];\n            }\n        }\n        return\
    \ p;\n    }\n};\n\n\n"
  code: "#ifndef _DATASTRUCTURE_DOUBLING_\n#define _DATASTRUCTURE_DOUBLING_\n/**\n\
    \ * @title \u30C0\u30D6\u30EA\u30F3\u30B0\n * @brief \u8981\u7D20\u6570M\u306E\
    \u3042\u308B\u8981\u7D20\u306B\u5BFE\u3059\u308BN\u500B\u5148\u306E\u8981\u7D20\
    \u53D6\u5F97\u3092\u524D\u51E6\u7406 $O(M\\log N)$\u3001\u53D6\u5F97$O(\\log N)$\u3067\
    \u884C\u3046\n * @see http://satanic0258.hatenablog.com/entry/2017/02/23/222647\n\
    \ * @see https://atcoder.jp/contests/typical90/submissions/24345528\n */\n#include\
    \ <vector>\n\nstruct Doubling {\n    int N; // \u8981\u7D20\u6570 \n    // \u8FBF\
    \u308B\u6DF1\u3055\u306E\u6700\u5927\u5024\u3002\u6700\u5927\u3067Q\u500B\u5148\
    \u307E\u3067\u898B\u308B\u5834\u5408`2^K > Q`\u3092\u6E80\u305F\u3059\u3088\u3046\
    \u306BK\u3092\u6C7A\u3081\u308B\n    // Q\u304Clong long\u306E\u7BC4\u56F2\u3067\
    \u3042\u308C\u3070\u3001K = 63\u3068\u3059\u308B\n    // FIXME: K >= 64\u3060\u3068\
    \u3001get\u306E(q>>k)\u304Coverflow\u3057\u3066\u53D6\u5F97\u3059\u308B\u5024\u304C\
    \u304A\u304B\u3057\u304F\u306A\u308B\n    int K;\n    const int EMPTY;\n    //\
    \ table[k][i]\u3067i\u756A\u76EE\u306E\u8981\u7D20\u306E\u300C2^k\u500B\u5148\u306E\
    \u8981\u7D20\u300D\u3092\u6307\u3059\n    // i\u756A\u76EE\u306E\u8981\u7D20\u306B\
    \u5BFE\u3057\u3066\u300C2^k\u500B\u5148\u306E\u8981\u7D20\u300D\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u3068\u304D\u306F\n    // `table[k][i] = EMPTY` \u3068\u306A\
    \u308B\n    std::vector<std::vector<int>> table;\n\n    Doubling(const std::vector<int>&\
    \ next, int k): N(next.size()), K(k), EMPTY(-1) {\n        init(next);\n    }\n\
    \    Doubling(const std::vector<int>& next): N(next.size()), K(63), EMPTY(-1)\
    \ {\n        init(next);\n    }\n\n    void init(const std::vector<int>& next)\
    \ {\n        table.push_back(next);\n        for (int k = 0; k < K; ++k) { \n\
    \            table.push_back(std::vector<int>(N));\n            for (int i = 0;\
    \ i < N; ++i) {\n                if (table[k][i] == EMPTY) {\n               \
    \     // 2^k\u500B\u5148\u306B\u8981\u7D20\u304C\u7121\u3044\u5834\u54082^(k+1)\u500B\
    \u5148\u306B\u3082\u8981\u7D20\u306F\u7121\u3044\n                    table[k+1][i]\
    \ = EMPTY;\n                }\n                else {\n                    //\
    \ \u300C2^k\u500B\u5148\u306E\u8981\u7D20\u300D\u306E2^k\u500B\u5148\u306E\u8981\
    \u7D20\u306F2^(k+1)\u500B\u5148\u306E\u8981\u7D20\n                    table[k+1][i]\
    \ = table[k][table[k][i]];\n                }\n            }\n        }\n\n  \
    \  }\n\n    // p\u756A\u76EE\u306E\u8981\u7D20\u306Eq\u500B\u5148\u306E\u8981\u7D20\
    \n    // NOTE: \u5927\u304D\u3044\u6570\u3067\u7B54\u3048\u304C\u5408\u308F\u306A\
    \u304B\u3063\u305F\u3089\u3001overflow\u3092\u7591\u3046\n    int get(int p, unsigned\
    \ long long q) const {\n        for (int k = K-1; k >= 0; --k) {\n           \
    \ if (p == EMPTY) break;\n            if ((q >> k) & 1ULL) {\n               \
    \ // k\u756A\u76EE\u306E\u30D3\u30C3\u30C8\u304C\u7ACB\u3063\u3066\u3044\u305F\
    \u3089p\u306E\u4F4D\u7F6E\u30922^k\u5148\u306B\u3059\u308B\n                p\
    \ = table[k][p];\n            }\n        }\n        return p;\n    }\n};\n\n#endif\
    \ // _DATASTRUCTURE_DOUBLING_"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/doubling.hpp
  requiredBy: []
  timestamp: '2021-07-18 14:38:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/doubling.test.cpp
documentation_of: datastructure/doubling.hpp
layout: document
redirect_from:
- /library/datastructure/doubling.hpp
- /library/datastructure/doubling.hpp.html
title: "\u30C0\u30D6\u30EA\u30F3\u30B0"
---
