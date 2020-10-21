---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/wavelet/succinct-indexable-dictionary.hpp
    title: datastructure/wavelet/succinct-indexable-dictionary.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    document_title: "\u5B8C\u5099\u8F9E\u66F8\u306E\u30C6\u30B9\u30C8"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp\"\
    \n// @title \u5B8C\u5099\u8F9E\u66F8\u306E\u30C6\u30B9\u30C8\n// dummy problem\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include <cassert>\n#include <iostream>\n#line 2 \"datastructure/wavelet/succinct-indexable-dictionary.hpp\"\
    \n\n#include <vector>\n\nstruct SuccinctIndexableDictionary {\n    using u16 =\
    \ unsigned short;\n    using u32 = unsigned int;\n    static int cw, bw;\n\n \
    \   u32 length; // bit\u5217\u306E\u9577\u3055\n    u32 nchunk, nblock;\n    std::vector<u16>\
    \ bit;\n    std::vector<u32> chunk;\n    std::vector<std::vector<u16>> blocks;\n\
    \    SuccinctIndexableDictionary() = default;\n    SuccinctIndexableDictionary(int\
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
    \n    int rank(bool b, int pos) {\n        return (b ? rank(pos) : pos - rank(pos));\n\
    \    }\n\n    // rank(idx)==num\u306A\u308B\u6700\u5C0F\u306Eidx\u3092\u8FD4\u3059\
    . 1\u304Cnum\u500B\u672A\u6E80\u306A\u3089-1\u3092\u8FD4\u3059\n    int select(int\
    \ num) const {\n        if (num == 0) return 0;\n        if (rank(length) < num)\
    \ return -1;\n\n        int ok = length, ng = 0;\n        while (ok - ng > 1)\
    \ {\n            int mid = (ok + ng) / 2;\n            if (rank(mid) >= num) {\n\
    \                ok = mid;\n            } else {\n                ng = mid;\n\
    \            }\n        }\n        return ok;\n    }\n};\n\nint SuccinctIndexableDictionary::cw\
    \ = 1024;\nint SuccinctIndexableDictionary::bw = 16;\n#line 7 \"test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp\"\
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
    \ World\" << endl;\n}\n"
  code: "// @title \u5B8C\u5099\u8F9E\u66F8\u306E\u30C6\u30B9\u30C8\n// dummy problem\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
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
  timestamp: '2020-10-22 07:10:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp
layout: document
redirect_from:
- /verify/test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp
- /verify/test/datastructure/wavelet/succinct-indexable-dictionary.test.cpp.html
title: "\u5B8C\u5099\u8F9E\u66F8\u306E\u30C6\u30B9\u30C8"
---
