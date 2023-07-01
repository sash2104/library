---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/rerooting.hpp
    title: "\u5168\u65B9\u4F4D\u6728DP (ReRooting)"
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: monoid/max.hpp
    title: monoid/max.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    document_title: "\u6728\u306E\u76F4\u5F84 (ReRooting)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "#line 1 \"test/aoj/GRL_5_A.rerooting.test.cpp\"\n// @brief \u6728\u306E\
    \u76F4\u5F84 (ReRooting)\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n\n#line 1 \"graph/rerooting.hpp\"\n/**\n * @brief \u5168\u65B9\u4F4D\u6728DP\
    \ (ReRooting)\n * https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e\n * https://github.com/noshi91/blog/blob/master/codes/rerooting.cpp\n\
    \ * \u4F7F\u7528\u4F8B: https://atcoder.jp/contests/typical90/submissions/24443488\n\
    \ * \n */\n#include <cassert>\n#include <functional>\n#include <stack>\n#include\
    \ <vector>\n#include <iostream>\n\n#line 1 \"graph/template.hpp\"\n\n\n\n#line\
    \ 6 \"graph/template.hpp\"\n\ntemplate< typename T >\nstruct Edge {\n  int from,\
    \ to;\n  T cost;\n  Edge() {}\n  Edge(int f, int t) : from(f), to(t), cost(1)\
    \ {}\n  Edge(int f, int t, T c) : from(f), to(t), cost(c) {}\n  friend bool operator\
    \ < (const Edge& lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };\n  friend\
    \ bool operator > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };\n\
    \  friend bool operator <= (const Edge& lhs, const Edge& rhs) { return !(lhs >\
    \ rhs); };\n  friend bool operator >= (const Edge& lhs, const Edge& rhs) { return\
    \ !(lhs < rhs); };\n};\n\ntemplate< typename T >\nusing Edges = std::vector< Edge<\
    \ T > >;\ntemplate< typename T >\nusing Graph = std::vector< Edges< T > >;\n\n\
    template< typename T >\nvoid debug(Graph<T> &g, int n = -1) {\n    if (n == -1)\
    \ n = g.size();\n    for (int i = 0; i < n; ++i) {\n        std::cerr << i  <<\
    \ \"\\t\";\n        for (auto &e: g[i]) {\n            std::cerr << e.to << \"\
    ,\";\n        }\n        std::cerr << std::endl;\n    }\n}\n\n\n#line 15 \"graph/rerooting.hpp\"\
    \n\ntemplate <typename Cost, class Monoid>\nstruct ReRooting {\n  struct Node\
    \ {\n    int to, rev;\n    Cost cost;\n  };\n  typedef typename Monoid::value_t\
    \ T;\n  int n; // node\u6570\n  const Monoid monoid;\n\n  std::vector<T> Res;\n\
    \  std::vector<std::vector<T>> DP;\n  std::vector<std::vector<Node>> g;\n\n  using\
    \ F = std::function<T(T, Cost)>;\n  F f; //T f(T value, Cost cost) { } \u3067\u5B9A\
    \u7FA9\u3055\u308C\u308B\u9802\u70B9\u306E\u8FFD\u52A0\u95A2\u6570\n\n  void add_edge(int\
    \ u, int v, const Cost &c) {\n    g[u].emplace_back((Node) {v, (int) g[v].size(),\
    \ c});\n    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, c});\n  }\n  void\
    \ add_edge(int u, int v, const Cost &c1, const Cost &c2) {\n    g[u].emplace_back((Node)\
    \ {v, (int) g[v].size(), c1});\n    g[v].emplace_back((Node) {u, (int) g[u].size()\
    \ - 1, c2});\n  }\n\n  ReRooting(int n, F f) : n(n), monoid(), g(n), f(f) {}\n\
    \  std::vector<T> solve() {\n    DP = std::vector<std::vector<T>>(n);\n    Res\
    \ = std::vector<T>(n, monoid.identity());\n    if (n == 1) { // FIXME: n = 1\u3082\
    \u540C\u69D8\u306B\u6271\u3048\u308B\u69D8\u306B\u3059\u308B\n      std::cerr\
    \ << \"n=1\u306F\u81EA\u5206\u3067\u6C42\u3081\u308B\u3053\u3068\" << std::endl;\n\
    \      assert(false);\n    }\n\n    for (int i = 0; i < n; i++) {\n      DP[i]\
    \ = std::vector<T>(g[i].size());\n    }\n    init();\n    return Res;\n  }\n\n\
    \  void init() {\n    // parents[i] := \u4E00\u6642\u7684\u306A\u6839\u4ED8\u304D\
    \u6728\u3068\u3057\u3066\u8003\u3048\u305F\u6642\u306E\u3001\u30CE\u30FC\u30C9\
    i\u306B\u3064\u3044\u3066\u306E\u89AA\n    std::vector<int> parents(n);\n    std::vector<int>\
    \ order(n); // dfs\u3067\u306E\u884C\u304D\u304C\u3051\u9806\n\n    int index\
    \ = 0;\n    std::stack<int> stack;\n    // 0\u3092\u6839\u3068\u3059\u308B\n \
    \   stack.push(0);\n    parents[0] = -1;\n    // \u884C\u304D\u304C\u3051\u9806\
    \u3092\u8A18\u9332\u3059\u308B\n    while (stack.size() > 0) {\n      int nodeId\
    \ = stack.top();\n      stack.pop();\n      order[index++] = nodeId;\n      for\
    \ (auto &node: g[nodeId]) {\n        if (node.to == parents[nodeId])\n       \
    \   continue;\n        stack.push(node.to);\n        parents[node.to] = nodeId;\n\
    \      }\n    }\n\n    //\u5E30\u308A\u304C\u3051\u9806\u3067\u90E8\u5206\u6728\
    \u306E\u5024\u3092\u6C42\u3081\u3066\u3044\u304F\n    for (int i = order.size()\
    \ - 1; i >= 1; i--) {\n      int nodeId = order[i];\n      int parent = parents[nodeId];\n\
    \      T accum = monoid.identity();\n      int parentId = -1;\n      for (int\
    \ j = 0; j < g[nodeId].size(); j++) {\n        if (g[nodeId][j].to == parent)\
    \ {\n          parentId = j;\n          continue;\n        }\n        accum =\
    \ monoid.merge(accum, DP[nodeId][j]);\n      }\n      int childId = g[nodeId][parentId].rev;\n\
    \      DP[parent][childId] = f(accum, g[parent][childId].cost);\n      // std::cerr\
    \ << parent << \"->\" << childId << \" \" << DP[parent][childId] << std::endl;\n\
    \    }\n\n    //\u884C\u304D\u304C\u3051\u9806\u3067\u9802\u70B9\u306E\u5024\u3092\
    \u78BA\u5B9A\u3055\u305B\u3066\u3044\u304F\n    for (int i = 0; i < order.size();\
    \ i++) {\n      int nodeId = order[i];\n      T accum = monoid.identity();\n \
    \     int numChild = g[nodeId].size();\n      std::vector<T> rdp(numChild);\n\
    \      rdp[numChild-1] = monoid.identity();\n      for (int j = numChild-1; j\
    \ >= 1; j--) {\n        rdp[j - 1] = monoid.merge(DP[nodeId][j], rdp[j]);\n  \
    \    }\n      for (int j = 0; j < numChild; j++) {\n        auto &node = g[nodeId][j];\n\
    \        DP[node.to][node.rev] = f(monoid.merge(accum, rdp[j]), g[node.to][node.rev].cost);\n\
    \        accum = monoid.merge(accum, DP[nodeId][j]);\n      }\n      // FIXME:\
    \ \u3053\u3053\u3001monoid.identity()\u306E\u5024\u3092\u6C17\u3092\u3064\u3051\
    \u306A\u3044\u3068child\u6570\u304C0\u306E\u5834\u5408\u306B\u30D0\u30B0\u308B\
    \u6C17\u304C\u3059\u308B\n      Res[nodeId] = accum;\n    }\n  }\n};\n#line 1\
    \ \"monoid/max.hpp\"\n\n\n#include <algorithm>\n#include <limits>\n\nnamespace\
    \ monoid {\ntemplate <class T>\nstruct max {\n  typedef T value_t;\n  T identity()\
    \ const { return std::numeric_limits<T>::min();}\n  T merge(T a, T b) const {\
    \ return std::max(a, b); }\n};\n} // namespace monoid\n\n\n#line 6 \"test/aoj/GRL_5_A.rerooting.test.cpp\"\
    \n\nusing namespace std;\n#line 9 \"test/aoj/GRL_5_A.rerooting.test.cpp\"\n\n\
    // rerooting\u3067\u3001\u5404\u9802\u70B9\u306B\u3064\u3044\u3066\u6700\u3082\
    \u9060\u3044\u9802\u70B9\u3068\u306E\u8DDD\u96E2\u3092\u3082\u3068\u3081\u308B\
    \u3002\u7B54\u3048\u306F\u305D\u306E\u6700\u5927\u5024\nint main() {\n  int N;\
    \ cin >> N;\n  auto f=[](int value, int cost) -> int { \n    if (value < 0) return\
    \ cost;\n    return value+cost;\n  };\n  ReRooting<int, monoid::max<int>> rerooting(N,\
    \ f);\n  for(int i = 1; i < N; i++) {\n    int x, y, z; cin >> x >> y >> z;\n\
    \    rerooting.add_edge(x, y, z);\n  }\n  if (N == 1) {\n    cout << 0 << endl;\n\
    \    return 0;\n  }\n  auto ret = rerooting.solve();\n  int ans = 0;\n  for (int\
    \ i = 0; i < N; ++i) {\n    ans = max(ans, ret[i]);\n  }\n  cout << ans << endl;\n\
    }\n"
  code: "// @brief \u6728\u306E\u76F4\u5F84 (ReRooting)\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n\n#include \"../../graph/rerooting.hpp\"\n#include \"../../monoid/max.hpp\"\n\
    \nusing namespace std;\n#include <iostream>\n\n// rerooting\u3067\u3001\u5404\u9802\
    \u70B9\u306B\u3064\u3044\u3066\u6700\u3082\u9060\u3044\u9802\u70B9\u3068\u306E\
    \u8DDD\u96E2\u3092\u3082\u3068\u3081\u308B\u3002\u7B54\u3048\u306F\u305D\u306E\
    \u6700\u5927\u5024\nint main() {\n  int N; cin >> N;\n  auto f=[](int value, int\
    \ cost) -> int { \n    if (value < 0) return cost;\n    return value+cost;\n \
    \ };\n  ReRooting<int, monoid::max<int>> rerooting(N, f);\n  for(int i = 1; i\
    \ < N; i++) {\n    int x, y, z; cin >> x >> y >> z;\n    rerooting.add_edge(x,\
    \ y, z);\n  }\n  if (N == 1) {\n    cout << 0 << endl;\n    return 0;\n  }\n \
    \ auto ret = rerooting.solve();\n  int ans = 0;\n  for (int i = 0; i < N; ++i)\
    \ {\n    ans = max(ans, ret[i]);\n  }\n  cout << ans << endl;\n}"
  dependsOn:
  - graph/rerooting.hpp
  - graph/template.hpp
  - monoid/max.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.rerooting.test.cpp
  requiredBy: []
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.rerooting.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.rerooting.test.cpp
- /verify/test/aoj/GRL_5_A.rerooting.test.cpp.html
title: "\u6728\u306E\u76F4\u5F84 (ReRooting)"
---
