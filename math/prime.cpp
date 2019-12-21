#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

class Prime {
// n以下の素数を列挙する
public:
  const int n;
  vector<bool> is_prime;
  vector<int> primes;
  Prime(int size) : n(size), is_prime(n+1, true) {
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
      if (!is_prime[i]) continue;
      primes.push_back(i);
      int tmp = 2*i;
      while (tmp <= n) {
        is_prime[tmp] = false;
        tmp += i;
      }
    }
  }

  bool check(int x) { return is_prime[x]; }
};

struct PrimeFactorization {
  // n*n以下の数についての素因数分解
  const int n;
  Prime p;
  PrimeFactorization(int n) : n(n), p(n) {}

  map<ll, int> calc(ll a) {
    map<ll, int> ret;
    ll tmp = a;
    for (int i: p.primes) {
      if (i > tmp) break;
      int count = 0;
      while (tmp % i == 0) { 
        ++count;
        tmp /= i;
      }
      if (count > 0) ret[i] = count;
    }
    if (tmp > 1) ret[tmp] = 1;
    return ret;
  }
};

#ifndef call_from_test
int main() {
  PrimeFactorization pf(1000000);
  map<ll, int> factors;


  ll a = (ll)2*2*5*7*7*41;
  factors = pf.calc(a);
  cout << "prime factors of " << a << " is ..." << endl;
  for (auto it : factors) { 
    cout << it.first << " " << it.second << endl;
  }
  cout << endl;

  // 最大数付近での確認
  a = (ll)999983*999983;
  factors = pf.calc(a);
  cout << "prime factors of " << a << " is ..." << endl;
  for (auto it : factors) { 
    cout << it.first << " " << it.second << endl;
  }
}
#endif
