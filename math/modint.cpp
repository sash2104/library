// @title mod int
#include <iostream>
using ll = long long;

#ifdef MUTABLE
int mod;
#else
template<int mod>
#endif
struct ModInt {
  int val;
  ModInt inv() const{
    int tmp,a=val,b=mod,x=1,y=0;
    while(b)tmp=a/b,a-=tmp*b,std::swap(a,b),x-=tmp*y,std::swap(x,y);
    return ModInt(x);
  }
  ModInt():val(0){}
  ModInt(ll x){if((val=x%mod)<0)val+=mod;}
  ModInt pow(ll t){ModInt res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}
  ModInt& operator+=(const ModInt& x){if((val+=x.val)>=mod)val-=mod;return *this;}
  ModInt& operator-=(const ModInt& x){if((val+=mod-x.val)>=mod)val-=mod; return *this;}
  ModInt& operator*=(const ModInt& x){val=(ll)val*x.val%mod; return *this;}
  ModInt& operator/=(const ModInt& x){return *this*=x.inv();}
  bool operator==(const ModInt& x) const{return val==x.val;}
  bool operator!=(const ModInt& x) const{return val!=x.val;}
  bool operator<(const ModInt& x) const{return val<x.val;}
  bool operator<=(const ModInt& x) const{return val<=x.val;}
  bool operator>(const ModInt& x) const{return val>x.val;}
  bool operator>=(const ModInt& x) const{return val>=x.val;}
  ModInt operator+(const ModInt& x) const{return ModInt(*this)+=x;}
  ModInt operator-(const ModInt& x) const{return ModInt(*this)-=x;}
  ModInt operator*(const ModInt& x) const{return ModInt(*this)*=x;}
  ModInt operator/(const ModInt& x) const{return ModInt(*this)/=x;}
  friend std::ostream& operator<<(std::ostream& os, const ModInt& mi) { os << mi.val; return os; }
  static int get_mod() { return mod; }
};

constexpr int MOD10 = 1000000007;
constexpr int MOD99 =  998244353;
#ifndef MUTABLE
using modint = ModInt<MOD10>;
using modint99 = ModInt<MOD99>;
#endif
