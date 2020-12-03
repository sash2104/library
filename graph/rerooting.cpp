/**
 * @brief 全方位木DP (ReRooting)
 * https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e
 * https://github.com/noshi91/blog/blob/master/codes/rerooting.cpp
 * 
 */
#include <cassert>
#include <functional>
#include <stack>
#include <vector>
#include <iostream>

#include "template.cpp"

template <typename Cost, class Monoid>
struct ReRooting {
  struct Node {
    int to, rev;
    Cost cost;
  };
  typedef typename Monoid::value_t T;
  int n; // node数
  const Monoid monoid;

  std::vector<T> Res;
  std::vector<std::vector<T>> DP;
  std::vector<std::vector<Node>> g;

  using F = std::function<T(T, int)>;
  F f; //T f(T value, int nodeId) { } で定義される頂点の追加関数

  void add_edge(int u, int v, const Cost &c) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), c});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, c});
  }

  ReRooting(int n, F f) : n(n), monoid(), g(n), f(f) {}
  std::vector<T> solve() {
    DP = std::vector<std::vector<T>>(n);
    Res = std::vector<T>(n);

    for (int i = 0; i < n; i++) {
      DP[i] = std::vector<T>(g[i].size());
    }
    if (n == 1) {
      std::cerr << "頂点数1の場合は自力で計算すること" << std::endl;
      assert(false);
    }
    else { init(); }
    return Res;
  }

  void init() {
    // parents[i] := 一時的な根付き木として考えた時の、ノードiについての親
    std::vector<int> parents(n);
    std::vector<int> order(n); // dfsでの行きがけ順

    int index = 0;
    std::stack<int> stack;
    // 0を根とする
    stack.push(0);
    parents[0] = -1;
    // 行きがけ順を記録する
    while (stack.size() > 0) {
      int nodeId = stack.top();
      stack.pop();
      order[index++] = nodeId;
      for (auto &node: g[nodeId]) {
        if (node.to == parents[nodeId])
          continue;
        stack.push(node.to);
        parents[node.to] = nodeId;
      }
    }

    //帰りがけ順で部分木の値を求めていく
    for (int i = order.size() - 1; i >= 1; i--) {
      int nodeId = order[i];
      int parent = parents[nodeId];
      T accum = monoid.identity();
      int parentId = -1;
      for (int j = 0; j < g[nodeId].size(); j++) {
        if (g[nodeId][j].to == parent) {
          parentId = j;
          continue;
        }
        accum = monoid.merge(accum, DP[nodeId][j]);
      }
      int childId = g[nodeId][parentId].rev;
      DP[parent][childId] = f(accum, nodeId);
    }

    //行きがけ順で頂点の値を確定させていく
    for (int i = 0; i < order.size(); i++) {
      int nodeId = order[i];
      T accum = monoid.identity();
      std::vector<T> rdp(g[nodeId].size());
      rdp[rdp.size() - 1] = monoid.identity();
      for (int j = rdp.size() - 1; j >= 1; j--) {
        rdp[j - 1] = monoid.merge(DP[nodeId][j], rdp[j]);
      }
      for (int j = 0; j < rdp.size(); j++) {
        auto &node = g[nodeId][j];
        DP[node.to][node.rev] = f(monoid.merge(accum, rdp[j]), nodeId);
        accum = monoid.merge(accum, DP[nodeId][j]);
      }
      Res[nodeId] = f(accum, nodeId);
    }
  }
};