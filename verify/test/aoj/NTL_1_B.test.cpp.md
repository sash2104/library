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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/NTL_1_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-21 20:28:54+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/modint.cpp.html">math/modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "../../math/modint.cpp"

int main() {
  int m, n;
  cin >> m >> n;
  modint x(m);
  modint ans = x.pow(n);
  cout << ans.val << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#line 1 "test/aoj/../../math/modint.cpp"
#include <iostream>
using namespace std;
typedef long long ll;

template<int mod>
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
  static int get_mod() { return mod; }
};

using modint = ModInt<1000000007>;
#line 3 "test/aoj/NTL_1_B.test.cpp"

int main() {
  int m, n;
  cin >> m >> n;
  modint x(m);
  modint ans = x.pow(n);
  cout << ans.val << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

