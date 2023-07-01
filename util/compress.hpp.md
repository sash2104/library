---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/abc036-c.cpp
    title: test/atcoder/abc036-c.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ util/compress.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/**\n * @title \u5EA7\u6A19\u5727\u7E2E\n */\n#pragma once\n#include <algorithm>\n\
    #include <vector>\n\ntemplate< typename T >\nstruct Compress {\n  std::vector<\
    \ T > xs;\n\n  Compress() = default;\n  Compress(const std::vector< T > &vs) {\
    \ add(vs); }\n  Compress(const std::initializer_list< std::vector< T > > &vs)\
    \ { for(const T &p : vs) add(p); }\n\n  void add(const std::vector< T > &vs) {\
    \ std::copy(std::begin(vs), std::end(vs), std::back_inserter(xs)); }\n  void add(const\
    \ T &x) { xs.emplace_back(x); }\n\n  void build() {\n    std::sort(std::begin(xs),\
    \ std::end(xs));\n    xs.erase(unique(std::begin(xs), std::end(xs)), std::end(xs));\n\
    \  }\n\n  std::vector< int > get(const std::vector< T > &vs) const {\n    std::vector<\
    \ int > ret;\n    std::transform(std::begin(vs), std::end(vs), std::back_inserter(ret),\
    \ [&](const T &x) {\n      return std::lower_bound(std::begin(xs), std::end(xs),\
    \ x) - std::begin(xs);\n    });\n    return ret;\n  }\n\n  int get(const T &x)\
    \ const {\n    return std::lower_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);\n\
    \  }\n\n  const T &operator[](int k) const { return xs[k]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: util/compress.hpp
  requiredBy:
  - test/atcoder/abc036-c.cpp
  timestamp: '2020-08-30 21:41:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/compress.hpp
layout: document
redirect_from:
- /library/util/compress.hpp
- /library/util/compress.hpp.html
title: "\u5EA7\u6A19\u5727\u7E2E"
---
