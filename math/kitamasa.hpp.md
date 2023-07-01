---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "kitamasa\u6CD5"
    links:
    - https://atcoder.jp/contests/tdpc/submissions/18910066
    - https://outline.hatenadiary.jp/entry/2020/07/02/205628
    - https://yosupo.hatenablog.com/entry/2015/03/27/025132
  bundledCode: "#line 1 \"math/kitamasa.hpp\"\n/**\n * @brief kitamasa\u6CD5\n * \u4F7F\
    \u7528\u4F8B: https://atcoder.jp/contests/tdpc/submissions/18910066\n * link:\
    \ https://outline.hatenadiary.jp/entry/2020/07/02/205628\n * link: https://yosupo.hatenablog.com/entry/2015/03/27/025132\n\
    \ */\n#include <cassert>\n#include <vector>\n\ntemplate<typename T>\nstruct Kitamasa{\n\
    \    std::vector<T> a;    // \u521D\u671F\u5024\u30D9\u30AF\u30C8\u30EB\n    std::vector<T>\
    \ d;    // \u4FC2\u6570\u30D9\u30AF\u30C8\u30EB\n    int k;\n    \n    Kitamasa(std::vector<T>&\
    \ a, std::vector<T>& d) : a(a), d(d), k((int)a.size()) {}\n    \n    // a_n \u306E\
    \u4FC2\u6570\u30D9\u30AF\u30C8\u30EB\u3092\u6C42\u3081\u308B\n    std::vector<T>\
    \ dfs(int64_t n){\n        assert(n >= k);\n        if(n == k)  return d;\n  \
    \      \n        std::vector<T> res(k);\n        if(n & 1 || n < k * 2){\n   \
    \         std::vector<T> x = dfs(n-1);\n            for(int i = 0; i < k; ++i)\
    \  res[i] = d[i] * x[k - 1];\n            for(int i = 0; i + 1 < k; ++i)  res[i\
    \ + 1] += x[i];\n        }\n        else{\n            std::vector<std::vector<T>>\
    \ x(k, std::vector<T>(k));\n            x[0] = dfs(n/2);\n            for(int\
    \ i = 0; i + 1 < k; ++i){\n                for(int j = 0; j < k; ++j)  x[i + 1][j]\
    \ = d[j] * x[i][k - 1];\n                for(int j = 0; j + 1 < k; ++j)  x[i +\
    \ 1][j + 1] += x[i][j];\n            }\n            for(int i = 0; i < k; ++i){\n\
    \                for(int j = 0; j < k; ++j){\n                    res[j] += x[0][i]\
    \ * x[i][j];\n                }\n            }\n        }\n\n        return res;\n\
    \    }\n\n    // a_n \u3092\u6C42\u3081\u308B\n    T calc(int64_t n){\n      \
    \  std::vector<T> x = dfs(n);\n        T res = 0;\n        for(int i = 0; i <\
    \ k; ++i)  res += x[i] * a[i];\n        return res;\n    }\n};\n"
  code: "/**\n * @brief kitamasa\u6CD5\n * \u4F7F\u7528\u4F8B: https://atcoder.jp/contests/tdpc/submissions/18910066\n\
    \ * link: https://outline.hatenadiary.jp/entry/2020/07/02/205628\n * link: https://yosupo.hatenablog.com/entry/2015/03/27/025132\n\
    \ */\n#include <cassert>\n#include <vector>\n\ntemplate<typename T>\nstruct Kitamasa{\n\
    \    std::vector<T> a;    // \u521D\u671F\u5024\u30D9\u30AF\u30C8\u30EB\n    std::vector<T>\
    \ d;    // \u4FC2\u6570\u30D9\u30AF\u30C8\u30EB\n    int k;\n    \n    Kitamasa(std::vector<T>&\
    \ a, std::vector<T>& d) : a(a), d(d), k((int)a.size()) {}\n    \n    // a_n \u306E\
    \u4FC2\u6570\u30D9\u30AF\u30C8\u30EB\u3092\u6C42\u3081\u308B\n    std::vector<T>\
    \ dfs(int64_t n){\n        assert(n >= k);\n        if(n == k)  return d;\n  \
    \      \n        std::vector<T> res(k);\n        if(n & 1 || n < k * 2){\n   \
    \         std::vector<T> x = dfs(n-1);\n            for(int i = 0; i < k; ++i)\
    \  res[i] = d[i] * x[k - 1];\n            for(int i = 0; i + 1 < k; ++i)  res[i\
    \ + 1] += x[i];\n        }\n        else{\n            std::vector<std::vector<T>>\
    \ x(k, std::vector<T>(k));\n            x[0] = dfs(n/2);\n            for(int\
    \ i = 0; i + 1 < k; ++i){\n                for(int j = 0; j < k; ++j)  x[i + 1][j]\
    \ = d[j] * x[i][k - 1];\n                for(int j = 0; j + 1 < k; ++j)  x[i +\
    \ 1][j + 1] += x[i][j];\n            }\n            for(int i = 0; i < k; ++i){\n\
    \                for(int j = 0; j < k; ++j){\n                    res[j] += x[0][i]\
    \ * x[i][j];\n                }\n            }\n        }\n\n        return res;\n\
    \    }\n\n    // a_n \u3092\u6C42\u3081\u308B\n    T calc(int64_t n){\n      \
    \  std::vector<T> x = dfs(n);\n        T res = 0;\n        for(int i = 0; i <\
    \ k; ++i)  res += x[i] * a[i];\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/kitamasa.hpp
  requiredBy: []
  timestamp: '2021-04-15 20:33:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/kitamasa.hpp
layout: document
redirect_from:
- /library/math/kitamasa.hpp
- /library/math/kitamasa.hpp.html
title: "kitamasa\u6CD5"
---
