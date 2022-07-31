---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp
    title: "\u5B8C\u5099\u8F9E\u66F8\u306E\u7C21\u6613\u7684\u306A\u30C6\u30B9\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5B8C\u5099\u8F9E\u66F8"
    links:
    - https://misteer.hatenablog.com/entry/bit-vector
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/wavelet/succinct-indexable-dictionary.hpp: line 3: #pragma once\
    \ found in a non-first line\n"
  code: "// @title \u5B8C\u5099\u8F9E\u66F8\n// https://misteer.hatenablog.com/entry/bit-vector\n\
    #pragma once\n\n#include <vector>\n\nstruct SuccinctIndexableDictionary {\n  \
    \  using u16 = unsigned short;\n    using u32 = unsigned int;\n    static int\
    \ cw, bw;\n\n    u32 length; // bit\u5217\u306E\u9577\u3055\n    u32 nchunk, nblock;\n\
    \    std::vector<u16> bit;\n    std::vector<u32> chunk;\n    std::vector<std::vector<u16>>\
    \ blocks;\n    SuccinctIndexableDictionary() = default;\n    SuccinctIndexableDictionary(int\
    \ n) : length(n), nchunk((n+cw-1)/cw), nblock(cw/bw) {\n        bit.assign(nchunk*nblock,\
    \ 0);\n        chunk.assign(nchunk+1, 0); // +1\u306F\u5148\u982D\u306E0\u306E\
    \u5206\n        blocks.assign(nchunk, std::vector<u16>(nblock, 0));\n    }\n\n\
    \    // pos\u756A\u76EE\u306Ebit\u30921\u306B\u3059\u308B\n    void set(int pos)\
    \ { \n        int bpos = pos / bw;\n        int offset = pos % bw;\n        bit[bpos]\
    \ |= (1U<<offset);\n    }\n\n    // chunk\u3068blocks\u3092\u9069\u5207\u306B\u57CB\
    \u3081\u308B\n    void build() {\n        chunk[0] = 0;\n        for (int i =\
    \ 0; i < nchunk; ++i) {\n            blocks[i][0] = 0;\n            for (int j\
    \ = 0; j < nblock - 1; ++j) {\n                blocks[i][j+1] = blocks[i][j] +\
    \ __builtin_popcount(bit[i*nblock+j]);\n            }\n            chunk[i+1]\
    \ = chunk[i] + blocks[i][nblock-1] + __builtin_popcount(bit[(i+1)*nblock-1]);\n\
    \        }\n    }\n\n    // pos\u756A\u76EE\u306Ebit\u3092\u8FD4\u3059\n    bool\
    \ operator[](int pos) const {\n        int bpos = pos / bw;\n        int offset\
    \ = pos % bw;\n        return (bool)((bit[bpos] >> offset) & 1);\n    }\n\n  \
    \  // [0, pos) \u306B\u3042\u308B1\u306E\u6570\u3092\u8FD4\u3059\n    int rank(int\
    \ pos) const {\n        int cpos = pos / cw;\n        int bpos = (pos % cw) /\
    \ bw;\n        int offset = pos % bw;\n        // \u4F59\u3063\u305F\u90E8\u5206\
    \u304B\u3089\u3001\u5FC5\u8981\u306A\u90E8\u5206\u3060\u3051\u3092bitmask\u3067\
    \u62BD\u51FA\u3059\u308B\n        u16 masked = (bit[cpos * nblock + bpos]) & ((1\
    \ << offset) - 1);\n        return chunk[cpos] + blocks[cpos][bpos] + __builtin_popcount(masked);\n\
    \    }\n\n    // [0, pos) \u306B\u3042\u308Bb(0 or 1)\u306E\u6570\u3092\u8FD4\u3059\
    \n    int rank(bool b, int pos) const {\n        return (b ? rank(pos) : pos -\
    \ rank(pos));\n    }\n\n    // rank(idx)==num\u306A\u308B\u6700\u5C0F\u306Eidx\u3092\
    \u8FD4\u3059. 1\u304Cnum\u500B\u672A\u6E80\u306A\u3089-1\u3092\u8FD4\u3059\n \
    \   int select(int num) const {\n        if (num == 0) return 0;\n        if (rank(length)\
    \ < num) return -1;\n\n        int ok = length, ng = 0;\n        while (ok - ng\
    \ > 1) {\n            int mid = (ok + ng) / 2;\n            if (rank(mid) >= num)\
    \ {\n                ok = mid;\n            } else {\n                ng = mid;\n\
    \            }\n        }\n        return ok;\n    }\n};\n\nint SuccinctIndexableDictionary::cw\
    \ = 1024;\nint SuccinctIndexableDictionary::bw = 16;\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/wavelet/succinct-indexable-dictionary.hpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp
documentation_of: datastructure/wavelet/succinct-indexable-dictionary.hpp
layout: document
redirect_from:
- /library/datastructure/wavelet/succinct-indexable-dictionary.hpp
- /library/datastructure/wavelet/succinct-indexable-dictionary.hpp.html
title: "\u5B8C\u5099\u8F9E\u66F8"
---
