---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Dijkstra
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n\n\n// @title Dijkstra\n#line 1 \"\
    graph/template.hpp\"\n\n\n\n#include <iostream>\n#include <vector>\n\ntemplate<\
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
    \    }\n}\n\n\n#line 5 \"graph/dijkstra.hpp\"\n\n#include <algorithm>\n#include\
    \ <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n#line\
    \ 12 \"graph/dijkstra.hpp\"\n\ntemplate < typename T >\nstruct Dijkstra {\n  using\
    \ P = std::pair<T, int>; // <\u59CB\u70B9\u304B\u3089\u306E\u8DDD\u96E2, \u70B9\
    \u306Eid>\n  const T INF; // \u5341\u5206\u306B\u5927\u304D\u3044\u304Coverflow\u3057\
    \u306A\u3044\u5024\u3068\u3057\u3066\u3001\u578BT\u306E\u6700\u5927\u5024\u306E\
    \u534A\u5206\u3092\u4F7F\u3046\n  const int V; // \u9802\u70B9\u6570\n  Graph<T>\
    \ g;\n  std::vector<T> dist; // \u59CB\u70B9\u304B\u3089\u306E\u8DDD\u96E2\n \
    \ std::vector<bool> visit; // \u3059\u3067\u306B\u63A2\u7D22\u6E08\u307F\u306E\
    \u70B9\u304B\n  std::vector<int> prev; // \u79FB\u52D5\u7D4C\u8DEF\n  Dijkstra(Graph<T>\
    \ &g): INF(std::numeric_limits<T>::max()/2), V(g.size()), g(g), dist(V), visit(V),\
    \ prev(V) {}\n  Dijkstra(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2),\
    \ V(V), g(g), dist(V), visit(V), prev(V) {}\n  void init(int s) {\n    std::fill(dist.begin(),\
    \ dist.end(), INF);\n    std::fill(visit.begin(), visit.end(), false);\n    std::fill(prev.begin(),\
    \ prev.end(), -1);\n    dist[s] = T(); // \u59CB\u70B9\u306E\u8DDD\u96E2\u3092\
    0\u3067\u521D\u671F\u5316\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n    pq.push({dist[s], s});\n    while (!pq.empty()) {\n      P node = pq.top();\
    \ pq.pop();\n      int from = node.second;\n      if (visit[from]) continue;\n\
    \      visit[from] = true;\n      for (auto &e : g[from]) {\n        if (visit[e.to])\
    \ continue;\n        T d = node.first + e.cost;\n        if (d >= dist[e.to])\
    \ continue;\n        dist[e.to] = d;\n        prev[e.to] = from;\n        pq.push({d,\
    \ e.to});\n      }\n    }\n  }\n\n  // \u79FB\u52D5\u7D4C\u8DEF\u3092\u53D6\u5F97\
    \n  std::vector<int> get_path(int t) {\n    std::vector<int> path;\n    for(;\
    \ t != -1;t=prev[t]){\n        path.push_back(t);\n    }\n    reverse(path.begin(),\
    \ path.end());\n    return path;\n  }\n\n};\n\n\n"
  code: "#ifndef __GRAPH__DIJKSTRA\n#define __GRAPH__DIJKSTRA\n// @title Dijkstra\n\
    #include \"template.hpp\"\n\n#include <algorithm>\n#include <functional>\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\ntemplate\
    \ < typename T >\nstruct Dijkstra {\n  using P = std::pair<T, int>; // <\u59CB\
    \u70B9\u304B\u3089\u306E\u8DDD\u96E2, \u70B9\u306Eid>\n  const T INF; // \u5341\
    \u5206\u306B\u5927\u304D\u3044\u304Coverflow\u3057\u306A\u3044\u5024\u3068\u3057\
    \u3066\u3001\u578BT\u306E\u6700\u5927\u5024\u306E\u534A\u5206\u3092\u4F7F\u3046\
    \n  const int V; // \u9802\u70B9\u6570\n  Graph<T> g;\n  std::vector<T> dist;\
    \ // \u59CB\u70B9\u304B\u3089\u306E\u8DDD\u96E2\n  std::vector<bool> visit; //\
    \ \u3059\u3067\u306B\u63A2\u7D22\u6E08\u307F\u306E\u70B9\u304B\n  std::vector<int>\
    \ prev; // \u79FB\u52D5\u7D4C\u8DEF\n  Dijkstra(Graph<T> &g): INF(std::numeric_limits<T>::max()/2),\
    \ V(g.size()), g(g), dist(V), visit(V), prev(V) {}\n  Dijkstra(Graph<T> &g, int\
    \ V): INF(std::numeric_limits<T>::max()/2), V(V), g(g), dist(V), visit(V), prev(V)\
    \ {}\n  void init(int s) {\n    std::fill(dist.begin(), dist.end(), INF);\n  \
    \  std::fill(visit.begin(), visit.end(), false);\n    std::fill(prev.begin(),\
    \ prev.end(), -1);\n    dist[s] = T(); // \u59CB\u70B9\u306E\u8DDD\u96E2\u3092\
    0\u3067\u521D\u671F\u5316\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n    pq.push({dist[s], s});\n    while (!pq.empty()) {\n      P node = pq.top();\
    \ pq.pop();\n      int from = node.second;\n      if (visit[from]) continue;\n\
    \      visit[from] = true;\n      for (auto &e : g[from]) {\n        if (visit[e.to])\
    \ continue;\n        T d = node.first + e.cost;\n        if (d >= dist[e.to])\
    \ continue;\n        dist[e.to] = d;\n        prev[e.to] = from;\n        pq.push({d,\
    \ e.to});\n      }\n    }\n  }\n\n  // \u79FB\u52D5\u7D4C\u8DEF\u3092\u53D6\u5F97\
    \n  std::vector<int> get_path(int t) {\n    std::vector<int> path;\n    for(;\
    \ t != -1;t=prev[t]){\n        path.push_back(t);\n    }\n    reverse(path.begin(),\
    \ path.end());\n    return path;\n  }\n\n};\n\n#endif // __GRAPH__DIJKSTRA"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_A.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: Dijkstra
---
