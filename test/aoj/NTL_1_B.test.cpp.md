---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n#line 1 \"math/modint.hpp\"\n// @title mod int\n#include <iostream>\nusing ll\
    \ = long long;\n\n#ifdef MUTABLE\nint mod;\n#else\ntemplate<int mod>\n#endif\n\
    struct ModInt {\n  int val;\n  ModInt inv() const{\n    int tmp,a=val,b=mod,x=1,y=0;\n\
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
    using modint99 = ModInt<MOD99>;\n#endif\n#line 3 \"test/aoj/NTL_1_B.test.cpp\"\
    \n\nusing namespace std;\nint main() {\n  int m, n;\n  cin >> m >> n;\n  modint\
    \ x(m);\n  modint ans = x.pow(n);\n  cout << ans.val << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n#include \"../../math/modint.hpp\"\n\nusing namespace std;\nint main() {\n \
    \ int m, n;\n  cin >> m >> n;\n  modint x(m);\n  modint ans = x.pow(n);\n  cout\
    \ << ans.val << endl;\n}\n"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
