/**
 * @title スライド最小値
 */
#include <iostream>
#include <deque>
#include <vector>

template <class T>
std::vector<int> slideMin(const std::vector<T>& v, int k) {
  /* vの連続するk区間の最小値のindexのリストを返す */
  std::vector<int> ret;
  std::deque<int> dq;
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    while (dq.size() && v[dq.back()] >= v[i]) dq.pop_back();
    dq.push_back(i);
    if (i - k + 1 >= 0) {
      ret.push_back(dq.front());
      if (dq.front() <= i-k+1) dq.pop_front();
    }
  }
  return ret;
}

#if 0
#include <cassert>
int main() {
  std::vector<int> v = {1, 3, 5, 4, 2};

  int k = 3;
  std::vector<int> ret = slideMin(v, k);
  assert(ret.size() == 3);
  assert(ret[0] == 0);
  assert(ret[1] == 1);
  assert(ret[2] == 4);
}
#endif
