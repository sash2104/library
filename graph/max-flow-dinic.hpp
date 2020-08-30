/**
 * @title 最大流
 * @see 蟻本 p.194 
 */
#pragma once
#include <vector>
#include <queue>

struct max_flow {
  struct edge { int to, cap, rev; };
  int INF_ = 1<<30;
  int V;
  std::vector<std::vector<edge>> G; // グラフの隣接リスト表現
  std::vector<int> level; // sからの距離
  std::vector<int> iter; // どこまで調べ終わったか
  max_flow(int V): V(V), G(V), level(V), iter(V) {}
  void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
  }

  // sからの最短距離を計算する
  void bfs(int s) {
    level.assign(V, -1);
    std::queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) { 
      int v = q.front(); q.pop();
      for (int i = 0; i < (int)G[v].size(); ++i) { 
        edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) { 
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }

  // 増加パスを探す
  int dfs(int v, int t, int f) { 
    if (v == t) return f;
    for (int &i = iter[v]; i < (int)G[v].size(); ++i) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) { 
        int d = dfs(e.to, t, std::min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  // sからtへの最大流を求める
  int run(int s, int t) {
    int flow = 0;
    while (true) {
      bfs(s);
      if (level[t] < 0) return flow;
      // FIXME: ここ毎回初期化しない方法もありそう？
      // https://snuke.hatenablog.com/entry/2019/05/07/013609
      iter.assign(V, 0);
      int f;
      while ((f = dfs(s, t, INF_)) > 0) {
        flow += f;
      }
    }
    return flow;
  }
};
