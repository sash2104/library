#include <vector>
#include <stack>
#include "template.cpp"
using namespace std;

template< typename G >
vector<int> topologicalSort(const G &g) {
  // トポロジカルソートした結果を返す
  const int V = g.size();
  vector<int> indegree(V); // 200000とかだと遅い？ 厳しそうならグローバル変数にする
  // 入次数の初期化. ほんとは読み込み時にやったほうが効率が良いけど許容する
  for (int v = 0; v < V; ++v) {
    for (auto& e: g[v]) ++indegree[e.to];
  }

  stack<int> st;
  for (int v = 0; v < V; ++v) {
    // 入次数0の点をstackにいれる
    if (indegree[v] == 0) st.push(v);
  }

  vector<int> order;
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
