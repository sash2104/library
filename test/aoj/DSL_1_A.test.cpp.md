---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/union-find-tree.hpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/aoj/DSL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#line 1 \"datastructure/union-find-tree.hpp\"\n/**\n * @title Union-Find\n */\n\
    #include <vector>\n\nclass UnionFind {\npublic:\n  std::vector<int> data; // size\u3068\
    par\u3092\u540C\u6642\u306B\u7BA1\u7406\u3059\u308B\n  UnionFind(int size) : data(size,\
    \ -1) {}\n  int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]);\
    \ }\n  void unite(int x, int y) {\n    int px = find(x);\n    int py = find(y);\n\
    \    if (px != py) {\n      if (data[py] < data[px]) std::swap(px, py);\n    \
    \  data[px] += data[py]; data[py] = px;\n    }\n  }\n  bool same(int x, int y)\
    \ { return find(x) == find(y); }\n  int size(int x) { return -data[find(x)]; }\n\
    };\n#line 3 \"test/aoj/DSL_1_A.test.cpp\"\n\n#include <iostream>\nusing namespace\
    \ std;\nint main() {\n  int n, q; cin >> n >> q;\n  UnionFind uf(n);\n  for (int\
    \ i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >> y;\n    if (c == 0)\
    \ { uf.unite(x, y); }\n    else {\n      if (uf.same(x, y)) cout << 1 << endl;\n\
    \      else cout << 0 << endl;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include \"../../datastructure/union-find-tree.hpp\"\n\n#include <iostream>\n\
    using namespace std;\nint main() {\n  int n, q; cin >> n >> q;\n  UnionFind uf(n);\n\
    \  for (int i = 0; i < q; ++i) {\n    int c, x, y; cin >> c >> x >> y;\n    if\
    \ (c == 0) { uf.unite(x, y); }\n    else {\n      if (uf.same(x, y)) cout << 1\
    \ << endl;\n      else cout << 0 << endl;\n    }\n  }\n}\n"
  dependsOn:
  - datastructure/union-find-tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-04-15 20:24:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_A.test.cpp
- /verify/test/aoj/DSL_1_A.test.cpp.html
title: test/aoj/DSL_1_A.test.cpp
---
