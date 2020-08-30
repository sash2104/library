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


# :heavy_check_mark: test/aoj/NTL_1_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:43:34+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/euclidean-algorithm.cpp.html">最大公約数・最小公倍数</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include "../../math/euclidean-algorithm.cpp"
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    ans = lcm(ans, a);
  }
  cout << ans << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#line 1 "math/euclidean-algorithm.cpp"
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
#line 4 "test/aoj/NTL_1_C.test.cpp"
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    ans = lcm(ans, a);
  }
  cout << ans << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

