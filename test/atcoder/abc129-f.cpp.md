---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: "\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/atcoder/abc129-f.cpp\"\n#include <cassert>\n#include\
    \ <cmath>\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n//\
    \ mod\u3092\u53EF\u5909\u306B\u3059\u308B\n#define MUTABLE\n\n#line 1 \"math/modint.hpp\"\
    \n// @title mod int\n#line 3 \"math/modint.hpp\"\nusing ll = long long;\n\n#ifdef\
    \ MUTABLE\nint mod;\n#else\ntemplate<int mod>\n#endif\nstruct ModInt {\n  int\
    \ val;\n  ModInt inv() const{\n    int tmp,a=val,b=mod,x=1,y=0;\n    while(b)tmp=a/b,a-=tmp*b,std::swap(a,b),x-=tmp*y,std::swap(x,y);\n\
    \    return ModInt(x);\n  }\n  ModInt():val(0){}\n  ModInt(ll x){if((val=x%mod)<0)val+=mod;}\n\
    \  ModInt pow(ll t){ModInt res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return\
    \ res;}\n  ModInt& operator+=(const ModInt& x){if((val+=x.val)>=mod)val-=mod;return\
    \ *this;}\n  ModInt& operator-=(const ModInt& x){if((val+=mod-x.val)>=mod)val-=mod;\
    \ return *this;}\n  ModInt& operator*=(const ModInt& x){val=(ll)val*x.val%mod;\
    \ return *this;}\n  ModInt& operator/=(const ModInt& x){return *this*=x.inv();}\n\
    \  bool operator==(const ModInt& x) const{return val==x.val;}\n  bool operator!=(const\
    \ ModInt& x) const{return val!=x.val;}\n  bool operator<(const ModInt& x) const{return\
    \ val<x.val;}\n  bool operator<=(const ModInt& x) const{return val<=x.val;}\n\
    \  bool operator>(const ModInt& x) const{return val>x.val;}\n  bool operator>=(const\
    \ ModInt& x) const{return val>=x.val;}\n  ModInt operator+(const ModInt& x) const{return\
    \ ModInt(*this)+=x;}\n  ModInt operator-(const ModInt& x) const{return ModInt(*this)-=x;}\n\
    \  ModInt operator*(const ModInt& x) const{return ModInt(*this)*=x;}\n  ModInt\
    \ operator/(const ModInt& x) const{return ModInt(*this)/=x;}\n  friend std::ostream&\
    \ operator<<(std::ostream& os, const ModInt& mi) { os << mi.val; return os; }\n\
    \  static int get_mod() { return mod; }\n};\n\nconstexpr int MOD10 = 1000000007;\n\
    constexpr int MOD99 =  998244353;\n#ifndef MUTABLE\nusing modint = ModInt<MOD10>;\n\
    using modint99 = ModInt<MOD99>;\n#endif\n#line 1 \"math/matrix.hpp\"\n// @title\
    \ \u884C\u5217\n// \u4F7F\u7528\u4F8B\uFF1Ahttps://atcoder.jp/contests/abc189/submissions/19676965\n\
    #line 6 \"math/matrix.hpp\"\n\ntemplate< class T >\nstruct Matrix {\n  int H,\
    \ W;\n  std::vector< std::vector< T > > A;\n  Matrix() {}\n  Matrix(int n, int\
    \ m) : H(n), W(m), A(H, std::vector< T >(W, 0)) {}\n  Matrix(int n) : H(n), W(n),\
    \ A(H, std::vector< T >(W, 0)) {};\n  Matrix(const std::vector<std::vector<T>>&\
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
    \      }\n    }\n    return (os);\n  }\n};\n#line 12 \"test/atcoder/abc129-f.cpp\"\
    \n\nusing namespace std;\ntypedef long long ll;\n\nusing matrix = Matrix<ModInt>;\n\
    \nint main() {\n  ll l, a, b, m;\n  cin >> l >> a >> b >> m;\n  mod = m;\n\n \
    \ // ld[i]\u306B\u3001i\u6841\u306E\u8981\u7D20\u6570\u3092\u683C\u7D0D\u3059\u308B\
    \n  vector<ll> ld0(19), ld(19);\n  for (int i = 0; i <= 18; ++i) {\n    ll x =\
    \ pow(10, i);\n    if (x <= a) continue;\n    ll d = (x-a+b-1)/b;\n    if (d >\
    \ l) ld0[i] = l;\n    else ld0[i] = d;\n    ld[i] = ld0[i];\n    if (i > 0) ld[i]\
    \ -= ld0[i-1];\n  }\n  matrix q(3);\n  q[0][0] = 1; q[1][1] = 1; q[2][2] = 1;\n\
    \  for (int i = 1; i <= 18; ++i) {\n    matrix p(3);\n    p[0][0] = pow(10, i);\
    \ p[0][1] = 0; p[0][2] = 0;\n    p[1][0] = 1;          p[1][1] = 1; p[2][2] =\
    \ 0;\n    p[2][0] = 0;          p[2][1] = b; p[2][2] = 1;\n    p ^= ld[i];\n \
    \   q *= p;\n  }\n  ModInt ans = q[1][0]*ModInt(a)+q[2][0];\n  cout << ans.val\
    \ << endl;\n}\n"
  code: "#include <cassert>\n#include <cmath>\n#include <algorithm>\n#include <iostream>\n\
    #include <vector>\n\n// mod\u3092\u53EF\u5909\u306B\u3059\u308B\n#define MUTABLE\n\
    \n#include \"../../math/modint.hpp\"\n#include \"../../math/matrix.hpp\"\n\nusing\
    \ namespace std;\ntypedef long long ll;\n\nusing matrix = Matrix<ModInt>;\n\n\
    int main() {\n  ll l, a, b, m;\n  cin >> l >> a >> b >> m;\n  mod = m;\n\n  //\
    \ ld[i]\u306B\u3001i\u6841\u306E\u8981\u7D20\u6570\u3092\u683C\u7D0D\u3059\u308B\
    \n  vector<ll> ld0(19), ld(19);\n  for (int i = 0; i <= 18; ++i) {\n    ll x =\
    \ pow(10, i);\n    if (x <= a) continue;\n    ll d = (x-a+b-1)/b;\n    if (d >\
    \ l) ld0[i] = l;\n    else ld0[i] = d;\n    ld[i] = ld0[i];\n    if (i > 0) ld[i]\
    \ -= ld0[i-1];\n  }\n  matrix q(3);\n  q[0][0] = 1; q[1][1] = 1; q[2][2] = 1;\n\
    \  for (int i = 1; i <= 18; ++i) {\n    matrix p(3);\n    p[0][0] = pow(10, i);\
    \ p[0][1] = 0; p[0][2] = 0;\n    p[1][0] = 1;          p[1][1] = 1; p[2][2] =\
    \ 0;\n    p[2][0] = 0;          p[2][1] = b; p[2][2] = 1;\n    p ^= ld[i];\n \
    \   q *= p;\n  }\n  ModInt ans = q[1][0]*ModInt(a)+q[2][0];\n  cout << ans.val\
    \ << endl;\n}\n"
  dependsOn:
  - math/modint.hpp
  - math/matrix.hpp
  isVerificationFile: false
  path: test/atcoder/abc129-f.cpp
  requiredBy: []
  timestamp: '2021-04-15 21:02:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc129-f.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc129-f.cpp
- /library/test/atcoder/abc129-f.cpp.html
title: test/atcoder/abc129-f.cpp
---
