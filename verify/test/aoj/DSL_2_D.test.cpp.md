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


# :heavy_check_mark: test/aoj/DSL_2_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-01 00:08:06+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/dual-segment-tree.cpp.html">datastructure/dual-segment-tree.cpp</a>
* :heavy_check_mark: <a href="../../../library/datastructure/lazy-segment-tree.cpp.html">datastructure/lazy-segment-tree.cpp</a>
* :heavy_check_mark: <a href="../../../library/monoid/fill.hpp.html">monoid/fill.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include "../../monoid/fill.hpp"
#include "../../datastructure/dual-segment-tree.cpp"
#include <iostream>
#include <climits>
using namespace std;

using p_bi = pair<bool, int>;

int main() {
  int n, q; cin >> n >> q;
  DualSegmentTree<monoid::fill<int>> st;
  st.build(vector<p_bi>(n, {true, INT_MAX}));
  for (int i = 0; i < q; ++i) {
    int c; cin >> c;
    if (c == 0) {
      int s, t, x; cin >> s >> t >> x;
      st.update(s, t+1, {true, x});
    }
    else {
      int s; cin >> s;
      cout << st[s].second << endl;
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#line 2 "test/aoj/../../monoid/fill.hpp"
#include <utility>

namespace monoid {
template <class T>
struct fill {
  typedef std::pair<bool, T> value_t;
  value_t identity() const { return std::make_pair(false, T()); }
  value_t merge(value_t a, value_t b) const { return b.first ? b : a; }
};
} // namespace monoid#line 1 "test/aoj/../../datastructure/dual-segment-tree.cpp"
#include <cassert>
#line 1 "test/aoj/../../datastructure/lazy-segment-tree.cpp"
#include <cassert>
#include <functional>
#include <utility>
#include <vector>

using namespace std;

// FIXME: coding styleを統一する
// FIXME: 要素に作用素を適用する関数であるGをclass化する
template <class Monoid, class OperatorMonoid>
struct LazySegmentTree {
  typedef typename Monoid::value_t value_t;
  typedef typename OperatorMonoid::value_t operator_t;
  const Monoid monoid;
  const OperatorMonoid op_monoid;
  using G = function< value_t(value_t, operator_t) >;
  const G g;
  int n; // n_以上の最小の2冪
  int height; // 木の深さ. n == pow(2, height)
  vector<value_t> data;
  vector<operator_t> lazy;
  LazySegmentTree(const G g): monoid(), op_monoid(), g(g) {}

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
      lazy[2 * k + 0] = op_monoid.merge(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = op_monoid.merge(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = op_monoid.identity();
    }
  }

  inline value_t reflect(int k) {
    return lazy[k] == op_monoid.identity() ? data[k] : g(data[k], lazy[k]);
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
      if(l & 1) lazy[l] = op_monoid.merge(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = op_monoid.merge(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }

  value_t query(int a, int b) { // 0-indexed, [a, b)
    thrust(a += n);
    thrust(b += n - 1);
    value_t vl = monoid.identity(), vr = monoid.identity();
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) vl = monoid.merge(vl, reflect(l++));
      if(r & 1) vr = monoid.merge(reflect(--r), vr);
    }
    return monoid.merge(vl, vr);
  }

  value_t operator[](const int &k) {
    return query(k, k + 1);
  }
};
#line 3 "test/aoj/../../datastructure/dual-segment-tree.cpp"

// 区間更新、一点取得がO(logN)でできるやつ
// 定数倍は悪そうだが、似たコードをたくさん管理したくないのでLazySegmentTreeを使い回す
template <class OperatorMonoid>
struct DualSegmentTree {
  typedef typename OperatorMonoid::value_t operator_t;
  LazySegmentTree<OperatorMonoid, OperatorMonoid> lst;
  DualSegmentTree() : lst([](operator_t a, operator_t b) { return OperatorMonoid().merge(a, b); }) {}
  void build(const vector<operator_t> &v) { lst.build(v); }
  void update(int a, int b, operator_t x) { lst.update(a, b, x); }
  operator_t query(int a, int b) {
    assert(a+1 == b); // 一点取得のみを認める
    return lst.query(a, b);
  }
  operator_t operator[](const int &k) { return lst[k]; }
};
#line 5 "test/aoj/DSL_2_D.test.cpp"
#include <iostream>
#include <climits>
using namespace std;

using p_bi = pair<bool, int>;

int main() {
  int n, q; cin >> n >> q;
  DualSegmentTree<monoid::fill<int>> st;
  st.build(vector<p_bi>(n, {true, INT_MAX}));
  for (int i = 0; i < q; ++i) {
    int c; cin >> c;
    if (c == 0) {
      int s, t, x; cin >> s >> t >> x;
      st.update(s, t+1, {true, x});
    }
    else {
      int s; cin >> s;
      cout << st[s].second << endl;
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

