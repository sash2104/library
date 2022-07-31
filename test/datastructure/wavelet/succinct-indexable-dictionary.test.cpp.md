---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/wavelet/succinct-indexable-dictionary.hpp
    title: "\u5B8C\u5099\u8F9E\u66F8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "\u5B8C\u5099\u8F9E\u66F8\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\
      \u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/wavelet/succinct-indexable-dictionary.hpp: line 3: #pragma once\
    \ found in a non-first line\n"
  code: "// @title \u5B8C\u5099\u8F9E\u66F8\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\
    \u30C8\n// dummy problem\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#include \"../../../datastructure/wavelet/succinct-indexable-dictionary.hpp\"\
    \nusing namespace std;\n\nvoid test_set_access() {\n    SuccinctIndexableDictionary\
    \ sid(2000);\n    sid.set(3);\n    sid.set(4);\n    for (int i = 0; i < sid.length;\
    \ ++i) {\n        if (i == 3 || i == 4) { assert(sid[i] == 1); }\n        else\
    \ { assert(sid[i] == 0); }\n    }\n}\n\nvoid test_rank() {\n    SuccinctIndexableDictionary\
    \ sid(2000);\n    for (int i = 1000; i < 1500; ++i) {\n        if (i % 2 == 0)\
    \ sid.set(i);\n    }\n    sid.build();\n    assert(sid.rank(0) == 0);\n    assert(sid.rank(1000)\
    \ == 0);\n    assert(sid.rank(1001) == 1);\n    assert(sid.rank(1002) == 1);\n\
    \    assert(sid.rank(1498) == 249);\n    assert(sid.rank(1499) == 250);\n    assert(sid.rank(1500)\
    \ == 250);\n    assert(sid.rank(2000) == 250);\n}\n\nvoid test_select() {\n  \
    \  SuccinctIndexableDictionary sid(2000);\n    for (int i = 1000; i < 1500; ++i)\
    \ {\n        if (i % 2 == 0) sid.set(i);\n    }\n    sid.build();\n    assert(sid.select(0)\
    \ == 0);\n    assert(sid.select(1) == 1001);\n    assert(sid.select(250) == 1499);\n\
    \    assert(sid.select(251) == -1);\n}\n\nint main() {\n    test_set_access();\n\
    \    test_rank();\n    test_select();\n\n    // dummy output\n    cout << \"Hello\
    \ World\" << endl;\n}"
  dependsOn:
  - datastructure/wavelet/succinct-indexable-dictionary.hpp
  isVerificationFile: true
  path: test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp
- /verify/test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp.html
title: "\u5B8C\u5099\u8F9E\u66F8\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\u30C8"
---
