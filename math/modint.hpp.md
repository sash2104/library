---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/factorial.hpp
    title: "\u968E\u4E57\u3001nPr\u3001nCr"
  - icon: ':warning:'
    path: test/atcoder/abc129-f.cpp
    title: test/atcoder/abc129-f.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: mod int
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\n// @title mod int\n#include <iostream>\n\
    using ll = long long;\n\n#ifdef MUTABLE\nint mod;\n#else\ntemplate<int mod>\n\
    #endif\nstruct ModInt {\n  int val;\n  ModInt inv() const{\n    int tmp,a=val,b=mod,x=1,y=0;\n\
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
    using modint99 = ModInt<MOD99>;\n#endif\n"
  code: "// @title mod int\n#include <iostream>\nusing ll = long long;\n\n#ifdef MUTABLE\n\
    int mod;\n#else\ntemplate<int mod>\n#endif\nstruct ModInt {\n  int val;\n  ModInt\
    \ inv() const{\n    int tmp,a=val,b=mod,x=1,y=0;\n    while(b)tmp=a/b,a-=tmp*b,std::swap(a,b),x-=tmp*y,std::swap(x,y);\n\
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
    using modint99 = ModInt<MOD99>;\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy:
  - math/factorial.hpp
  - test/atcoder/abc129-f.cpp
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_B.test.cpp
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: mod int
---
