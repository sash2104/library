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


# :heavy_check_mark: test/aoj/ALDS_1_14_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS_1_14_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 21:34:36+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/string/rolling-hash.hpp.html">ローリングハッシュ</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "../../string/rolling-hash.hpp"
#include <iostream>
using namespace std; 

using ull = unsigned long long;
int main() {
  string T, P;

  cin >> T;
  cin >> P;
  RollingHash rh(T), rh2(P);
  for(int i = 0; i + P.size() <= T.size(); i++) {
    ull h1 = rh.get(i, i+ P.size());
    ull h2 = rh2.get(0, P.size());
    // cerr << h1 << " " << h2 << " " << i + P.size() << endl;
    if(rh.get(i, i + P.size()) == rh2.get(0, P.size())) {
      cout << i << endl;
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS_1_14_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#line 1 "string/rolling-hash.hpp"
// @title ローリングハッシュ
#include <vector>
#include <string>
#include <iostream>

using ull = unsigned long long;
struct RollingHash {
  static const ull MASK30 = (1UL << 30) - 1;
  static const ull MASK31 = (1UL << 31) - 1;
  static const ull MOD = (1UL << 61) - 1;
  static const ull OFFSET = MOD * ((1UL << 3) - 1);
  static const unsigned int BASE = 10007;
  std::vector<ull> pows, hashed;
  RollingHash(const std::string &s) {
    int sz = (int) s.size();
    pows.resize(sz+1, 0);
    hashed.resize(sz+1, 0);
    pows[0] = 1;
    for (int i = 0; i < sz; i++) {
      pows[i+1] = CalcMod(Mul(pows[i], BASE));
      hashed[i+1] = CalcMod(Mul(hashed[i], BASE) + s[i]);
      // std::cerr << s[i] << " " << i << " " << hashed[i+1] << std::endl;
    }
  }

  // [l, r) の区間のhashを求める
  ull get(int l, int r) {
    return CalcMod(hashed[r] + OFFSET - Mul(hashed[l], pows[r-l]));
  }

  static ull Mul(ull l, ull r) { 
    ull lu = l >> 31;
    ull ld = l & MASK31;
    ull ru = r >> 31;
    ull rd = r & MASK31;
    ull c = ld * ru + lu * rd;
    return ((lu * ru) << 1) + ld * rd + ((c & MASK30) << 31) + (c >> 30);
  }

  static ull Mul(ull l, unsigned int r) { 
    ull lu = l >> 31;
    ull rd = r & MASK31;
    ull c = lu * rd;
    return (l & MASK31) * rd + ((c & MASK30) << 31) + (c >> 30);
  }

  static ull CalcMod(ull x) { 
    x = (x & MOD) + (x >> 61);
    if (x >= MOD) x -= MOD;
    return x;
  }

};
#line 5 "test/aoj/ALDS_1_14_B.test.cpp"
using namespace std; 

using ull = unsigned long long;
int main() {
  string T, P;

  cin >> T;
  cin >> P;
  RollingHash rh(T), rh2(P);
  for(int i = 0; i + P.size() <= T.size(); i++) {
    ull h1 = rh.get(i, i+ P.size());
    ull h2 = rh2.get(0, P.size());
    // cerr << h1 << " " << h2 << " " << i + P.size() << endl;
    if(rh.get(i, i + P.size()) == rh2.get(0, P.size())) {
      cout << i << endl;
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

