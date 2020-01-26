#pragma once
#include <cmath>

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
