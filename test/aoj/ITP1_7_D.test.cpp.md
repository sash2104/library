---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: "\u884C\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D
  bundledCode: "#line 1 \"test/aoj/ITP1_7_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D\"\
    \n#line 1 \"math/matrix.hpp\"\n// @title \u884C\u5217\n// \u4F7F\u7528\u4F8B\uFF1A\
    https://atcoder.jp/contests/abc189/submissions/19676965\n#include <cassert>\n\
    #include <iostream>\n#include <vector>\n\ntemplate< class T >\nstruct Matrix {\n\
    \  int H, W;\n  std::vector< std::vector< T > > A;\n  Matrix() {}\n  Matrix(int\
    \ n, int m) : H(n), W(m), A(H, std::vector< T >(W, 0)) {}\n  Matrix(int n) : H(n),\
    \ W(n), A(H, std::vector< T >(W, 0)) {};\n  Matrix(const std::vector<std::vector<T>>&\
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
    \      }\n    }\n    return (os);\n  }\n};\n#line 4 \"test/aoj/ITP1_7_D.test.cpp\"\
    \nusing namespace std;\n\nusing matrix = Matrix<long long>;\nint main() {\n  int\
    \ n, m, l; cin >> n >> m >> l;\n  matrix A(n, m), B(m, l);\n  for (int i = 0;\
    \ i < n; ++i) {\n    for (int j = 0; j < m; ++j) {\n      cin >> A[i][j];\n  \
    \  }\n  }\n  for (int i = 0; i < m; ++i) {\n    for (int j = 0; j < l; ++j) {\n\
    \      cin >> B[i][j];\n    }\n  }\n  matrix C = A*B;\n  for (int i = 0; i < n;\
    \ ++i) {\n    for (int j = 0; j < l; ++j) {\n      cout << C[i][j] << (j+1 ==\
    \ l ? \"\\n\":\" \");\n    }\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D\"\
    \n#include \"../../math/matrix.hpp\"\n#include <iostream>\nusing namespace std;\n\
    \nusing matrix = Matrix<long long>;\nint main() {\n  int n, m, l; cin >> n >>\
    \ m >> l;\n  matrix A(n, m), B(m, l);\n  for (int i = 0; i < n; ++i) {\n    for\
    \ (int j = 0; j < m; ++j) {\n      cin >> A[i][j];\n    }\n  }\n  for (int i =\
    \ 0; i < m; ++i) {\n    for (int j = 0; j < l; ++j) {\n      cin >> B[i][j];\n\
    \    }\n  }\n  matrix C = A*B;\n  for (int i = 0; i < n; ++i) {\n    for (int\
    \ j = 0; j < l; ++j) {\n      cout << C[i][j] << (j+1 == l ? \"\\n\":\" \");\n\
    \    }\n  }\n}"
  dependsOn:
  - math/matrix.hpp
  isVerificationFile: true
  path: test/aoj/ITP1_7_D.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_7_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_7_D.test.cpp
- /verify/test/aoj/ITP1_7_D.test.cpp.html
title: test/aoj/ITP1_7_D.test.cpp
---
