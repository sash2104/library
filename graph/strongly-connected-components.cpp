#include <cassert>
#include <algorithm>
#include <vector>

#include "template.cpp"
using namespace std;

template< typename T >
struct stronglyConnectedComponents {
  using graph = Graph<T>;
  const int V;
  graph g, rg;
  vector<bool> visit;
  vector<int> comp, order;
  vector<vector<int>> components;

  stronglyConnectedComponents(const graph &g) : V(g.size()), g(g), rg(V), visit(V, false), comp(V, -1) {
    // 辺の向きを逆にしたグラフを構築
    for (int v = 0; v < V; ++v) {
      for (auto &e : g[v]) { 
        rg[e.to].emplace_back(e.to, e.from);
      }
    }
  }

  // 同じ強連結成分に属していればtrueを返す
  bool same(int s, int t) {
    assert(comp[s] != -1 && comp[t] != -1);
    return comp[s] == comp[t];
  }

  void dfs(int sv) { 
    if (visit[sv]) return;
    visit[sv] = true;
    for (auto &e : g[sv]) { 
      dfs(e.to);
    }
    order.push_back(sv);
  }

  void rdfs(int sv, int cnt) { 
    if (comp[sv] != -1) return;
    comp[sv] = cnt;

    if (components.size() <= cnt) { 
      vector<int> v;
      components.push_back(v);
    }
    components[cnt].push_back(sv);

    for (auto &e : rg[sv]) { 
      rdfs(e.to, cnt);
    }
  }

  void build() {
    for(int i = 0; i < V; i++) { dfs(i); } 
    assert(order.size() == V);
    reverse(order.begin(), order.end()); // dfsでつけた番号を逆順にする
    int cnt = 0; // 強連結成分毎のid
    for (int v : order) { 
      if (comp[v] != -1) continue;
      rdfs(v, cnt);
      // 強連結成分の頂点をループの順に並び替え
      if (components[cnt].size() > 1) {
        reverse(components[cnt].begin()+1, components[cnt].end());
      }
      ++cnt;
    }
  }
};
