#include "../../math/modint.cpp"

int main() {
  int m, n;
  cin >> m >> n;
  modint x(m);
  modint ans = x.pow(n);
  cout << ans.val << endl;
}
