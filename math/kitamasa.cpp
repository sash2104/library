/**
 * @brief kitamasa法
 * 使用例: https://atcoder.jp/contests/tdpc/submissions/18910066
 * link: https://outline.hatenadiary.jp/entry/2020/07/02/205628
 * link: https://yosupo.hatenablog.com/entry/2015/03/27/025132
 */
#include <cassert>
#include <vector>

template<typename T>
struct Kitamasa{
    std::vector<T> a;    // 初期値ベクトル
    std::vector<T> d;    // 係数ベクトル
    int k;
    
    Kitamasa(std::vector<T>& a, std::vector<T>& d) : a(a), d(d), k((int)a.size()) {}
    
    // a_n の係数ベクトルを求める
    std::vector<T> dfs(int64_t n){
        assert(n >= k);
        if(n == k)  return d;
        
        std::vector<T> res(k);
        if(n & 1 || n < k * 2){
            std::vector<T> x = dfs(n-1);
            for(int i = 0; i < k; ++i)  res[i] = d[i] * x[k - 1];
            for(int i = 0; i + 1 < k; ++i)  res[i + 1] += x[i];
        }
        else{
            std::vector<std::vector<T>> x(k, std::vector<T>(k));
            x[0] = dfs(n/2);
            for(int i = 0; i + 1 < k; ++i){
                for(int j = 0; j < k; ++j)  x[i + 1][j] = d[j] * x[i][k - 1];
                for(int j = 0; j + 1 < k; ++j)  x[i + 1][j + 1] += x[i][j];
            }
            for(int i = 0; i < k; ++i){
                for(int j = 0; j < k; ++j){
                    res[j] += x[0][i] * x[i][j];
                }
            }
        }

        return res;
    }

    // a_n を求める
    T calc(int64_t n){
        std::vector<T> x = dfs(n);
        T res = 0;
        for(int i = 0; i < k; ++i)  res += x[i] * a[i];
        return res;
    }
};