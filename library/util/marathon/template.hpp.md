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


# :warning: util/marathon/template.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6cc910c4eb495362d5e64f63c07ca62e">util/marathon</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/marathon/template.hpp">View this file on GitHub</a>
    - Last commit date: 2020-01-26 13:05:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cmath>

struct Timer {
  static constexpr int64_t CYCLES_PER_SEC = 2800000000;
  static constexpr double LIMIT = 2.95; // FIXME: 時間制限(s)
  int64_t start;
  Timer() { reset(); }
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
  Timer timer;
  while (true) {
    double ti = timer.get(); // elapsed seconds
    if (Timer::LIMIT < ti) break;
    double diff = 1; // SAのdiff. 仮で1としているが実際は計算する
    double startTemp = 10;
    double endTemp = 30;
    double rem = (Timer::LIMIT - ti) / Timer::LIMIT; // remain time rate
    double T = startTemp + (endTemp-startTemp)*rem;
    if (diff >= T * rnd.nextLog()) {
      // FIXME: 更新
    }
  }
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "util/marathon/template.hpp"
#include <cmath>

struct Timer {
  static constexpr int64_t CYCLES_PER_SEC = 2800000000;
  static constexpr double LIMIT = 2.95; // FIXME: 時間制限(s)
  int64_t start;
  Timer() { reset(); }
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
  Timer timer;
  while (true) {
    double ti = timer.get(); // elapsed seconds
    if (Timer::LIMIT < ti) break;
    double diff = 1; // SAのdiff. 仮で1としているが実際は計算する
    double startTemp = 10;
    double endTemp = 30;
    double rem = (Timer::LIMIT - ti) / Timer::LIMIT; // remain time rate
    double T = startTemp + (endTemp-startTemp)*rem;
    if (diff >= T * rnd.nextLog()) {
      // FIXME: 更新
    }
  }
}
#endif

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

