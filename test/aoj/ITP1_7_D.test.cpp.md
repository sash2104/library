---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.cpp
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
    \n#line 1 \"math/matrix.cpp\"\n// @title \u884C\u5217\n#include <cassert>\n#include\
    \ <iostream>\n#include <vector>\nusing namespace std;\n\ntemplate< class T >\n\
    struct Matrix {\n  const size_t H, W;\n  vector< vector< T > > A;\n  Matrix()\
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
    \      }\n    }\n    return (os);\n  }\n};\n#line 4 \"test/aoj/ITP1_7_D.test.cpp\"\
    \nusing namespace std;\n\nusing matrix = Matrix<long long>;\nint main() {\n  int\
    \ n, m, l; cin >> n >> m >> l;\n  matrix A(n, m), B(m, l);\n  for (int i = 0;\
    \ i < n; ++i) {\n    for (int j = 0; j < m; ++j) {\n      cin >> A[i][j];\n  \
    \  }\n  }\n  for (int i = 0; i < m; ++i) {\n    for (int j = 0; j < l; ++j) {\n\
    \      cin >> B[i][j];\n    }\n  }\n  matrix C = A*B;\n  for (int i = 0; i < n;\
    \ ++i) {\n    for (int j = 0; j < l; ++j) {\n      cout << C[i][j] << (j+1 ==\
    \ l ? \"\\n\":\" \");\n    }\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D\"\
    \n#include \"../../math/matrix.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nusing matrix = Matrix<long long>;\nint main() {\n  int n, m, l; cin >> n >>\
    \ m >> l;\n  matrix A(n, m), B(m, l);\n  for (int i = 0; i < n; ++i) {\n    for\
    \ (int j = 0; j < m; ++j) {\n      cin >> A[i][j];\n    }\n  }\n  for (int i =\
    \ 0; i < m; ++i) {\n    for (int j = 0; j < l; ++j) {\n      cin >> B[i][j];\n\
    \    }\n  }\n  matrix C = A*B;\n  for (int i = 0; i < n; ++i) {\n    for (int\
    \ j = 0; j < l; ++j) {\n      cout << C[i][j] << (j+1 == l ? \"\\n\":\" \");\n\
    \    }\n  }\n}"
  dependsOn:
  - math/matrix.cpp
  isVerificationFile: true
  path: test/aoj/ITP1_7_D.test.cpp
  requiredBy: []
  timestamp: '2020-08-30 21:21:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_7_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_7_D.test.cpp
- /verify/test/aoj/ITP1_7_D.test.cpp.html
title: test/aoj/ITP1_7_D.test.cpp
---
