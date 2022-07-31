---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: util/marathon/simulated_annealing.cpp
    title: util/marathon/simulated_annealing.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/marathon/template.hpp\"\n#include <bits/stdc++.h>\n\
    \n// #define DEBUG\n#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n\
    #define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REPR(i,\
    \ n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for\
    \ (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x),\
    \ std::end(x)\n\n// ------------------------ DEBUG PRINT --------------------------\n\
    template<class T>\nvoid print_collection(std::ostream& out, T const& x);\n\ntemplate<class\
    \ A>\nstd::ostream& operator<<(std::ostream& out, std::vector<A> const& x) { print_collection(out,\
    \ x); return out; }\ntemplate<class A, size_t N>\nstd::ostream& operator<<(std::ostream&\
    \ out, std::array<A, N> const& x) { print_collection(out, x); return out; }\n\n\
    \ntemplate<class T, size_t... I>\nvoid print_tuple(std::ostream& out, T const&\
    \ a, std::index_sequence<I...>);\ntemplate<class... A>\nstd::ostream& operator<<(std::ostream&\
    \ out, std::tuple<A...> const& x) {\n  print_tuple(out, x, std::index_sequence_for<A...>{});\n\
    \  return out;\n}\n\ntemplate<class T, size_t... I>\nvoid print_tuple(std::ostream&\
    \ out, T const& a, std::index_sequence<I...>){\n  using swallow = int[];\n  out\
    \ << '(';\n  (void)swallow{0, (void(out << (I == 0? \"\" : \", \") << std::get<I>(a)),\
    \ 0)...};\n  out << ')';\n}\n\ntemplate<class T>\nvoid print_collection(std::ostream&\
    \ out, T const& x) {\n  int f = 0;\n  out << '[';\n  for(auto const& i: x) {\n\
    \    out << (f++ ? \",\" : \"\");\n    out << i;\n  }\n  out << \"]\";\n}\n\n\
    static inline void d1_impl_seq() { std::cerr << \"}\"; }\ntemplate <class T, class...\
    \ V>\nvoid d1_impl_seq(T const& t, V const&... v) {\n  std::cerr << t;\n  if(sizeof...(v))\
    \ { std::cerr << \", \"; }\n  d1_impl_seq(v...);\n}\n\nstatic inline void d2_impl_seq()\
    \ { }\ntemplate <class T, class... V>\nvoid d2_impl_seq(T const& t, V const&...\
    \ v) {\n  std::cerr << \" \" << t;\n  d2_impl_seq(v...);\n}\n\n#define D0(x) do\
    \ { std::cerr << __FILE__ \":\" << __LINE__ << \":\" << __func__ <<  \" \" <<\
    \ x << std::endl; } while (0)\n#define D1(x...) do {                         \
    \                \\\n    std::cerr << __LINE__ << \"  {\" << #x << \"} = {\";\
    \  \\\n    d1_impl_seq(x);                                           \\\n    std::cerr\
    \ << std::endl << std::flush;                     \\\n  } while(0)\n#define D2(x...)\
    \ do {                     \\\n    std::cerr << \"!\";                     \\\n\
    \    d2_impl_seq(x);                       \\\n    std::cerr << std::endl << std::flush;\
    \ \\\n  } while(0)\nstatic inline void debug_impl_seq() {\n  std::cerr << \"}\"\
    ;\n}\n\nnamespace logger {\ninline void json_() {}\ntemplate<typename Key, typename\
    \ Value, typename... Rest>\nvoid json_(const Key& key, const Value& value, const\
    \ Rest&... rest)\n{\n  std::cerr << \"\\\"\" << key << \"\\\":\\\"\" << value\
    \ << \"\\\"\";\n  if (sizeof...(Rest) > 0) std::cerr << \",\";\n  json_(rest...);\n\
    }\n\n// example : json(\"key1\", \"foo\", \"key2\", 3, \"key\", 4.0);\n// {\"\
    key1\":\"foo\",\"key2\":\"3\",\"key\":\"4\"}\ntemplate<typename... Args>\nvoid\
    \ json(const Args&... args)\n{\n#ifdef DEBUG\n  std::cerr << \"{\"; json_(args...);\
    \ std::cerr << \"}\" << std::endl;\n#endif\n}\n} // namespace logger\n// ------------------------\
    \ DEBUG PRINT --------------------------\n\nstruct Timer {\n  const double LIMIT;\
    \ // FIXME: \u6642\u9593\u5236\u9650(s)\n  Timer() : LIMIT(0.95) { reset(); }\n\
    \  Timer(double limit) : LIMIT(limit) { reset(); }\n\tchrono::system_clock::time_point\
    \ start;\n\tvoid reset() {\n\t\tstart = chrono::system_clock::now();\n\t}\n \n\
    \tdouble get() {\n\t\tauto end = chrono::system_clock::now();\n\t\treturn chrono::duration_cast<chrono::milliseconds>(end\
    \ - start).count()/1000.0;\n\t}\n};\n\nstruct XorShift {\n  unsigned int x, y,\
    \ z, w;\n  double nL[65536];\n  XorShift() { init(); }\n  void init()\n  {\n \
    \   x = 314159265; y = 358979323; z = 846264338; w = 327950288;\n    double n\
    \ = 1 / (double)(2 * 65536);\n    for (int i = 0; i < 65536; i++) {\n      nL[i]\
    \ = log(((double)i / 65536) + n);\n    }\n  }\n  inline unsigned int next() {\
    \ unsigned int t=x^x<<11; x=y; y=z; z=w; return w=w^w>>19^t^t>>8; }\n  inline\
    \ double nextLog() { return nL[next()&0xFFFF]; }\n  inline int nextInt(int m)\
    \ { return (int)(next()%m); } // [0, m)\n  int nextInt(int min, int max) { return\
    \ min+nextInt(max-min+1); } // [min, max]\n  inline double nextDouble() { return\
    \ (double)next()/((long long)1<<32); } // [0, 1]\n};\nXorShift rng;\n\ntemplate\
    \ <typename T>\ninline void rough_shuffle(vector<T>& lv) {\n    int n = lv.size();\n\
    \    for (int i = n; i > 0; --i) {\n        int id = rng.nextInt(i);\n       \
    \ swap(lv[id], lv[i-1]);\n    }\n}\n\nstd::size_t calc_hash(std::vector<int> const&\
    \ vec) {\n  std::size_t seed = vec.size();\n  for(auto& i : vec) {\n    seed ^=\
    \ i + 0x9e3779b9 + (seed << 6) + (seed >> 2);\n  }\n  return seed;\n}\n\n#if 0\n\
    int main() { \n  // `#define DEGUB` \u304C\u5FC5\u8981\n  json(\"key1\", \"foo\"\
    , \"key2\", 1, \"key3\", 3.14);\n\n  Timer timer(0.45);\n  while (true) {\n  \
    \  double t = timer.get(); // elapsed seconds\n    if (timer.LIMIT < t) break;\n\
    \    double diff = 1; // SA\u306Ediff. \u4EEE\u30671\u3068\u3057\u3066\u3044\u308B\
    \u304C\u5B9F\u969B\u306F\u8A08\u7B97\u3059\u308B\n    double startTemp = 30;\n\
    \    double endTemp = 10;\n    double T = startTemp + (endTemp-startTemp)*(t/timer.LIMIT);\n\
    \    if (diff >= T * rnd.nextLog()) {\n      // FIXME: \u66F4\u65B0\n    }\n \
    \ }\n}\n#endif\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\n// #define DEBUG\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m, n) for (int i\
    \ = (m); (i) < (int)(n); ++ (i))\n#define REPR(i, n) for (int i = (int)(n) - 1;\
    \ (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >=\
    \ (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n\n// ------------------------\
    \ DEBUG PRINT --------------------------\ntemplate<class T>\nvoid print_collection(std::ostream&\
    \ out, T const& x);\n\ntemplate<class A>\nstd::ostream& operator<<(std::ostream&\
    \ out, std::vector<A> const& x) { print_collection(out, x); return out; }\ntemplate<class\
    \ A, size_t N>\nstd::ostream& operator<<(std::ostream& out, std::array<A, N> const&\
    \ x) { print_collection(out, x); return out; }\n\n\ntemplate<class T, size_t...\
    \ I>\nvoid print_tuple(std::ostream& out, T const& a, std::index_sequence<I...>);\n\
    template<class... A>\nstd::ostream& operator<<(std::ostream& out, std::tuple<A...>\
    \ const& x) {\n  print_tuple(out, x, std::index_sequence_for<A...>{});\n  return\
    \ out;\n}\n\ntemplate<class T, size_t... I>\nvoid print_tuple(std::ostream& out,\
    \ T const& a, std::index_sequence<I...>){\n  using swallow = int[];\n  out <<\
    \ '(';\n  (void)swallow{0, (void(out << (I == 0? \"\" : \", \") << std::get<I>(a)),\
    \ 0)...};\n  out << ')';\n}\n\ntemplate<class T>\nvoid print_collection(std::ostream&\
    \ out, T const& x) {\n  int f = 0;\n  out << '[';\n  for(auto const& i: x) {\n\
    \    out << (f++ ? \",\" : \"\");\n    out << i;\n  }\n  out << \"]\";\n}\n\n\
    static inline void d1_impl_seq() { std::cerr << \"}\"; }\ntemplate <class T, class...\
    \ V>\nvoid d1_impl_seq(T const& t, V const&... v) {\n  std::cerr << t;\n  if(sizeof...(v))\
    \ { std::cerr << \", \"; }\n  d1_impl_seq(v...);\n}\n\nstatic inline void d2_impl_seq()\
    \ { }\ntemplate <class T, class... V>\nvoid d2_impl_seq(T const& t, V const&...\
    \ v) {\n  std::cerr << \" \" << t;\n  d2_impl_seq(v...);\n}\n\n#define D0(x) do\
    \ { std::cerr << __FILE__ \":\" << __LINE__ << \":\" << __func__ <<  \" \" <<\
    \ x << std::endl; } while (0)\n#define D1(x...) do {                         \
    \                \\\n    std::cerr << __LINE__ << \"  {\" << #x << \"} = {\";\
    \  \\\n    d1_impl_seq(x);                                           \\\n    std::cerr\
    \ << std::endl << std::flush;                     \\\n  } while(0)\n#define D2(x...)\
    \ do {                     \\\n    std::cerr << \"!\";                     \\\n\
    \    d2_impl_seq(x);                       \\\n    std::cerr << std::endl << std::flush;\
    \ \\\n  } while(0)\nstatic inline void debug_impl_seq() {\n  std::cerr << \"}\"\
    ;\n}\n\nnamespace logger {\ninline void json_() {}\ntemplate<typename Key, typename\
    \ Value, typename... Rest>\nvoid json_(const Key& key, const Value& value, const\
    \ Rest&... rest)\n{\n  std::cerr << \"\\\"\" << key << \"\\\":\\\"\" << value\
    \ << \"\\\"\";\n  if (sizeof...(Rest) > 0) std::cerr << \",\";\n  json_(rest...);\n\
    }\n\n// example : json(\"key1\", \"foo\", \"key2\", 3, \"key\", 4.0);\n// {\"\
    key1\":\"foo\",\"key2\":\"3\",\"key\":\"4\"}\ntemplate<typename... Args>\nvoid\
    \ json(const Args&... args)\n{\n#ifdef DEBUG\n  std::cerr << \"{\"; json_(args...);\
    \ std::cerr << \"}\" << std::endl;\n#endif\n}\n} // namespace logger\n// ------------------------\
    \ DEBUG PRINT --------------------------\n\nstruct Timer {\n  const double LIMIT;\
    \ // FIXME: \u6642\u9593\u5236\u9650(s)\n  Timer() : LIMIT(0.95) { reset(); }\n\
    \  Timer(double limit) : LIMIT(limit) { reset(); }\n\tchrono::system_clock::time_point\
    \ start;\n\tvoid reset() {\n\t\tstart = chrono::system_clock::now();\n\t}\n \n\
    \tdouble get() {\n\t\tauto end = chrono::system_clock::now();\n\t\treturn chrono::duration_cast<chrono::milliseconds>(end\
    \ - start).count()/1000.0;\n\t}\n};\n\nstruct XorShift {\n  unsigned int x, y,\
    \ z, w;\n  double nL[65536];\n  XorShift() { init(); }\n  void init()\n  {\n \
    \   x = 314159265; y = 358979323; z = 846264338; w = 327950288;\n    double n\
    \ = 1 / (double)(2 * 65536);\n    for (int i = 0; i < 65536; i++) {\n      nL[i]\
    \ = log(((double)i / 65536) + n);\n    }\n  }\n  inline unsigned int next() {\
    \ unsigned int t=x^x<<11; x=y; y=z; z=w; return w=w^w>>19^t^t>>8; }\n  inline\
    \ double nextLog() { return nL[next()&0xFFFF]; }\n  inline int nextInt(int m)\
    \ { return (int)(next()%m); } // [0, m)\n  int nextInt(int min, int max) { return\
    \ min+nextInt(max-min+1); } // [min, max]\n  inline double nextDouble() { return\
    \ (double)next()/((long long)1<<32); } // [0, 1]\n};\nXorShift rng;\n\ntemplate\
    \ <typename T>\ninline void rough_shuffle(vector<T>& lv) {\n    int n = lv.size();\n\
    \    for (int i = n; i > 0; --i) {\n        int id = rng.nextInt(i);\n       \
    \ swap(lv[id], lv[i-1]);\n    }\n}\n\nstd::size_t calc_hash(std::vector<int> const&\
    \ vec) {\n  std::size_t seed = vec.size();\n  for(auto& i : vec) {\n    seed ^=\
    \ i + 0x9e3779b9 + (seed << 6) + (seed >> 2);\n  }\n  return seed;\n}\n\n#if 0\n\
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
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/marathon/template.hpp
layout: document
redirect_from:
- /library/util/marathon/template.hpp
- /library/util/marathon/template.hpp.html
title: util/marathon/template.hpp
---
