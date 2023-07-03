#pragma once
#include <array>

// 初期化をO(1)でできるやつ。BFSを繰り返すときに便利
// @see https://topcoder-tomerun.hatenablog.jp/entry/2022/11/06/145156
// @see https://twitter.com/koyumeishi_/status/1589142265209188352
template<int N>
struct InitArray {
  uint32_t epoch = 1;
  std::array<uint32_t, N> arr = {};
  void set(int i) { arr[i] = epoch; }
  void reset() { epoch++; }
  bool operator[](int i) const {
    return arr[i] == epoch;
  }
};