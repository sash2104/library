---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: util/marathon/simulated_annealing.cpp
    title: util/marathon/simulated_annealing.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/marathon/template.hpp\"\n#include <cmath>\n#include\
    \ <iostream>\n\n// #define DEBUG\n\nnamespace logger {\ninline void json_() {}\n\
    template<typename Key, typename Value, typename... Rest>\nvoid json_(const Key&\
    \ key, const Value& value, const Rest&... rest)\n{\n  std::cerr << \"\\\"\" <<\
    \ key << \"\\\":\\\"\" << value << \"\\\"\";\n  if (sizeof...(Rest) > 0) std::cerr\
    \ << \",\";\n  json_(rest...);\n}\n\n// example : json(\"key1\", \"foo\", \"key2\"\
    , 3, \"key\", 4.0);\n// {\"key1\":\"foo\",\"key2\":\"3\",\"key\":\"4\"}\ntemplate<typename...\
    \ Args>\nvoid json(const Args&... args)\n{\n#ifdef DEBUG\n  std::cerr << \"{\"\
    ; json_(args...); std::cerr << \"}\" << std::endl;\n#endif\n}\n} // namespace\
    \ logger\n\nstruct Timer {\n  static constexpr int64_t CYCLES_PER_SEC = 2800000000;\n\
    \  const double LIMIT; // FIXME: \u6642\u9593\u5236\u9650(s)\n  int64_t start;\n\
    \  Timer() : LIMIT(0.95) { reset(); }\n  Timer(double limit) : LIMIT(limit) {\
    \ reset(); }\n  void reset() { start = getCycle(); }\n  void plus(double a) {\
    \ start -= (a * CYCLES_PER_SEC); }\n  inline double get() { return (double)(getCycle()\
    \ - start) / CYCLES_PER_SEC; }\n  inline int64_t getCycle() {\n    uint32_t low,\
    \ high;\n    __asm__ volatile (\"rdtsc\" : \"=a\" (low), \"=d\" (high));\n   \
    \ return ((int64_t)low) | ((int64_t)high << 32);\n  }\n};\n\nstruct XorShift {\n\
    \  unsigned int x, y, z, w;\n  double nL[65536];\n  XorShift() { init(); }\n \
    \ void init()\n  {\n    x = 314159265; y = 358979323; z = 846264338; w = 327950288;\n\
    \    double n = 1 / (double)(2 * 65536);\n    for (int i = 0; i < 65536; i++)\
    \ {\n      nL[i] = log(((double)i / 65536) + n);\n    }\n  }\n  inline unsigned\
    \ int next() { unsigned int t=x^x<<11; x=y; y=z; z=w; return w=w^w>>19^t^t>>8;\
    \ }\n  inline double nextLog() { return nL[next()&0xFFFF]; }\n  inline int nextInt(int\
    \ m) { return (int)(next()%m); } // [0, m)\n  int nextInt(int min, int max) {\
    \ return min+nextInt(max-min+1); } // [min, max]\n  inline double nextDouble()\
    \ { return (double)next()/((long long)1<<32); } // [0, 1]\n};\nXorShift rnd;\n\
    \n#if 0\nint main() { \n  // `#define DEGUB` \u304C\u5FC5\u8981\n  json(\"key1\"\
    , \"foo\", \"key2\", 1, \"key3\", 3.14);\n\n  Timer timer(0.45);\n  while (true)\
    \ {\n    double t = timer.get(); // elapsed seconds\n    if (timer.LIMIT < t)\
    \ break;\n    double diff = 1; // SA\u306Ediff. \u4EEE\u30671\u3068\u3057\u3066\
    \u3044\u308B\u304C\u5B9F\u969B\u306F\u8A08\u7B97\u3059\u308B\n    double startTemp\
    \ = 30;\n    double endTemp = 10;\n    double T = startTemp + (endTemp-startTemp)*(t/timer.LIMIT);\n\
    \    if (diff >= T * rnd.nextLog()) {\n      // FIXME: \u66F4\u65B0\n    }\n \
    \ }\n}\n#endif\n"
  code: "#pragma once\n#include <cmath>\n#include <iostream>\n\n// #define DEBUG\n\
    \nnamespace logger {\ninline void json_() {}\ntemplate<typename Key, typename\
    \ Value, typename... Rest>\nvoid json_(const Key& key, const Value& value, const\
    \ Rest&... rest)\n{\n  std::cerr << \"\\\"\" << key << \"\\\":\\\"\" << value\
    \ << \"\\\"\";\n  if (sizeof...(Rest) > 0) std::cerr << \",\";\n  json_(rest...);\n\
    }\n\n// example : json(\"key1\", \"foo\", \"key2\", 3, \"key\", 4.0);\n// {\"\
    key1\":\"foo\",\"key2\":\"3\",\"key\":\"4\"}\ntemplate<typename... Args>\nvoid\
    \ json(const Args&... args)\n{\n#ifdef DEBUG\n  std::cerr << \"{\"; json_(args...);\
    \ std::cerr << \"}\" << std::endl;\n#endif\n}\n} // namespace logger\n\nstruct\
    \ Timer {\n  static constexpr int64_t CYCLES_PER_SEC = 2800000000;\n  const double\
    \ LIMIT; // FIXME: \u6642\u9593\u5236\u9650(s)\n  int64_t start;\n  Timer() :\
    \ LIMIT(0.95) { reset(); }\n  Timer(double limit) : LIMIT(limit) { reset(); }\n\
    \  void reset() { start = getCycle(); }\n  void plus(double a) { start -= (a *\
    \ CYCLES_PER_SEC); }\n  inline double get() { return (double)(getCycle() - start)\
    \ / CYCLES_PER_SEC; }\n  inline int64_t getCycle() {\n    uint32_t low, high;\n\
    \    __asm__ volatile (\"rdtsc\" : \"=a\" (low), \"=d\" (high));\n    return ((int64_t)low)\
    \ | ((int64_t)high << 32);\n  }\n};\n\nstruct XorShift {\n  unsigned int x, y,\
    \ z, w;\n  double nL[65536];\n  XorShift() { init(); }\n  void init()\n  {\n \
    \   x = 314159265; y = 358979323; z = 846264338; w = 327950288;\n    double n\
    \ = 1 / (double)(2 * 65536);\n    for (int i = 0; i < 65536; i++) {\n      nL[i]\
    \ = log(((double)i / 65536) + n);\n    }\n  }\n  inline unsigned int next() {\
    \ unsigned int t=x^x<<11; x=y; y=z; z=w; return w=w^w>>19^t^t>>8; }\n  inline\
    \ double nextLog() { return nL[next()&0xFFFF]; }\n  inline int nextInt(int m)\
    \ { return (int)(next()%m); } // [0, m)\n  int nextInt(int min, int max) { return\
    \ min+nextInt(max-min+1); } // [min, max]\n  inline double nextDouble() { return\
    \ (double)next()/((long long)1<<32); } // [0, 1]\n};\nXorShift rnd;\n\n#if 0\n\
    int main() { \n  // `#define DEGUB` \u304C\u5FC5\u8981\n  json(\"key1\", \"foo\"\
    , \"key2\", 1, \"key3\", 3.14);\n\n  Timer timer(0.45);\n  while (true) {\n  \
    \  double t = timer.get(); // elapsed seconds\n    if (timer.LIMIT < t) break;\n\
    \    double diff = 1; // SA\u306Ediff. \u4EEE\u30671\u3068\u3057\u3066\u3044\u308B\
    \u304C\u5B9F\u969B\u306F\u8A08\u7B97\u3059\u308B\n    double startTemp = 30;\n\
    \    double endTemp = 10;\n    double T = startTemp + (endTemp-startTemp)*(t/timer.LIMIT);\n\
    \    if (diff >= T * rnd.nextLog()) {\n      // FIXME: \u66F4\u65B0\n    }\n \
    \ }\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: util/marathon/template.hpp
  requiredBy:
  - util/marathon/simulated_annealing.cpp
  timestamp: '2020-02-03 21:31:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/marathon/template.hpp
layout: document
redirect_from:
- /library/util/marathon/template.hpp
- /library/util/marathon/template.hpp.html
title: util/marathon/template.hpp
---
