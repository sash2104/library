---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
  bundledCode: "#line 1 \"test/aoj/CGL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\
    \n#define ERROR \"0.00000001\"\n#line 2 \"geometry/template.hpp\"\n#include <cmath>\n\
    #include <algorithm>\n#include <complex>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <vector>\nusing namespace std;\n\nusing Real = double;\n\
    using Point = complex< Real >;\nconst Real EPS = 1e-10, PI = acos(-1);\n#define\
    \ X real()\n#define Y imag()\n\ninline bool eq(Real a, Real b) { return fabs(b\
    \ - a) < EPS; }\n\nPoint operator*(const Point &p, const Real &d) {\n  return\
    \ Point(real(p) * d, imag(p) * d);\n}\n\nistream &operator>>(istream &is, Point\
    \ &p) {\n  Real a, b;\n  is >> a >> b;\n  p = Point(a, b);\n  return is;\n}\n\n\
    ostream &operator<<(ostream &os, Point &p) {\n  return os << fixed << setprecision(10)\
    \ << p.X << \" \" << p.Y;\n}\n\n// rotate point p counterclockwise by theta rad\n\
    Point rotate(Real theta, const Point &p) {\n  return Point(cos(theta) * p.X -\
    \ sin(theta) * p.Y, sin(theta) * p.X + cos(theta) * p.Y);\n}\n\nReal radian_to_degree(Real\
    \ r) {\n  return (r * 180.0 / PI);\n}\n\nReal degree_to_radian(Real d) {\n  return\
    \ (d * PI / 180.0);\n}\n\n// smaller angle of the a-b-c\nReal get_angle(const\
    \ Point &a, const Point &b, const Point &c) {\n  const Point v(b - a), w(c - b);\n\
    \  Real alpha = atan2(v.Y, v.X), beta = atan2(w.Y, w.X);\n  if(alpha > beta) swap(alpha,\
    \ beta);\n  Real theta = (beta - alpha);\n  return min(theta, 2 * acos(-1) - theta);\n\
    }\n\nnamespace std {\n  bool operator<(const Point &a, const Point &b) {\n   \
    \ return a.X != b.X ? a.X < b.X : a.Y < b.Y;\n  }\n}\n\n\nstruct Line {\n  Point\
    \ a, b;\n\n  Line() = default;\n\n  Line(Point a, Point b) : a(a), b(b) {}\n\n\
    \  Line(Real A, Real B, Real C) // Ax + By = C\n  {\n    if(eq(A, 0)) a = Point(0,\
    \ C / B), b = Point(1, C / B);\n    else if(eq(B, 0)) b = Point(C / A, 0), b =\
    \ Point(C / A, 1);\n    else a = Point(0, C / B), b = Point(C / A, 0);\n  }\n\n\
    \  friend ostream &operator<<(ostream &os, Line &p) {\n    return os << p.a <<\
    \ \" to \" << p.b;\n  }\n\n  friend istream &operator>>(istream &is, Line &a)\
    \ {\n    return is >> a.a >> a.b;\n  }\n};\n\nstruct Segment : Line {\n  Segment()\
    \ = default;\n\n  Segment(Point a, Point b) : Line(a, b) {}\n};\n\nusing Points\
    \ = vector< Point >;\nusing Polygon = vector< Point >;\nusing Segments = vector<\
    \ Segment >;\nusing Lines = vector< Line >;\n\nReal cross(const Point &a, const\
    \ Point &b) {\n  return real(a) * imag(b) - imag(a) * real(b);\n}\n\nReal dot(const\
    \ Point &a, const Point &b) {\n  return real(a) * real(b) + imag(a) * imag(b);\n\
    }\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\nint\
    \ ccw(const Point &a, const Point &b, const Point &c) {\n  Point b2 = b-a;\n \
    \ Point c2 = c-a;\n  if(cross(b2, c2) > EPS) return +1;  // \"COUNTER_CLOCKWISE\"\
    \n  if(cross(b2, c2) < -EPS) return -1; // \"CLOCKWISE\"\n  if(dot(b2, c2) < 0)\
    \ return +2;      // \"ONLINE_BACK\" c-a-b\n  if(norm(b2) < norm(c2)) return -2;\
    \  // \"ONLINE_FRONT\" a-b-c\n  return 0;                         // \"ON_SEGMENT\"\
    \ a-c-b\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    bool parallel(const Line &a, const Line &b) {\n  return eq(cross(a.b - a.a, b.b\
    \ - b.a), 0.0);\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    bool orthogonal(const Line &a, const Line &b) {\n  return eq(dot(a.a - a.b, b.a\
    \ - b.b), 0.0);\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    Point projection(const Line &l, const Point &p) {\n  double t = dot(p - l.a, l.a\
    \ - l.b) / norm(l.a - l.b);\n  return l.a + (l.a - l.b) * t;\n}\n\nPoint projection(const\
    \ Segment &l, const Point &p) {\n  double t = dot(p - l.a, l.a - l.b) / norm(l.a\
    \ - l.b);\n  return l.a + (l.a - l.b) * t;\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\n\
    Point reflection(const Line &l, const Point &p) {\n  return p + (projection(l,\
    \ p) - p) * 2.0;\n}\n\nbool intersect(const Line &l, const Point &p) {\n  return\
    \ abs(ccw(l.a, l.b, p)) != 1;\n}\n\nbool intersect(const Line &l, const Line &m)\
    \ {\n  return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b\
    \ - l.a)) < EPS;\n}\n\nbool intersect(const Segment &s, const Point &p) {\n  return\
    \ ccw(s.a, s.b, p) == 0;\n}\n\nbool intersect(const Line &l, const Segment &s)\
    \ {\n  return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;\n\
    }\n\nReal distance(const Line &l, const Point &p);\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\n\
    bool intersect(const Segment &s, const Segment &t) {\n  return ccw(s.a, s.b, t.a)\
    \ * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n\
    }\n\nReal distance(const Point &a, const Point &b) {\n  return abs(a - b);\n}\n\
    \nReal distance(const Line &l, const Point &p) {\n  return abs(p - projection(l,\
    \ p));\n}\n\nReal distance(const Line &l, const Line &m) {\n  return intersect(l,\
    \ m) ? 0 : distance(l, m.a);\n}\n\nReal distance(const Segment &s, const Point\
    \ &p) {\n  Point r = projection(s, p);\n  if(intersect(s, r)) return abs(r - p);\n\
    \  return min(abs(s.a - p), abs(s.b - p));\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\n\
    Real distance(const Segment &a, const Segment &b) {\n  if(intersect(a, b)) return\
    \ 0;\n  return min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b,\
    \ a.b)});\n}\n\nReal distance(const Line &l, const Segment &s) {\n  if(intersect(l,\
    \ s)) return 0;\n  return min(distance(l, s.a), distance(l, s.b));\n}\n\nPoint\
    \ crosspoint(const Line &l, const Line &m) {\n  Real A = cross(l.b - l.a, m.b\
    \ - m.a);\n  Real B = cross(l.b - l.a, l.b - m.a);\n  if(eq(abs(A), 0.0) && eq(abs(B),\
    \ 0.0)) return m.a;\n  return m.a + (m.b - m.a) * B / A;\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\n\
    Point crosspoint(const Segment &l, const Segment &m) {\n  return crosspoint(Line(l),\
    \ Line(m));\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\n\
    bool is_convex(const Polygon &p) {\n  int n = (int) p.size();\n  for(int i = 0;\
    \ i < n; i++) {\n    if(ccw(p[(i + n - 1) % n], p[i], p[(i + 1) % n]) == -1) return\
    \ false;\n  }\n  return true;\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    Polygon convex_hull(Polygon &p) {\n  int n = (int) p.size(), k = 0;\n  if(n <=\
    \ 2) return p;\n  sort(p.begin(), p.end());\n  vector< Point > ch(2 * n);\n  for(int\
    \ i = 0; i < n; ch[k++] = p[i++]) {\n    while(k >= 2 && cross(ch[k - 1] - ch[k\
    \ - 2], p[i] - ch[k - 1]) < EPS) --k;\n  }\n  for(int i = n - 2, t = k + 1; i\
    \ >= 0; ch[k++] = p[i--]) {\n    while(k >= t && cross(ch[k - 1] - ch[k - 2],\
    \ p[i] - ch[k - 1]) < EPS) --k;\n  }\n  ch.resize(k - 1);\n  return ch;\n}\n\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C\nenum {\n\
    \  OUT, ON, IN\n};\n\nint contains(const Polygon &Q, const Point &p) {\n  bool\
    \ in = false;\n  for(int i = 0; i < (int)Q.size(); i++) {\n    Point a = Q[i]\
    \ - p, b = Q[(i + 1) % Q.size()] - p;\n    if(a.Y > b.Y) swap(a, b);\n    if(a.Y\
    \ <= 0 && 0 < b.Y && cross(a, b) < 0) in = !in;\n    if(cross(a, b) == 0 && dot(a,\
    \ b) <= 0) return ON;\n  }\n  return in ? IN : OUT;\n}\n\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033\n\
    // deduplication of line segments\nvoid merge_segments(vector< Segment > &segs)\
    \ {\n\n  auto merge_if_able = [](Segment &s1, const Segment &s2) {\n    if(abs(cross(s1.b\
    \ - s1.a, s2.b - s2.a)) > EPS) return false;\n    if(ccw(s1.a, s2.a, s1.b) ==\
    \ 1 || ccw(s1.a, s2.a, s1.b) == -1) return false;\n    if(ccw(s1.a, s1.b, s2.a)\
    \ == -2 || ccw(s2.a, s2.b, s1.a) == -2) return false;\n    s1 = Segment(min(s1.a,\
    \ s2.a), max(s1.b, s2.b));\n    return true;\n  };\n\n  for(int i = 0; i < (int)segs.size();\
    \ i++) {\n    if(segs[i].b < segs[i].a) swap(segs[i].a, segs[i].b);\n  }\n  for(int\
    \ i = 0; i < (int)segs.size(); i++) {\n    for(int j = i + 1; j < (int)segs.size();\
    \ j++) {\n      if(merge_if_able(segs[i], segs[j])) {\n        segs[j--] = segs.back(),\
    \ segs.pop_back();\n      }\n    }\n  }\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033\n\
    // construct a graph with the vertex of the intersection of any two line segments\n\
    vector< vector< int > > segment_arrangement(vector< Segment > &segs, vector< Point\
    \ > &ps) {\n  vector< vector< int > > g;\n  int N = (int) segs.size();\n  for(int\
    \ i = 0; i < N; i++) {\n    ps.emplace_back(segs[i].a);\n    ps.emplace_back(segs[i].b);\n\
    \    for(int j = i + 1; j < N; j++) {\n      const Point p1 = segs[i].b - segs[i].a;\n\
    \      const Point p2 = segs[j].b - segs[j].a;\n      if(cross(p1, p2) == 0) continue;\n\
    \      if(intersect(segs[i], segs[j])) {\n        ps.emplace_back(crosspoint(segs[i],\
    \ segs[j]));\n      }\n    }\n  }\n  sort(begin(ps), end(ps));\n  ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n\n  int M = (int) ps.size();\n  g.resize(M);\n  for(int\
    \ i = 0; i < N; i++) {\n    vector< int > vec;\n    for(int j = 0; j < M; j++)\
    \ {\n      if(intersect(segs[i], ps[j])) {\n        vec.emplace_back(j);\n   \
    \   }\n    }\n    for(int j = 1; j < (int)vec.size(); j++) {\n      g[vec[j -\
    \ 1]].push_back(vec[j]);\n      g[vec[j]].push_back(vec[j - 1]);\n    }\n  }\n\
    \  return (g);\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\n\
    // cut with a straight line l and return a convex polygon on the left\nPolygon\
    \ convex_cut(const Polygon &U, Line l) {\n  Polygon ret;\n  for(int i = 0; i <\
    \ (int)U.size(); i++) {\n    Point now = U[i], nxt = U[(i + 1) % U.size()];\n\
    \    if(ccw(l.a, l.b, now) != -1) ret.push_back(now);\n    if(ccw(l.a, l.b, now)\
    \ * ccw(l.a, l.b, nxt) < 0) {\n      ret.push_back(crosspoint(Line(now, nxt),\
    \ l));\n    }\n  }\n  return (ret);\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    Real area(const Polygon &p) {\n  Real A = 0;\n  for(int i = 0; i < (int)p.size();\
    \ ++i) {\n    A += cross(p[i], p[(i + 1) % p.size()]);\n  }\n  return A * 0.5;\n\
    }\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\nReal\
    \ convex_diameter(const Polygon &p) {\n  int N = (int) p.size();\n  int is = 0,\
    \ js = 0;\n  for(int i = 1; i < N; i++) {\n    if(p[i].Y > p[is].Y) is = i;\n\
    \    if(p[i].Y < p[js].Y) js = i;\n  }\n  Real maxdis = norm(p[is] - p[js]);\n\
    \n  int maxi, maxj, i, j;\n  i = maxi = is;\n  j = maxj = js;\n  do {\n    if(cross(p[(i\
    \ + 1) % N] - p[i], p[(j + 1) % N] - p[j]) >= 0) {\n      j = (j + 1) % N;\n \
    \   } else {\n      i = (i + 1) % N;\n    }\n    if(norm(p[i] - p[j]) > maxdis)\
    \ {\n      maxdis = norm(p[i] - p[j]);\n      maxi = i;\n      maxj = j;\n   \
    \ }\n  } while(i != is || j != js);\n  return sqrt(maxdis);\n}\n\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\n\
    Real closest_pair(Points ps) {\n  if(ps.size() <= 1) throw (0);\n  sort(begin(ps),\
    \ end(ps));\n\n  auto compare_y = [&](const Point &a, const Point &b) {\n    return\
    \ imag(a) < imag(b);\n  };\n  vector< Point > beet(ps.size());\n  const Real INF\
    \ = 1e18;\n\n  function< Real(int, int) > rec = [&](int left, int right) {\n \
    \   if(right - left <= 1) return INF;\n    int mid = (left + right) >> 1;\n  \
    \  auto x = real(ps[mid]);\n    auto ret = min(rec(left, mid), rec(mid, right));\n\
    \    inplace_merge(begin(ps) + left, begin(ps) + mid, begin(ps) + right, compare_y);\n\
    \    int ptr = 0;\n    for(int i = left; i < right; i++) {\n      if(abs(real(ps[i])\
    \ - x) >= ret) continue;\n      for(int j = 0; j < ptr; j++) {\n        auto luz\
    \ = ps[i] - beet[ptr - j - 1];\n        if(imag(luz) >= ret) break;\n        ret\
    \ = min(ret, abs(luz));\n      }\n      beet[ptr++] = ps[i];\n    }\n    return\
    \ ret;\n  };\n  return rec(0, (int) ps.size());\n}\n#line 4 \"test/aoj/CGL_1_B.test.cpp\"\
    \n\n#line 6 \"test/aoj/CGL_1_B.test.cpp\"\nusing namespace std;\nint main() {\n\
    \  Line l; cin >> l;\n  int q; cin >> q;\n  for (int i = 0; i < q; ++i) {\n  \
    \  Point p; cin >> p;\n    Point x = reflection(l, p);\n    cout << x << endl;\n\
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\
    \n#define ERROR \"0.00000001\"\n#include \"../../geometry/template.hpp\"\n\n#include\
    \ <iostream>\nusing namespace std;\nint main() {\n  Line l; cin >> l;\n  int q;\
    \ cin >> q;\n  for (int i = 0; i < q; ++i) {\n    Point p; cin >> p;\n    Point\
    \ x = reflection(l, p);\n    cout << x << endl;\n  }\n}"
  dependsOn:
  - geometry/template.hpp
  isVerificationFile: true
  path: test/aoj/CGL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-03-04 21:04:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_1_B.test.cpp
- /verify/test/aoj/CGL_1_B.test.cpp.html
title: test/aoj/CGL_1_B.test.cpp
---
