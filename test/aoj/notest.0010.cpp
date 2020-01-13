#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0010"
#include "../../geometry/triangle.hpp"

#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    Point a, b, c;
    cin >> a >> b >> c;
    Circle cc = circumcircle(a, b, c);
    cout << fixed << setprecision(3) << cc.p.X << " " << cc.p.Y << " " << cc.r << endl;
  }
}