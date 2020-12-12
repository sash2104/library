// @brief 最長増加部分列 (LIS)

#include <vector>
#include <algorithm>
template< typename T >
std::vector<T> longest_increasing_subsequence(const std::vector< T > &a, bool strict) {
  std::vector< T > lis;
  for(auto &p : a) {
    typename std::vector< T >::iterator it;
    if(strict) it = std::lower_bound(lis.begin(), lis.end(), p);
    else it = std::upper_bound(std::begin(lis), std::end(lis), p);
    if(lis.end() == it) lis.emplace_back(p);
    else *it = p;
  }
  return lis;
}