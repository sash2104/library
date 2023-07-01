---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bin-bfs.hpp
    title: 01-BFS
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"test/aoj/ALDS_1_11_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#line 1 \"graph/bin-bfs.hpp\"\n\n\n// @title 01-BFS\n#line 1 \"graph/template.hpp\"\
    \n\n\n\n#include <iostream>\n#include <vector>\n\ntemplate< typename T >\nstruct\
    \ Edge {\n  int from, to;\n  T cost;\n  Edge() {}\n  Edge(int f, int t) : from(f),\
    \ to(t), cost(1) {}\n  Edge(int f, int t, T c) : from(f), to(t), cost(c) {}\n\
    \  friend bool operator < (const Edge& lhs, const Edge& rhs) { return lhs.cost\
    \ < rhs.cost; };\n  friend bool operator > (const Edge& lhs, const Edge& rhs)\
    \ { return rhs < lhs; };\n  friend bool operator <= (const Edge& lhs, const Edge&\
    \ rhs) { return !(lhs > rhs); };\n  friend bool operator >= (const Edge& lhs,\
    \ const Edge& rhs) { return !(lhs < rhs); };\n};\n\ntemplate< typename T >\nusing\
    \ Edges = std::vector< Edge< T > >;\ntemplate< typename T >\nusing Graph = std::vector<\
    \ Edges< T > >;\n\ntemplate< typename T >\nvoid debug(Graph<T> &g, int n = -1)\
    \ {\n    if (n == -1) n = g.size();\n    for (int i = 0; i < n; ++i) {\n     \
    \   std::cerr << i  << \"\\t\";\n        for (auto &e: g[i]) {\n            std::cerr\
    \ << e.to << \",\";\n        }\n        std::cerr << std::endl;\n    }\n}\n\n\n\
    #line 5 \"graph/bin-bfs.hpp\"\n\n#include <algorithm>\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <utility>\n#line 12 \"graph/bin-bfs.hpp\"\
    \n\ntemplate < typename T >\nstruct BinBFS {\n  using P = std::pair<T, int>; //\
    \ <\u59CB\u70B9\u304B\u3089\u306E\u8DDD\u96E2, \u70B9\u306Eid>\n  const T INF;\
    \ // \u5341\u5206\u306B\u5927\u304D\u3044\u304Coverflow\u3057\u306A\u3044\u5024\
    \u3068\u3057\u3066\u3001\u578BT\u306E\u6700\u5927\u5024\u306E\u534A\u5206\u3092\
    \u4F7F\u3046\n  const int V; // \u9802\u70B9\u6570\n  Graph<T> g;\n  std::vector<T>\
    \ dist; // \u59CB\u70B9\u304B\u3089\u306E\u8DDD\u96E2\n  std::vector<bool> visit;\
    \ // \u3059\u3067\u306B\u63A2\u7D22\u6E08\u307F\u306E\u70B9\u304B\n  BinBFS(Graph<T>\
    \ &g): INF(std::numeric_limits<T>::max()/2), V(g.size()), g(g), dist(V), visit(V)\
    \ {}\n  BinBFS(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2), V(V),\
    \ g(g), dist(V), visit(V) {}\n  void init(int s) {\n    std::fill(dist.begin(),\
    \ dist.end(), INF);\n    std::fill(visit.begin(), visit.end(), false);\n    dist[s]\
    \ = T(); // \u59CB\u70B9\u306E\u8DDD\u96E2\u30920\u3067\u521D\u671F\u5316\n  \
    \  std::deque<P> q;\n    q.push_front({dist[s], s});\n    while (!q.empty()) {\n\
    \      P node = q.front(); q.pop_front();\n      int from = node.second;\n   \
    \   if (visit[from]) continue;\n      visit[from] = true;\n      for (auto &e\
    \ : g[from]) {\n        if (visit[e.to]) continue;\n        T d = node.first +\
    \ e.cost;\n        if (d >= dist[e.to]) continue;\n        if (e.cost == 0) {\n\
    \          q.push_front({d, e.to});\n        }\n        else {\n          q.push_back({d,\
    \ e.to});\n        }\n        dist[e.to] = d;\n      }\n    }\n  }\n};\n\n\n#line\
    \ 5 \"test/aoj/ALDS_1_11_C.test.cpp\"\nusing namespace std; \n\nint main() {\n\
    \  int n; cin >> n;\n  Graph<int> g(n);\n  for (int i = 0; i < n; ++i) {\n   \
    \ int u, k; cin >> u >> k;\n    --u;\n    for (int j = 0; j < k; ++j) {\n    \
    \  int v; cin >> v; --v;\n      g[u].emplace_back(u, v, 1);\n    }\n  }\n  BinBFS<int>\
    \ bfs(g);\n  bfs.init(0);\n  for (int i = 0; i < n; ++i) {\n    int d = bfs.dist[i];\n\
    \    if (d == bfs.INF) d = -1;\n    cout << i+1 << \" \" << d << endl;\n  }\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include \"../../graph/bin-bfs.hpp\"\n#include <iostream>\nusing namespace\
    \ std; \n\nint main() {\n  int n; cin >> n;\n  Graph<int> g(n);\n  for (int i\
    \ = 0; i < n; ++i) {\n    int u, k; cin >> u >> k;\n    --u;\n    for (int j =\
    \ 0; j < k; ++j) {\n      int v; cin >> v; --v;\n      g[u].emplace_back(u, v,\
    \ 1);\n    }\n  }\n  BinBFS<int> bfs(g);\n  bfs.init(0);\n  for (int i = 0; i\
    \ < n; ++i) {\n    int d = bfs.dist[i];\n    if (d == bfs.INF) d = -1;\n    cout\
    \ << i+1 << \" \" << d << endl;\n  }\n}\n"
  dependsOn:
  - graph/bin-bfs.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/aoj/ALDS_1_11_C.test.cpp
  requiredBy: []
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS_1_11_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS_1_11_C.test.cpp
- /verify/test/aoj/ALDS_1_11_C.test.cpp.html
title: test/aoj/ALDS_1_11_C.test.cpp
---
