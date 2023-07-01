---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ac-library/segtree.sum.test.cpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001sum (ac-library)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "atcoder/segtree/add.hpp"


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

    '
  code: '#pragma once


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

    } // namespace segtree'
  dependsOn: []
  isVerificationFile: false
  path: atcoder/segtree/add.hpp
  requiredBy: []
  timestamp: '2020-09-29 22:26:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ac-library/segtree.sum.test.cpp
documentation_of: atcoder/segtree/add.hpp
layout: document
redirect_from:
- /library/atcoder/segtree/add.hpp
- /library/atcoder/segtree/add.hpp.html
title: atcoder/segtree/add.hpp
---
