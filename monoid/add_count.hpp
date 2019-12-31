#pragma once
#include <algorithm>
#include <utility>
#include <limits>

namespace monoid {
template <class T>
struct add_count {
  typedef std::pair<T,T> value_t;
  value_t identity() const { return std::make_pair(T(),T()); }
  value_t merge(value_t a, value_t b) const { return std::make_pair(a.first+b.first, a.second+b.second); }
};
} // namespace monoid
