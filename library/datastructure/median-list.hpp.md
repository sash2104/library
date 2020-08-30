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


# :warning: 中央値

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/median-list.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:34:24+09:00


* see: <a href="https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4">https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 中央値
 * @see https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4
 * @brief 集合の中央値の取得, 集合への要素の追加, 削除がO(logQ)程度で行えるデータ構造
 */
#pragma once

#include <cassert>
#include <algorithm>
#include <iostream>
#include <map>

struct MedianSet {
  int l; // 中央値より小さい要素の個数
  int r; // 中央値より大きい要素の個数
  int m; // 中央値
  int n; // 要素数
  int loss; // (中央値と各要素との差分の絶対値)の和
  MedianSet() : l(0), r(0), m(0), n(0), loss(0) {}
  std::map<int, int> data; 

  void update() { // l, r, mの値を適切なものに更新する
    if (n == 0) { l = r = m = loss = 0; return; }
    int bm = m;
    if (l >= data[m]+r) {
      int nm = std::prev(data.find(m))->first;
      r += data[m];
      l -= data[nm];
      m = nm;
    }
    else if (r > data[m]+l) {
      auto it = std::next(data.find(m));
      int nm = std::next(data.find(m))->first;
      l += data[m];
      r -= data[nm];
      m = nm;
    }
    if (data[bm] == 0) data.erase(bm);
  }

  int add(int x)  {
    int bm = m, bl = l, br = r, bc = data[bm];
    ++data[x]; ++n;
    if (x < m) ++l;
    else if (x > m) ++r;
    update();
    if (n == 1) return 0;
    // cerr << "[!]" << bl << " " << br << " " << bm << " " << m << endl;
    int dloss = (br-bl)*(bm-m)+abs(m-bm)*bc+abs(x-m);
    loss += dloss;
    return dloss;
  }

  int remove(int x) {
    int bm = m, bl = l, br = r, bc = data[bm];
    if (x < bm) --bl;
    else if (x == bm) --bc;
    else --br;
    --data[x]; --n;
    if (data[x] == 0) data.erase(x);
    if (x < m) --l;
    else if (x > m) --r;
    update();
    // cerr << "[!]" << bl << " " << br << " " << bm << " " << m << " " << x << endl;
    int dloss = (br-bl)*(m-bm)-abs(m-bm)*bc+abs(x-bm);
    loss -= dloss;
    return dloss;
  }

  int get() { return m; }

  void show() {
    std::cerr << m << " " << n << " " << loss << std::endl;
    for (auto it: data) {
      std::cerr << it.first << " " << it.second << std::endl;
    }
  }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/median-list.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

