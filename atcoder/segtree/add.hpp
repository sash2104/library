#pragma once

#include <atcoder/segtree>
#include <limits>

namespace segtree {
namespace add {
template<typename S>
S op(S a, S b) { return a+b; }
template<typename S>
S e() { return 0;}
template<typename S>
using type = atcoder::segtree<S, op, e>;
} // namespace add
} // namespace segtree