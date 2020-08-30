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


# :heavy_check_mark: セグメント木 (一点更新、区間取得がO(logN))

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/segment-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:34:24+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.segtree.test.cpp.html">test/aoj/DSL_2_B.segtree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title セグメント木 (一点更新、区間取得がO(logN))
 * 
 */
#include <cassert>
#include <vector>

template <class Monoid>
struct SegmentTree {
  typedef typename Monoid::value_t value_t;
  const Monoid monoid;
  int n; // n_以上の最小の2冪
  std::vector<value_t> data;
  SegmentTree(int n_): monoid() {
    n = 1;
    while (n < n_) n *= 2;
    data.assign(2*n-1, monoid.identity());
  }

  // k番目の値(0-indexed)をaに変更
  void update(int k, int a) { // 0-indexed
    assert(0 <= k && k < n);
    // 葉の節点
    data[k+n-1] = a;
    // 登りながら更新
    for (k = (k+n)/2; k > 0; k /= 2) {  // 1-indexed
      data[k-1] = monoid.merge(data[2*k-1], data[2*k]);
    }
  }

  value_t query(int l, int r) {  // 0-indexed, [l, r)
    assert(0 <= l && l <= r && r <= n);
    value_t vl = monoid.identity(), vr = monoid.identity();
    for (l += n, r += n; l < r; l /= 2, r /= 2) {  // 1-indexed
      if (l & 1) vl = monoid.merge(vl, data[(l++)-1]);
      if (r & 1) vr = monoid.merge(data[(--r)-1],vr);
    }
    return monoid.merge(vl, vr);
  }

  value_t operator[](const int &k) {
    return query(k, k + 1);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/segment-tree.cpp"
/**
 * @title セグメント木 (一点更新、区間取得がO(logN))
 * 
 */
#include <cassert>
#include <vector>

template <class Monoid>
struct SegmentTree {
  typedef typename Monoid::value_t value_t;
  const Monoid monoid;
  int n; // n_以上の最小の2冪
  std::vector<value_t> data;
  SegmentTree(int n_): monoid() {
    n = 1;
    while (n < n_) n *= 2;
    data.assign(2*n-1, monoid.identity());
  }

  // k番目の値(0-indexed)をaに変更
  void update(int k, int a) { // 0-indexed
    assert(0 <= k && k < n);
    // 葉の節点
    data[k+n-1] = a;
    // 登りながら更新
    for (k = (k+n)/2; k > 0; k /= 2) {  // 1-indexed
      data[k-1] = monoid.merge(data[2*k-1], data[2*k]);
    }
  }

  value_t query(int l, int r) {  // 0-indexed, [l, r)
    assert(0 <= l && l <= r && r <= n);
    value_t vl = monoid.identity(), vr = monoid.identity();
    for (l += n, r += n; l < r; l /= 2, r /= 2) {  // 1-indexed
      if (l & 1) vl = monoid.merge(vl, data[(l++)-1]);
      if (r & 1) vr = monoid.merge(data[(--r)-1],vr);
    }
    return monoid.merge(vl, vr);
  }

  value_t operator[](const int &k) {
    return query(k, k + 1);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

