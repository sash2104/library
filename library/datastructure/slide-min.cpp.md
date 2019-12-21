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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: datastructure/slide-min.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/slide-min.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-21 12:27:41+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.test.cpp.html">test/aoj/DSL_3_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/slide-min.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

