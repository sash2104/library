---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS_1_11_C.test.cpp
    title: test/aoj/ALDS_1_11_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: 01-BFS
    links: []
  bundledCode: "#line 1 \"graph/bin-bfs.hpp\"\n\n\n// @title 01-BFS\n#line 1 \"graph/template.hpp\"\
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
    \ e.to});\n        }\n        dist[e.to] = d;\n      }\n    }\n  }\n};\n\n\n"
  code: "#ifndef __GRAPH__BIN__BFS\n#define __GRAPH__BIN__BFS\n// @title 01-BFS\n\
    #include \"template.hpp\"\n\n#include <algorithm>\n#include <functional>\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\ntemplate\
    \ < typename T >\nstruct BinBFS {\n  using P = std::pair<T, int>; // <\u59CB\u70B9\
    \u304B\u3089\u306E\u8DDD\u96E2, \u70B9\u306Eid>\n  const T INF; // \u5341\u5206\
    \u306B\u5927\u304D\u3044\u304Coverflow\u3057\u306A\u3044\u5024\u3068\u3057\u3066\
    \u3001\u578BT\u306E\u6700\u5927\u5024\u306E\u534A\u5206\u3092\u4F7F\u3046\n  const\
    \ int V; // \u9802\u70B9\u6570\n  Graph<T> g;\n  std::vector<T> dist; // \u59CB\
    \u70B9\u304B\u3089\u306E\u8DDD\u96E2\n  std::vector<bool> visit; // \u3059\u3067\
    \u306B\u63A2\u7D22\u6E08\u307F\u306E\u70B9\u304B\n  BinBFS(Graph<T> &g): INF(std::numeric_limits<T>::max()/2),\
    \ V(g.size()), g(g), dist(V), visit(V) {}\n  BinBFS(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2),\
    \ V(V), g(g), dist(V), visit(V) {}\n  void init(int s) {\n    std::fill(dist.begin(),\
    \ dist.end(), INF);\n    std::fill(visit.begin(), visit.end(), false);\n    dist[s]\
    \ = T(); // \u59CB\u70B9\u306E\u8DDD\u96E2\u30920\u3067\u521D\u671F\u5316\n  \
    \  std::deque<P> q;\n    q.push_front({dist[s], s});\n    while (!q.empty()) {\n\
    \      P node = q.front(); q.pop_front();\n      int from = node.second;\n   \
    \   if (visit[from]) continue;\n      visit[from] = true;\n      for (auto &e\
    \ : g[from]) {\n        if (visit[e.to]) continue;\n        T d = node.first +\
    \ e.cost;\n        if (d >= dist[e.to]) continue;\n        if (e.cost == 0) {\n\
    \          q.push_front({d, e.to});\n        }\n        else {\n          q.push_back({d,\
    \ e.to});\n        }\n        dist[e.to] = d;\n      }\n    }\n  }\n};\n\n#endif\
    \ // __GRAPH__BIN__BFS"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/bin-bfs.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS_1_11_C.test.cpp
documentation_of: graph/bin-bfs.hpp
layout: document
redirect_from:
- /library/graph/bin-bfs.hpp
- /library/graph/bin-bfs.hpp.html
title: 01-BFS
---
