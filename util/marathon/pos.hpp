#pragma once
#include <cmath>
#include <limits>
#include <iostream>

int DX[9] = {0, 1, 0, -1, -1, -1, 1, 1, 0};
int DY[9] = {-1, 0, 1, 0, -1, 1, -1, 1, 0};

namespace pos {
    int W, H; // xとyのサイズ
    static constexpr int UP = 0;
    static constexpr int RIGHT = 1;
    static constexpr int DOWN = 2;
    static constexpr int LEFT = 3;
}

struct Pos {
  int x = -1, y = -1;
  Pos() {}
  Pos(int i): x(i%pos::W), y(i/pos::W) {}
  Pos(int x, int y): x(x), y(y) {}
  bool operator == (const Pos &other) const { 
    return (other.x == x) && (other.y == y);
  }
  bool operator != (const Pos &other) const { 
    return !((*this) == other);
  }
  int euclid(const Pos &other) const {
    return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
  }
  int manhattan(const Pos &other) const {
    return abs(x-other.x)+abs(y-other.y);
  }
  Pos to(int d) const { return Pos(x+DX[d],y+DY[d]); }
  int id() const { return y*pos::W+x; }
  bool outside() const {
    return x < 0 || x >= pos::W || y < 0 || y >= pos::H;
  }
  friend std::ostream& operator<<(std::ostream& os, const Pos &p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
  }
};

namespace pos {
    Pos nullpos;
}