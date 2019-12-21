#include <iostream>
using namespace std;
typedef long long ll;

template<int mod>
struct ModInt {
  int val;
  ModInt inv() const{
    int tmp,a=val,b=mod,x=1,y=0;
    while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
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
  static int get_mod() { return mod; }
};

using modint = ModInt<1000000007>;