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


# :warning: test/aoj/notest.1562.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/notest.1562.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:16:58+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1562">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1562</a>


## Depends on

* :warning: <a href="../../math/divisor.cpp.html">約数列挙</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1562"
#include "../../math/divisor.cpp"


int main() {
  int n; cin >> n;
  for (int i = 1; i <= (1<<n); ++i) {
    vector<ll> divs = divisor(i);
    if (divs.size() == n) {
      cout << i << endl;
      return 0;
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/notest.1562.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1562"
#line 1 "math/divisor.cpp"
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
#line 3 "test/aoj/notest.1562.cpp"


int main() {
  int n; cin >> n;
  for (int i = 1; i <= (1<<n); ++i) {
    vector<ll> divs = divisor(i);
    if (divs.size() == n) {
      cout << i << endl;
      return 0;
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

