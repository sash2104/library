/**
 * @title 中央値
 * @see https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4
 * @brief 集合の中央値の取得, 集合への要素の追加, 削除がO(logQ)程度で行えるデータ構造
 */
#pragma once

#include <cassert>
#include <algorithm>
#include <iostream>
#include <map>

struct MedianSet {
  int l; // 中央値より小さい要素の個数
  int r; // 中央値より大きい要素の個数
  int m; // 中央値
  int n; // 要素数
  int loss; // (中央値と各要素との差分の絶対値)の和
  MedianSet() : l(0), r(0), m(0), n(0), loss(0) {}
  std::map<int, int> data; 

  void update() { // l, r, mの値を適切なものに更新する
    if (n == 0) { l = r = m = loss = 0; return; }
    int bm = m;
    if (l >= data[m]+r) {
      int nm = std::prev(data.find(m))->first;
      r += data[m];
      l -= data[nm];
      m = nm;
    }
    else if (r > data[m]+l) {
      auto it = std::next(data.find(m));
      int nm = std::next(data.find(m))->first;
      l += data[m];
      r -= data[nm];
      m = nm;
    }
    if (data[bm] == 0) data.erase(bm);
  }

  int add(int x)  {
    int bm = m, bl = l, br = r, bc = data[bm];
    ++data[x]; ++n;
    if (x < m) ++l;
    else if (x > m) ++r;
    update();
    if (n == 1) return 0;
    // cerr << "[!]" << bl << " " << br << " " << bm << " " << m << endl;
    int dloss = (br-bl)*(bm-m)+abs(m-bm)*bc+abs(x-m);
    loss += dloss;
    return dloss;
  }

  int remove(int x) {
    int bm = m, bl = l, br = r, bc = data[bm];
    if (x < bm) --bl;
    else if (x == bm) --bc;
    else --br;
    --data[x]; --n;
    if (data[x] == 0) data.erase(x);
    if (x < m) --l;
    else if (x > m) --r;
    update();
    // cerr << "[!]" << bl << " " << br << " " << bm << " " << m << " " << x << endl;
    int dloss = (br-bl)*(m-bm)-abs(m-bm)*bc+abs(x-bm);
    loss -= dloss;
    return dloss;
  }

  int get() { return m; }

  void show() {
    std::cerr << m << " " << n << " " << loss << std::endl;
    for (auto it: data) {
      std::cerr << it.first << " " << it.second << std::endl;
    }
  }
};