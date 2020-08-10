---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: math/prime.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-21 12:04:49+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS_1_1_C.test.cpp.html">test/aoj/ALDS_1_1_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

