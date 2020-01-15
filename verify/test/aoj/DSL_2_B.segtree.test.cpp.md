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


# :heavy_check_mark: test/aoj/DSL_2_B.segtree.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_B.segtree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-15 21:59:48+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/segment-tree.cpp.html">datastructure/segment-tree.cpp</a>
* :heavy_check_mark: <a href="../../../library/monoid/add.hpp.html">monoid/add.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../../monoid/add.hpp"
#include "../../datastructure/segment-tree.cpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  SegmentTree<monoid::add<int>> st(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y; --x;
    if (c == 0) st.update(x, st[x]+y);
    else cout << st.query(x, y) << endl;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_B.segtree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#line 2 "test/aoj/../../monoid/add.hpp"

namespace monoid {
template <class T>
struct add {
  typedef T value_t;
  T identity() const { return T(); }
  T merge(T a, T b) const { return a+b; }
};
} // namespace monoid
#line 1 "test/aoj/../../datastructure/segment-tree.cpp"
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
#line 5 "test/aoj/DSL_2_B.segtree.test.cpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  SegmentTree<monoid::add<int>> st(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y; --x;
    if (c == 0) st.update(x, st[x]+y);
    else cout << st.query(x, y) << endl;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

