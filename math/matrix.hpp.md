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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u884C\u5217"
    links:
    - https://atcoder.jp/contests/abc189/submissions/19676965
  bundledCode: "#line 1 \"math/matrix.hpp\"\n// @title \u884C\u5217\n// \u4F7F\u7528\
    \u4F8B\uFF1Ahttps://atcoder.jp/contests/abc189/submissions/19676965\n#include\
    \ <cassert>\n#include <iostream>\n#include <vector>\n\ntemplate< class T >\nstruct\
    \ Matrix {\n  int H, W;\n  std::vector< std::vector< T > > A;\n  Matrix() {}\n\
    \  Matrix(int n, int m) : H(n), W(m), A(H, std::vector< T >(W, 0)) {}\n  Matrix(int\
    \ n) : H(n), W(n), A(H, std::vector< T >(W, 0)) {};\n  Matrix(const std::vector<std::vector<T>>&\
    \ a) : A(a) {\n      H = (int)a.size();\n      assert(H > 0);\n      W = (int)a[0].size();\n\
    \  }\n  int height() const { return H; }\n  int width() const { return W; }\n\
    \  inline const std::vector< T > &operator[](int k) const { return (A.at(k));\
    \ }\n  inline std::vector< T > &operator[](int k) { return (A.at(k)); }\n  static\
    \ Matrix I(int n) {\n    Matrix mat(n);\n    for(int i = 0; i < n; i++) mat[i][i]\
    \ = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const Matrix &B) {\n  \
    \  assert(H == B.H && W == B.W);\n    for(int i = 0; i < H; i++)\n      for(int\
    \ j = 0; j < W; j++)\n        (*this)[i][j] += B[i][j];\n    return (*this);\n\
    \  }\n\n  Matrix &operator-=(const Matrix &B) {\n    assert(H == B.H && W == B.W);\n\
    \    for(int i = 0; i < H; i++)\n      for(int j = 0; j < W; j++)\n        (*this)[i][j]\
    \ -= B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator*=(const Matrix &B)\
    \ {\n    assert(W == B.H);\n    std::vector< std::vector< T > > C(H, std::vector<\
    \ T >(B.W, 0));\n    for(int i = 0; i < H; i++)\n      for(int j = 0; j < B.W;\
    \ j++)\n        for(int k = 0; k < W; k++)\n          C[i][j] += ((*this)[i][k]\
    \ * B[k][j]);\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I(H);\n    while(k > 0) {\n      if(k & 1)\
    \ B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  std::vector<T> operator*(const std::vector<T> &v)\
    \ {\n    assert(W == (int)v.size());\n    std::vector<T> ret(H, 0);\n    for(int\
    \ i = 0; i < H; i++)\n      for(int j = 0; j < W; j++)\n        ret[i] += ((*this)[i][j]\
    \ * v[j]);\n    return ret;\n  }\n\n  Matrix operator+(const Matrix &B) const\
    \ { return (Matrix(*this) += B); }\n  Matrix operator-(const Matrix &B) const\
    \ { return (Matrix(*this) -= B); }\n  Matrix operator*(const Matrix &B) const\
    \ { return (Matrix(*this) *= B); }\n  Matrix operator^(const long long k) const\
    \ { return (Matrix(*this) ^= k); }\n\n  friend std::ostream &operator<<(std::ostream\
    \ &os, Matrix &p) {\n    for(int i = 0; i < p.H; i++) {\n      for(int j = 0;\
    \ j < p.W; j++) {\n        os << p[i][j] << (j + 1 == p.W ? \"\\n\" : \" \");\n\
    \      }\n    }\n    return (os);\n  }\n};\n"
  code: "// @title \u884C\u5217\n// \u4F7F\u7528\u4F8B\uFF1Ahttps://atcoder.jp/contests/abc189/submissions/19676965\n\
    #include <cassert>\n#include <iostream>\n#include <vector>\n\ntemplate< class\
    \ T >\nstruct Matrix {\n  int H, W;\n  std::vector< std::vector< T > > A;\n  Matrix()\
    \ {}\n  Matrix(int n, int m) : H(n), W(m), A(H, std::vector< T >(W, 0)) {}\n \
    \ Matrix(int n) : H(n), W(n), A(H, std::vector< T >(W, 0)) {};\n  Matrix(const\
    \ std::vector<std::vector<T>>& a) : A(a) {\n      H = (int)a.size();\n      assert(H\
    \ > 0);\n      W = (int)a[0].size();\n  }\n  int height() const { return H; }\n\
    \  int width() const { return W; }\n  inline const std::vector< T > &operator[](int\
    \ k) const { return (A.at(k)); }\n  inline std::vector< T > &operator[](int k)\
    \ { return (A.at(k)); }\n  static Matrix I(int n) {\n    Matrix mat(n);\n    for(int\
    \ i = 0; i < n; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const\
    \ Matrix &B) {\n    assert(H == B.H && W == B.W);\n    for(int i = 0; i < H; i++)\n\
    \      for(int j = 0; j < W; j++)\n        (*this)[i][j] += B[i][j];\n    return\
    \ (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B) {\n    assert(H == B.H\
    \ && W == B.W);\n    for(int i = 0; i < H; i++)\n      for(int j = 0; j < W; j++)\n\
    \        (*this)[i][j] -= B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator*=(const\
    \ Matrix &B) {\n    assert(W == B.H);\n    std::vector< std::vector< T > > C(H,\
    \ std::vector< T >(B.W, 0));\n    for(int i = 0; i < H; i++)\n      for(int j\
    \ = 0; j < B.W; j++)\n        for(int k = 0; k < W; k++)\n          C[i][j] +=\
    \ ((*this)[i][k] * B[k][j]);\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix\
    \ &operator^=(long long k) {\n    Matrix B = Matrix::I(H);\n    while(k > 0) {\n\
    \      if(k & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n\
    \    A.swap(B.A);\n    return (*this);\n  }\n\n  std::vector<T> operator*(const\
    \ std::vector<T> &v) {\n    assert(W == (int)v.size());\n    std::vector<T> ret(H,\
    \ 0);\n    for(int i = 0; i < H; i++)\n      for(int j = 0; j < W; j++)\n    \
    \    ret[i] += ((*this)[i][j] * v[j]);\n    return ret;\n  }\n\n  Matrix operator+(const\
    \ Matrix &B) const { return (Matrix(*this) += B); }\n  Matrix operator-(const\
    \ Matrix &B) const { return (Matrix(*this) -= B); }\n  Matrix operator*(const\
    \ Matrix &B) const { return (Matrix(*this) *= B); }\n  Matrix operator^(const\
    \ long long k) const { return (Matrix(*this) ^= k); }\n\n  friend std::ostream\
    \ &operator<<(std::ostream &os, Matrix &p) {\n    for(int i = 0; i < p.H; i++)\
    \ {\n      for(int j = 0; j < p.W; j++) {\n        os << p[i][j] << (j + 1 ==\
    \ p.W ? \"\\n\" : \" \");\n      }\n    }\n    return (os);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy:
  - test/atcoder/abc129-f.cpp
  timestamp: '2021-04-15 20:33:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP1_7_D.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: "\u884C\u5217"
---
