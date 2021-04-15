/**
 * @title トポロジカルソート 
 */
#include <vector>
#include <stack>
#include "template.hpp"

template< typename G >
std::vector<int> topologicalSort(const G &g) {
  // トポロジカルソートした結果を返す
  const int V = g.size();
  std::vector<int> indegree(V); // 200000とかだと遅い？ 厳しそうならグローバル変数にする
  // 入次数の初期化. ほんとは読み込み時にやったほうが効率が良いけど許容する
  for (int v = 0; v < V; ++v) {
    for (auto& e: g[v]) ++indegree[e.to];
  }

  std::stack<int> st;
  for (int v = 0; v < V; ++v) {
    // 入次数0の点をstackにいれる
    if (indegree[v] == 0) st.push(v);
  }

  std::vector<int> order;
  while (!st.empty()) {
    int v = st.top(); st.pop();
    order.push_back(v);
    for (auto& e: g[v]) {
      --indegree[e.to];
      if (indegree[e.to] == 0) st.push(e.to);
    }
  }

  return order;
}
