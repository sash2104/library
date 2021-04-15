#ifndef __GRAPH__LCA
#define __GRAPH__LCA
// @title LCA (最小共通祖先)
#include "template.hpp"

#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

template< typename T >
struct LCA {
  using graph = Graph<T>;
  int root;
  // n : 頂点数
  const int n;
  const int log2_n;
  graph g;
  vector<vector<int>> parent;
  vector<int> depth;

  LCA(int root, const graph &g) : root(root), n(g.size()), log2_n(log2(n)+1), g(g), parent(log2_n, vector<int>(n)), depth(n) {
    dfs(g, root, root, 1);
    for (int k = 0; k+1 < log2_n; ++k) {
      parent.push_back(vector<int>(n, root)); // 要素数n, 値rootで初期化
      for (int v = n-1; v >= 0; --v) {
        int par = parent[k][v];
        parent[k+1][v] = parent[k][par];
      }
    }
  }
  
  /** 
   * par : 親のid
   * d : 木の深さ (1から始める)
   */ 
  void dfs(const graph& g, int from, int par, int d) {
    parent[0][from] = par;
    depth[from] = d;
    for (auto &e: g[from]) {
      if (depth[e.to] > 0) continue;
      dfs(g, e.to, from, d+1);
    }
  }

  int get(int v1, int v2) {
    // 深さが同じになるまで片方を登らせる
    if (depth[v1] < depth[v2]) swap(v1, v2);
    for (int k = 0; k < log2_n; ++k) {
      if ((depth[v1]-depth[v2]) >> k & 1) {
        v1 = parent[k][v1];
      }
    }
    if (v1 == v2) return v1;

    // 親が同じになる直前まで登らせる
    for (int k = log2_n-1; k >= 0; --k) {
      int p_v1 = parent[k][v1];
      int p_v2 = parent[k][v2];
      if (p_v1 == p_v2) continue;
      v1 = p_v1;
      v2 = p_v2;
    }
    assert(parent[0][v1] == parent[0][v2]);
    return parent[0][v1];
  }
};

#endif // __GRAPH__LCA