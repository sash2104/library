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
