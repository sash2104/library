#pragma once
#include <algorithm>
#include <limits>

namespace monoid {
template <class T>
struct add {
  typedef T value_t;
  T identity() const { return 0; }
  T merge(T a, T b) const { return a+b; }
};
} // namespace monoid