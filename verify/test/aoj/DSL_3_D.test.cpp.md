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


# :heavy_check_mark: test/aoj/DSL_3_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_3_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-21 12:27:41+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/slide-min.cpp.html">datastructure/slide-min.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#define call_from_test
#include "../../datastructure/slide-min.cpp"
#undef call_from_test

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, l; cin >> n >> l;
  vector<int> la(n);
  for (int &a: la) cin >> a;

  vector<int> ret = slideMin(la, l);
  for (int i = 0; i < ret.size(); ++i) {
    if (i > 0) cout << " ";
    cout << la[ret[i]];
  }
  cout << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_3_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#define call_from_test
#line 1 "test/aoj/../../datastructure/slide-min.cpp"
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

template <class T>
std::vector<int> slideMin(const std::vector<T>& v, int k) {
  /* vの連続するk区間の最小値のindexのリストを返す */
  std::vector<int> ret;
  std::deque<int> dq;
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    while (dq.size() && v[dq.back()] >= v[i]) dq.pop_back();
    dq.push_back(i);
    if (i - k + 1 >= 0) {
      ret.push_back(dq.front());
      if (dq.front() <= i-k+1) dq.pop_front();
    }
  }
  return ret;
}

#ifndef call_from_test
#include <cassert>
int main() {
  vector<int> v = {1, 3, 5, 4, 2};

  int k = 3;
  vector<int> ret = slideMin(v, k);
  assert(ret.size() == 3);
  assert(ret[0] == 0);
  assert(ret[1] == 1);
  assert(ret[2] == 4);
}
#endif
#line 5 "test/aoj/DSL_3_D.test.cpp"
#undef call_from_test

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, l; cin >> n >> l;
  vector<int> la(n);
  for (int &a: la) cin >> a;

  vector<int> ret = slideMin(la, l);
  for (int i = 0; i < ret.size(); ++i) {
    if (i > 0) cout << " ";
    cout << la[ret[i]];
  }
  cout << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

