---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/abc129-f.cpp
    title: test/atcoder/abc129-f.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_7_D.test.cpp
    title: test/aoj/ITP1_7_D.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u884C\u5217"
    links: []
  bundledCode: "#line 1 \"math/matrix.cpp\"\n// @title \u884C\u5217\n#include <cassert>\n\
    #include <iostream>\n#include <vector>\nusing namespace std;\n\ntemplate< class\
    \ T >\nstruct Matrix {\n  const size_t H, W;\n  vector< vector< T > > A;\n  Matrix()\
    \ {}\n  Matrix(size_t n, size_t m) : H(n), W(m), A(H, vector< T >(W, 0)) {}\n\
    \  Matrix(size_t n) : H(n), W(n), A(H, vector< T >(W, 0)) {};\n  size_t height()\
    \ const { return H; }\n  size_t width() const { return W; }\n  inline const vector<\
    \ T > &operator[](int k) const { return (A.at(k)); }\n  inline vector< T > &operator[](int\
    \ k) { return (A.at(k)); }\n  static Matrix I(size_t n) {\n    Matrix mat(n);\n\
    \    for(int i = 0; i < n; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix\
    \ &operator+=(const Matrix &B) {\n    assert(H == B.H && W == B.W);\n    for(int\
    \ i = 0; i < H; i++)\n      for(int j = 0; j < W; j++)\n        (*this)[i][j]\
    \ += B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B)\
    \ {\n    assert(H == B.H && W == B.W);\n    for(int i = 0; i < H; i++)\n     \
    \ for(int j = 0; j < W; j++)\n        (*this)[i][j] -= B[i][j];\n    return (*this);\n\
    \  }\n\n  Matrix &operator*=(const Matrix &B) {\n    assert(W == B.H);\n    vector<\
    \ vector< T > > C(H, vector< T >(B.W, 0));\n    for(int i = 0; i < H; i++)\n \
    \     for(int j = 0; j < B.W; j++)\n        for(int k = 0; k < W; k++)\n     \
    \     C[i][j] += ((*this)[i][k] * B[k][j]);\n    A.swap(C);\n    return (*this);\n\
    \  }\n\n  Matrix &operator^=(long long k) {\n    Matrix B = Matrix::I(H);\n  \
    \  while(k > 0) {\n      if(k & 1) B *= *this;\n      *this *= *this;\n      k\
    \ >>= 1LL;\n    }\n    A.swap(B.A);\n    return (*this);\n  }\n\n  Matrix operator+(const\
    \ Matrix &B) const { return (Matrix(*this) += B); }\n  Matrix operator-(const\
    \ Matrix &B) const { return (Matrix(*this) -= B); }\n  Matrix operator*(const\
    \ Matrix &B) const { return (Matrix(*this) *= B); }\n  Matrix operator^(const\
    \ long long k) const { return (Matrix(*this) ^= k); }\n\n  friend ostream &operator<<(ostream\
    \ &os, Matrix &p) {\n    for(int i = 0; i < p.H; i++) {\n      for(int j = 0;\
    \ j < p.W; j++) {\n        os << p[i][j] << (j + 1 == p.W ? \"\\n\" : \" \");\n\
    \      }\n    }\n    return (os);\n  }\n};\n"
  code: "// @title \u884C\u5217\n#include <cassert>\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate< class T >\nstruct Matrix {\n  const\
    \ size_t H, W;\n  vector< vector< T > > A;\n  Matrix() {}\n  Matrix(size_t n,\
    \ size_t m) : H(n), W(m), A(H, vector< T >(W, 0)) {}\n  Matrix(size_t n) : H(n),\
    \ W(n), A(H, vector< T >(W, 0)) {};\n  size_t height() const { return H; }\n \
    \ size_t width() const { return W; }\n  inline const vector< T > &operator[](int\
    \ k) const { return (A.at(k)); }\n  inline vector< T > &operator[](int k) { return\
    \ (A.at(k)); }\n  static Matrix I(size_t n) {\n    Matrix mat(n);\n    for(int\
    \ i = 0; i < n; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const\
    \ Matrix &B) {\n    assert(H == B.H && W == B.W);\n    for(int i = 0; i < H; i++)\n\
    \      for(int j = 0; j < W; j++)\n        (*this)[i][j] += B[i][j];\n    return\
    \ (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B) {\n    assert(H == B.H\
    \ && W == B.W);\n    for(int i = 0; i < H; i++)\n      for(int j = 0; j < W; j++)\n\
    \        (*this)[i][j] -= B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator*=(const\
    \ Matrix &B) {\n    assert(W == B.H);\n    vector< vector< T > > C(H, vector<\
    \ T >(B.W, 0));\n    for(int i = 0; i < H; i++)\n      for(int j = 0; j < B.W;\
    \ j++)\n        for(int k = 0; k < W; k++)\n          C[i][j] += ((*this)[i][k]\
    \ * B[k][j]);\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I(H);\n    while(k > 0) {\n      if(k & 1)\
    \ B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  friend ostream &operator<<(ostream &os, Matrix\
    \ &p) {\n    for(int i = 0; i < p.H; i++) {\n      for(int j = 0; j < p.W; j++)\
    \ {\n        os << p[i][j] << (j + 1 == p.W ? \"\\n\" : \" \");\n      }\n   \
    \ }\n    return (os);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy:
  - test/atcoder/abc129-f.cpp
  timestamp: '2020-08-30 21:21:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP1_7_D.test.cpp
documentation_of: math/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix.cpp
- /library/math/matrix.cpp.html
title: "\u884C\u5217"
---
