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
