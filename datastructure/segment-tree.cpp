#include <cassert>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <class Monoid>
struct SegmentTree {
  typedef typename Monoid::value_t value_t;
  const Monoid monoid;
  int n; // n_以上の最小の2冪
  vector<int> data;
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
      if (l % 2 == 1) vl = monoid.merge(vl, data[(l++)-1]);
      if (r % 2 == 1) vr = monoid.merge(data[(--r)-1],vr);
    }
    return monoid.merge(vl, vr);
  }
};
