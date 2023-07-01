---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
    links:
    - https://atcoder.jp/contests/typical90/submissions/23946854
    - https://imoz.jp/algorithms/imos_method.html
  bundledCode: "#line 1 \"datastructure/ruisekiwa2d.hpp\"\n\n\n/**\n * @title \u4E8C\
    \u6B21\u5143\u7D2F\u7A4D\u548C\n * @brief \u7E26H\u6A2AW\u306E\u7BC4\u56F2\u306E\
    \u77E9\u5F62\u306B\u5BFE\u3057add\u3092N\u56DE\u3057\u305F\u3068\u304D\u3001\u524D\
    \u51E6\u7406 $O(N+HW)$\u3001\u53D6\u5F97$O(1)$\n * @see https://atcoder.jp/contests/typical90/submissions/23946854\n\
    \ */\n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\nstruct Ruisekiwa2D\
    \ {\n    int W, H;\n    std::vector<std::vector<int>> v;\n    Ruisekiwa2D(int\
    \ W, int H): W(W), H(H), v(H, std::vector<int>(W)) {}\n    void add(int sx, int\
    \ sy, int tx, int ty, int c) {\n        // x = [sx,tx], y = [sy,ty] \u306E\u7BC4\
    \u56F2\u306E\u9577\u65B9\u5F62\u306Bc\u3092\u52A0\u3048\u308B\n        // @see\
    \ https://imoz.jp/algorithms/imos_method.html\n        assert(sx < tx && sy <\
    \ ty);\n        v[sy][sx] += c;\n        v[sy][tx] -= c;\n        v[ty][sx] -=\
    \ c;\n        v[ty][tx] += c;\n    }\n    void build() {\n        for (int y =\
    \ 0; y < H; ++y) {\n            for (int x = 0; x < W; ++x) {\n              \
    \  if (0 < y) v[y][x] += v[y - 1][x];\n                if (0 < x) v[y][x] += v[y][x\
    \ - 1];\n                if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];\n   \
    \         }\n        }\n    }\n    int get(int x, int y) {\n        return v[y][x];\n\
    \    }\n    void show(int sx, int sy, int tx, int ty) {\n        // x = [sx,tx],\
    \ y = [sy,ty] \u306E\u7BC4\u56F2\u306E\u9577\u65B9\u5F62\u3092\u8868\u793A\u3059\
    \u308B\n        for (int y = sy; y < ty; ++y) {\n            for (int x = sx;\
    \ x < tx; ++x) {\n                std::cerr << v[y][x] << ' ';\n            }\n\
    \            std::cerr << std::endl;\n        }\n    }\n};\n\n\n"
  code: "#ifndef __RUISEKIWA2D\n#define __RUISEKIWA2D\n/**\n * @title \u4E8C\u6B21\
    \u5143\u7D2F\u7A4D\u548C\n * @brief \u7E26H\u6A2AW\u306E\u7BC4\u56F2\u306E\u77E9\
    \u5F62\u306B\u5BFE\u3057add\u3092N\u56DE\u3057\u305F\u3068\u304D\u3001\u524D\u51E6\
    \u7406 $O(N+HW)$\u3001\u53D6\u5F97$O(1)$\n * @see https://atcoder.jp/contests/typical90/submissions/23946854\n\
    \ */\n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\nstruct Ruisekiwa2D\
    \ {\n    int W, H;\n    std::vector<std::vector<int>> v;\n    Ruisekiwa2D(int\
    \ W, int H): W(W), H(H), v(H, std::vector<int>(W)) {}\n    void add(int sx, int\
    \ sy, int tx, int ty, int c) {\n        // x = [sx,tx], y = [sy,ty] \u306E\u7BC4\
    \u56F2\u306E\u9577\u65B9\u5F62\u306Bc\u3092\u52A0\u3048\u308B\n        // @see\
    \ https://imoz.jp/algorithms/imos_method.html\n        assert(sx < tx && sy <\
    \ ty);\n        v[sy][sx] += c;\n        v[sy][tx] -= c;\n        v[ty][sx] -=\
    \ c;\n        v[ty][tx] += c;\n    }\n    void build() {\n        for (int y =\
    \ 0; y < H; ++y) {\n            for (int x = 0; x < W; ++x) {\n              \
    \  if (0 < y) v[y][x] += v[y - 1][x];\n                if (0 < x) v[y][x] += v[y][x\
    \ - 1];\n                if (0 < y && 0 < x) v[y][x] -= v[y - 1][x - 1];\n   \
    \         }\n        }\n    }\n    int get(int x, int y) {\n        return v[y][x];\n\
    \    }\n    void show(int sx, int sy, int tx, int ty) {\n        // x = [sx,tx],\
    \ y = [sy,ty] \u306E\u7BC4\u56F2\u306E\u9577\u65B9\u5F62\u3092\u8868\u793A\u3059\
    \u308B\n        for (int y = sy; y < ty; ++y) {\n            for (int x = sx;\
    \ x < tx; ++x) {\n                std::cerr << v[y][x] << ' ';\n            }\n\
    \            std::cerr << std::endl;\n        }\n    }\n};\n\n#endif // __RUISEKIWA2D"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/ruisekiwa2d.hpp
  requiredBy: []
  timestamp: '2021-07-04 19:48:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/ruisekiwa2d.hpp
layout: document
redirect_from:
- /library/datastructure/ruisekiwa2d.hpp
- /library/datastructure/ruisekiwa2d.hpp.html
title: "\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
---
