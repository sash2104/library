---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/dual-segment-tree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\u65B0\
      \u3001\u4E00\u70B9\u53D6\u5F97)"
  - icon: ':heavy_check_mark:'
    path: datastructure/lazy-segment-tree.hpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\u65B0\
      \u3001\u533A\u9593\u53D6\u5F97)"
  - icon: ':heavy_check_mark:'
    path: monoid/fill.hpp
    title: monoid/fill.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    document_title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\
      \u5909\u66F4\u30FB\u4E00\u70B9\u53D6\u5F97)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL_2_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n// @title \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u5909\
    \u66F4\u30FB\u4E00\u70B9\u53D6\u5F97)\n\n#line 1 \"monoid/fill.hpp\"\n\n\n#include\
    \ <utility>\n\nnamespace monoid {\ntemplate <class T>\nstruct fill {\n  typedef\
    \ std::pair<bool, T> value_t;\n  value_t identity() const { return std::make_pair(false,\
    \ T()); }\n  value_t merge(value_t a, value_t b) const { return b.first ? b :\
    \ a; }\n};\n} // namespace monoid\n\n\n#line 1 \"datastructure/dual-segment-tree.hpp\"\
    \n\n\n/**\n * @title \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\
    \u66F4\u65B0\u3001\u4E00\u70B9\u53D6\u5F97)\n * @brief \u533A\u9593\u66F4\u65B0\
    \u3001\u4E00\u70B9\u53D6\u5F97\u304C\u3067\u304D\u308B\u3084\u3064\n *   \u5B9A\
    \u6570\u500D\u306F\u60AA\u305D\u3046\u3060\u304C\u3001\u4F3C\u305F\u30B3\u30FC\
    \u30C9\u3092\u305F\u304F\u3055\u3093\u7BA1\u7406\u3057\u305F\u304F\u306A\u3044\
    \u306E\u3067LazySegmentTree\u3092\u4F7F\u3044\u56DE\u3059\n *  \n */ \n#include\
    \ <cassert>\n#line 1 \"datastructure/lazy-segment-tree.hpp\"\n\n\n/**\n * @title\
    \ \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u66F4\u65B0\u3001\
    \u533A\u9593\u53D6\u5F97)\n */ \n#line 7 \"datastructure/lazy-segment-tree.hpp\"\
    \n#include <functional>\n#include <vector>\n\n// FIXME: coding style\u3092\u7D71\
    \u4E00\u3059\u308B\n// FIXME: \u8981\u7D20\u306B\u4F5C\u7528\u7D20\u3092\u9069\
    \u7528\u3059\u308B\u95A2\u6570\u3067\u3042\u308BG\u3092class\u5316\u3059\u308B\
    \ntemplate <class Monoid, class OperatorMonoid>\nstruct LazySegmentTree {\n  typedef\
    \ typename Monoid::value_t value_t;\n  typedef typename OperatorMonoid::value_t\
    \ operator_t;\n  const Monoid monoid;\n  const OperatorMonoid op_monoid;\n  using\
    \ G = std::function< value_t(value_t, operator_t) >;\n  const G g;\n  int n; //\
    \ n_\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E2\u51AA\n  int height; // \u6728\u306E\
    \u6DF1\u3055. n == pow(2, height)\n  std::vector<value_t> data;\n  std::vector<operator_t>\
    \ lazy;\n  LazySegmentTree(const G g): monoid(), op_monoid(), g(g) {}\n\n  void\
    \ init(int n_) {\n    n = 1;\n    height = 0;\n    while (n < n_) { n *= 2; ++height;\
    \ }\n    data.assign(2*n, monoid.identity());\n    lazy.assign(2*n, op_monoid.identity());\n\
    \  }\n\n  void set(int k, value_t x) {\n    data[k + n] = x;\n  }\n\n  void build(const\
    \ std::vector<value_t> &v) {\n    int n_=v.size();\n    init(n_);\n    for(int\
    \ i=0;i<n_;i++) data[n+i]=v[i];\n    for(int i=n-1;i;i--)\n      data[i] = monoid.merge(data[(i<<1)|0],\
    \ data[(i<<1)|1]);\n  }\n\n  inline void propagate(int k) {\n    if(lazy[k] !=\
    \ op_monoid.identity()) {\n      lazy[2 * k + 0] = op_monoid.merge(lazy[2 * k\
    \ + 0], lazy[k]);\n      lazy[2 * k + 1] = op_monoid.merge(lazy[2 * k + 1], lazy[k]);\n\
    \      data[k] = reflect(k);\n      lazy[k] = op_monoid.identity();\n    }\n \
    \ }\n\n  inline value_t reflect(int k) {\n    return lazy[k] == op_monoid.identity()\
    \ ? data[k] : g(data[k], lazy[k]);\n  }\n\n  inline void recalc(int k) {\n   \
    \ while(k >>= 1) data[k] = monoid.merge(reflect(2 * k + 0), reflect(2 * k + 1));\n\
    \  }\n\n  inline void thrust(int k) {\n    for(int i = height; i > 0; i--) propagate(k\
    \ >> i);\n  }\n\n  void update(int a, int b, operator_t x) { // 0-indexed, [a,\
    \ b)\n    assert(0 <= a && a <= b && b <= n);\n    thrust(a += n);\n    thrust(b\
    \ += n - 1);\n    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n     \
    \ if(l & 1) lazy[l] = op_monoid.merge(lazy[l], x), ++l;\n      if(r & 1) --r,\
    \ lazy[r] = op_monoid.merge(lazy[r], x);\n    }\n    recalc(a);\n    recalc(b);\n\
    \  }\n\n  value_t query(int a, int b) { // 0-indexed, [a, b)\n    assert(0 <=\
    \ a && a <= b && b <= n);\n    thrust(a += n);\n    thrust(b += n - 1);\n    value_t\
    \ vl = monoid.identity(), vr = monoid.identity();\n    for(int l = a, r = b +\
    \ 1; l < r; l >>= 1, r >>= 1) {\n      if(l & 1) vl = monoid.merge(vl, reflect(l++));\n\
    \      if(r & 1) vr = monoid.merge(reflect(--r), vr);\n    }\n    return monoid.merge(vl,\
    \ vr);\n  }\n\n  value_t operator[](const int &k) {\n    return query(k, k + 1);\n\
    \  }\n};\n\n\n#line 11 \"datastructure/dual-segment-tree.hpp\"\n\ntemplate <class\
    \ OperatorMonoid>\nstruct DualSegmentTree {\n  typedef typename OperatorMonoid::value_t\
    \ operator_t;\n  LazySegmentTree<OperatorMonoid, OperatorMonoid> lst;\n  DualSegmentTree()\
    \ : lst([](operator_t a, operator_t b) { return OperatorMonoid().merge(a, b);\
    \ }) {}\n  void build(const std::vector<operator_t> &v) { lst.build(v); }\n  void\
    \ update(int a, int b, operator_t x) { lst.update(a, b, x); }\n  operator_t query(int\
    \ a) {\n    return lst.query(a, a+1);\n  }\n  operator_t operator[](const int\
    \ &k) { return lst[k]; }\n};\n\n\n#line 6 \"test/aoj/DSL_2_D.test.cpp\"\n#include\
    \ <iostream>\n#include <climits>\nusing namespace std;\n\nusing p_bi = pair<bool,\
    \ int>;\n\nint main() {\n  int n, q; cin >> n >> q;\n  DualSegmentTree<monoid::fill<int>>\
    \ st;\n  st.build(vector<p_bi>(n, {true, INT_MAX}));\n  for (int i = 0; i < q;\
    \ ++i) {\n    int c; cin >> c;\n    if (c == 0) {\n      int s, t, x; cin >> s\
    \ >> t >> x;\n      st.update(s, t+1, {true, x});\n    }\n    else {\n      int\
    \ s; cin >> s;\n      cout << st[s].second << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n// @title \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u5909\
    \u66F4\u30FB\u4E00\u70B9\u53D6\u5F97)\n\n#include \"../../monoid/fill.hpp\"\n\
    #include \"../../datastructure/dual-segment-tree.hpp\"\n#include <iostream>\n\
    #include <climits>\nusing namespace std;\n\nusing p_bi = pair<bool, int>;\n\n\
    int main() {\n  int n, q; cin >> n >> q;\n  DualSegmentTree<monoid::fill<int>>\
    \ st;\n  st.build(vector<p_bi>(n, {true, INT_MAX}));\n  for (int i = 0; i < q;\
    \ ++i) {\n    int c; cin >> c;\n    if (c == 0) {\n      int s, t, x; cin >> s\
    \ >> t >> x;\n      st.update(s, t+1, {true, x});\n    }\n    else {\n      int\
    \ s; cin >> s;\n      cout << st[s].second << endl;\n    }\n  }\n}\n"
  dependsOn:
  - monoid/fill.hpp
  - datastructure/dual-segment-tree.hpp
  - datastructure/lazy-segment-tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_D.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D.test.cpp
- /verify/test/aoj/DSL_2_D.test.cpp.html
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u533A\u9593\u5909\u66F4\
  \u30FB\u4E00\u70B9\u53D6\u5F97)"
---
