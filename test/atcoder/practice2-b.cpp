// @title AtCoder Libraryのサンプル
// @see https://atcoder.jp/contests/practice2/tasks/practice2_b

#include <iostream>
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n, q; cin >> n >> q;
    fenwick_tree<ll> fw(n);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        fw.add(i, a);
    }
    for (int i = 0; i < q; ++i) {
        int t; cin >> t;
        if (t == 0) { 
            ll p, x; cin >> p >> x;
            fw.add(p, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }
}