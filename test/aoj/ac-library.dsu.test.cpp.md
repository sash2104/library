---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/aoj/ac-library.dsu.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <atcoder/dsu>\n\n#include <iostream>\nusing namespace std;\nusing namespace\
    \ atcoder;\n\nint main() {\n  int n, q; cin >> n >> q;\n  dsu d(n);\n  for (int\
    \ i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >> y;\n    if (c == 0)\
    \ { d.merge(x, y); }\n    else {\n      if (d.same(x, y)) {\n        cout << 1\
    \ << endl;\n      }\n      else {\n        cout << 0 << endl;\n      }\n    }\n\
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <atcoder/dsu>\n\n#include <iostream>\nusing namespace std;\nusing namespace\
    \ atcoder;\n\nint main() {\n  int n, q; cin >> n >> q;\n  dsu d(n);\n  for (int\
    \ i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >> y;\n    if (c == 0)\
    \ { d.merge(x, y); }\n    else {\n      if (d.same(x, y)) {\n        cout << 1\
    \ << endl;\n      }\n      else {\n        cout << 0 << endl;\n      }\n    }\n\
    \  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/ac-library.dsu.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 21:41:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ac-library.dsu.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ac-library.dsu.test.cpp
- /verify/test/aoj/ac-library.dsu.test.cpp.html
title: test/aoj/ac-library.dsu.test.cpp
---
