#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"
#define ERROR "0.00000001"
#include "../../geometry/template.hpp"

#include <iostream>
using namespace std;
int main() {
  Line l; cin >> l;
  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    Point p; cin >> p;
    Point x = projection(l, p);
    cout << x << endl;
  }
}