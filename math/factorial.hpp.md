---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u968E\u4E57\u3001nPr\u3001nCr"
    links: []
  bundledCode: "#line 1 \"math/factorial.hpp\"\n// @title \u968E\u4E57\u3001nPr\u3001\
    nCr\n#include <vector>\n#line 1 \"math/modint.hpp\"\n// @title mod int\n#include\
    \ <iostream>\nusing ll = long long;\n\n#ifdef MUTABLE\nint mod;\n#else\ntemplate<int\
    \ mod>\n#endif\nstruct ModInt {\n  int val;\n  ModInt inv() const{\n    int tmp,a=val,b=mod,x=1,y=0;\n\
    \    while(b)tmp=a/b,a-=tmp*b,std::swap(a,b),x-=tmp*y,std::swap(x,y);\n    return\
    \ ModInt(x);\n  }\n  ModInt():val(0){}\n  ModInt(ll x){if((val=x%mod)<0)val+=mod;}\n\
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
    using modint99 = ModInt<MOD99>;\n#endif\n#line 4 \"math/factorial.hpp\"\n\ntemplate\
    \ <int mod>\nstruct Factorial {\n  using mint = ModInt<mod>;\n  std::vector<mint>\
    \ Fact, Finv;\npublic:\n  Factorial(int _n): Fact(_n+1), Finv(_n+1) {\n      Fact[0]=mint(1);\
    \ for (int i = 0; i < _n; ++i) Fact[i+1]=Fact[i]*(i+1);\n      Finv[_n]=mint(1)/Fact[_n];\
    \ for (int i = _n; i > 0; --i) Finv[i-1]=Finv[i]*i;\n  }\n  mint fact(int n,bool\
    \ inv=0) { if (inv) return Finv[n]; else return Fact[n]; }\n  mint nPr(int n,int\
    \ r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[n-r]; }\n  mint\
    \ nCr(int n,int r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[r]*Finv[n-r];\
    \ }\n};\n\nusing factorial = Factorial<MOD10>;\nusing factorial99 = Factorial<MOD99>;\n"
  code: "// @title \u968E\u4E57\u3001nPr\u3001nCr\n#include <vector>\n#include \"\
    modint.hpp\"\n\ntemplate <int mod>\nstruct Factorial {\n  using mint = ModInt<mod>;\n\
    \  std::vector<mint> Fact, Finv;\npublic:\n  Factorial(int _n): Fact(_n+1), Finv(_n+1)\
    \ {\n      Fact[0]=mint(1); for (int i = 0; i < _n; ++i) Fact[i+1]=Fact[i]*(i+1);\n\
    \      Finv[_n]=mint(1)/Fact[_n]; for (int i = _n; i > 0; --i) Finv[i-1]=Finv[i]*i;\n\
    \  }\n  mint fact(int n,bool inv=0) { if (inv) return Finv[n]; else return Fact[n];\
    \ }\n  mint nPr(int n,int r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[n-r];\
    \ }\n  mint nCr(int n,int r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[r]*Finv[n-r];\
    \ }\n};\n\nusing factorial = Factorial<MOD10>;\nusing factorial99 = Factorial<MOD99>;\n"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/factorial.hpp
  requiredBy: []
  timestamp: '2021-04-15 20:33:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorial.hpp
layout: document
redirect_from:
- /library/math/factorial.hpp
- /library/math/factorial.hpp.html
title: "\u968E\u4E57\u3001nPr\u3001nCr"
---
