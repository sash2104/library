---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/factorial.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/factorial.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-08 10:49:15+09:00




## Depends on

* :heavy_check_mark: <a href="modint.cpp.html">math/modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include "modint.cpp"
using namespace std;

template <int mod>
struct Factorial {
  using mint = ModInt<mod>;
  vector<modint> Fact, Finv;
public:
  Factorial(int _n): Fact(_n+1), Finv(_n+1) {
      Fact[0]=mint(1); for (int i = 0; i < _n; ++i) Fact[i+1]=Fact[i]*(i+1);
      Finv[_n]=mint(1)/Fact[_n]; for (int i = _n; i > 0; --i) Finv[i-1]=Finv[i]*i;
  }
  mint fact(int n,bool inv=0) { if (inv) return Finv[n]; else return Fact[n]; }
  mint nPr(int n,int r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[n-r]; }
  mint nCr(int n,int r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[r]*Finv[n-r]; }
};

using factorial = Factorial<1000000007>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/factorial.cpp"
#include <vector>
#line 1 "math/modint.cpp"
#include <iostream>
using namespace std;
typedef long long ll;

#ifdef MUTABLE
int mod;
#else
template<int mod>
#endif
struct ModInt {
  int val;
  ModInt inv() const{
    int tmp,a=val,b=mod,x=1,y=0;
    while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
    return ModInt(x);
  }
  ModInt():val(0){}
  ModInt(ll x){if((val=x%mod)<0)val+=mod;}
  ModInt pow(ll t){ModInt res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}
  ModInt& operator+=(const ModInt& x){if((val+=x.val)>=mod)val-=mod;return *this;}
  ModInt& operator-=(const ModInt& x){if((val+=mod-x.val)>=mod)val-=mod; return *this;}
  ModInt& operator*=(const ModInt& x){val=(ll)val*x.val%mod; return *this;}
  ModInt& operator/=(const ModInt& x){return *this*=x.inv();}
  bool operator==(const ModInt& x) const{return val==x.val;}
  bool operator!=(const ModInt& x) const{return val!=x.val;}
  bool operator<(const ModInt& x) const{return val<x.val;}
  bool operator<=(const ModInt& x) const{return val<=x.val;}
  bool operator>(const ModInt& x) const{return val>x.val;}
  bool operator>=(const ModInt& x) const{return val>=x.val;}
  ModInt operator+(const ModInt& x) const{return ModInt(*this)+=x;}
  ModInt operator-(const ModInt& x) const{return ModInt(*this)-=x;}
  ModInt operator*(const ModInt& x) const{return ModInt(*this)*=x;}
  ModInt operator/(const ModInt& x) const{return ModInt(*this)/=x;}
  friend ostream& operator<<(ostream& os, const ModInt& mi) { os << mi.val; return os; }
  static int get_mod() { return mod; }
};

#ifndef MUTABLE
using modint = ModInt<1000000007>;
#endif
#line 3 "math/factorial.cpp"
using namespace std;

template <int mod>
struct Factorial {
  using mint = ModInt<mod>;
  vector<modint> Fact, Finv;
public:
  Factorial(int _n): Fact(_n+1), Finv(_n+1) {
      Fact[0]=mint(1); for (int i = 0; i < _n; ++i) Fact[i+1]=Fact[i]*(i+1);
      Finv[_n]=mint(1)/Fact[_n]; for (int i = _n; i > 0; --i) Finv[i-1]=Finv[i]*i;
  }
  mint fact(int n,bool inv=0) { if (inv) return Finv[n]; else return Fact[n]; }
  mint nPr(int n,int r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[n-r]; }
  mint nCr(int n,int r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[r]*Finv[n-r]; }
};

using factorial = Factorial<1000000007>;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

