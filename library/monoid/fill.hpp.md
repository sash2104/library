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


# :heavy_check_mark: monoid/fill.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c3437aaac8e99d51d51e80f390e49b05">monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/monoid/fill.hpp">View this file on GitHub</a>
    - Last commit date: 2019-12-31 21:45:44+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_F.test.cpp.html">test/aoj/DSL_2_F.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

namespace monoid {
template <class T>
struct fill {
  typedef std::pair<bool, T> value_t;
  value_t identity() const { return std::make_pair(false, T()); }
  value_t merge(value_t a, value_t b) const { return b.first ? b : a; }
};
} // namespace monoid
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "monoid/fill.hpp"
#include <utility>

namespace monoid {
template <class T>
struct fill {
  typedef std::pair<bool, T> value_t;
  value_t identity() const { return std::make_pair(false, T()); }
  value_t merge(value_t a, value_t b) const { return b.first ? b : a; }
};
} // namespace monoid
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

