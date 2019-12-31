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


# :heavy_check_mark: test/aoj/DSL_2_H.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_H.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-31 17:37:57+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/lazy-segment-tree.cpp.html">datastructure/lazy-segment-tree.cpp</a>
* :heavy_check_mark: <a href="../../../library/monoid/add.hpp.html">monoid/add.hpp</a>
* :heavy_check_mark: <a href="../../../library/monoid/min.hpp.html">monoid/min.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include "../../monoid/add.hpp"
#include "../../monoid/min.hpp"
#include "../../datastructure/lazy-segment-tree.cpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  auto h=[](int a,int b){return a+b;};
  LazySegmentTree<monoid::min<int>, monoid::add<int>> st(h);
  st.build(vector<int>(n,0));
  for (int i = 0; i < q; ++i) {
    int c; cin >> c;
    if (c == 0) {
      int s, t, x; cin >> s >> t >> x;
      st.update(s, t+1, x);
    }
    else {
      int s, t; cin >> s >> t;
      cout << st.query(s, t+1) << endl;
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_H.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#line 2 "test/aoj/../../monoid/add.hpp"
#include <algorithm>
#include <limits>

namespace monoid {
template <class T>
struct add {
  typedef T value_t;
  T identity() const { return 0; }
  T merge(T a, T b) const { return a+b; }
};
} // namespace monoid#line 2 "test/aoj/../../monoid/min.hpp"
#include <algorithm>
#include <limits>

namespace monoid {
template <class T>
struct min {
  typedef T value_t;
  T identity() const { return std::numeric_limits<T>::max();}
  T merge(T a, T b) const { return std::min(a, b); }
};
} // namespace monoid#line 1 "test/aoj/../../datastructure/lazy-segment-tree.cpp"
#include <cassert>
#include <functional>
#include <utility>
#include <vector>

using namespace std;

// FIXME: coding styleを統一する
// FIXME: 作用素同士を結合する関数であるHをclass化する
template <class Monoid, class OperatorMonoid>
struct LazySegmentTree {
  typedef typename Monoid::value_t value_t;
  typedef typename OperatorMonoid::value_t operator_t;
  const Monoid monoid;
  const OperatorMonoid op_monoid;
  using H = function< operator_t(operator_t, operator_t) >;
  const H h;
  int n; // n_以上の最小の2冪
  int height; // 木の深さ. n == pow(2, height)
  vector<int> data, lazy;
  LazySegmentTree(const H h): monoid(), op_monoid(), h(h) {}

  void init(int n_) {
    n = 1;
    height = 0;
    while (n < n_) { n *= 2; ++height; }
    data.assign(2*n, monoid.identity());
    lazy.assign(2*n, op_monoid.identity());
  }

  void set(int k, value_t x) {
    data[k + n] = x;
  }

  void build(const vector<value_t> &v) {
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) data[n+i]=v[i];
    for(int i=n-1;i;i--)
      data[i] = monoid.merge(data[(i<<1)|0], data[(i<<1)|1]);
  }

  inline void propagate(int k) {
    if(lazy[k] != op_monoid.identity()) {
      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = op_monoid.identity();
    }
  }

  inline value_t reflect(int k) {
    return lazy[k] == op_monoid.identity() ? data[k] : op_monoid.merge(data[k], lazy[k]);
  }

  inline void recalc(int k) {
    while(k >>= 1) data[k] = monoid.merge(reflect(2 * k + 0), reflect(2 * k + 1));
  }

  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, operator_t x) { // 0-indexed, [a, b)
    thrust(a += n);
    thrust(b += n - 1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = h(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }

  value_t query(int a, int b) { // 0-indexed, [a, b)
    thrust(a += n);
    thrust(b += n - 1);
    value_t L = monoid.identity(), R = monoid.identity();
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = monoid.merge(L, reflect(l++));
      if(r & 1) R = monoid.merge(reflect(--r), R);
    }
    return monoid.merge(L, R);
  }

  value_t operator[](const int &k) {
    return query(k, k + 1);
  }
};
#line 6 "test/aoj/DSL_2_H.test.cpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  auto h=[](int a,int b){return a+b;};
  LazySegmentTree<monoid::min<int>, monoid::add<int>> st(h);
  st.build(vector<int>(n,0));
  for (int i = 0; i < q; ++i) {
    int c; cin >> c;
    if (c == 0) {
      int s, t, x; cin >> s >> t >> x;
      st.update(s, t+1, x);
    }
    else {
      int s, t; cin >> s >> t;
      cout << st.query(s, t+1) << endl;
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

