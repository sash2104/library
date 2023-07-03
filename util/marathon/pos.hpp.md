---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/marathon/pos.test.cpp
    title: "Pos\u30AF\u30E9\u30B9\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/marathon/pos.hpp\"\n#include <cmath>\n#include <limits>\n\
    #include <iostream>\n\nint DX[9] = {0, 1, 0, -1, -1, -1, 1, 1, 0};\nint DY[9]\
    \ = {-1, 0, 1, 0, -1, 1, -1, 1, 0};\n\nnamespace pos {\n    int W, H; // x\u3068\
    y\u306E\u30B5\u30A4\u30BA\n    static constexpr int UP = 0;\n    static constexpr\
    \ int RIGHT = 1;\n    static constexpr int DOWN = 2;\n    static constexpr int\
    \ LEFT = 3;\n}\n\nstruct Pos {\n  int x = -1, y = -1;\n  Pos() {}\n  Pos(int i):\
    \ x(i%pos::W), y(i/pos::W) {}\n  Pos(int x, int y): x(x), y(y) {}\n  bool operator\
    \ == (const Pos &other) const { \n    return (other.x == x) && (other.y == y);\n\
    \  }\n  bool operator != (const Pos &other) const { \n    return !((*this) ==\
    \ other);\n  }\n  int euclid(const Pos &other) const {\n    return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));\n\
    \  }\n  int manhattan(const Pos &other) const {\n    return abs(x-other.x)+abs(y-other.y);\n\
    \  }\n  Pos to(int d) const { return Pos(x+DX[d],y+DY[d]); }\n  int id() const\
    \ { return y*pos::W+x; }\n  bool outside() const {\n    return x < 0 || x >= pos::W\
    \ || y < 0 || y >= pos::H;\n  }\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const Pos &p) {\n    os << '(' << p.x << ',' << p.y << ')';\n    return\
    \ os;\n  }\n};\n\nnamespace pos {\n    Pos nullpos;\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <limits>\n#include <iostream>\n\n\
    int DX[9] = {0, 1, 0, -1, -1, -1, 1, 1, 0};\nint DY[9] = {-1, 0, 1, 0, -1, 1,\
    \ -1, 1, 0};\n\nnamespace pos {\n    int W, H; // x\u3068y\u306E\u30B5\u30A4\u30BA\
    \n    static constexpr int UP = 0;\n    static constexpr int RIGHT = 1;\n    static\
    \ constexpr int DOWN = 2;\n    static constexpr int LEFT = 3;\n}\n\nstruct Pos\
    \ {\n  int x = -1, y = -1;\n  Pos() {}\n  Pos(int i): x(i%pos::W), y(i/pos::W)\
    \ {}\n  Pos(int x, int y): x(x), y(y) {}\n  bool operator == (const Pos &other)\
    \ const { \n    return (other.x == x) && (other.y == y);\n  }\n  bool operator\
    \ != (const Pos &other) const { \n    return !((*this) == other);\n  }\n  int\
    \ euclid(const Pos &other) const {\n    return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));\n\
    \  }\n  int manhattan(const Pos &other) const {\n    return abs(x-other.x)+abs(y-other.y);\n\
    \  }\n  Pos to(int d) const { return Pos(x+DX[d],y+DY[d]); }\n  int id() const\
    \ { return y*pos::W+x; }\n  bool outside() const {\n    return x < 0 || x >= pos::W\
    \ || y < 0 || y >= pos::H;\n  }\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const Pos &p) {\n    os << '(' << p.x << ',' << p.y << ')';\n    return\
    \ os;\n  }\n};\n\nnamespace pos {\n    Pos nullpos;\n}"
  dependsOn: []
  isVerificationFile: false
  path: util/marathon/pos.hpp
  requiredBy: []
  timestamp: '2023-07-03 21:08:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/marathon/pos.test.cpp
documentation_of: util/marathon/pos.hpp
layout: document
redirect_from:
- /library/util/marathon/pos.hpp
- /library/util/marathon/pos.hpp.html
title: util/marathon/pos.hpp
---
