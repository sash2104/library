#include <algorithm>
#include <iostream>
#include <vector>
#include "template.cpp"
#include "../datastructure/union-find-tree.cpp"

template< typename T >
T kruscal(int V, Edges< T > &edges) {
  // 最小全域木の重みを返す
  UnionFind uf(V);
  T weight = 0;
  sort(edges.begin(), edges.end());
  for (auto e : edges) {
    if (uf.same(e.from, e.to)) continue;
    uf.unite(e.from, e.to);
    weight += e.cost;
  }
  return weight;
}