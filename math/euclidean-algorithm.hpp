// @title 最大公約数・最小公倍数
#include <cassert>

using ll = long long;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a*b / gcd(a, b);
}

#if 0
int main() {
  assert(gcd(18, 24) == 6);
  assert(lcm(18, 24) == 72);
  // aとbの順序が逆でもok
  assert(gcd(7, 3) == 1);
  // aとbの順序が逆でもok
  assert(lcm(7, 3) == 21);
  // intを超える範囲でも問題なく計算できる
  assert(gcd(123456789123456789, 987654321987654321) == 9000000009);
}
#endif
