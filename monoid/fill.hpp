#pragma once
#include <utility>

namespace monoid {
template <class T>
struct fill {
  typedef std::pair<bool, T> value_t;
  value_t identity() const { return std::make_pair(false, T()); }
  value_t merge(value_t a, value_t b) const { return b.first ? b : a; }
};
} // namespace monoid
