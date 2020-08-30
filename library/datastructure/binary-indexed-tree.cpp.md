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


# :heavy_check_mark: BIT (Binary-Indexed-Tree)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/binary-indexed-tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:34:24+09:00


* see: <a href="http://hos.ac/slides/20140319_bit.pdf">http://hos.ac/slides/20140319_bit.pdf</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.bit.test.cpp.html">test/aoj/DSL_2_B.bit.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title BIT (Binary-Indexed-Tree)
 * @see http://hos.ac/slides/20140319_bit.pdf
 */
#include <cassert>
#include <vector>

template <class T>
struct BinaryIndexedTree {
  int n;
  std::vector<T> bit;
  BinaryIndexedTree(int n): n(n), bit(n+1) {}

  void build(const std::vector<T> &v) {
    for (int x = 1; x <= n; ++x) bit[x] = v[x-1];
    for (int x = 1; x < n; ++x) bit[x + (x & -x)] += bit[x];
  }

  void add(int a, T w) { // 0-indexed
    assert(0 <= a && a < n);
    for (int x = a+1; x <= n; x += x & -x) bit[x] += w; // 1-indexed
  }

  T sum(int a) { // [0, a)
    assert(0 <= a && a <= n);
    T ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x]; // 1-indexed
    return ret;
  }

  T sum(int l, int r) { return sum(r)-sum(l); } // 0-indexed, [l, r)
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/binary-indexed-tree.cpp"
/**
 * @title BIT (Binary-Indexed-Tree)
 * @see http://hos.ac/slides/20140319_bit.pdf
 */
#include <cassert>
#include <vector>

template <class T>
struct BinaryIndexedTree {
  int n;
  std::vector<T> bit;
  BinaryIndexedTree(int n): n(n), bit(n+1) {}

  void build(const std::vector<T> &v) {
    for (int x = 1; x <= n; ++x) bit[x] = v[x-1];
    for (int x = 1; x < n; ++x) bit[x + (x & -x)] += bit[x];
  }

  void add(int a, T w) { // 0-indexed
    assert(0 <= a && a < n);
    for (int x = a+1; x <= n; x += x & -x) bit[x] += w; // 1-indexed
  }

  T sum(int a) { // [0, a)
    assert(0 <= a && a <= n);
    T ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x]; // 1-indexed
    return ret;
  }

  T sum(int l, int r) { return sum(r)-sum(l); } // 0-indexed, [l, r)
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

