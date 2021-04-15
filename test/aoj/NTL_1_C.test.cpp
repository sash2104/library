#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include "../../math/euclidean-algorithm.hpp"
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    ans = lcm(ans, a);
  }
  cout << ans << endl;
}
