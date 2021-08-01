// @brief 最長増加部分列 (LIS)

#include <vector>
#include <algorithm>
template< typename T >
int longest_increasing_subsequence(const std::vector<T> &a, bool strict, std::vector<int> &len) {
    std::vector<T> lis;
    typename std::vector<T>::iterator it;
    for (int i = 0; i < a.size(); ++i) {
        T p = a[i];
        if(strict) it = std::lower_bound(lis.begin(), lis.end(), p);
        else it = std::upper_bound(lis.begin(), lis.end(), p);

        // a[0],...,a[i]までの最長増加部分列の長さ
        int pos = distance(lis.begin(), it);
        len.push_back(pos+1);

        if(lis.end() == it) lis.emplace_back(p);
        else *it = p;
    }
    return lis.size();
}