#ifndef _DATASTRUCTURE_DUAL_SEGMENT_TREE
#define _DATASTRUCTURE_DUAL_SEGMENT_TREE
/**
 * @title 双対セグメント木 (区間更新、一点取得)
 * @brief 区間更新、一点取得ができるやつ
 *   定数倍は悪そうだが、似たコードをたくさん管理したくないのでLazySegmentTreeを使い回す
 *  
 */ 
#include <cassert>
#include "lazy-segment-tree.hpp"

template <class OperatorMonoid>
struct DualSegmentTree {
  typedef typename OperatorMonoid::value_t operator_t;
  LazySegmentTree<OperatorMonoid, OperatorMonoid> lst;
  DualSegmentTree() : lst([](operator_t a, operator_t b) { return OperatorMonoid().merge(a, b); }) {}
  void build(const std::vector<operator_t> &v) { lst.build(v); }
  void update(int a, int b, operator_t x) { lst.update(a, b, x); }
  operator_t query(int a) {
    return lst.query(a, a+1);
  }
  operator_t operator[](const int &k) { return lst[k]; }
};

#endif // _DATASTRUCTURE_DUAL_SEGMENT_TREE