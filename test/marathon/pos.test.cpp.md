---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: util/marathon/pos.hpp
    title: util/marathon/pos.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "Pos\u30AF\u30E9\u30B9\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\
      \u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/marathon/pos.test.cpp\"\n// @title Pos\u30AF\u30E9\u30B9\
    \u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\u30C8\n// dummy problem\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#include\
    \ <cassert>\n#include <iostream>\n#include <set>\n#line 2 \"util/marathon/pos.hpp\"\
    \n#include <cmath>\n#include <limits>\n#line 5 \"util/marathon/pos.hpp\"\n\nint\
    \ DX[9] = {0, 1, 0, -1, -1, -1, 1, 1, 0};\nint DY[9] = {-1, 0, 1, 0, -1, 1, -1,\
    \ 1, 0};\n\nnamespace pos {\n    int W, H; // x\u3068y\u306E\u30B5\u30A4\u30BA\
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
    \ os;\n  }\n};\n\nnamespace pos {\n    Pos nullpos;\n}\n#line 8 \"test/marathon/pos.test.cpp\"\
    \nusing namespace std;\n\nvoid test_operator() {\n    {\n        Pos p;\n    \
    \    assert (p == pos::nullpos);\n    }\n    {\n        Pos p1(1,2);\n       \
    \ Pos p2(1,-2);\n        assert (p1 != p2);\n        p1.y = -2;\n        assert\
    \ (p1 == p2);\n    }\n}\n\nvoid test_to() {\n    Pos p(0,0);\n    assert (p.to(pos::UP)\
    \ == Pos(0,-1));\n    assert (p.to(pos::RIGHT) == Pos(1,0));\n    assert (p.to(pos::DOWN)\
    \ == Pos(0,1));\n    assert (p.to(pos::LEFT) == Pos(-1,0));\n}\n\nvoid test_id()\
    \ {\n    pos::W = 3;\n    pos::H = 5;\n    std::set<int> ids;\n    for (int x\
    \ = 0; x < pos::W; ++x) {\n        for (int y = 0; y < pos::H; ++y) {\n      \
    \      Pos p(x,y);\n            int id = p.id();\n            // \u540C\u3058\
    id\u306F\u767B\u5834\u3057\u306A\u3044\n            assert (ids.count(id) == 0);\n\
    \            ids.insert(id);\n            Pos np(id);\n            // id\u304B\
    \u3089Pos\u3092\u5FA9\u5143\u3067\u304D\u308B\n            assert (p == np);\n\
    \        }\n    }\n}\n\nvoid test_outside() {\n    pos::W = 3;\n    pos::H = 5;\n\
    \    Pos ul(0, 0);\n    Pos ur(pos::W-1, 0);\n    Pos dr(pos::W-1, pos::H-1);\n\
    \    Pos dl(0, pos::H-1);\n    assert (!ul.outside());\n    assert (!ur.outside());\n\
    \    assert (!dr.outside());\n    assert (!dl.outside());\n    assert (ul.to(pos::UP).outside());\n\
    \    assert (ul.to(pos::LEFT).outside());\n    assert (ur.to(pos::UP).outside());\n\
    \    assert (ur.to(pos::RIGHT).outside());\n    assert (dr.to(pos::DOWN).outside());\n\
    \    assert (dr.to(pos::RIGHT).outside());\n    assert (dr.to(pos::DOWN).outside());\n\
    \    assert (dl.to(pos::LEFT).outside());\n}\n\nint main() {\n    test_operator();\n\
    \    test_to();\n    test_id();\n    test_outside();\n\n    // dummy output\n\
    \    cout << \"Hello World\" << endl;\n}\n"
  code: "// @title Pos\u30AF\u30E9\u30B9\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\
    \u30C8\n// dummy problem\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include <set>\n#include \"../../util/marathon/pos.hpp\"\
    \nusing namespace std;\n\nvoid test_operator() {\n    {\n        Pos p;\n    \
    \    assert (p == pos::nullpos);\n    }\n    {\n        Pos p1(1,2);\n       \
    \ Pos p2(1,-2);\n        assert (p1 != p2);\n        p1.y = -2;\n        assert\
    \ (p1 == p2);\n    }\n}\n\nvoid test_to() {\n    Pos p(0,0);\n    assert (p.to(pos::UP)\
    \ == Pos(0,-1));\n    assert (p.to(pos::RIGHT) == Pos(1,0));\n    assert (p.to(pos::DOWN)\
    \ == Pos(0,1));\n    assert (p.to(pos::LEFT) == Pos(-1,0));\n}\n\nvoid test_id()\
    \ {\n    pos::W = 3;\n    pos::H = 5;\n    std::set<int> ids;\n    for (int x\
    \ = 0; x < pos::W; ++x) {\n        for (int y = 0; y < pos::H; ++y) {\n      \
    \      Pos p(x,y);\n            int id = p.id();\n            // \u540C\u3058\
    id\u306F\u767B\u5834\u3057\u306A\u3044\n            assert (ids.count(id) == 0);\n\
    \            ids.insert(id);\n            Pos np(id);\n            // id\u304B\
    \u3089Pos\u3092\u5FA9\u5143\u3067\u304D\u308B\n            assert (p == np);\n\
    \        }\n    }\n}\n\nvoid test_outside() {\n    pos::W = 3;\n    pos::H = 5;\n\
    \    Pos ul(0, 0);\n    Pos ur(pos::W-1, 0);\n    Pos dr(pos::W-1, pos::H-1);\n\
    \    Pos dl(0, pos::H-1);\n    assert (!ul.outside());\n    assert (!ur.outside());\n\
    \    assert (!dr.outside());\n    assert (!dl.outside());\n    assert (ul.to(pos::UP).outside());\n\
    \    assert (ul.to(pos::LEFT).outside());\n    assert (ur.to(pos::UP).outside());\n\
    \    assert (ur.to(pos::RIGHT).outside());\n    assert (dr.to(pos::DOWN).outside());\n\
    \    assert (dr.to(pos::RIGHT).outside());\n    assert (dr.to(pos::DOWN).outside());\n\
    \    assert (dl.to(pos::LEFT).outside());\n}\n\nint main() {\n    test_operator();\n\
    \    test_to();\n    test_id();\n    test_outside();\n\n    // dummy output\n\
    \    cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - util/marathon/pos.hpp
  isVerificationFile: true
  path: test/marathon/pos.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 21:08:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/marathon/pos.test.cpp
layout: document
redirect_from:
- /verify/test/marathon/pos.test.cpp
- /verify/test/marathon/pos.test.cpp.html
title: "Pos\u30AF\u30E9\u30B9\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\u30C8"
---
