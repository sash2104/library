// @brief 木の直径のテスト
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../../graph/tree-diameter.cpp"

using namespace std;
#include <iostream>

int main() {
  int N; cin >> N;
  Graph< int > g(N);
  for(int i = 1; i < N; i++) {
    int x, y, z; cin >> x >> y >> z;
    g[x].emplace_back(x, y, z);
    g[y].emplace_back(y, x, z);
  }
  cout << tree_diameter(g) << endl;
}