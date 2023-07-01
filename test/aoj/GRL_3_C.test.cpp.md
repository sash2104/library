---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly-connected-components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"test/aoj/GRL_3_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#line 1 \"graph/strongly-connected-components.hpp\"\n\n\n// @title \u5F37\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\n#include <cassert>\n#include <algorithm>\n#include\
    \ <vector>\n\n#line 1 \"graph/template.hpp\"\n\n\n\n#include <iostream>\n#line\
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
    \      }\n      ++cnt;\n    }\n  }\n};\n\n\n#line 5 \"test/aoj/GRL_3_C.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n  int V, E;\n  cin >> V >> E;\n  Graph<int>\
    \ graph(V);\n  for (int i = 0; i < E; ++i) {\n    int x, y;\n    cin >> x >> y;\n\
    \    graph[x].emplace_back(x, y);\n  }\n  stronglyConnectedComponents<int> scc(graph);\n\
    \  scc.build();\n  int Q;\n  cin >> Q;\n  for (int i = 0; i < Q; ++i) { \n   \
    \ int u, v;\n    cin >> u >> v;\n    if (scc.same(u, v)) { cout << \"1\" << endl;\
    \ }\n    else { cout << \"0\" << endl; }\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include \"../../graph/strongly-connected-components.hpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n  int V, E;\n  cin >> V >> E;\n  Graph<int>\
    \ graph(V);\n  for (int i = 0; i < E; ++i) {\n    int x, y;\n    cin >> x >> y;\n\
    \    graph[x].emplace_back(x, y);\n  }\n  stronglyConnectedComponents<int> scc(graph);\n\
    \  scc.build();\n  int Q;\n  cin >> Q;\n  for (int i = 0; i < Q; ++i) { \n   \
    \ int u, v;\n    cin >> u >> v;\n    if (scc.same(u, v)) { cout << \"1\" << endl;\
    \ }\n    else { cout << \"0\" << endl; }\n  }\n}\n"
  dependsOn:
  - graph/strongly-connected-components.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2021-08-01 23:46:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_C.test.cpp
- /verify/test/aoj/GRL_3_C.test.cpp.html
title: test/aoj/GRL_3_C.test.cpp
---
