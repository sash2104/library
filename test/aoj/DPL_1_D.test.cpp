// @brief LISのテスト
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
#include "../../util/lis.hpp"

#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> la(n);
  for (int i = 0; i < n; ++i) {
      cin >> la[i];
  }
  auto lis = longest_increasing_subsequence(la, true);
  cout << lis.size() << endl;
}