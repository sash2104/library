#include <algorithm>
#include <limits>

namespace monoid {
template <class T>
struct min {
  typedef T value_t;
  T identity() const { return std::numeric_limits<T>::max();}
  T merge(T a, T b) const { return std::min(a, b); }
};
} // namespace monoid
