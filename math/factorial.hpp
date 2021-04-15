// @title 階乗、nPr、nCr
#include <vector>
#include "modint.hpp"

template <int mod>
struct Factorial {
  using mint = ModInt<mod>;
  std::vector<mint> Fact, Finv;
public:
  Factorial(int _n): Fact(_n+1), Finv(_n+1) {
      Fact[0]=mint(1); for (int i = 0; i < _n; ++i) Fact[i+1]=Fact[i]*(i+1);
      Finv[_n]=mint(1)/Fact[_n]; for (int i = _n; i > 0; --i) Finv[i-1]=Finv[i]*i;
  }
  mint fact(int n,bool inv=0) { if (inv) return Finv[n]; else return Fact[n]; }
  mint nPr(int n,int r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[n-r]; }
  mint nCr(int n,int r){ if (n<0||n<r||r<0) return mint(0); else return Fact[n]*Finv[r]*Finv[n-r]; }
};

using factorial = Factorial<MOD10>;
using factorial99 = Factorial<MOD99>;
