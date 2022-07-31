---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30B0\u30EA\u30C3\u30C9\u30B0\u30E9\u30D5"
    links:
    - https://atcoder.jp/contests/abc020/submissions/18517344
  bundledCode: "#line 1 \"graph/grid-graph.hpp\"\n\n\n/**\n * @brief \u30B0\u30EA\u30C3\
    \u30C9\u30B0\u30E9\u30D5\n * \u4F7F\u7528\u4F8B: https://atcoder.jp/contests/abc020/submissions/18517344\n\
    \ * \n */\n#line 1 \"graph/template.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <vector>\n\ntemplate< typename T >\nstruct Edge {\n  int from, to;\n  T cost;\n\
    \  Edge() {}\n  Edge(int f, int t) : from(f), to(t), cost(1) {}\n  Edge(int f,\
    \ int t, T c) : from(f), to(t), cost(c) {}\n  friend bool operator < (const Edge&\
    \ lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };\n  friend bool operator\
    \ > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };\n  friend bool operator\
    \ <= (const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); };\n  friend bool\
    \ operator >= (const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };\n};\n\
    \ntemplate< typename T >\nusing Edges = std::vector< Edge< T > >;\ntemplate< typename\
    \ T >\nusing Graph = std::vector< Edges< T > >;\n\ntemplate< typename T >\nvoid\
    \ debug(Graph<T> &g, int n = -1) {\n    if (n == -1) n = g.size();\n    for (int\
    \ i = 0; i < n; ++i) {\n        std::cerr << i  << \"\\t\";\n        for (auto\
    \ &e: g[i]) {\n            std::cerr << e.to << \",\";\n        }\n        std::cerr\
    \ << std::endl;\n    }\n}\n\n\n#line 9 \"graph/grid-graph.hpp\"\n#include <cassert>\n\
    #include <string>\n#line 12 \"graph/grid-graph.hpp\"\n\nnamespace grid_graph {\n\
    using grid_t = std::vector<std::string>;\nint H, W;\nint dx[4] = {0, 1, 0, -1};\n\
    int dy[4] = {1, 0, -1, 0};\nint xy2id(int x, int y) { return y*W+x; }\nint id2x(int\
    \ id) { return id%W; }\nint id2y(int id) { return id/W; }\nbool outside(int x,\
    \ int y) {\n    if (x < 0 || x >= W) return true;\n    if (y < 0 || y >= H) return\
    \ true;\n    return false;\n}\n\nint cost(char c) {\n    // FIXME: \u3053\u3053\
    \u3092\u5B9F\u88C5\u3059\u308B\n    int inf = 1<<30;\n    if (c == '#') return\
    \ inf;\n    return 1;\n}\n\nGraph<int> build(const grid_t& grid) {\n    Graph<int>\
    \ ret(H*W);\n    assert(grid.size() == H);\n    assert(grid[0].size() == W);\n\
    \    for (int y = 0; y < H; ++y) {\n        for (int x = 0; x < W; ++x) {\n  \
    \          int id = xy2id(x,y);\n            for (int d = 0; d < 4; ++d) {\n \
    \               int nx = x+dx[d];\n                int ny = y+dy[d];\n       \
    \         if (outside(nx,ny)) continue;\n                int nid = xy2id(nx,ny);\n\
    \                int c = cost(grid[ny][nx]);\n                ret[id].emplace_back(id,\
    \ nid, c);\n            }\n        }\n    }\n    return ret;\n}\n\nint find_pos(const\
    \ grid_t& grid, char c) {\n    // c\u304C\u521D\u3081\u306B\u898B\u3064\u304B\u3063\
    \u305F\u4F4D\u7F6E\u3092\u8FD4\u3059\n    // \u898B\u3064\u304B\u3089\u306A\u3051\
    \u308C\u3070-1\n    for (int y = 0; y < H; ++y) {\n        for (int x = 0; x <\
    \ W; ++x) {\n            if (grid[y][x] == c) {\n                return xy2id(x,y);\n\
    \            }\n        }\n    }\n    return -1;\n}\n} // namespace grid_graph\n\
    \n\n"
  code: "#ifndef __GRAPH__GRID__GRAPH\n#define __GRAPH__GRID__GRAPH\n/**\n * @brief\
    \ \u30B0\u30EA\u30C3\u30C9\u30B0\u30E9\u30D5\n * \u4F7F\u7528\u4F8B: https://atcoder.jp/contests/abc020/submissions/18517344\n\
    \ * \n */\n#include \"template.hpp\"\n#include <cassert>\n#include <string>\n\
    #include <vector>\n\nnamespace grid_graph {\nusing grid_t = std::vector<std::string>;\n\
    int H, W;\nint dx[4] = {0, 1, 0, -1};\nint dy[4] = {1, 0, -1, 0};\nint xy2id(int\
    \ x, int y) { return y*W+x; }\nint id2x(int id) { return id%W; }\nint id2y(int\
    \ id) { return id/W; }\nbool outside(int x, int y) {\n    if (x < 0 || x >= W)\
    \ return true;\n    if (y < 0 || y >= H) return true;\n    return false;\n}\n\n\
    int cost(char c) {\n    // FIXME: \u3053\u3053\u3092\u5B9F\u88C5\u3059\u308B\n\
    \    int inf = 1<<30;\n    if (c == '#') return inf;\n    return 1;\n}\n\nGraph<int>\
    \ build(const grid_t& grid) {\n    Graph<int> ret(H*W);\n    assert(grid.size()\
    \ == H);\n    assert(grid[0].size() == W);\n    for (int y = 0; y < H; ++y) {\n\
    \        for (int x = 0; x < W; ++x) {\n            int id = xy2id(x,y);\n   \
    \         for (int d = 0; d < 4; ++d) {\n                int nx = x+dx[d];\n \
    \               int ny = y+dy[d];\n                if (outside(nx,ny)) continue;\n\
    \                int nid = xy2id(nx,ny);\n                int c = cost(grid[ny][nx]);\n\
    \                ret[id].emplace_back(id, nid, c);\n            }\n        }\n\
    \    }\n    return ret;\n}\n\nint find_pos(const grid_t& grid, char c) {\n   \
    \ // c\u304C\u521D\u3081\u306B\u898B\u3064\u304B\u3063\u305F\u4F4D\u7F6E\u3092\
    \u8FD4\u3059\n    // \u898B\u3064\u304B\u3089\u306A\u3051\u308C\u3070-1\n    for\
    \ (int y = 0; y < H; ++y) {\n        for (int x = 0; x < W; ++x) {\n         \
    \   if (grid[y][x] == c) {\n                return xy2id(x,y);\n            }\n\
    \        }\n    }\n    return -1;\n}\n} // namespace grid_graph\n\n#endif // __GRAPH__GRID__GRAPH"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/grid-graph.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/grid-graph.hpp
layout: document
redirect_from:
- /library/graph/grid-graph.hpp
- /library/graph/grid-graph.hpp.html
title: "\u30B0\u30EA\u30C3\u30C9\u30B0\u30E9\u30D5"
---
