---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/DSL_2_B.bit.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_B.bit.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-15 21:59:48+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/binary-indexed-tree.cpp.html">datastructure/binary-indexed-tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../../datastructure/binary-indexed-tree.cpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  BinaryIndexedTree<int> st(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y; --x;
    if (c == 0) st.add(x, y);
    else cout << st.sum(x, y) << endl;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_B.bit.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#line 1 "test/aoj/../../datastructure/binary-indexed-tree.cpp"
// original: http://hos.ac/slides/20140319_bit.pdf
#include <cassert>
#include <vector>

template <class T>
struct BinaryIndexedTree {
  int n;
  std::vector<T> bit;
  BinaryIndexedTree(int n): n(n), bit(n+1) {}

  void build(const std::vector<T> &v) {
    for (int x = 1; x <= n; ++x) bit[x] = v[x-1];
    for (int x = 1; x < n; ++x) bit[x + (x & -x)] += bit[x];
  }

  void add(int a, T w) { // 0-indexed
    assert(0 <= a && a < n);
    for (int x = a+1; x <= n; x += x & -x) bit[x] += w; // 1-indexed
  }

  T sum(int a) { // [0, a)
    assert(0 <= a && a <= n);
    T ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x]; // 1-indexed
    return ret;
  }

  T sum(int l, int r) { return sum(r)-sum(l); } // 0-indexed, [l, r)
};
#line 4 "test/aoj/DSL_2_B.bit.test.cpp"

#include <iostream>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  BinaryIndexedTree<int> st(n);
  for (int i = 0; i < q; ++i) {
    int c, x, y; cin >> c >> x >> y; --x;
    if (c == 0) st.add(x, y);
    else cout << st.sum(x, y) << endl;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

