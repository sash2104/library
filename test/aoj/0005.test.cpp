#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0005"

#define call_from_test
#include "../../math/euclidean-algorithm.cpp"
#undef call_from_test

#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll a, b;
  while (cin >> a >> b) {
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
  }
  return 0;
}
