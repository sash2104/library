#ifndef __GRAPH__TREE_DIAMETER
#define __GRAPH__TREE_DIAMETER
// @title 木の直径

#include <utility>
#include "template.hpp"

namespace tree_diameter_
{
template< typename T >
std::pair< T, int > dfs(const Graph<T> &g, int idx, int par) {
  std::pair< T, int > ret(0, idx);
  for(auto &e : g[idx]) {
    if(e.to == par) continue;
    auto cost = dfs(g, e.to, idx);
    cost.first += e.cost;
    ret = max(ret, cost);
  }
  return ret;
}

} // namespace tree_diameter

template< typename T >
T tree_diameter(const Graph<T> &g) {
  auto p = tree_diameter_::dfs(g, 0, -1);
  auto q = tree_diameter_::dfs(g, p.second, -1);
  return (q.first);
}

#endif // __GRAPH__TREE_DIAMETER