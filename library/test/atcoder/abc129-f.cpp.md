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


# :warning: test/atcoder/abc129-f.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e8ba03245cc911ba95395348d53122a0">test/atcoder</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/atcoder/abc129-f.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-08 10:49:15+09:00




## Depends on

* :heavy_check_mark: <a href="../../math/matrix.cpp.html">math/matrix.cpp</a>
* :heavy_check_mark: <a href="../../math/modint.cpp.html">math/modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

// modを可変にする
#define MUTABLE

#include "../../math/modint.cpp"
#include "../../math/matrix.cpp"

using namespace std;
typedef long long ll;

using matrix = Matrix<ModInt>;

int main() {
  ll l, a, b, m;
  cin >> l >> a >> b >> m;
  mod = m;

  // ld[i]に、i桁の要素数を格納する
  vector<ll> ld0(19), ld(19);
  for (int i = 0; i <= 18; ++i) {
    ll x = pow(10, i);
    if (x <= a) continue;
    ll d = (x-a+b-1)/b;
    if (d > l) ld0[i] = l;
    else ld0[i] = d;
    ld[i] = ld0[i];
    if (i > 0) ld[i] -= ld0[i-1];
  }
  matrix q(3);
  q[0][0] = 1; q[1][1] = 1; q[2][2] = 1;
  for (int i = 1; i <= 18; ++i) {
    matrix p(3);
    p[0][0] = pow(10, i); p[0][1] = 0; p[0][2] = 0;
    p[1][0] = 1;          p[1][1] = 1; p[2][2] = 0;
    p[2][0] = 0;          p[2][1] = b; p[2][2] = 1;
    p ^= ld[i];
    q *= p;
  }
  ModInt ans = q[1][0]*ModInt(a)+q[2][0];
  cout << ans.val << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/atcoder/abc129-f.cpp"
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

// modを可変にする
#define MUTABLE

#line 2 "math/modint.cpp"
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
#line 4 "math/matrix.cpp"
using namespace std;

template< class T >
struct Matrix {
  const size_t H, W;
  vector< vector< T > > A;
  Matrix() {}
  Matrix(size_t n, size_t m) : H(n), W(m), A(H, vector< T >(W, 0)) {}
  Matrix(size_t n) : H(n), W(n), A(H, vector< T >(W, 0)) {};
  size_t height() const { return H; }
  size_t width() const { return W; }
  inline const vector< T > &operator[](int k) const { return (A.at(k)); }
  inline vector< T > &operator[](int k) { return (A.at(k)); }
  static Matrix I(size_t n) {
    Matrix mat(n);
    for(int i = 0; i < n; i++) mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B) {
    assert(H == B.H && W == B.W);
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
        (*this)[i][j] += B[i][j];
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    assert(H == B.H && W == B.W);
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
        (*this)[i][j] -= B[i][j];
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    assert(W == B.H);
    vector< vector< T > > C(H, vector< T >(B.W, 0));
    for(int i = 0; i < H; i++)
      for(int j = 0; j < B.W; j++)
        for(int k = 0; k < W; k++)
          C[i][j] += ((*this)[i][k] * B[k][j]);
    A.swap(C);
    return (*this);
  }

  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I(H);
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }
  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }
  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }
  Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

  friend ostream &operator<<(ostream &os, Matrix &p) {
    for(int i = 0; i < p.H; i++) {
      for(int j = 0; j < p.W; j++) {
        os << p[i][j] << (j + 1 == p.W ? "\n" : " ");
      }
    }
    return (os);
  }
};
#line 12 "test/atcoder/abc129-f.cpp"

using namespace std;
typedef long long ll;

using matrix = Matrix<ModInt>;

int main() {
  ll l, a, b, m;
  cin >> l >> a >> b >> m;
  mod = m;

  // ld[i]に、i桁の要素数を格納する
  vector<ll> ld0(19), ld(19);
  for (int i = 0; i <= 18; ++i) {
    ll x = pow(10, i);
    if (x <= a) continue;
    ll d = (x-a+b-1)/b;
    if (d > l) ld0[i] = l;
    else ld0[i] = d;
    ld[i] = ld0[i];
    if (i > 0) ld[i] -= ld0[i-1];
  }
  matrix q(3);
  q[0][0] = 1; q[1][1] = 1; q[2][2] = 1;
  for (int i = 1; i <= 18; ++i) {
    matrix p(3);
    p[0][0] = pow(10, i); p[0][1] = 0; p[0][2] = 0;
    p[1][0] = 1;          p[1][1] = 1; p[2][2] = 0;
    p[2][0] = 0;          p[2][1] = b; p[2][2] = 1;
    p ^= ld[i];
    q *= p;
  }
  ModInt ans = q[1][0]*ModInt(a)+q[2][0];
  cout << ans.val << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

