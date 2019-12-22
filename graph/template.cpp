#include <vector>

using namespace std;

template< typename T >
struct Edge {
  int from, to;
  T cost;
  Edge() {}
  Edge(int f, int t) : cost((int)1), from(f), to(t) {}
  Edge(int f, int t, T c) : from(f), to(t), cost(c) {}
  friend bool operator < (const Edge& lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };
  friend bool operator > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };
  friend bool operator <= (const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); };
  friend bool operator >= (const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };
};

template< typename T >
using Edges = vector< Edge< T > >;
template< typename T >
using Graph = vector< Edges< T > >;
