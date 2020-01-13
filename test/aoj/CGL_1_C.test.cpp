#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"
#include "../../geometry/template.hpp"

#include <cassert>
#include <iostream>
using namespace std;
int main() {
  Point p0, p1; cin >> p0 >> p1;
  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    Point p2; cin >> p2;
    int type = ccw(p0, p1, p2);
    switch(type) {
      case +1: cout << "COUNTER_CLOCKWISE"; break;
      case -1: cout << "CLOCKWISE"; break;
      case +2: cout << "ONLINE_BACK"; break;
      case -2: cout << "ONLINE_FRONT"; break;
      case 0: cout << "ON_SEGMENT"; break;
      default: assert(false);
    }
    cout << endl;
  }
}