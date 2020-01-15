#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

// modを可変にする
#define MUTABLE

#include "../../math/modint.cpp"
#include "../../math/matrix.cpp"

using namespace std;
typedef long long ll;

using matrix = Matrix<ModInt>;

int main() {
  ll l, a, b, m;
  cin >> l >> a >> b >> m;
  mod = m;

  // ld[i]に、i桁の要素数を格納する
  vector<ll> ld0(19), ld(19);
  for (int i = 0; i <= 18; ++i) {
    ll x = pow(10, i);
    if (x <= a) continue;
    ll d = (x-a+b-1)/b;
    if (d > l) ld0[i] = l;
    else ld0[i] = d;
    ld[i] = ld0[i];
    if (i > 0) ld[i] -= ld0[i-1];
  }
  matrix q(3);
  q[0][0] = 1; q[1][1] = 1; q[2][2] = 1;
  for (int i = 1; i <= 18; ++i) {
    matrix p(3);
    p[0][0] = pow(10, i); p[0][1] = 0; p[0][2] = 0;
    p[1][0] = 1;          p[1][1] = 1; p[2][2] = 0;
    p[2][0] = 0;          p[2][1] = b; p[2][2] = 1;
    p ^= ld[i];
    q *= p;
  }
  ModInt ans = q[1][0]*ModInt(a)+q[2][0];
  cout << ans.val << endl;
}
