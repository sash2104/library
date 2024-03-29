#ifndef _MONOID_MAX
#define _MONOID_MAX
#include <algorithm>
#include <limits>

namespace monoid {
template <class T>
struct max {
  typedef T value_t;
  T identity() const { return std::numeric_limits<T>::min();}
  T merge(T a, T b) const { return std::max(a, b); }
};
} // namespace monoid

#endif // _MONOID_MAX