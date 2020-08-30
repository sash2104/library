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


# :warning: datastructure/median-set2.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/median-set2.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:34:24+09:00


* see: <a href=": https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4">: https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;
// @see : https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4
// 集合の中央値の取得, 集合への要素の追加, 削除がO(logQ)程度で行えるデータ構造
struct MedianSet2 {
  vector<int> data;
  int m; // 中央値
  int n; // 要素数
  int loss; // (中央値と各要素との差分の絶対値)の和
  MedianSet2() : m(0), n(0), loss(0), data(26, 0) {}

  int add(int x)  {
    ++n; ++data[x];
    int nm = (n+1)/2;
    int c = 0;
    for (int i = 0; i < 26; ++i) {
      if (data[i] == 0) continue;
      c += data[i];
      if (c >= nm) { m = i; break; }
    }
    int nloss = 0;
    for (int i = 0; i < 26; ++i) {
      nloss += data[i]*abs(i-m);
    }
    int dloss = nloss-loss;
    loss = nloss;
    return dloss;
  }

  int remove(int x) {
    --n; --data[x];
    if (n == 0) { m = loss = 0; return 0; }
    int nm = (n+1)/2;
    int c = 0;
    for (int i = 0; i < 26; ++i) {
      if (data[i] == 0) continue;
      c += data[i];
      if (c >= nm) { m = i; break; }
    }
    int nloss = 0;
    for (int i = 0; i < 26; ++i) {
      nloss += data[i]*abs(i-m);
    }
    int dloss = nloss-loss;
    loss = nloss;
    return -dloss;
  }

  int get() { return m; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "datastructure/median-set2.hpp"

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;
// @see : https://wiki.kimiyuki.net/%E4%B8%AD%E5%A4%AE%E5%80%A4
// 集合の中央値の取得, 集合への要素の追加, 削除がO(logQ)程度で行えるデータ構造
struct MedianSet2 {
  vector<int> data;
  int m; // 中央値
  int n; // 要素数
  int loss; // (中央値と各要素との差分の絶対値)の和
  MedianSet2() : m(0), n(0), loss(0), data(26, 0) {}

  int add(int x)  {
    ++n; ++data[x];
    int nm = (n+1)/2;
    int c = 0;
    for (int i = 0; i < 26; ++i) {
      if (data[i] == 0) continue;
      c += data[i];
      if (c >= nm) { m = i; break; }
    }
    int nloss = 0;
    for (int i = 0; i < 26; ++i) {
      nloss += data[i]*abs(i-m);
    }
    int dloss = nloss-loss;
    loss = nloss;
    return dloss;
  }

  int remove(int x) {
    --n; --data[x];
    if (n == 0) { m = loss = 0; return 0; }
    int nm = (n+1)/2;
    int c = 0;
    for (int i = 0; i < 26; ++i) {
      if (data[i] == 0) continue;
      c += data[i];
      if (c >= nm) { m = i; break; }
    }
    int nloss = 0;
    for (int i = 0; i < 26; ++i) {
      nloss += data[i]*abs(i-m);
    }
    int dloss = nloss-loss;
    loss = nloss;
    return -dloss;
  }

  int get() { return m; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

