---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/warshall-floyd.hpp
    title: warshall-floyd
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/aoj/GRL_1_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#line 1 \"graph/warshall-floyd.hpp\"\n\n\n// @title warshall-floyd\n#line 1\
    \ \"graph/template.hpp\"\n\n\n\n#include <iostream>\n#include <vector>\n\ntemplate<\
    \ typename T >\nstruct Edge {\n  int from, to;\n  T cost;\n  Edge() {}\n  Edge(int\
    \ f, int t) : from(f), to(t), cost(1) {}\n  Edge(int f, int t, T c) : from(f),\
    \ to(t), cost(c) {}\n  friend bool operator < (const Edge& lhs, const Edge& rhs)\
    \ { return lhs.cost < rhs.cost; };\n  friend bool operator > (const Edge& lhs,\
    \ const Edge& rhs) { return rhs < lhs; };\n  friend bool operator <= (const Edge&\
    \ lhs, const Edge& rhs) { return !(lhs > rhs); };\n  friend bool operator >= (const\
    \ Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };\n};\n\ntemplate< typename\
    \ T >\nusing Edges = std::vector< Edge< T > >;\ntemplate< typename T >\nusing\
    \ Graph = std::vector< Edges< T > >;\n\ntemplate< typename T >\nvoid debug(Graph<T>\
    \ &g, int n = -1) {\n    if (n == -1) n = g.size();\n    for (int i = 0; i < n;\
    \ ++i) {\n        std::cerr << i  << \"\\t\";\n        for (auto &e: g[i]) {\n\
    \            std::cerr << e.to << \",\";\n        }\n        std::cerr << std::endl;\n\
    \    }\n}\n\n\n#line 5 \"graph/warshall-floyd.hpp\"\n\n#include <limits>\n#line\
    \ 8 \"graph/warshall-floyd.hpp\"\n\ntemplate < typename T >\nstruct WarshallFloyd\
    \ {\n  const T INF; // dijkstra\u3068INF\u306E\u5024\u3092\u63C3\u3048\u308B\u305F\
    \u3081\u3001\u578BT\u306E\u6700\u5927\u5024\u306E\u534A\u5206\u3092\u4F7F\u3046\
    \n  const int V; // \u9802\u70B9\u6570\n  Graph<T> g;\n  std::vector<std::vector<T>>\
    \ dist;\n  WarshallFloyd(Graph<T> &g): INF(std::numeric_limits<T>::max()/2), V(g.size()),\
    \ g(g), dist(V, std::vector<T>(V, INF)) { init(); }\n  WarshallFloyd(Graph<T>\
    \ &g, int V): INF(std::numeric_limits<T>::max()/2), V(V), g(g), dist(V, std::vector<T>(V,\
    \ INF)) { init(); }\n  void init() {\n    for (int i = 0; i < V; ++i) {\n    \
    \  dist[i][i] = 0;\n      for (auto &e: g[i]) dist[i][e.to] = e.cost;\n    }\n\
    \    for (int k = 0; k < V; ++k) {\n      for (int i = 0; i < V; ++i) {\n    \
    \    for (int j = 0; j < V; ++j) {\n          if (dist[i][k] == INF || dist[k][j]\
    \ == INF) continue;\n          T d = dist[i][k]+dist[k][j];\n          if (dist[i][j]\
    \ > d) dist[i][j] = d;\n        }\n      }\n    }\n  }\n  bool has_negative_cycle()\
    \ {\n    for (int i = 0; i < V; ++i) {\n      if (dist[i][i] < 0) return true;\n\
    \    }\n    return false;\n  }\n};\n\n\n#line 3 \"test/aoj/GRL_1_C.test.cpp\"\n\
    \n#line 5 \"test/aoj/GRL_1_C.test.cpp\"\nusing namespace std;\n\ntypedef long\
    \ long ll;\n\nint main() {\n  int V, E;\n  cin >> V >> E;\n  Graph<ll> g(V);\n\
    \  for (int i = 0; i < E; ++i) {\n    int x, y; ll d;\n    cin >> x >> y >> d;\n\
    \    g[x].emplace_back(x, y, d);\n  }\n  WarshallFloyd<ll> wf(g);\n  if (wf.has_negative_cycle())\
    \ {\n    cout << \"NEGATIVE CYCLE\" << endl;\n    return 0;\n  }\n  for (int i\
    \ = 0; i < V; ++i) {\n    for (int j = 0; j < V; ++j) {\n      if (j > 0) cout\
    \ << \" \";\n      if (wf.dist[i][j] == wf.INF) cout << \"INF\";\n      else cout\
    \ << wf.dist[i][j];\n    }\n    cout << endl;\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include \"../../graph/warshall-floyd.hpp\"\n\n#include <iostream>\nusing namespace\
    \ std;\n\ntypedef long long ll;\n\nint main() {\n  int V, E;\n  cin >> V >> E;\n\
    \  Graph<ll> g(V);\n  for (int i = 0; i < E; ++i) {\n    int x, y; ll d;\n   \
    \ cin >> x >> y >> d;\n    g[x].emplace_back(x, y, d);\n  }\n  WarshallFloyd<ll>\
    \ wf(g);\n  if (wf.has_negative_cycle()) {\n    cout << \"NEGATIVE CYCLE\" <<\
    \ endl;\n    return 0;\n  }\n  for (int i = 0; i < V; ++i) {\n    for (int j =\
    \ 0; j < V; ++j) {\n      if (j > 0) cout << \" \";\n      if (wf.dist[i][j] ==\
    \ wf.INF) cout << \"INF\";\n      else cout << wf.dist[i][j];\n    }\n    cout\
    \ << endl;\n  }\n}\n"
  dependsOn:
  - graph/warshall-floyd.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C.test.cpp
- /verify/test/aoj/GRL_1_C.test.cpp.html
title: test/aoj/GRL_1_C.test.cpp
---
