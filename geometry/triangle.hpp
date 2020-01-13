#pragma once
#include "template.hpp"

// 外接円
Circle circumcircle(const Point &a, const Point &b, const Point &c) {
  Real a1,a2,b1,b2,c1,c2;
  a1=2*(b.X-a.X);
  b1=2*(b.Y-a.Y);
  c1=a.X*a.X-b.X*b.X+a.Y*a.Y-b.Y*b.Y;
  a2=2*(c.X-a.X);
  b2=2*(c.Y-a.Y);
  c2=a.X*a.X-c.X*c.X+a.Y*a.Y-c.Y*c.Y;
  Real px = (b1*c2-b2*c1)/(a1*b2-a2*b1);
  Real py = (c1*a2-c2*a1)/(a1*b2-a2*b1);
  Point circumcenter(px, py); // 外心
  Real r = distance(a, circumcenter);
  return Circle(circumcenter, r);
}
