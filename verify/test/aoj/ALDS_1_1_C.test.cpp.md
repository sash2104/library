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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/ALDS_1_1_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS_1_1_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 09:05:46+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/prime.cpp.html">素数判定、素因数分解</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#define call_from_test
#include "../../math/prime.cpp"
#undef call_from_test

#include <iostream>
using namespace std;

int main() {
  PrimeFactorization pf(100000);
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS_1_1_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#define call_from_test
#line 1 "math/prime.cpp"
// @title 素数判定、素因数分解
#include <cassert>
#include <iostream>
#include <vector>
#include <map>

using ll = long long;

class Prime {
// n以下の素数を列挙する
public:
  const int n;
  std::vector<bool> is_prime;
  std::vector<int> primes;
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

  std::map<ll, int> calc(ll a) {
    std::map<ll, int> ret;
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

struct FastPrimeFactorization {
  /**
   * @brief n以下の数について高速で、n*n以下の数で普通に素因数分解を行う
   * 
   */
  int n;
  std::vector<int> divides; // その数を割り切る最小の素因数
  std::vector<int> primes; // n以下の素数
  FastPrimeFactorization(int n) : n(n), divides(n+1) {
    assert(n <= 2000000);
    // エラトステネスの篩にかけ、最小の素因数をdividesに書き込んでいく
    for (int i = 2; i <= n; ++i) {
      if (divides[i] > 0) continue;
      primes.push_back(i);
      int j = i;
      while (j <= n) {
        if (divides[j] == 0) {
          divides[j] = i;
        }
        j += i;
      }
    }
    // for (int i = 0; i <= n; ++i) { 
    //   cout << i << " " << divides[i] << endl;
    // }
  }

  std::map<ll, int> calc(ll a) {
    std::map<ll, int> ret;
    {
      // 高速に計算できない部分は愚直にやる
      ll tmp = a;
      while (tmp > n) {
        for (int i: primes) {
          if (i > tmp) break;
          int count = 0;
          while (tmp % i == 0) { 
            ++count;
            tmp /= i;
          }
          if (count > 0) ret[i] = count;
        }
      }
    }
    {
      int tmp = a;
      while (tmp > 1) {
        int d = divides[tmp];
        ++ret[d];
        tmp /= d;
      }
    }
    return ret;
  }
};

#if 0
using namespace std;
int main() {
  FastPrimeFactorization pf(1000000);
  // PrimeFactorization pf(1000000);
  std::map<ll, int> factors;


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
#line 5 "test/aoj/ALDS_1_1_C.test.cpp"
#undef call_from_test

#line 8 "test/aoj/ALDS_1_1_C.test.cpp"
using namespace std;

int main() {
  PrimeFactorization pf(100000);
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

