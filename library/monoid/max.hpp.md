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


# :warning: monoid/max.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c3437aaac8e99d51d51e80f390e49b05">monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoid/max.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-08 10:49:15+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <limits>

namespace monoid {
template <class T>
struct max {
  typedef T value_t;
  T identity() const { return std::numeric_limits<T>::min();}
  T merge(T a, T b) const { return std::max(a, b); }
};
} // namespace monoid

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoid/max.hpp"
#include <algorithm>
#include <limits>

namespace monoid {
template <class T>
struct max {
  typedef T value_t;
  T identity() const { return std::numeric_limits<T>::min();}
  T merge(T a, T b) const { return std::max(a, b); }
};
} // namespace monoid

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

