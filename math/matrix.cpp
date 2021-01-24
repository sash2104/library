// @title 行列
// 使用例：https://atcoder.jp/contests/abc189/submissions/19676965
#include <cassert>
#include <iostream>
#include <vector>

template< class T >
struct Matrix {
  int H, W;
  std::vector< std::vector< T > > A;
  Matrix() {}
  Matrix(int n, int m) : H(n), W(m), A(H, std::vector< T >(W, 0)) {}
  Matrix(int n) : H(n), W(n), A(H, std::vector< T >(W, 0)) {};
  Matrix(const std::vector<std::vector<T>>& a) : A(a) {
      H = (int)a.size();
      assert(H > 0);
      W = (int)a[0].size();
  }
  int height() const { return H; }
  int width() const { return W; }
  inline const std::vector< T > &operator[](int k) const { return (A.at(k)); }
  inline std::vector< T > &operator[](int k) { return (A.at(k)); }
  static Matrix I(int n) {
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
    std::vector< std::vector< T > > C(H, std::vector< T >(B.W, 0));
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

  std::vector<T> operator*(const std::vector<T> &v) {
    assert(W == (int)v.size());
    std::vector<T> ret(H, 0);
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
        ret[i] += ((*this)[i][j] * v[j]);
    return ret;
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