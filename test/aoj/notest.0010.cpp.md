---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/template.circle.hpp
    title: "\u5186"
  - icon: ':heavy_check_mark:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  - icon: ':warning:'
    path: geometry/triangle.hpp
    title: "\u4E09\u89D2\u5F62\u306E\u4E94\u5FC3\u306E\u5EA7\u6A19"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0010
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/triangle.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0010\"\
    \n#include \"../../geometry/triangle.hpp\"\n\n#include <iostream>\nusing namespace\
    \ std;\nint main() {\n  int n; cin >> n;\n  for (int i = 0; i < n; ++i) {\n  \
    \  Point a, b, c;\n    cin >> a >> b >> c;\n    Circle cc = circumcircle(a, b,\
    \ c);\n    cout << fixed << setprecision(3) << cc.p.X << \" \" << cc.p.Y << \"\
    \ \" << cc.r << endl;\n  }\n}"
  dependsOn:
  - geometry/triangle.hpp
  - geometry/template.circle.hpp
  - geometry/template.hpp
  isVerificationFile: false
  path: test/aoj/notest.0010.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/aoj/notest.0010.cpp
layout: document
redirect_from:
- /library/test/aoj/notest.0010.cpp
- /library/test/aoj/notest.0010.cpp.html
title: test/aoj/notest.0010.cpp
---
