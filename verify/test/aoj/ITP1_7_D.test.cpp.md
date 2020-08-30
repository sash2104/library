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


# :heavy_check_mark: test/aoj/ITP1_7_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ITP1_7_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:21:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/matrix.cpp.html">行列</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"
#include "../../math/matrix.cpp"
#include <iostream>
using namespace std;

using matrix = Matrix<long long>;
int main() {
  int n, m, l; cin >> n >> m >> l;
  matrix A(n, m), B(m, l);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < l; ++j) {
      cin >> B[i][j];
    }
  }
  matrix C = A*B;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j) {
      cout << C[i][j] << (j+1 == l ? "\n":" ");
    }
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ITP1_7_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"
#line 1 "math/matrix.cpp"
// @title 行列
#include <cassert>
#include <iostream>
#include <vector>
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
#line 4 "test/aoj/ITP1_7_D.test.cpp"
using namespace std;

using matrix = Matrix<long long>;
int main() {
  int n, m, l; cin >> n >> m >> l;
  matrix A(n, m), B(m, l);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < l; ++j) {
      cin >> B[i][j];
    }
  }
  matrix C = A*B;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j) {
      cout << C[i][j] << (j+1 == l ? "\n":" ");
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

