// @title 約数列挙
#include <algorithm>
#include <vector>

using ll = long long;

std::vector<ll> divisor(ll n) { 
  std::vector<ll> ret;
  for (ll i = 1; (ll)i*i <= n; ++i) { 
    if (n % i == 0) {
      ret.push_back(i);
      if (i*i != n) { ret.push_back(n/i); }
    }
  }
  std::sort(ret.begin(), ret.end());
  return ret;
};
