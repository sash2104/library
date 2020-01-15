// original: http://hos.ac/slides/20140319_bit.pdf
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
