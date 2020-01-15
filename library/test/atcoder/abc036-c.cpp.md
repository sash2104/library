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


# :warning: test/atcoder/abc036-c.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e8ba03245cc911ba95395348d53122a0">test/atcoder</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/atcoder/abc036-c.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-15 22:52:23+09:00




## Depends on

* :warning: <a href="../../util/compress.hpp.html">util/compress.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>

#include "../../util/compress.hpp"

using namespace std;

int main() {
  int n; cin >> n;

  // ld[i]に、i桁の要素数を格納する
  vector<int> la(n);
  for (int &a: la) cin >> a;
  Compress<int> comp(la);
  comp.build();
  for (int &b: comp.get(la)) cout << b << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/atcoder/abc036-c.cpp"
#include <iostream>

#line 2 "test/atcoder/../../util/compress.hpp"
#include <algorithm>
#include <vector>

template< typename T >
struct Compress {
  std::vector< T > xs;

  Compress() = default;
  Compress(const std::vector< T > &vs) { add(vs); }
  Compress(const std::initializer_list< std::vector< T > > &vs) { for(const T &p : vs) add(p); }

  void add(const std::vector< T > &vs) { std::copy(std::begin(vs), std::end(vs), std::back_inserter(xs)); }
  void add(const T &x) { xs.emplace_back(x); }

  void build() {
    std::sort(std::begin(xs), std::end(xs));
    xs.erase(unique(std::begin(xs), std::end(xs)), std::end(xs));
  }

  std::vector< int > get(const std::vector< T > &vs) const {
    std::vector< int > ret;
    std::transform(std::begin(vs), std::end(vs), std::back_inserter(ret), [&](const T &x) {
      return std::lower_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);
    });
    return ret;
  }

  int get(const T &x) const {
    return std::lower_bound(std::begin(xs), std::end(xs), x) - std::begin(xs);
  }

  const T &operator[](int k) const { return xs[k]; }
};
#line 4 "test/atcoder/abc036-c.cpp"

using namespace std;

int main() {
  int n; cin >> n;

  // ld[i]に、i桁の要素数を格納する
  vector<int> la(n);
  for (int &a: la) cin >> a;
  Compress<int> comp(la);
  comp.build();
  for (int &b: comp.get(la)) cout << b << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

