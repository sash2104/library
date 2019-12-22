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


# :heavy_check_mark: math/matrix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-22 14:49:56+09:00




## Required by

* :warning: <a href="../test/atcoder/129-f.cpp.html">test/atcoder/129-f.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ITP1_7_D.test.cpp.html">test/aoj/ITP1_7_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

