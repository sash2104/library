---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"graph/strongly-connected-components.hpp\"\n\n\n// @title\
    \ \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n#include <cassert>\n#include <algorithm>\n\
    #include <vector>\n\n#line 1 \"graph/template.hpp\"\n\n\n\n#include <iostream>\n\
    #line 6 \"graph/template.hpp\"\n\ntemplate< typename T >\nstruct Edge {\n  int\
    \ from, to;\n  T cost;\n  Edge() {}\n  Edge(int f, int t) : from(f), to(t), cost(1)\
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
    ,\";\n        }\n        std::cerr << std::endl;\n    }\n}\n\n\n#line 9 \"graph/strongly-connected-components.hpp\"\
    \nusing namespace std;\n\ntemplate< typename T >\nstruct stronglyConnectedComponents\
    \ {\n  using graph = Graph<T>;\n  const int V;\n  graph g, rg;\n  vector<bool>\
    \ visit;\n  vector<int> comp, order;\n  vector<vector<int>> components;\n\n  stronglyConnectedComponents(const\
    \ graph &g) : V(g.size()), g(g), rg(V), visit(V, false), comp(V, -1) {\n    //\
    \ \u8FBA\u306E\u5411\u304D\u3092\u9006\u306B\u3057\u305F\u30B0\u30E9\u30D5\u3092\
    \u69CB\u7BC9\n    for (int v = 0; v < V; ++v) {\n      for (auto &e : g[v]) {\
    \ \n        rg[e.to].emplace_back(e.to, e.from);\n      }\n    }\n  }\n\n  //\
    \ \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\u3044\u308C\
    \u3070true\u3092\u8FD4\u3059\n  bool same(int s, int t) {\n    assert(comp[s]\
    \ != -1 && comp[t] != -1);\n    return comp[s] == comp[t];\n  }\n\n  void dfs(int\
    \ sv) { \n    if (visit[sv]) return;\n    visit[sv] = true;\n    for (auto &e\
    \ : g[sv]) { \n      dfs(e.to);\n    }\n    order.push_back(sv);\n  }\n\n  void\
    \ rdfs(int sv, int cnt) { \n    if (comp[sv] != -1) return;\n    comp[sv] = cnt;\n\
    \n    if (components.size() <= cnt) { \n      vector<int> v;\n      components.push_back(v);\n\
    \    }\n    components[cnt].push_back(sv);\n\n    for (auto &e : rg[sv]) { \n\
    \      rdfs(e.to, cnt);\n    }\n  }\n\n  void build() {\n    for(int i = 0; i\
    \ < V; i++) { dfs(i); } \n    assert(order.size() == V);\n    reverse(order.begin(),\
    \ order.end()); // dfs\u3067\u3064\u3051\u305F\u756A\u53F7\u3092\u9006\u9806\u306B\
    \u3059\u308B\n    int cnt = 0; // \u5F37\u9023\u7D50\u6210\u5206\u6BCE\u306Eid\n\
    \    for (int v : order) { \n      if (comp[v] != -1) continue;\n      rdfs(v,\
    \ cnt);\n      // \u5F37\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u3092\u30EB\
    \u30FC\u30D7\u306E\u9806\u306B\u4E26\u3073\u66FF\u3048\n      if (components[cnt].size()\
    \ > 1) {\n        reverse(components[cnt].begin()+1, components[cnt].end());\n\
    \      }\n      ++cnt;\n    }\n  }\n};\n\n\n"
  code: "#ifndef __GRAPH__SCC\n#define __GRAPH__SCC\n// @title \u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\n#include <cassert>\n#include <algorithm>\n#include <vector>\n\
    \n#include \"template.hpp\"\nusing namespace std;\n\ntemplate< typename T >\n\
    struct stronglyConnectedComponents {\n  using graph = Graph<T>;\n  const int V;\n\
    \  graph g, rg;\n  vector<bool> visit;\n  vector<int> comp, order;\n  vector<vector<int>>\
    \ components;\n\n  stronglyConnectedComponents(const graph &g) : V(g.size()),\
    \ g(g), rg(V), visit(V, false), comp(V, -1) {\n    // \u8FBA\u306E\u5411\u304D\
    \u3092\u9006\u306B\u3057\u305F\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n    for (int\
    \ v = 0; v < V; ++v) {\n      for (auto &e : g[v]) { \n        rg[e.to].emplace_back(e.to,\
    \ e.from);\n      }\n    }\n  }\n\n  // \u540C\u3058\u5F37\u9023\u7D50\u6210\u5206\
    \u306B\u5C5E\u3057\u3066\u3044\u308C\u3070true\u3092\u8FD4\u3059\n  bool same(int\
    \ s, int t) {\n    assert(comp[s] != -1 && comp[t] != -1);\n    return comp[s]\
    \ == comp[t];\n  }\n\n  void dfs(int sv) { \n    if (visit[sv]) return;\n    visit[sv]\
    \ = true;\n    for (auto &e : g[sv]) { \n      dfs(e.to);\n    }\n    order.push_back(sv);\n\
    \  }\n\n  void rdfs(int sv, int cnt) { \n    if (comp[sv] != -1) return;\n   \
    \ comp[sv] = cnt;\n\n    if (components.size() <= cnt) { \n      vector<int> v;\n\
    \      components.push_back(v);\n    }\n    components[cnt].push_back(sv);\n\n\
    \    for (auto &e : rg[sv]) { \n      rdfs(e.to, cnt);\n    }\n  }\n\n  void build()\
    \ {\n    for(int i = 0; i < V; i++) { dfs(i); } \n    assert(order.size() == V);\n\
    \    reverse(order.begin(), order.end()); // dfs\u3067\u3064\u3051\u305F\u756A\
    \u53F7\u3092\u9006\u9806\u306B\u3059\u308B\n    int cnt = 0; // \u5F37\u9023\u7D50\
    \u6210\u5206\u6BCE\u306Eid\n    for (int v : order) { \n      if (comp[v] != -1)\
    \ continue;\n      rdfs(v, cnt);\n      // \u5F37\u9023\u7D50\u6210\u5206\u306E\
    \u9802\u70B9\u3092\u30EB\u30FC\u30D7\u306E\u9806\u306B\u4E26\u3073\u66FF\u3048\
    \n      if (components[cnt].size() > 1) {\n        reverse(components[cnt].begin()+1,\
    \ components[cnt].end());\n      }\n      ++cnt;\n    }\n  }\n};\n\n#endif //\
    \ __GRAPH__SCC"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/strongly-connected-components.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_C.test.cpp
documentation_of: graph/strongly-connected-components.hpp
layout: document
redirect_from:
- /library/graph/strongly-connected-components.hpp
- /library/graph/strongly-connected-components.hpp.html
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
