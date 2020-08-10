#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "../../string/rolling-hash.hpp"
#include <iostream>
using namespace std; 

using ull = unsigned long long;
int main() {
  string T, P;

  cin >> T;
  cin >> P;
  RollingHash rh(T), rh2(P);
  for(int i = 0; i + P.size() <= T.size(); i++) {
    ull h1 = rh.get(i, i+ P.size());
    ull h2 = rh2.get(0, P.size());
    // cerr << h1 << " " << h2 << " " << i + P.size() << endl;
    if(rh.get(i, i + P.size()) == rh2.get(0, P.size())) {
      cout << i << endl;
    }
  }
}
