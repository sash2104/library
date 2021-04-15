/**
 * @title 最小全域木 (クラスカル法)
 */
#include <algorithm>
#include "template.hpp"
#include "../datastructure/union-find-tree.hpp"

template< typename T >
T kruscal(int V, Edges< T > &edges) {
  // 最小全域木の重みを返す
  UnionFind uf(V);
  T weight = 0;
  std::sort(edges.begin(), edges.end());
  for (auto e : edges) {
    if (uf.same(e.from, e.to)) continue;
    uf.unite(e.from, e.to);
    weight += e.cost;
  }
  return weight;
}
