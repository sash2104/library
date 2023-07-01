---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/template.circle.hpp
    title: "\u5186"
  - icon: ':heavy_check_mark:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/aoj/notest.0010.cpp
    title: test/aoj/notest.0010.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E09\u89D2\u5F62\u306E\u4E94\u5FC3\u306E\u5EA7\u6A19"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/triangle.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/**\n * @title \u4E09\u89D2\u5F62\u306E\u4E94\u5FC3\u306E\u5EA7\u6A19\n */\n\
    #pragma once\n#include \"template.circle.hpp\"\n\n// \u5916\u63A5\u5186\nCircle\
    \ circumcircle(const Point &a, const Point &b, const Point &c) {\n  Real a1,a2,b1,b2,c1,c2;\n\
    \  a1=2*(b.X-a.X);\n  b1=2*(b.Y-a.Y);\n  c1=a.X*a.X-b.X*b.X+a.Y*a.Y-b.Y*b.Y;\n\
    \  a2=2*(c.X-a.X);\n  b2=2*(c.Y-a.Y);\n  c2=a.X*a.X-c.X*c.X+a.Y*a.Y-c.Y*c.Y;\n\
    \  Real px = (b1*c2-b2*c1)/(a1*b2-a2*b1);\n  Real py = (c1*a2-c2*a1)/(a1*b2-a2*b1);\n\
    \  Point circumcenter(px, py); // \u5916\u5FC3\n  Real r = distance(a, circumcenter);\n\
    \  return Circle(circumcenter, r);\n}\n"
  dependsOn:
  - geometry/template.circle.hpp
  - geometry/template.hpp
  isVerificationFile: false
  path: geometry/triangle.hpp
  requiredBy:
  - test/aoj/notest.0010.cpp
  timestamp: '2020-08-30 21:41:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/triangle.hpp
layout: document
redirect_from:
- /library/geometry/triangle.hpp
- /library/geometry/triangle.hpp.html
title: "\u4E09\u89D2\u5F62\u306E\u4E94\u5FC3\u306E\u5EA7\u6A19"
---
