---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/binary-indexed-tree.hpp
    title: BIT (Binary-Indexed-Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    document_title: "BIT\u306E\u30C6\u30B9\u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.bit.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n// @title BIT\u306E\u30C6\u30B9\u30C8\n\n#line 1 \"datastructure/binary-indexed-tree.hpp\"\
    \n/**\n * @title BIT (Binary-Indexed-Tree)\n * @see http://hos.ac/slides/20140319_bit.pdf\n\
    \ */\n#include <cassert>\n#include <vector>\n\ntemplate <class T>\nstruct BinaryIndexedTree\
    \ {\n  int n;\n  std::vector<T> bit;\n  BinaryIndexedTree(int n): n(n), bit(n+1)\
    \ {}\n\n  void build(const std::vector<T> &v) {\n    for (int x = 1; x <= n; ++x)\
    \ bit[x] = v[x-1];\n    for (int x = 1; x < n; ++x) bit[x + (x & -x)] += bit[x];\n\
    \  }\n\n  void add(int a, T w) { // 0-indexed\n    assert(0 <= a && a < n);\n\
    \    for (int x = a+1; x <= n; x += x & -x) bit[x] += w; // 1-indexed\n  }\n\n\
    \  T sum(int a) { // [0, a)\n    assert(0 <= a && a <= n);\n    T ret = 0;\n \
    \   for (int x = a; x > 0; x -= x & -x) ret += bit[x]; // 1-indexed\n    return\
    \ ret;\n  }\n\n  T sum(int l, int r) { return sum(r)-sum(l); } // 0-indexed, [l,\
    \ r)\n};\n#line 5 \"test/aoj/DSL_2_B.bit.test.cpp\"\n\n#include <iostream>\nusing\
    \ namespace std;\n\nint main() {\n  int n, q; cin >> n >> q;\n  BinaryIndexedTree<int>\
    \ st(n);\n  for (int i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >> y;\
    \ --x;\n    if (c == 0) st.add(x, y);\n    else cout << st.sum(x, y) << endl;\n\
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n// @title BIT\u306E\u30C6\u30B9\u30C8\n\n#include \"../../datastructure/binary-indexed-tree.hpp\"\
    \n\n#include <iostream>\nusing namespace std;\n\nint main() {\n  int n, q; cin\
    \ >> n >> q;\n  BinaryIndexedTree<int> st(n);\n  for (int i = 0; i < q; ++i) {\n\
    \    int c, x, y; cin >> c >> x >> y; --x;\n    if (c == 0) st.add(x, y);\n  \
    \  else cout << st.sum(x, y) << endl;\n  }\n}\n"
  dependsOn:
  - datastructure/binary-indexed-tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.bit.test.cpp
  requiredBy: []
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.bit.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.bit.test.cpp
- /verify/test/aoj/DSL_2_B.bit.test.cpp.html
title: "BIT\u306E\u30C6\u30B9\u30C8"
---
