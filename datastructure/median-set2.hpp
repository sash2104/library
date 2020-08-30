#pragma once

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;
// @see : https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4
// 集合の中央値の取得, 集合への要素の追加, 削除がO(logQ)程度で行えるデータ構造
struct MedianSet2 {
  vector<int> data;
  int m; // 中央値
  int n; // 要素数
  int loss; // (中央値と各要素との差分の絶対値)の和
  MedianSet2() : m(0), n(0), loss(0), data(26, 0) {}

  int add(int x)  {
    ++n; ++data[x];
    int nm = (n+1)/2;
    int c = 0;
    for (int i = 0; i < 26; ++i) {
      if (data[i] == 0) continue;
      c += data[i];
      if (c >= nm) { m = i; break; }
    }
    int nloss = 0;
    for (int i = 0; i < 26; ++i) {
      nloss += data[i]*abs(i-m);
    }
    int dloss = nloss-loss;
    loss = nloss;
    return dloss;
  }

  int remove(int x) {
    --n; --data[x];
    if (n == 0) { m = loss = 0; return 0; }
    int nm = (n+1)/2;
    int c = 0;
    for (int i = 0; i < 26; ++i) {
      if (data[i] == 0) continue;
      c += data[i];
      if (c >= nm) { m = i; break; }
    }
    int nloss = 0;
    for (int i = 0; i < 26; ++i) {
      nloss += data[i]*abs(i-m);
    }
    int dloss = nloss-loss;
    loss = nloss;
    return -dloss;
  }

  int get() { return m; }
};