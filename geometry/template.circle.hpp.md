---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/triangle.hpp
    title: "\u4E09\u89D2\u5F62\u306E\u4E94\u5FC3\u306E\u5EA7\u6A19"
  - icon: ':warning:'
    path: test/aoj/notest.0010.cpp
    title: test/aoj/notest.0010.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5186"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/template.circle.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/**\n * @title \u5186\n */\n#pragma once\n#include \"template.hpp\"\n\nstruct\
    \ Circle {\n  Point p;\n  Real r;\n\n  Circle() = default;\n\n  Circle(Point p,\
    \ Real r) : p(p), r(r) {}\n};\n\nusing Circles = vector< Circle >;\n\nbool intersect(const\
    \ Circle &c, const Line &l) {\n  return distance(l, c.p) <= c.r + EPS;\n}\n\n\
    bool intersect(const Circle &c, const Point &p) {\n  return abs(abs(p - c.p) -\
    \ c.r) < EPS;\n}\n\nint intersect(const Circle &c, const Segment &l) {\n  if(norm(projection(l,\
    \ c.p) - c.p) - c.r * c.r > EPS) return 0;\n  auto d1 = abs(c.p - l.a), d2 = abs(c.p\
    \ - l.b);\n  if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;\n  if((d1 < c.r -\
    \ EPS && d2 > c.r + EPS) || (d1 > c.r + EPS && d2 < c.r - EPS)) return 1;\n  const\
    \ Point h = projection(l, c.p);\n  if(dot(l.a - h, l.b - h) < 0) return 2;\n \
    \ return 0;\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp\n\
    int intersect(Circle c1, Circle c2) {\n  if(c1.r < c2.r) swap(c1, c2);\n  Real\
    \ d = abs(c1.p - c2.p);\n  if(c1.r + c2.r < d) return 4;\n  if(eq(c1.r + c2.r,\
    \ d)) return 3;\n  if(c1.r - c2.r < d) return 2;\n  if(eq(c1.r - c2.r, d)) return\
    \ 1;\n  return 0;\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\n\
    pair< Point, Point > crosspoint(const Circle &c, const Line l) {\n  Point pr =\
    \ projection(l, c.p);\n  Point e = (l.b - l.a) / abs(l.b - l.a);\n  if(eq(distance(l,\
    \ c.p), c.r)) return {pr, pr};\n  double base = sqrt(c.r * c.r - norm(pr - c.p));\n\
    \  return {pr - e * base, pr + e * base};\n}\n\npair< Point, Point > crosspoint(const\
    \ Circle &c, const Segment &l) {\n  Line aa = Line(l.a, l.b);\n  if(intersect(c,\
    \ l) == 2) return crosspoint(c, aa);\n  auto ret = crosspoint(c, aa);\n  if(dot(l.a\
    \ - ret.first, l.b - ret.first) < 0) ret.second = ret.first;\n  else ret.first\
    \ = ret.second;\n  return ret;\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\n\
    pair< Point, Point > crosspoint(const Circle &c1, const Circle &c2) {\n  Real\
    \ d = abs(c1.p - c2.p);\n  Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) /\
    \ (2 * c1.r * d));\n  Real t = atan2(c2.p.Y - c1.p.Y, c2.p.X - c1.p.X);\n  Point\
    \ p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);\n  Point p2 = c1.p\
    \ + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);\n  return {p1, p2};\n}\n\n//\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\n// tangent\
    \ of circle c through point p\npair< Point, Point > tangent(const Circle &c1,\
    \ const Point &p2) {\n  return crosspoint(c1, Circle(p2, sqrt(norm(c1.p - p2)\
    \ - c1.r * c1.r)));\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G\n\
    // common tangent of circles c1 and c2\nLines tangent(Circle c1, Circle c2) {\n\
    \  Lines ret;\n  if(c1.r < c2.r) swap(c1, c2);\n  Real g = norm(c1.p - c2.p);\n\
    \  if(eq(g, 0)) return ret;\n  Point u = (c2.p - c1.p) / sqrt(g);\n  Point v =\
    \ rotate(PI * 0.5, u);\n  for(int s : {-1, 1}) {\n    Real h = (c1.r + s * c2.r)\
    \ / sqrt(g);\n    if(eq(1 - h * h, 0)) {\n      ret.emplace_back(c1.p + u * c1.r,\
    \ c1.p + (u + v) * c1.r);\n    } else if(1 - h * h > 0) {\n      Point uu = u\
    \ * h, vv = v * sqrt(1 - h * h);\n      ret.emplace_back(c1.p + (uu + vv) * c1.r,\
    \ c2.p - (uu + vv) * c2.r * s);\n      ret.emplace_back(c1.p + (uu - vv) * c1.r,\
    \ c2.p - (uu - vv) * c2.r * s);\n    }\n  }\n  return ret;\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H\n\
    Real area(const Polygon &p, const Circle &c) {\n  if(p.size() < 3) return 0.0;\n\
    \  function< Real(Circle, Point, Point) > cross_area = [&](const Circle &c, const\
    \ Point &a, const Point &b) {\n    Point va = c.p - a, vb = c.p - b;\n    Real\
    \ f = cross(va, vb), ret = 0.0;\n    if(eq(f, 0.0)) return ret;\n    if(max(abs(va),\
    \ abs(vb)) < c.r + EPS) return f;\n    if(distance(Segment(a, b), c.p) > c.r -\
    \ EPS) return c.r * c.r * arg(vb * conj(va));\n    auto u = crosspoint(c, Segment(a,\
    \ b));\n    vector< Point > tot{a, u.first, u.second, b};\n    for(int i = 0;\
    \ i + 1 < (int)tot.size(); i++) {\n      ret += cross_area(c, tot[i], tot[i +\
    \ 1]);\n    }\n    return ret;\n  };\n  Real A = 0;\n  for(int i = 0; i < (int)p.size();\
    \ i++) {\n    A += cross_area(c, p[i], p[(i + 1) % p.size()]);\n  }\n  return\
    \ A;\n}\n"
  dependsOn:
  - geometry/template.hpp
  isVerificationFile: false
  path: geometry/template.circle.hpp
  requiredBy:
  - test/aoj/notest.0010.cpp
  - geometry/triangle.hpp
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/template.circle.hpp
layout: document
redirect_from:
- /library/geometry/template.circle.hpp
- /library/geometry/template.circle.hpp.html
title: "\u5186"
---
