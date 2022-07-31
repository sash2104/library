---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: external/fft.hpp
    title: external/fft.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/atcoder/atc001-c.cpp\"\n#include <vector>\n#line 1\
    \ \"external/fft.hpp\"\n/*!\n * original: https://www.creativ.xyz/fast-fourier-transform/\n\
    \ * terms of use: https://www.creativ.xyz/about/\n */\n#include <complex>\n#include\
    \ <iostream>\n#line 8 \"external/fft.hpp\"\n\nusing namespace std;\n\n// Cooley\u2013\
    Tukey FFT algorithm O(N log N)\nvector<complex<double>> fft(vector<complex<double>>\
    \ a, bool inverse = false) {\n    int n = a.size();\n    int h = 0; // h = log_2(n)\n\
    \    for (int i = 0; 1 << i < n; i++) h++;\n    // \u30D0\u30BF\u30D5\u30E9\u30A4\
    \u6F14\u7B97\u7528\u306E\u914D\u7F6E\u5165\u308C\u66FF\u3048\n    for (int i =\
    \ 0; i < n; i++) {\n        int j = 0;\n        for (int k = 0; k < h; k++) j\
    \ |= (i >> k & 1) << (h - 1 - k);\n        if (i < j) swap(a[i], a[j]);\n    }\n\
    \    // \u30D0\u30BF\u30D5\u30E9\u30A4\u6F14\u7B97\n    for (int b = 1; b < n;\
    \ b *= 2) {\n        // \u7B2C log_2(b) + 1 \u6BB5\n        // \u30D6\u30ED\u30C3\
    \u30AF\u30B5\u30A4\u30BA = b * 2\n        for (int j = 0; j < b; j++) {\n    \
    \        // \u30D6\u30ED\u30C3\u30AF\u5185 j \u500B\u76EE\n            // \u91CD\
    \u307F w = (1 \u306E\u539F\u59CB 2b \u4E57\u6839\u306E j \u4E57)\n           \
    \ complex<double> w =\n                polar(1.0, (2 * M_PI) / (2 * b) * j * (inverse\
    \ ? 1 : -1));\n            for (int k = 0; k < n; k += b * 2) {\n            \
    \    // k \u3092\u5148\u982D\u3068\u3059\u308B\u30D6\u30ED\u30C3\u30AF\n     \
    \           complex<double> s = a[j + k];         // \u524D\n                complex<double>\
    \ t = a[j + k + b] * w; // \u5F8C\n                a[j + k] = s + t;         \
    \            // \u524D\u306E\u66F4\u65B0\n                a[j + k + b] = s - t;\
    \                 // \u5F8C\u306E\u66F4\u65B0\n            }\n        }\n    }\n\
    \    // \u9006\u5909\u63DB\u6642\u306B\u30B5\u30A4\u30BA\u3067\u5272\u308B\u8ABF\
    \u6574\n    if (inverse)\n        for (int i = 0; i < n; i++) a[i] /= n;\n   \
    \ return a;\n}\n// Cooley\u2013Tukey FFT algorithm O(N log N)\nvector<complex<double>>\
    \ fft(vector<double> a, bool inverse = false) {\n    vector<complex<double>> a_complex(a.size());\n\
    \    for (int i = 0; i < a.size(); i++) a_complex[i] = complex<double>(a[i], 0);\n\
    \    return fft(a_complex, inverse);\n}\n\n// FFT \u306B\u3088\u308B\u7573\u307F\
    \u8FBC\u307F O(N log N)\nvector<double> convolve(vector<double> a, vector<double>\
    \ b) {\n    int s = a.size() + b.size() - 1; // \u7573\u307F\u8FBC\u307F\u7D50\
    \u679C\u306E\u30B5\u30A4\u30BA\n    int t = 1; // FFT \u306B\u4F7F\u3046\u914D\
    \u5217\u306E\u30B5\u30A4\u30BA\uFF082 \u306E\u7D2F\u4E57\uFF09\n    while (t <\
    \ s) t *= 2;\n    a.resize(t); // FFT \u3059\u308B\u305F\u3081\u306B\u30EA\u30B5\
    \u30A4\u30BA\n    b.resize(t); // FFT \u3059\u308B\u305F\u3081\u306B\u30EA\u30B5\
    \u30A4\u30BA\n    vector<complex<double>> A = fft(a);\n    vector<complex<double>>\
    \ B = fft(b);\n    for (int i = 0; i < t; i++) {\n        A[i] *= B[i]; // \u7573\
    \u307F\u8FBC\u307F\u7D50\u679C\u306E FFT \u7D50\u679C\u3092\u5F97\u308B\n    }\n\
    \    A = fft(A, true); // IFFT \u3067\u7573\u307F\u8FBC\u307F\u7D50\u679C\u3092\
    \u5F97\u308B\n    a.resize(s);      // \u7573\u307F\u8FBC\u307F\u7D50\u679C\u3092\
    \u5165\u308C\u308B\u305F\u3081\u306B\u30EA\u30B5\u30A4\u30BA\n    for (int i =\
    \ 0; i < s; i++) a[i] = A[i].real(); // \u5B9F\u90E8\u304C\u7B54\u3048\n    return\
    \ a;\n}\n#line 3 \"test/atcoder/atc001-c.cpp\"\n\nusing namespace std;\n\nint\
    \ main() {\n  int n; cin >> n;\n  vector<double> a(n+1), b(n+1);\n  for (int i\
    \ = 0; i < n; ++i) { \n    cin >> a[i+1] >> b[i+1];\n  }\n  vector<double> c =\
    \ convolve(a, b);\n  for (int i = 1; i <= 2*n; ++i) {\n    cout << (int)(c[i]+0.5)\
    \ << endl;\n  }\n}\n"
  code: "#include <vector>\n#include \"../../external/fft.hpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n  int n; cin >> n;\n  vector<double> a(n+1), b(n+1);\n\
    \  for (int i = 0; i < n; ++i) { \n    cin >> a[i+1] >> b[i+1];\n  }\n  vector<double>\
    \ c = convolve(a, b);\n  for (int i = 1; i <= 2*n; ++i) {\n    cout << (int)(c[i]+0.5)\
    \ << endl;\n  }\n}\n"
  dependsOn:
  - external/fft.hpp
  isVerificationFile: false
  path: test/atcoder/atc001-c.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/atc001-c.cpp
layout: document
redirect_from:
- /library/test/atcoder/atc001-c.cpp
- /library/test/atcoder/atc001-c.cpp.html
title: test/atcoder/atc001-c.cpp
---
