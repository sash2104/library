---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/segment-tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\u3001\u533A\
      \u9593\u53D6\u5F97)"
  - icon: ':heavy_check_mark:'
    path: monoid/add.hpp
    title: monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u52A0\u7B97\
      \u30FB\u533A\u9593\u548C)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.segtree.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n// @title\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u52A0\u7B97\u30FB\u533A\u9593\
    \u548C)\n\n#line 1 \"monoid/add.hpp\"\n\n\n\nnamespace monoid {\ntemplate <class\
    \ T>\nstruct add {\n  typedef T value_t;\n  T identity() const { return T(); }\n\
    \  T merge(T a, T b) const { return a+b; }\n};\n} // namespace monoid\n\n\n#line\
    \ 1 \"datastructure/segment-tree.hpp\"\n\n\n/**\n * @title \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728 (\u4E00\u70B9\u66F4\u65B0\u3001\u533A\u9593\u53D6\u5F97)\n * \n */\n\
    #include <cassert>\n#include <vector>\n\ntemplate <class Monoid>\nstruct SegmentTree\
    \ {\n  typedef typename Monoid::value_t value_t;\n  const Monoid monoid;\n  int\
    \ n; // n_\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E2\u51AA\n  std::vector<value_t>\
    \ data;\n  SegmentTree(int n_): monoid() {\n    n = 1;\n    while (n < n_) n *=\
    \ 2;\n    data.assign(2*n-1, monoid.identity());\n  }\n\n  // k\u756A\u76EE\u306E\
    \u5024(0-indexed)\u3092a\u306B\u5909\u66F4\n  void update(int k, int a) { // 0-indexed\n\
    \    assert(0 <= k && k < n);\n    // \u8449\u306E\u7BC0\u70B9\n    data[k+n-1]\
    \ = a;\n    // \u767B\u308A\u306A\u304C\u3089\u66F4\u65B0\n    for (k = (k+n)/2;\
    \ k > 0; k /= 2) {  // 1-indexed\n      data[k-1] = monoid.merge(data[2*k-1],\
    \ data[2*k]);\n    }\n  }\n\n  value_t query(int l, int r) {  // 0-indexed, [l,\
    \ r)\n    assert(0 <= l && l <= r && r <= n);\n    value_t vl = monoid.identity(),\
    \ vr = monoid.identity();\n    for (l += n, r += n; l < r; l /= 2, r /= 2) { \
    \ // 1-indexed\n      if (l & 1) vl = monoid.merge(vl, data[(l++)-1]);\n     \
    \ if (r & 1) vr = monoid.merge(data[(--r)-1],vr);\n    }\n    return monoid.merge(vl,\
    \ vr);\n  }\n\n  value_t operator[](const int &k) {\n    return query(k, k + 1);\n\
    \  }\n};\n\n\n#line 6 \"test/aoj/DSL_2_B.segtree.test.cpp\"\n\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n  int n, q; cin >> n >> q;\n  SegmentTree<monoid::add<int>>\
    \ st(n);\n  for (int i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >> y;\
    \ --x;\n    if (c == 0) st.update(x, st[x]+y);\n    else cout << st.query(x, y)\
    \ << endl;\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n// @title \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u52A0\u7B97\u30FB\
    \u533A\u9593\u548C)\n\n#include \"../../monoid/add.hpp\"\n#include \"../../datastructure/segment-tree.hpp\"\
    \n\n#include <iostream>\nusing namespace std;\n\nint main() {\n  int n, q; cin\
    \ >> n >> q;\n  SegmentTree<monoid::add<int>> st(n);\n  for (int i = 0; i < q;\
    \ ++i) {\n    int c, x, y; cin >> c >> x >> y; --x;\n    if (c == 0) st.update(x,\
    \ st[x]+y);\n    else cout << st.query(x, y) << endl;\n  }\n}\n"
  dependsOn:
  - monoid/add.hpp
  - datastructure/segment-tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.segtree.test.cpp
  requiredBy: []
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.segtree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.segtree.test.cpp
- /verify/test/aoj/DSL_2_B.segtree.test.cpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u4E00\u70B9\u52A0\u7B97\u30FB\u533A\
  \u9593\u548C)"
---
