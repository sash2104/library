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


# :heavy_check_mark: math/euclidean-algorithm.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/euclidean-algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-21 20:55:01+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_C.test.cpp.html">test/aoj/NTL_1_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/euclidean-algorithm.cpp"
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
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

