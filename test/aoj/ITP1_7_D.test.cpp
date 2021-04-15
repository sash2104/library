#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D"
#include "../../math/matrix.hpp"
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