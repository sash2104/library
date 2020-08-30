/**
 * @title 双対セグメント木 (区間更新、一点取得がO(logN))
 * @brief 区間更新、一点取得がO(logN)でできるやつ
 *   定数倍は悪そうだが、似たコードをたくさん管理したくないのでLazySegmentTreeを使い回す
 *  
 */ 
#include <cassert>
#include "lazy-segment-tree.cpp"

template <class OperatorMonoid>
struct DualSegmentTree {
  typedef typename OperatorMonoid::value_t operator_t;
  LazySegmentTree<OperatorMonoid, OperatorMonoid> lst;
  DualSegmentTree() : lst([](operator_t a, operator_t b) { return OperatorMonoid().merge(a, b); }) {}
  void build(const std::vector<operator_t> &v) { lst.build(v); }
  void update(int a, int b, operator_t x) { lst.update(a, b, x); }
  operator_t query(int a, int b) {
    assert(a+1 == b); // 一点取得のみを認める
    return lst.query(a, b);
  }
  operator_t operator[](const int &k) { return lst[k]; }
};
