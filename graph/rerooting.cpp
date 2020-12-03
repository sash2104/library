/**
 * @brief 全方位木DP (ReRooting)
 * https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e
 * https://github.com/noshi91/blog/blob/master/codes/rerooting.cpp
 * 
 */
#include <functional>
#include <stack>
#include <vector>
#include <iostream>

#include "template.cpp"

template <typename Cost, class Monoid>
struct ReRooting {
  struct Edge { 
    int from, to;
    Cost cost;
  };
  typedef typename Monoid::value_t T;
  int n; // node数
  const Monoid monoid;

  std::vector<std::vector<int>> adjacents;
  std::vector<std::vector<int>> adjacentIds;

  std::vector<T> Res;
  std::vector<std::vector<T>> DP;

  using F = std::function<T(T, int)>;
  F f; //T f(T value, int nodeID) { } で定義される頂点の追加関数

  void add_edge(int u, int v) {
      adjacentIds[u].push_back(adjacents[v].size());
      adjacentIds[v].push_back(adjacents[u].size());
      adjacents[u].push_back(v);
      adjacents[v].push_back(u);
  }
  ReRooting(int n, F f) : n(n), monoid(), f(f), adjacents(n), adjacentIds(n) {}
  std::vector<T> solve() {
    DP = std::vector<std::vector<T>>(n);
    Res = std::vector<T>(n);

    for (int i = 0; i < adjacents.size(); i++) {
      DP[i] = std::vector<T>(adjacents[i].size());
    }
    if (n == 1) {
      Res[0] = f(monoid.identity(), 0);
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
      int node = stack.top();
      stack.pop();
      order[index++] = node;
      for (int adjacent: adjacents[node]) {
        if (adjacent == parents[node])
          continue;
        stack.push(adjacent);
        parents[adjacent] = node;
      }
    }

    //帰りがけ順で部分木の値を求めていく
    for (int i = order.size() - 1; i >= 1; i--) {
      int node = order[i];
      int parent = parents[node];
      T accum = monoid.identity();
      int parentId = -1;
      for (int j = 0; j < adjacents[node].size(); j++) {
        if (adjacents[node][j] == parent) {
          parentId = j;
          continue;
        }
        accum = monoid.merge(accum, DP[node][j]);
      }
      int childId = adjacentIds[node][parentId];
      DP[parent][childId] = f(accum, node);
    }

    //行きがけ順で頂点の値を確定させていく
    for (int i = 0; i < order.size(); i++) {
      int node = order[i];
      T accum = monoid.identity();
      std::vector<T> rdp(adjacents[node].size());
      rdp[rdp.size() - 1] = monoid.identity();
      for (int j = rdp.size() - 1; j >= 1; j--) {
        rdp[j - 1] = monoid.merge(DP[node][j], rdp[j]);
      }
      for (int j = 0; j < rdp.size(); j++) {
        DP[adjacents[node][j]][adjacentIds[node][j]] =
          f(monoid.merge(accum, rdp[j]), node);
        accum = monoid.merge(accum, DP[node][j]);
      }
      Res[node] = f(accum, node);
    }
  }
};