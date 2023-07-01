---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6383\u304D\u51FA\u3057\u6CD5 (binary\u884C\u5217)"
    links:
    - https://atcoder.jp/contests/typical90/submissions/24717118
    - https://drken1215.hatenablog.com/entry/2019/03/20/202800
    - https://github.com/drken1215/algorithm/blob/2eadcda21d142c36a50774bee10465caaa4f8022/MathAlgebra/matrix_binary.cpp
  bundledCode: "#line 1 \"math/linear-equation-bin.hpp\"\n/**\n * @brief \u6383\u304D\
    \u51FA\u3057\u6CD5 (binary\u884C\u5217)\n * original: https://github.com/drken1215/algorithm/blob/2eadcda21d142c36a50774bee10465caaa4f8022/MathAlgebra/matrix_binary.cpp\n\
    \ * blog: https://drken1215.hatenablog.com/entry/2019/03/20/202800\n * \u4F7F\u7528\
    \u4F8B: https://atcoder.jp/contests/typical90/submissions/24717118\n */\n#include\
    \ <cassert>\n#include <iostream>\n#include <vector>\n#include <bitset>\n\nconst\
    \ int MAX_ROW = 510; // to be set appropriately\nconst int MAX_COL = 510; // to\
    \ be set appropriately\nstruct BitMatrix {\n    int H, W;\n    std::bitset<MAX_COL>\
    \ val[MAX_ROW];\n    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}\n    inline\
    \ std::bitset<MAX_COL>& operator [] (int i) {return val[i];}\n    inline friend\
    \ std::ostream& operator << (std::ostream& s, BitMatrix M) {\n        s << std::endl;\n\
    \        for (int i = 0; i < M.H; ++i) {\n            for (int j = 0; j < M.W;\
    \ ++j) s << M.val[i][j];\n            s << std::endl;\n        }\n        return\
    \ s;\n    }\n};\n\nint GaussJordan(BitMatrix &A, bool is_extended = false) {\n\
    \    int rank = 0;\n    for (int col = 0; col < A.W; ++col) {\n        if (is_extended\
    \ && col == A.W - 1) break;\n        int pivot = -1;\n        for (int row = rank;\
    \ row < A.H; ++row) {\n            if (A[row][col]) {\n                pivot =\
    \ row;\n                break;\n            }\n        }\n        if (pivot ==\
    \ -1) continue;\n        swap(A[pivot], A[rank]);\n        for (int row = 0; row\
    \ < A.H; ++row) {\n            if (row != rank && A[row][col]) A[row] ^= A[rank];\n\
    \        }\n        ++rank;\n    }\n    return rank;\n}\n\nint linear_equation(BitMatrix\
    \ &A, std::vector<int> &b, std::vector<int> &res) {\n    int m = A.H, n = A.W;\n\
    \    assert(m == (int)b.size());\n    BitMatrix M(m, n + 1);\n    for (int i =\
    \ 0; i < m; ++i) {\n        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];\n \
    \       M[i][n] = b[i];\n    }\n    int rank = GaussJordan(M, true);\n\n    //\
    \ check if it has no solution\n    for (int row = rank; row < m; ++row) if (M[row][n])\
    \ return -1;\n\n    // answer\n    res.assign(n, 0);\n    for (int i = 0; i <\
    \ rank; ++i) res[i] = M[i][n];\n    return rank;\n}\n"
  code: "/**\n * @brief \u6383\u304D\u51FA\u3057\u6CD5 (binary\u884C\u5217)\n * original:\
    \ https://github.com/drken1215/algorithm/blob/2eadcda21d142c36a50774bee10465caaa4f8022/MathAlgebra/matrix_binary.cpp\n\
    \ * blog: https://drken1215.hatenablog.com/entry/2019/03/20/202800\n * \u4F7F\u7528\
    \u4F8B: https://atcoder.jp/contests/typical90/submissions/24717118\n */\n#include\
    \ <cassert>\n#include <iostream>\n#include <vector>\n#include <bitset>\n\nconst\
    \ int MAX_ROW = 510; // to be set appropriately\nconst int MAX_COL = 510; // to\
    \ be set appropriately\nstruct BitMatrix {\n    int H, W;\n    std::bitset<MAX_COL>\
    \ val[MAX_ROW];\n    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}\n    inline\
    \ std::bitset<MAX_COL>& operator [] (int i) {return val[i];}\n    inline friend\
    \ std::ostream& operator << (std::ostream& s, BitMatrix M) {\n        s << std::endl;\n\
    \        for (int i = 0; i < M.H; ++i) {\n            for (int j = 0; j < M.W;\
    \ ++j) s << M.val[i][j];\n            s << std::endl;\n        }\n        return\
    \ s;\n    }\n};\n\nint GaussJordan(BitMatrix &A, bool is_extended = false) {\n\
    \    int rank = 0;\n    for (int col = 0; col < A.W; ++col) {\n        if (is_extended\
    \ && col == A.W - 1) break;\n        int pivot = -1;\n        for (int row = rank;\
    \ row < A.H; ++row) {\n            if (A[row][col]) {\n                pivot =\
    \ row;\n                break;\n            }\n        }\n        if (pivot ==\
    \ -1) continue;\n        swap(A[pivot], A[rank]);\n        for (int row = 0; row\
    \ < A.H; ++row) {\n            if (row != rank && A[row][col]) A[row] ^= A[rank];\n\
    \        }\n        ++rank;\n    }\n    return rank;\n}\n\nint linear_equation(BitMatrix\
    \ &A, std::vector<int> &b, std::vector<int> &res) {\n    int m = A.H, n = A.W;\n\
    \    assert(m == (int)b.size());\n    BitMatrix M(m, n + 1);\n    for (int i =\
    \ 0; i < m; ++i) {\n        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];\n \
    \       M[i][n] = b[i];\n    }\n    int rank = GaussJordan(M, true);\n\n    //\
    \ check if it has no solution\n    for (int row = rank; row < m; ++row) if (M[row][n])\
    \ return -1;\n\n    // answer\n    res.assign(n, 0);\n    for (int i = 0; i <\
    \ rank; ++i) res[i] = M[i][n];\n    return rank;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/linear-equation-bin.hpp
  requiredBy: []
  timestamp: '2021-08-01 20:13:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/linear-equation-bin.hpp
layout: document
redirect_from:
- /library/math/linear-equation-bin.hpp
- /library/math/linear-equation-bin.hpp.html
title: "\u6383\u304D\u51FA\u3057\u6CD5 (binary\u884C\u5217)"
---
