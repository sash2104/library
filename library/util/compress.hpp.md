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


# :warning: 座標圧縮

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/compress.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:41:13+09:00




## Required by

* :warning: <a href="../test/atcoder/abc036-c.cpp.html">test/atcoder/abc036-c.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 座標圧縮
 */
#pragma once
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: util/compress.hpp: line 4: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

