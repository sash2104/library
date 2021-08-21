/**
 * @title ハンガリアン法
 * @brief 二部グラフの最小重み最大マッチングを返す
 * 行数N, 列数Mとすると、N <= Mを満たす必要がある
 * 計算量 $O(N^2M)$
 * 元：https://ei1333.github.io/luzhiled/snippets/graph/hungarian.html
 */
#include <cassert>
#include <vector>
#include <limits>

template< typename T >
struct Hungarian {
  const T INF;
  const int N, M;
  std::vector<std::vector<T>> A; // 1-indexed
  std::vector<int> P, way, match; // match[i]: = 行iの割当先の列番号. 0-indexed
  std::vector< T > U, V, minV;
  std::vector<bool> used;
  Hungarian(const std::vector<std::vector<T>> &A_):
    INF(std::numeric_limits<T>::max()), N(A_.size()+1), M(A_[0].size()+1), A(N, std::vector<T>(M)), P(M), way(M), match(N-1),
    U(N, 0), V(M, 0), minV(M), used(M) {
      for(int i = 0; i < N-1; ++i) {
        for (int j = 0; j < M-1; ++j) {
          A[i+1][j+1] = A_[i][j];
        }
      }
  }
  int get(int i) const {
    // 行iの割当先の列を返す
    return match[i];
  }
  T solve() {
    for(int i = 1; i < N; i++) {
      P[0] = i;
      minV.assign(M, INF);
      used.assign(M, false);
      int j0 = 0;
      while(P[j0] != 0) {
        int i0 = P[j0], j1 = 0;
        used[j0] = true;
        T delta = INF;
        for(int j = 1; j < M; j++) {
          if(used[j]) continue;
          T curr = A[i0][j] - U[i0] - V[j];
          if(curr < minV[j]) minV[j] = curr, way[j] = j0;
          if(minV[j] < delta) delta = minV[j], j1 = j;
        }
        for(int j = 0; j < M; j++) {
          if(used[j]) U[P[j]] += delta, V[j] -= delta;
          else minV[j] -= delta;
        }
        j0 = j1;
      }
      do {
        P[j0] = P[way[j0]];
        j0 = way[j0];
      } while(j0 != 0);
    }
    for(int j = 1; j < M; j++) {
      if (P[j] == 0) continue;
      match[P[j]-1] = j-1;
    }
    return -V[0];
  }
};