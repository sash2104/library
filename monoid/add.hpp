#pragma once

namespace monoid {
template <class T>
struct add {
  typedef T value_t;
  T identity() const { return T(); }
  T merge(T a, T b) const { return a+b; }
};
} // namespace monoid
