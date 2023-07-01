---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: util/compress.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ util/compress.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#include <iostream>\n\n#include \"../../util/compress.hpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n  int n; cin >> n;\n  vector<int> la(n);\n  for (int &a:\
    \ la) cin >> a;\n  Compress<int> comp(la);\n  comp.build();\n  for (int &b: comp.get(la))\
    \ cout << b << endl;\n}\n"
  dependsOn:
  - util/compress.hpp
  isVerificationFile: false
  path: test/atcoder/abc036-c.cpp
  requiredBy: []
  timestamp: '2020-08-30 21:41:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc036-c.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc036-c.cpp
- /library/test/atcoder/abc036-c.cpp.html
title: test/atcoder/abc036-c.cpp
---
