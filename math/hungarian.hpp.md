---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/hungarian.test.cpp
    title: "\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5\u306E\u7C21\u6613\u7684\u306A\
      \u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5"
    links:
    - https://ei1333.github.io/luzhiled/snippets/graph/hungarian.html
  bundledCode: "#line 1 \"math/hungarian.hpp\"\n/**\n * @title \u30CF\u30F3\u30AC\u30EA\
    \u30A2\u30F3\u6CD5\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\
    \u91CD\u307F\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u8FD4\u3059\n * \u884C\
    \u6570N, \u5217\u6570M\u3068\u3059\u308B\u3068\u3001N <= M\u3092\u6E80\u305F\u3059\
    \u5FC5\u8981\u304C\u3042\u308B\n * \u8A08\u7B97\u91CF $O(N^2M)$\n * \u5143\uFF1A\
    https://ei1333.github.io/luzhiled/snippets/graph/hungarian.html\n */\n#include\
    \ <cassert>\n#include <vector>\n#include <limits>\n\ntemplate< typename T >\n\
    struct Hungarian {\n  const T INF;\n  const int N, M;\n  std::vector<std::vector<T>>\
    \ A; // 1-indexed\n  std::vector<int> P, way, match; // match[i]: = \u884Ci\u306E\
    \u5272\u5F53\u5148\u306E\u5217\u756A\u53F7. 0-indexed\n  std::vector< T > U, V,\
    \ minV;\n  std::vector<bool> used;\n  Hungarian(const std::vector<std::vector<T>>\
    \ &A_):\n    INF(std::numeric_limits<T>::max()), N(A_.size()+1), M(A_[0].size()+1),\
    \ A(N, std::vector<T>(M)), P(M), way(M), match(N-1),\n    U(N, 0), V(M, 0), minV(M),\
    \ used(M) {\n      for(int i = 0; i < N-1; ++i) {\n        for (int j = 0; j <\
    \ M-1; ++j) {\n          A[i+1][j+1] = A_[i][j];\n        }\n      }\n  }\n  int\
    \ get(int i) const {\n    // \u884Ci\u306E\u5272\u5F53\u5148\u306E\u5217\u3092\
    \u8FD4\u3059\n    return match[i];\n  }\n  T solve() {\n    for(int i = 1; i <\
    \ N; i++) {\n      P[0] = i;\n      minV.assign(M, INF);\n      used.assign(M,\
    \ false);\n      int j0 = 0;\n      while(P[j0] != 0) {\n        int i0 = P[j0],\
    \ j1 = 0;\n        used[j0] = true;\n        T delta = INF;\n        for(int j\
    \ = 1; j < M; j++) {\n          if(used[j]) continue;\n          T curr = A[i0][j]\
    \ - U[i0] - V[j];\n          if(curr < minV[j]) minV[j] = curr, way[j] = j0;\n\
    \          if(minV[j] < delta) delta = minV[j], j1 = j;\n        }\n        for(int\
    \ j = 0; j < M; j++) {\n          if(used[j]) U[P[j]] += delta, V[j] -= delta;\n\
    \          else minV[j] -= delta;\n        }\n        j0 = j1;\n      }\n    \
    \  do {\n        P[j0] = P[way[j0]];\n        j0 = way[j0];\n      } while(j0\
    \ != 0);\n    }\n    for(int j = 1; j < M; j++) {\n      if (P[j] == 0) continue;\n\
    \      match[P[j]-1] = j-1;\n    }\n    return -V[0];\n  }\n};\n"
  code: "/**\n * @title \u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5\n * @brief \u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u91CD\u307F\u6700\u5927\u30DE\u30C3\
    \u30C1\u30F3\u30B0\u3092\u8FD4\u3059\n * \u884C\u6570N, \u5217\u6570M\u3068\u3059\
    \u308B\u3068\u3001N <= M\u3092\u6E80\u305F\u3059\u5FC5\u8981\u304C\u3042\u308B\
    \n * \u8A08\u7B97\u91CF $O(N^2M)$\n * \u5143\uFF1Ahttps://ei1333.github.io/luzhiled/snippets/graph/hungarian.html\n\
    \ */\n#include <cassert>\n#include <vector>\n#include <limits>\n\ntemplate< typename\
    \ T >\nstruct Hungarian {\n  const T INF;\n  const int N, M;\n  std::vector<std::vector<T>>\
    \ A; // 1-indexed\n  std::vector<int> P, way, match; // match[i]: = \u884Ci\u306E\
    \u5272\u5F53\u5148\u306E\u5217\u756A\u53F7. 0-indexed\n  std::vector< T > U, V,\
    \ minV;\n  std::vector<bool> used;\n  Hungarian(const std::vector<std::vector<T>>\
    \ &A_):\n    INF(std::numeric_limits<T>::max()), N(A_.size()+1), M(A_[0].size()+1),\
    \ A(N, std::vector<T>(M)), P(M), way(M), match(N-1),\n    U(N, 0), V(M, 0), minV(M),\
    \ used(M) {\n      for(int i = 0; i < N-1; ++i) {\n        for (int j = 0; j <\
    \ M-1; ++j) {\n          A[i+1][j+1] = A_[i][j];\n        }\n      }\n  }\n  int\
    \ get(int i) const {\n    // \u884Ci\u306E\u5272\u5F53\u5148\u306E\u5217\u3092\
    \u8FD4\u3059\n    return match[i];\n  }\n  T solve() {\n    for(int i = 1; i <\
    \ N; i++) {\n      P[0] = i;\n      minV.assign(M, INF);\n      used.assign(M,\
    \ false);\n      int j0 = 0;\n      while(P[j0] != 0) {\n        int i0 = P[j0],\
    \ j1 = 0;\n        used[j0] = true;\n        T delta = INF;\n        for(int j\
    \ = 1; j < M; j++) {\n          if(used[j]) continue;\n          T curr = A[i0][j]\
    \ - U[i0] - V[j];\n          if(curr < minV[j]) minV[j] = curr, way[j] = j0;\n\
    \          if(minV[j] < delta) delta = minV[j], j1 = j;\n        }\n        for(int\
    \ j = 0; j < M; j++) {\n          if(used[j]) U[P[j]] += delta, V[j] -= delta;\n\
    \          else minV[j] -= delta;\n        }\n        j0 = j1;\n      }\n    \
    \  do {\n        P[j0] = P[way[j0]];\n        j0 = way[j0];\n      } while(j0\
    \ != 0);\n    }\n    for(int j = 1; j < M; j++) {\n      if (P[j] == 0) continue;\n\
    \      match[P[j]-1] = j-1;\n    }\n    return -V[0];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/hungarian.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/hungarian.test.cpp
documentation_of: math/hungarian.hpp
layout: document
redirect_from:
- /library/math/hungarian.hpp
- /library/math/hungarian.hpp.html
title: "\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5"
---
