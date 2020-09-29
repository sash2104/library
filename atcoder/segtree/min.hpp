#pragma once

#include <atcoder/segtree>
#include <limits>

namespace segtree {
namespace min {
template<typename S>
S op(S a, S b) { return std::min(a, b); }
template<typename S>
S e() { return std::numeric_limits<S>::max();}
template<typename S>
using type = atcoder::segtree<S, op, e>;
} // namespace min
} // namespace segtree