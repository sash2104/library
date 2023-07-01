---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    document_title: Disjoint Set Union (ac-library)
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/ac-library/dsu.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <iostream>\n#include <atcoder/dsu>\nusing namespace std;\nusing namespace\
    \ atcoder;\n// @title Disjoint Set Union (ac-library)\n\nint main() {\n  int n,\
    \ q; cin >> n >> q;\n  dsu d(n);\n  for (int i = 0; i < q; ++i) {\n    int c,\
    \ x, y; cin >> c >> x >> y;\n    if (c == 0) { d.merge(x, y); }\n    else {\n\
    \      if (d.same(x, y)) { cout << 1 << endl; }\n      else { cout << 0 << endl;\
    \ }\n    }\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <iostream>\n#include <atcoder/dsu>\nusing namespace std;\nusing namespace\
    \ atcoder;\n// @title Disjoint Set Union (ac-library)\n\nint main() {\n  int n,\
    \ q; cin >> n >> q;\n  dsu d(n);\n  for (int i = 0; i < q; ++i) {\n    int c,\
    \ x, y; cin >> c >> x >> y;\n    if (c == 0) { d.merge(x, y); }\n    else {\n\
    \      if (d.same(x, y)) { cout << 1 << endl; }\n      else { cout << 0 << endl;\
    \ }\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/ac-library/dsu.test.cpp
  requiredBy: []
  timestamp: '2020-09-29 21:53:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ac-library/dsu.test.cpp
layout: document
redirect_from:
- /verify/test/ac-library/dsu.test.cpp
- /verify/test/ac-library/dsu.test.cpp.html
title: Disjoint Set Union (ac-library)
---
