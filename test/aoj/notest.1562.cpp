#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1562"
#include "../../math/divisor.hpp"


int main() {
  int n; cin >> n;
  for (int i = 1; i <= (1<<n); ++i) {
    vector<ll> divs = divisor(i);
    if (divs.size() == n) {
      cout << i << endl;
      return 0;
    }
  }
}
