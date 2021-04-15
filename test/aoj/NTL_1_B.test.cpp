#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "../../math/modint.hpp"

using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  modint x(m);
  modint ans = x.pow(n);
  cout << ans.val << endl;
}
