---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: util/marathon/simulated_annealing.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6cc910c4eb495362d5e64f63c07ca62e">util/marathon</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/marathon/simulated_annealing.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-03 21:31:14+09:00




## Depends on

* :warning: <a href="template.hpp.html">util/marathon/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 利用例:  https://atcoder.jp/contests/chokudai004/submissions/9724794
#include "template.hpp"
using namespace std;

// update(), calcScore(), revert(), write()を実装する
struct State {
  State() {}
  double update() { return 0; } // FIXME: 状態を次状態に更新しスコアの差分を返す. 
  double calcScore() { return 0; } // FIXME: 現在の状態のスコアを返す.
  void revert() {} // update()適用前の状態に戻す.
  void write() {} // 現在の状態を出力する.
};

struct SASolver {
  double startTemp = 30;
  double endTemp = 10;
  Timer timer = Timer(2.95);
  State best;
  SASolver() { init(); }
  SASolver(double st, double et): startTemp(st), endTemp(et) { init(); }
  SASolver(double st, double et, double limit): startTemp(st), endTemp(et), timer(limit) { init(); }
  void init() {} // 初期化処理をここに書く

  void solve(State &state) {
    double t;
    double score = state.calcScore();
    best = state;
    double bestScore = score;
    int counter = 0;
    while ((t = timer.get()) < timer.LIMIT) // 焼きなまし終了時刻までループ
    {
      for (int i = 0; i < 1000; ++i) { // 時間計算を間引く
        int diff = state.update();

        // 最初t=0のときは、スコアが良くなろうが悪くなろうが、常に次状態を使用
        // 最後t=timer.LIMITのときは、スコアが改善したときのみ、次状態を使用
        double T = startTemp + (endTemp - startTemp) * t / timer.LIMIT;
        // スコアが良くなった or 悪くなっても強制遷移
        if (diff >= T*rnd.nextLog())
        {
          score += diff;
          if (bestScore < score) {
            bestScore = score;
            best = state;
            // cerr << "time = " << t << ", counter = " << counter << ", score = " << bestScore << endl;
          }
        }
        else { state.revert(); }
        ++counter;
      }
    }
    // cerr << "counter = " << counter << ", score = " << bestScore << endl;
  }
};

#if 0
int main() {
  State state; // 開始状態
  SASolver s;
  s.solve(state);
  s.best.write();
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/marathon/simulated_annealing.cpp"
// 利用例:  https://atcoder.jp/contests/chokudai004/submissions/9724794
#line 2 "util/marathon/template.hpp"
#include <cmath>
#include <iostream>

// #define DEBUG

namespace logger {
inline void json_() {}
template<typename Key, typename Value, typename... Rest>
void json_(const Key& key, const Value& value, const Rest&... rest)
{
  std::cerr << "\"" << key << "\":\"" << value << "\"";
  if (sizeof...(Rest) > 0) std::cerr << ",";
  json_(rest...);
}

// example : json("key1", "foo", "key2", 3, "key", 4.0);
// {"key1":"foo","key2":"3","key":"4"}
template<typename... Args>
void json(const Args&... args)
{
#ifdef DEBUG
  std::cerr << "{"; json_(args...); std::cerr << "}" << std::endl;
#endif
}
} // namespace logger

struct Timer {
  static constexpr int64_t CYCLES_PER_SEC = 2800000000;
  const double LIMIT; // FIXME: 時間制限(s)
  int64_t start;
  Timer() : LIMIT(0.95) { reset(); }
  Timer(double limit) : LIMIT(limit) { reset(); }
  void reset() { start = getCycle(); }
  void plus(double a) { start -= (a * CYCLES_PER_SEC); }
  inline double get() { return (double)(getCycle() - start) / CYCLES_PER_SEC; }
  inline int64_t getCycle() {
    uint32_t low, high;
    __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
    return ((int64_t)low) | ((int64_t)high << 32);
  }
};

struct XorShift {
  unsigned int x, y, z, w;
  double nL[65536];
  XorShift() { init(); }
  void init()
  {
    x = 314159265; y = 358979323; z = 846264338; w = 327950288;
    double n = 1 / (double)(2 * 65536);
    for (int i = 0; i < 65536; i++) {
      nL[i] = log(((double)i / 65536) + n);
    }
  }
  inline unsigned int next() { unsigned int t=x^x<<11; x=y; y=z; z=w; return w=w^w>>19^t^t>>8; }
  inline double nextLog() { return nL[next()&0xFFFF]; }
  inline int nextInt(int m) { return (int)(next()%m); } // [0, m)
  int nextInt(int min, int max) { return min+nextInt(max-min+1); } // [min, max]
  inline double nextDouble() { return (double)next()/((long long)1<<32); } // [0, 1]
};
XorShift rnd;

#if 0
int main() { 
  // `#define DEGUB` が必要
  json("key1", "foo", "key2", 1, "key3", 3.14);

  Timer timer(0.45);
  while (true) {
    double t = timer.get(); // elapsed seconds
    if (timer.LIMIT < t) break;
    double diff = 1; // SAのdiff. 仮で1としているが実際は計算する
    double startTemp = 30;
    double endTemp = 10;
    double T = startTemp + (endTemp-startTemp)*(t/timer.LIMIT);
    if (diff >= T * rnd.nextLog()) {
      // FIXME: 更新
    }
  }
}
#endif
#line 3 "util/marathon/simulated_annealing.cpp"
using namespace std;

// update(), calcScore(), revert(), write()を実装する
struct State {
  State() {}
  double update() { return 0; } // FIXME: 状態を次状態に更新しスコアの差分を返す. 
  double calcScore() { return 0; } // FIXME: 現在の状態のスコアを返す.
  void revert() {} // update()適用前の状態に戻す.
  void write() {} // 現在の状態を出力する.
};

struct SASolver {
  double startTemp = 30;
  double endTemp = 10;
  Timer timer = Timer(2.95);
  State best;
  SASolver() { init(); }
  SASolver(double st, double et): startTemp(st), endTemp(et) { init(); }
  SASolver(double st, double et, double limit): startTemp(st), endTemp(et), timer(limit) { init(); }
  void init() {} // 初期化処理をここに書く

  void solve(State &state) {
    double t;
    double score = state.calcScore();
    best = state;
    double bestScore = score;
    int counter = 0;
    while ((t = timer.get()) < timer.LIMIT) // 焼きなまし終了時刻までループ
    {
      for (int i = 0; i < 1000; ++i) { // 時間計算を間引く
        int diff = state.update();

        // 最初t=0のときは、スコアが良くなろうが悪くなろうが、常に次状態を使用
        // 最後t=timer.LIMITのときは、スコアが改善したときのみ、次状態を使用
        double T = startTemp + (endTemp - startTemp) * t / timer.LIMIT;
        // スコアが良くなった or 悪くなっても強制遷移
        if (diff >= T*rnd.nextLog())
        {
          score += diff;
          if (bestScore < score) {
            bestScore = score;
            best = state;
            // cerr << "time = " << t << ", counter = " << counter << ", score = " << bestScore << endl;
          }
        }
        else { state.revert(); }
        ++counter;
      }
    }
    // cerr << "counter = " << counter << ", score = " << bestScore << endl;
  }
};

#if 0
int main() {
  State state; // 開始状態
  SASolver s;
  s.solve(state);
  s.best.write();
}
#endif

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

