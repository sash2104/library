#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a*b / gcd(a, b);
}

#ifndef call_from_test
int main() {
  assert(gcd(18, 24) == 6);
  assert(lcm(18, 24) == 72);
  // aとbの順序が逆でもok
  assert(gcd(7, 3) == 1);
  // aとbの順序が逆でもok
  assert(lcm(7, 3) == 21);
  // intを超える範囲でも問題なく計算できる
  assert(gcd(123456789123456789, 987654321987654321) == 9000000009);

  // 全てのassertを通過したら表示される
  cout << "ok" << endl;
}
#endif
