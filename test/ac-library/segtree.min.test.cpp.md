---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree/min.hpp
    title: atcoder/segtree/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001min (ac-library)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/ac-library/segtree.min.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\n\n#include\
    \ <iostream>\n#line 2 \"atcoder/segtree/min.hpp\"\n\n#include <atcoder/segtree>\n\
    #include <limits>\n\nnamespace segtree {\nnamespace min {\ntemplate<typename S>\n\
    S op(S a, S b) { return std::min(a, b); }\ntemplate<typename S>\nS e() { return\
    \ std::numeric_limits<S>::max();}\ntemplate<typename S>\nusing type = atcoder::segtree<S,\
    \ op, e>;\n} // namespace min\n} // namespace segtree\n#line 5 \"test/ac-library/segtree.min.test.cpp\"\
    \nusing namespace std;\n\n// @title \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001\
    min (ac-library)\nint main() {\n  int n, q; cin >> n >> q;\n  segtree::min::type<int>\
    \ seg(n);\n  for (int i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >>\
    \ y;\n    if (c == 0) seg.set(x, y);\n    else cout << seg.prod(x, y+1) << endl;\n\
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <iostream>\n#include \"../../atcoder/segtree/min.hpp\"\nusing namespace\
    \ std;\n\n// @title \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001min (ac-library)\n\
    int main() {\n  int n, q; cin >> n >> q;\n  segtree::min::type<int> seg(n);\n\
    \  for (int i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >> y;\n    if\
    \ (c == 0) seg.set(x, y);\n    else cout << seg.prod(x, y+1) << endl;\n  }\n}\n"
  dependsOn:
  - atcoder/segtree/min.hpp
  isVerificationFile: true
  path: test/ac-library/segtree.min.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ac-library/segtree.min.test.cpp
layout: document
redirect_from:
- /verify/test/ac-library/segtree.min.test.cpp
- /verify/test/ac-library/segtree.min.test.cpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3001min (ac-library)"
---
