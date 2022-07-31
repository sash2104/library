---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/hungarian.hpp
    title: "\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5\u306E\u7C21\u6613\u7684\
      \u306A\u30C6\u30B9\u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/math/hungarian.test.cpp\"\n// @title \u30CF\u30F3\u30AC\
    \u30EA\u30A2\u30F3\u6CD5\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\u30C8\n// dummy\
    \ problem\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#line 1 \"math/hungarian.hpp\"\n/**\n\
    \ * @title \u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5\n * @brief \u4E8C\u90E8\u30B0\
    \u30E9\u30D5\u306E\u6700\u5C0F\u91CD\u307F\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u3092\u8FD4\u3059\n * \u884C\u6570N, \u5217\u6570M\u3068\u3059\u308B\u3068\
    \u3001N <= M\u3092\u6E80\u305F\u3059\u5FC5\u8981\u304C\u3042\u308B\n * \u8A08\u7B97\
    \u91CF $O(N^2M)$\n * \u5143\uFF1Ahttps://ei1333.github.io/luzhiled/snippets/graph/hungarian.html\n\
    \ */\n#line 9 \"math/hungarian.hpp\"\n#include <vector>\n#include <limits>\n\n\
    template< typename T >\nstruct Hungarian {\n  const T INF;\n  const int N, M;\n\
    \  std::vector<std::vector<T>> A; // 1-indexed\n  std::vector<int> P, way, match;\
    \ // match[i]: = \u884Ci\u306E\u5272\u5F53\u5148\u306E\u5217\u756A\u53F7. 0-indexed\n\
    \  std::vector< T > U, V, minV;\n  std::vector<bool> used;\n  Hungarian(const\
    \ std::vector<std::vector<T>> &A_):\n    INF(std::numeric_limits<T>::max()), N(A_.size()+1),\
    \ M(A_[0].size()+1), A(N, std::vector<T>(M)), P(M), way(M), match(N-1),\n    U(N,\
    \ 0), V(M, 0), minV(M), used(M) {\n      for(int i = 0; i < N-1; ++i) {\n    \
    \    for (int j = 0; j < M-1; ++j) {\n          A[i+1][j+1] = A_[i][j];\n    \
    \    }\n      }\n  }\n  int get(int i) const {\n    // \u884Ci\u306E\u5272\u5F53\
    \u5148\u306E\u5217\u3092\u8FD4\u3059\n    return match[i];\n  }\n  T solve() {\n\
    \    for(int i = 1; i < N; i++) {\n      P[0] = i;\n      minV.assign(M, INF);\n\
    \      used.assign(M, false);\n      int j0 = 0;\n      while(P[j0] != 0) {\n\
    \        int i0 = P[j0], j1 = 0;\n        used[j0] = true;\n        T delta =\
    \ INF;\n        for(int j = 1; j < M; j++) {\n          if(used[j]) continue;\n\
    \          T curr = A[i0][j] - U[i0] - V[j];\n          if(curr < minV[j]) minV[j]\
    \ = curr, way[j] = j0;\n          if(minV[j] < delta) delta = minV[j], j1 = j;\n\
    \        }\n        for(int j = 0; j < M; j++) {\n          if(used[j]) U[P[j]]\
    \ += delta, V[j] -= delta;\n          else minV[j] -= delta;\n        }\n    \
    \    j0 = j1;\n      }\n      do {\n        P[j0] = P[way[j0]];\n        j0 =\
    \ way[j0];\n      } while(j0 != 0);\n    }\n    for(int j = 1; j < M; j++) {\n\
    \      if (P[j] == 0) continue;\n      match[P[j]-1] = j-1;\n    }\n    return\
    \ -V[0];\n  }\n};\n#line 7 \"test/math/hungarian.test.cpp\"\nusing namespace std;\n\
    \nvoid test_solve() {\n    // M > N\u3067\u3082\u52D5\u4F5C\u3059\u308B\u3053\u3068\
    \u306E\u78BA\u8A8D\u3068\u3057\u3066\u30010\u5217\u76EE\u306B\u306F\u7D76\u5BFE\
    \u306B\u4F7F\u308F\u308C\u306A\u3044\u5024\u3092\u8A2D\u5B9A\n    vector<vector<int>>\
    \ A = {\n        {99, 15, 6, 9, 8},\n        {99, 3, 13, 7, 6},\n        {99,\
    \ 9, 10, 5, 11},\n        {99, 3, 5, 7, 11},\n    };\n    Hungarian<int> hungarian(A);\n\
    \    // A[0][2]+A[1][4]+A[2][3]+A[3][1]\n    assert(20 == hungarian.solve());\n\
    \    // \u5404\u884C\u306B\u5272\u308A\u5F53\u3066\u3089\u308C\u305F\u5217\n \
    \   assert(2 == hungarian.get(0));\n    assert(4 == hungarian.get(1));\n    assert(3\
    \ == hungarian.get(2));\n    assert(1 == hungarian.get(3));\n}\n\nint main() {\n\
    \    test_solve();\n\n    // dummy output\n    cout << \"Hello World\" << endl;\n\
    }\n"
  code: "// @title \u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5\u306E\u7C21\u6613\u7684\
    \u306A\u30C6\u30B9\u30C8\n// dummy problem\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include \"../../math/hungarian.hpp\"\
    \nusing namespace std;\n\nvoid test_solve() {\n    // M > N\u3067\u3082\u52D5\u4F5C\
    \u3059\u308B\u3053\u3068\u306E\u78BA\u8A8D\u3068\u3057\u3066\u30010\u5217\u76EE\
    \u306B\u306F\u7D76\u5BFE\u306B\u4F7F\u308F\u308C\u306A\u3044\u5024\u3092\u8A2D\
    \u5B9A\n    vector<vector<int>> A = {\n        {99, 15, 6, 9, 8},\n        {99,\
    \ 3, 13, 7, 6},\n        {99, 9, 10, 5, 11},\n        {99, 3, 5, 7, 11},\n   \
    \ };\n    Hungarian<int> hungarian(A);\n    // A[0][2]+A[1][4]+A[2][3]+A[3][1]\n\
    \    assert(20 == hungarian.solve());\n    // \u5404\u884C\u306B\u5272\u308A\u5F53\
    \u3066\u3089\u308C\u305F\u5217\n    assert(2 == hungarian.get(0));\n    assert(4\
    \ == hungarian.get(1));\n    assert(3 == hungarian.get(2));\n    assert(1 == hungarian.get(3));\n\
    }\n\nint main() {\n    test_solve();\n\n    // dummy output\n    cout << \"Hello\
    \ World\" << endl;\n}"
  dependsOn:
  - math/hungarian.hpp
  isVerificationFile: true
  path: test/math/hungarian.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/hungarian.test.cpp
layout: document
redirect_from:
- /verify/test/math/hungarian.test.cpp
- /verify/test/math/hungarian.test.cpp.html
title: "\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5\u306E\u7C21\u6613\u7684\u306A\u30C6\
  \u30B9\u30C8"
---
