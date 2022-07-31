---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree/add.hpp
    title: atcoder/segtree/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001sum (ac-library)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/ac-library/segtree.sum.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n#include\
    \ <iostream>\n#line 2 \"atcoder/segtree/add.hpp\"\n\n#include <atcoder/segtree>\n\
    #include <limits>\n\nnamespace segtree {\nnamespace add {\ntemplate<typename S>\n\
    S op(S a, S b) { return a+b; }\ntemplate<typename S>\nS e() { return 0;}\ntemplate<typename\
    \ S>\nusing type = atcoder::segtree<S, op, e>;\n} // namespace add\n} // namespace\
    \ segtree\n#line 5 \"test/ac-library/segtree.sum.test.cpp\"\nusing namespace std;\n\
    \n// @title \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001sum (ac-library)\nusing\
    \ ll = long long;\nint main() {\n  int n, q; cin >> n >> q;\n  segtree::add::type<ll>\
    \ seg(n);\n  for (int i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >>\
    \ y; --x;\n    if (c == 0) seg.set(x, seg.get(x) + y);\n    else cout << seg.prod(x,\
    \ y) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <iostream>\n#include \"../../atcoder/segtree/add.hpp\"\nusing namespace\
    \ std;\n\n// @title \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001sum (ac-library)\n\
    using ll = long long;\nint main() {\n  int n, q; cin >> n >> q;\n  segtree::add::type<ll>\
    \ seg(n);\n  for (int i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >>\
    \ y; --x;\n    if (c == 0) seg.set(x, seg.get(x) + y);\n    else cout << seg.prod(x,\
    \ y) << endl;\n  }\n}\n"
  dependsOn:
  - atcoder/segtree/add.hpp
  isVerificationFile: true
  path: test/ac-library/segtree.sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ac-library/segtree.sum.test.cpp
layout: document
redirect_from:
- /verify/test/ac-library/segtree.sum.test.cpp
- /verify/test/ac-library/segtree.sum.test.cpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001sum (ac-library)"
---
