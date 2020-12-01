/**
 * @brief グリッドグラフ
 * 使用例: https://atcoder.jp/contests/abc020/submissions/18517344
 * 
 */
#include "template.cpp"
#include <cassert>
#include <string>
#include <vector>

namespace grid_graph {
using grid_t = std::vector<std::string>;
int H, W;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int xy2id(int x, int y) { return y*W+x; }
int id2x(int id) { return id%W; }
int id2y(int id) { return id/W; }
bool outside(int x, int y) {
    if (x < 0 || x >= W) return true;
    if (y < 0 || y >= H) return true;
    return false;
}

int cost(char c) {
    // FIXME: ここを実装する
    int inf = 1<<30;
    if (c == '#') return inf;
    return 1;
}

Graph<int> build(const grid_t& grid) {
    Graph<int> ret(H*W);
    assert(grid.size() == H);
    assert(grid[0].size() == W);
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            int id = xy2id(x,y);
            for (int d = 0; d < 4; ++d) {
                int nx = x+dx[d];
                int ny = y+dy[d];
                if (outside(nx,ny)) continue;
                int nid = xy2id(nx,ny);
                int c = cost(grid[ny][nx]);
                ret[id].emplace_back(id, nid, c);
            }
        }
    }
    return ret;
}

int find_pos(const grid_t& grid, char c) {
    // cが初めに見つかった位置を返す
    // 見つからなければ-1
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (grid[y][x] == c) {
                return xy2id(x,y);
            }
        }
    }
    return -1;
}
} // namespace grid_graph