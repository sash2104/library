#include <cassert>
#include <functional>
#include <vector>

// FIXME: coding styleを統一する
// FIXME: 要素に作用素を適用する関数であるGをclass化する
template <class Monoid, class OperatorMonoid>
struct LazySegmentTree {
  typedef typename Monoid::value_t value_t;
  typedef typename OperatorMonoid::value_t operator_t;
  const Monoid monoid;
  const OperatorMonoid op_monoid;
  using G = std::function< value_t(value_t, operator_t) >;
  const G g;
  int n; // n_以上の最小の2冪
  int height; // 木の深さ. n == pow(2, height)
  std::vector<value_t> data;
  std::vector<operator_t> lazy;
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

  void build(const std::vector<value_t> &v) {
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
    assert(0 <= a && a <= b && b <= n);
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
    assert(0 <= a && a <= b && b <= n);
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
