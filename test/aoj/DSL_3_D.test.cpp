#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#define call_from_test
#include "../../datastructure/slide-min.cpp"
#undef call_from_test

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, l; cin >> n >> l;
  vector<int> la(n);
  for (int &a: la) cin >> a;

  vector<int> ret = slideMin(la, l);
  for (int i = 0; i < ret.size(); ++i) {
    if (i > 0) cout << " ";
    cout << la[ret[i]];
  }
  cout << endl;
}
