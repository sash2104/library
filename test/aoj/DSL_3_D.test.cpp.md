---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/slide-min.hpp
    title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#define call_from_test\n#line 1 \"datastructure/slide-min.hpp\"\n/**\n * @title\
    \ \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\n */\n#include <iostream>\n#include\
    \ <deque>\n#include <vector>\n\ntemplate <class T>\nstd::vector<int> slideMin(const\
    \ std::vector<T>& v, int k) {\n  /* v\u306E\u9023\u7D9A\u3059\u308Bk\u533A\u9593\
    \u306E\u6700\u5C0F\u5024\u306Eindex\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\
    \ */\n  std::vector<int> ret;\n  std::deque<int> dq;\n  int n = v.size();\n  for\
    \ (int i = 0; i < n; ++i) {\n    while (dq.size() && v[dq.back()] >= v[i]) dq.pop_back();\n\
    \    dq.push_back(i);\n    if (i - k + 1 >= 0) {\n      ret.push_back(dq.front());\n\
    \      if (dq.front() <= i-k+1) dq.pop_front();\n    }\n  }\n  return ret;\n}\n\
    \n#if 0\n#include <cassert>\nint main() {\n  std::vector<int> v = {1, 3, 5, 4,\
    \ 2};\n\n  int k = 3;\n  std::vector<int> ret = slideMin(v, k);\n  assert(ret.size()\
    \ == 3);\n  assert(ret[0] == 0);\n  assert(ret[1] == 1);\n  assert(ret[2] == 4);\n\
    }\n#endif\n#line 5 \"test/aoj/DSL_3_D.test.cpp\"\n#undef call_from_test\n\n#line\
    \ 9 \"test/aoj/DSL_3_D.test.cpp\"\nusing namespace std;\n\nint main() {\n  int\
    \ n, l; cin >> n >> l;\n  vector<int> la(n);\n  for (int &a: la) cin >> a;\n\n\
    \  vector<int> ret = slideMin(la, l);\n  for (int i = 0; i < ret.size(); ++i)\
    \ {\n    if (i > 0) cout << \" \";\n    cout << la[ret[i]];\n  }\n  cout << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#define call_from_test\n#include \"../../datastructure/slide-min.hpp\"\n#undef\
    \ call_from_test\n\n#include <iostream>\n#include <vector>\nusing namespace std;\n\
    \nint main() {\n  int n, l; cin >> n >> l;\n  vector<int> la(n);\n  for (int &a:\
    \ la) cin >> a;\n\n  vector<int> ret = slideMin(la, l);\n  for (int i = 0; i <\
    \ ret.size(); ++i) {\n    if (i > 0) cout << \" \";\n    cout << la[ret[i]];\n\
    \  }\n  cout << endl;\n}\n"
  dependsOn:
  - datastructure/slide-min.hpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.test.cpp
  requiredBy: []
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.test.cpp
- /verify/test/aoj/DSL_3_D.test.cpp.html
title: test/aoj/DSL_3_D.test.cpp
---
