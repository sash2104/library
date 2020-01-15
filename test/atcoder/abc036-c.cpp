#include <iostream>

#include "../../util/compress.hpp"

using namespace std;

int main() {
  int n; cin >> n;

  // ld[i]に、i桁の要素数を格納する
  vector<int> la(n);
  for (int &a: la) cin >> a;
  Compress<int> comp(la);
  comp.build();
  for (int &b: comp.get(la)) cout << b << endl;
}
