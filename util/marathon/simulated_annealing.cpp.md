---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: util/marathon/template.hpp
    title: util/marathon/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/chokudai004/submissions/9724794
  bundledCode: "#line 1 \"util/marathon/simulated_annealing.cpp\"\n// \u5229\u7528\
    \u4F8B:  https://atcoder.jp/contests/chokudai004/submissions/9724794\n#line 2\
    \ \"util/marathon/template.hpp\"\n#include <bits/stdc++.h>\n\n// #define DEBUG\n\
    #define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define REP3(i, m,\
    \ n) for (int i = (m); (i) < (int)(n); ++ (i))\n#define REPR(i, n) for (int i\
    \ = (int)(n) - 1; (i) >= 0; -- (i))\n#define REP3R(i, m, n) for (int i = (int)(n)\
    \ - 1; (i) >= (int)(m); -- (i))\n#define ALL(x) std::begin(x), std::end(x)\n\n\
    // ------------------------ DEBUG PRINT --------------------------\ntemplate<class\
    \ T>\nvoid print_collection(std::ostream& out, T const& x);\n\ntemplate<class\
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
    \ }\n}\n#endif\n#line 3 \"util/marathon/simulated_annealing.cpp\"\nusing namespace\
    \ std;\n\n// update(), calcScore(), revert(), write()\u3092\u5B9F\u88C5\u3059\u308B\
    \nstruct State {\n  double score = 0;\n  State() {}\n  double update(double progress)\
    \ { return 0; } // FIXME: \u72B6\u614B\u3092\u6B21\u72B6\u614B\u306B\u66F4\u65B0\
    \u3057\u30B9\u30B3\u30A2\u306E\u5DEE\u5206\u3092\u8FD4\u3059. \n  double calcScore()\
    \ { return 0; } // FIXME: \u73FE\u5728\u306E\u72B6\u614B\u306E\u30B9\u30B3\u30A2\
    \u3092\u8FD4\u3059.\n  void revert() {} // update()\u9069\u7528\u524D\u306E\u72B6\
    \u614B\u306B\u623B\u3059.\n  void write() {} // \u73FE\u5728\u306E\u72B6\u614B\
    \u3092\u51FA\u529B\u3059\u308B.\n};\n\nstruct SASolver {\n  double startTemp =\
    \ 30;\n  double endTemp = 10;\n  Timer timer = Timer(2.95);\n  State best;\n \
    \ SASolver() { init(); }\n  SASolver(double st, double et): startTemp(st), endTemp(et)\
    \ { init(); }\n  SASolver(double st, double et, double limit): startTemp(st),\
    \ endTemp(et), timer(limit) { init(); }\n  void init() {} // \u521D\u671F\u5316\
    \u51E6\u7406\u3092\u3053\u3053\u306B\u66F8\u304F\n\n  void solve(State &state)\
    \ {\n    double t;\n    best = state;\n    int step = 0;\n    // best.write();\n\
    \    while ((t = timer.get()) < timer.LIMIT) // \u713C\u304D\u306A\u307E\u3057\
    \u7D42\u4E86\u6642\u523B\u307E\u3067\u30EB\u30FC\u30D7\n    {\n      double T\
    \ = startTemp + (endTemp - startTemp) * t / timer.LIMIT;\n      double progress\
    \ = t/timer.LIMIT;\n      // assert(0 <= progress && progress <= 1);\n      for\
    \ (int i = 0; i < 100; ++i) { // \u6642\u9593\u8A08\u7B97\u3092\u9593\u5F15\u304F\
    \n        double diff = state.update(progress);\n\n        // \u6700\u521Dt=0\u306E\
    \u3068\u304D\u306F\u3001\u30B9\u30B3\u30A2\u304C\u826F\u304F\u306A\u308D\u3046\
    \u304C\u60AA\u304F\u306A\u308D\u3046\u304C\u3001\u5E38\u306B\u6B21\u72B6\u614B\
    \u3092\u4F7F\u7528\n        // \u6700\u5F8Ct=timer.LIMIT\u306E\u3068\u304D\u306F\
    \u3001\u30B9\u30B3\u30A2\u304C\u6539\u5584\u3057\u305F\u3068\u304D\u306E\u307F\
    \u3001\u6B21\u72B6\u614B\u3092\u4F7F\u7528\n        // \u30B9\u30B3\u30A2\u304C\
    \u826F\u304F\u306A\u3063\u305F or \u60AA\u304F\u306A\u3063\u3066\u3082\u5F37\u5236\
    \u9077\u79FB\n        double tr = T*rng.nextLog();\n        if (diff >= tr)\n\
    \        {\n          if (best.score < state.score) {\n            best = state;\n\
    \            D1(t, step, best.score);\n            // best.write();\n        \
    \  }\n        }\n        else { state.revert(); }\n        ++step;\n      }\n\
    \    }\n    D1(step, best.score);\n  }\n};\n\n#if 0\nint main() {\n  State state;\
    \ // \u958B\u59CB\u72B6\u614B\n  SASolver s;\n  s.solve(state);\n  s.best.write();\n\
    }\n#endif\n"
  code: "// \u5229\u7528\u4F8B:  https://atcoder.jp/contests/chokudai004/submissions/9724794\n\
    #include \"template.hpp\"\nusing namespace std;\n\n// update(), calcScore(), revert(),\
    \ write()\u3092\u5B9F\u88C5\u3059\u308B\nstruct State {\n  double score = 0;\n\
    \  State() {}\n  double update(double progress) { return 0; } // FIXME: \u72B6\
    \u614B\u3092\u6B21\u72B6\u614B\u306B\u66F4\u65B0\u3057\u30B9\u30B3\u30A2\u306E\
    \u5DEE\u5206\u3092\u8FD4\u3059. \n  double calcScore() { return 0; } // FIXME:\
    \ \u73FE\u5728\u306E\u72B6\u614B\u306E\u30B9\u30B3\u30A2\u3092\u8FD4\u3059.\n\
    \  void revert() {} // update()\u9069\u7528\u524D\u306E\u72B6\u614B\u306B\u623B\
    \u3059.\n  void write() {} // \u73FE\u5728\u306E\u72B6\u614B\u3092\u51FA\u529B\
    \u3059\u308B.\n};\n\nstruct SASolver {\n  double startTemp = 30;\n  double endTemp\
    \ = 10;\n  Timer timer = Timer(2.95);\n  State best;\n  SASolver() { init(); }\n\
    \  SASolver(double st, double et): startTemp(st), endTemp(et) { init(); }\n  SASolver(double\
    \ st, double et, double limit): startTemp(st), endTemp(et), timer(limit) { init();\
    \ }\n  void init() {} // \u521D\u671F\u5316\u51E6\u7406\u3092\u3053\u3053\u306B\
    \u66F8\u304F\n\n  void solve(State &state) {\n    double t;\n    best = state;\n\
    \    int step = 0;\n    // best.write();\n    while ((t = timer.get()) < timer.LIMIT)\
    \ // \u713C\u304D\u306A\u307E\u3057\u7D42\u4E86\u6642\u523B\u307E\u3067\u30EB\u30FC\
    \u30D7\n    {\n      double T = startTemp + (endTemp - startTemp) * t / timer.LIMIT;\n\
    \      double progress = t/timer.LIMIT;\n      // assert(0 <= progress && progress\
    \ <= 1);\n      for (int i = 0; i < 100; ++i) { // \u6642\u9593\u8A08\u7B97\u3092\
    \u9593\u5F15\u304F\n        double diff = state.update(progress);\n\n        //\
    \ \u6700\u521Dt=0\u306E\u3068\u304D\u306F\u3001\u30B9\u30B3\u30A2\u304C\u826F\u304F\
    \u306A\u308D\u3046\u304C\u60AA\u304F\u306A\u308D\u3046\u304C\u3001\u5E38\u306B\
    \u6B21\u72B6\u614B\u3092\u4F7F\u7528\n        // \u6700\u5F8Ct=timer.LIMIT\u306E\
    \u3068\u304D\u306F\u3001\u30B9\u30B3\u30A2\u304C\u6539\u5584\u3057\u305F\u3068\
    \u304D\u306E\u307F\u3001\u6B21\u72B6\u614B\u3092\u4F7F\u7528\n        // \u30B9\
    \u30B3\u30A2\u304C\u826F\u304F\u306A\u3063\u305F or \u60AA\u304F\u306A\u3063\u3066\
    \u3082\u5F37\u5236\u9077\u79FB\n        double tr = T*rng.nextLog();\n       \
    \ if (diff >= tr)\n        {\n          if (best.score < state.score) {\n    \
    \        best = state;\n            D1(t, step, best.score);\n            // best.write();\n\
    \          }\n        }\n        else { state.revert(); }\n        ++step;\n \
    \     }\n    }\n    D1(step, best.score);\n  }\n};\n\n#if 0\nint main() {\n  State\
    \ state; // \u958B\u59CB\u72B6\u614B\n  SASolver s;\n  s.solve(state);\n  s.best.write();\n\
    }\n#endif\n"
  dependsOn:
  - util/marathon/template.hpp
  isVerificationFile: false
  path: util/marathon/simulated_annealing.cpp
  requiredBy: []
  timestamp: '2022-07-31 09:27:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/marathon/simulated_annealing.cpp
layout: document
redirect_from:
- /library/util/marathon/simulated_annealing.cpp
- /library/util/marathon/simulated_annealing.cpp.html
title: util/marathon/simulated_annealing.cpp
---
