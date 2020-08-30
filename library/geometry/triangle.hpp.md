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


# :warning: 三角形の五心の座標

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed7daeb157cd9b31e53896ad3c771a26">geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/geometry/triangle.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:41:37+09:00




## Depends on

* :warning: <a href="template.circle.hpp.html">円</a>
* :heavy_check_mark: <a href="template.hpp.html">geometry/template.hpp</a>


## Required by

* :warning: <a href="../test/aoj/notest.0010.cpp.html">test/aoj/notest.0010.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 三角形の五心の座標
 */
#pragma once
#include "template.circle.hpp"

// 外接円
Circle circumcircle(const Point &a, const Point &b, const Point &c) {
  Real a1,a2,b1,b2,c1,c2;
  a1=2*(b.X-a.X);
  b1=2*(b.Y-a.Y);
  c1=a.X*a.X-b.X*b.X+a.Y*a.Y-b.Y*b.Y;
  a2=2*(c.X-a.X);
  b2=2*(c.Y-a.Y);
  c2=a.X*a.X-c.X*c.X+a.Y*a.Y-c.Y*c.Y;
  Real px = (b1*c2-b2*c1)/(a1*b2-a2*b1);
  Real py = (c1*a2-c2*a1)/(a1*b2-a2*b1);
  Point circumcenter(px, py); // 外心
  Real r = distance(a, circumcenter);
  return Circle(circumcenter, r);
}

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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/triangle.hpp: line 4: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

