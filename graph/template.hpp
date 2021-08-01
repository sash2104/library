#ifndef __GRAPH__TEMPLATE
#define __GRAPH__TEMPLATE

#include <iostream>
#include <vector>

template< typename T >
struct Edge {
  int from, to;
  T cost;
  Edge() {}
  Edge(int f, int t) : from(f), to(t), cost(1) {}
  Edge(int f, int t, T c) : from(f), to(t), cost(c) {}
  friend bool operator < (const Edge& lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };
  friend bool operator > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };
  friend bool operator <= (const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); };
  friend bool operator >= (const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };
};

template< typename T >
using Edges = std::vector< Edge< T > >;
template< typename T >
using Graph = std::vector< Edges< T > >;

template< typename T >
void debug(Graph<T> &g, int n = -1) {
    if (n == -1) n = g.size();
    for (int i = 0; i < n; ++i) {
        std::cerr << i  << "\t";
        for (auto &e: g[i]) {
            std::cerr << e.to << ",";
        }
        std::cerr << std::endl;
    }
}

#endif // __GRAPH_TEMPLATE