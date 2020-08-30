#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#define call_from_test
#include "../../math/prime.cpp"
#undef call_from_test

#include <iostream>
using namespace std;

int main() {
  FastPrimeFactorization pf(100000);
  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    map<ll, int> factors = pf.calc(x);
    if (factors.size() > 1) continue;
    auto it = factors.begin();
    if (it->second == 1) ++ans;
  }
  cout << ans << endl;
}
