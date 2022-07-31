---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ac-library/segtree.min.test.cpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001min (ac-library)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "atcoder/segtree/min.hpp"


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

    '
  code: '#pragma once


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

    } // namespace segtree'
  dependsOn: []
  isVerificationFile: false
  path: atcoder/segtree/min.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ac-library/segtree.min.test.cpp
documentation_of: atcoder/segtree/min.hpp
layout: document
redirect_from:
- /library/atcoder/segtree/min.hpp
- /library/atcoder/segtree/min.hpp.html
title: atcoder/segtree/min.hpp
---
