#ifndef __MONOID__ADD
#define __MONOID__ADD

namespace monoid {
template <class T>
struct add {
  typedef T value_t;
  T identity() const { return T(); }
  T merge(T a, T b) const { return a+b; }
};
} // namespace monoid

#endif // __MONOID__ADD