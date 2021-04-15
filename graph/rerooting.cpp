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

#include "template.hpp"

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

  using F = std::function<T(T, Cost)>;
  F f; //T f(T value, Cost cost) { } で定義される頂点の追加関数

  void add_edge(int u, int v, const Cost &c) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), c});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, c});
  }
  void add_edge(int u, int v, const Cost &c1, const Cost &c2) {
    g[u].emplace_back((Node) {v, (int) g[v].size(), c1});
    g[v].emplace_back((Node) {u, (int) g[u].size() - 1, c2});
  }

  ReRooting(int n, F f) : n(n), monoid(), g(n), f(f) {}
  std::vector<T> solve() {
    DP = std::vector<std::vector<T>>(n);
    Res = std::vector<T>(n, monoid.identity());
    if (n == 1) { // FIXME: n = 1も同様に扱える様にする
      std::cerr << "n=1は自分で求めること" << std::endl;
      assert(false);
    }

    for (int i = 0; i < n; i++) {
      DP[i] = std::vector<T>(g[i].size());
    }
    init();
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
      DP[parent][childId] = f(accum, g[parent][childId].cost);
      // std::cerr << parent << "->" << childId << " " << DP[parent][childId] << std::endl;
    }

    //行きがけ順で頂点の値を確定させていく
    for (int i = 0; i < order.size(); i++) {
      int nodeId = order[i];
      T accum = monoid.identity();
      int numChild = g[nodeId].size();
      std::vector<T> rdp(numChild);
      rdp[numChild-1] = monoid.identity();
      for (int j = numChild-1; j >= 1; j--) {
        rdp[j - 1] = monoid.merge(DP[nodeId][j], rdp[j]);
      }
      for (int j = 0; j < numChild; j++) {
        auto &node = g[nodeId][j];
        DP[node.to][node.rev] = f(monoid.merge(accum, rdp[j]), g[node.to][node.rev].cost);
        accum = monoid.merge(accum, DP[nodeId][j]);
      }
      // FIXME: ここ、monoid.identity()の値を気をつけないとchild数が0の場合にバグる気がする
      Res[nodeId] = accum;
    }
  }
};