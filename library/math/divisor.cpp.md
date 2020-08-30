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


# :warning: 約数列挙

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/divisor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:16:58+09:00




## Required by

* :warning: <a href="../test/aoj/notest.1562.cpp.html">test/aoj/notest.1562.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

