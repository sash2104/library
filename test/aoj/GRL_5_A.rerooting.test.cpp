// @brief 木の直径 (ReRooting)
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../../graph/rerooting.cpp"

using namespace std;
#include <iostream>

#include <algorithm>
#include <limits>

namespace monoid {
template <class T>
struct max {
  typedef T value_t;
  T identity() const { return std::numeric_limits<T>::min();}
  T merge(T a, T b) const { return std::max(a, b); }
};
} // namespace monoid

int main() {
  int N; cin >> N;
  auto f=[](int value, int id) -> int { 
    if (value < 0) return 0;
    return value+1;
  };
  ReRooting<int, monoid::max<int>> rerooting(N, f);
  for(int i = 1; i < N; i++) {
    int x, y, z; cin >> x >> y >> z;
    rerooting.add_edge(x, y);
  }
  auto ret = rerooting.solve();
  for (int i = 0; i < N; ++i) {
    cout << i << " " << ret[i] << endl;
  }
}