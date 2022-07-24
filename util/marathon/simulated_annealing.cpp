// 利用例:  https://atcoder.jp/contests/chokudai004/submissions/9724794
#include "template.hpp"
using namespace std;

// update(), calcScore(), revert(), write()を実装する
struct State {
  double score = 0;
  State() {}
  double update(double progress) { return 0; } // FIXME: 状態を次状態に更新しスコアの差分を返す. 
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
    best = state;
    int step = 0;
    // best.write();
    while ((t = timer.get()) < timer.LIMIT) // 焼きなまし終了時刻までループ
    {
      double T = startTemp + (endTemp - startTemp) * t / timer.LIMIT;
      double progress = t/timer.LIMIT;
      // assert(0 <= progress && progress <= 1);
      for (int i = 0; i < 100; ++i) { // 時間計算を間引く
        double diff = state.update(progress);

        // 最初t=0のときは、スコアが良くなろうが悪くなろうが、常に次状態を使用
        // 最後t=timer.LIMITのときは、スコアが改善したときのみ、次状態を使用
        // スコアが良くなった or 悪くなっても強制遷移
        double tr = T*rng.nextLog();
        if (diff >= tr)
        {
          if (best.score < state.score) {
            best = state;
            D1(t, step, best.score);
            // best.write();
          }
        }
        else { state.revert(); }
        ++step;
      }
    }
    D1(step, best.score);
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
