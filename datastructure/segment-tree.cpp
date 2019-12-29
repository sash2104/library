#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// FIXME: 現状はRMQしか捌けないので汎用的に使えるよう修正する
struct SegmentTree {
  const int n_;
  int n; // n_以上の最小の2冪
  vector<int> data;
  SegmentTree(int size) : n_(size) {
    n = 1;
    while (n < n_) n *= 2;
    data.resize(2*n-1);

    std::fill(data.begin(), data.end(), INT_MAX);
  }

  // k番目の値(0-indexed)をaに変更
  void update(int k, int a) {
    // 葉の節点
    k += n-1;
    data[k] = a;
    // 登りながら更新
    while (k > 0) { 
      k = (k - 1)/2;
      data[k] = min(data[k*2+1], data[k*2+2]);
    }
  }

  int query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  // [a, b)の最小値を求める
  // query(a, b, 0, 0, n)として呼ぶ
  int query(int a, int b, int k, int l, int r) { 
    // [a, b)と[l, r)が交差しなければINT_MAX
    // cerr << a << " " << b << " " << k << " " << l << " " << r << endl;
    if (r <= a || b <= l) return INT_MAX;

    // [a, b)が[l, r)を完全に含んでいればこの接点の値
    if (a <= l && r <= b) return data[k];

    // そうでなければ二つの子の最小値
    int vl = query(a, b, k*2+1, l, (l+r)/2);
    int vr = query(a, b, k*2+2, (l+r)/2, r);
    // cerr << vl << " " << vr << endl;
    return min(vl, vr);
  }
};
