/**
 * @title 座標圧縮
 */
#pragma once
#include <algorithm>
#include <vector>

template< typename T >
struct Compress {
  std::vector< T > xs;

  Compress() = default;
  Compress(const std::vector< T > &vs) { add(vs); }
  Compress(const std::initializer_list< std::vector< T > > &vs) { for(const T &p : vs) add(p); }

  void add(const std::vector< T > &vs) { std::copy(std::begin(vs), std::end(vs), std::back_inserter(xs)); }
  void add(const T &x) { xs.emplace_back(x); }

  void build() {
    std::sort(std::begin(xs), std::end(xs));
    xs.erase(unique(std::begin(xs), std::end(xs)), std::end(xs));
  }

  std::vector< int > get(const std::vector< T > &vs) const {
    std::vector< int > ret;
    std::transform(std::begin(vs), std::end(vs), std::back_inserter(ret), [&](const T &x) {
      return std::lower_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);
    });
    return ret;
  }

  int get(const T &x) const {
    return std::lower_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);
  }

  const T &operator[](int k) const { return xs[k]; }
};
