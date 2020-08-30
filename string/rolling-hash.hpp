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