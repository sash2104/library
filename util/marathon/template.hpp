#pragma once
#include <bits/stdc++.h>

// #define DEBUG
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)

// ------------------------ DEBUG PRINT --------------------------
template<class T>
void print_collection(std::ostream& out, T const& x);

template<class A>
std::ostream& operator<<(std::ostream& out, std::vector<A> const& x) { print_collection(out, x); return out; }
template<class A, size_t N>
std::ostream& operator<<(std::ostream& out, std::array<A, N> const& x) { print_collection(out, x); return out; }


template<class T, size_t... I>
void print_tuple(std::ostream& out, T const& a, std::index_sequence<I...>);
template<class... A>
std::ostream& operator<<(std::ostream& out, std::tuple<A...> const& x) {
  print_tuple(out, x, std::index_sequence_for<A...>{});
  return out;
}

template<class T, size_t... I>
void print_tuple(std::ostream& out, T const& a, std::index_sequence<I...>){
  using swallow = int[];
  out << '(';
  (void)swallow{0, (void(out << (I == 0? "" : ", ") << std::get<I>(a)), 0)...};
  out << ')';
}

template<class T>
void print_collection(std::ostream& out, T const& x) {
  int f = 0;
  out << '[';
  for(auto const& i: x) {
    out << (f++ ? "," : "");
    out << i;
  }
  out << "]";
}

static inline void d1_impl_seq() { std::cerr << "}"; }
template <class T, class... V>
void d1_impl_seq(T const& t, V const&... v) {
  std::cerr << t;
  if(sizeof...(v)) { std::cerr << ", "; }
  d1_impl_seq(v...);
}

static inline void d2_impl_seq() { }
template <class T, class... V>
void d2_impl_seq(T const& t, V const&... v) {
  std::cerr << " " << t;
  d2_impl_seq(v...);
}

#define D0(x) do { std::cerr << __FILE__ ":" << __LINE__ << ":" << __func__ <<  " " << x << std::endl; } while (0)
#define D1(x...) do {                                         \
    std::cerr << __LINE__ << "  {" << #x << "} = {";  \
    d1_impl_seq(x);                                           \
    std::cerr << std::endl << std::flush;                     \
  } while(0)
#define D2(x...) do {                     \
    std::cerr << "!";                     \
    d2_impl_seq(x);                       \
    std::cerr << std::endl << std::flush; \
  } while(0)
static inline void debug_impl_seq() {
  std::cerr << "}";
}

namespace logger {
inline void json_() {}
template<typename Key, typename Value, typename... Rest>
void json_(const Key& key, const Value& value, const Rest&... rest)
{
  std::cerr << "\"" << key << "\":\"" << value << "\"";
  if (sizeof...(Rest) > 0) std::cerr << ",";
  json_(rest...);
}

// example : json("key1", "foo", "key2", 3, "key", 4.0);
// {"key1":"foo","key2":"3","key":"4"}
template<typename... Args>
void json(const Args&... args)
{
#ifdef DEBUG
  std::cerr << "{"; json_(args...); std::cerr << "}" << std::endl;
#endif
}
} // namespace logger
// ------------------------ DEBUG PRINT --------------------------

struct Timer {
  const double LIMIT; // FIXME: 時間制限(s)
  Timer() : LIMIT(0.95) { reset(); }
  Timer(double limit) : LIMIT(limit) { reset(); }
	chrono::system_clock::time_point start;
	void reset() {
		start = chrono::system_clock::now();
	}
 
	double get() {
		auto end = chrono::system_clock::now();
		return chrono::duration_cast<chrono::milliseconds>(end - start).count()/1000.0;
	}
};

struct XorShift {
  unsigned int x, y, z, w;
  double nL[65536];
  XorShift() { init(); }
  void init()
  {
    x = 314159265; y = 358979323; z = 846264338; w = 327950288;
    double n = 1 / (double)(2 * 65536);
    for (int i = 0; i < 65536; i++) {
      nL[i] = log(((double)i / 65536) + n);
    }
  }
  inline unsigned int next() { unsigned int t=x^x<<11; x=y; y=z; z=w; return w=w^w>>19^t^t>>8; }
  inline double nextLog() { return nL[next()&0xFFFF]; }
  inline int nextInt(int m) { return (int)(next()%m); } // [0, m)
  int nextInt(int min, int max) { return min+nextInt(max-min+1); } // [min, max]
  inline double nextDouble() { return (double)next()/((long long)1<<32); } // [0, 1]
};
XorShift rng;

template <typename T>
inline void rough_shuffle(vector<T>& lv) {
    int n = lv.size();
    for (int i = n; i > 0; --i) {
        int id = rng.nextInt(i);
        swap(lv[id], lv[i-1]);
    }
}

std::size_t calc_hash(std::vector<int> const& vec) {
  std::size_t seed = vec.size();
  for(auto& i : vec) {
    seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  return seed;
}

#if 0
int main() { 
  // `#define DEGUB` が必要
  json("key1", "foo", "key2", 1, "key3", 3.14);

  Timer timer(0.45);
  while (true) {
    double t = timer.get(); // elapsed seconds
    if (timer.LIMIT < t) break;
    double diff = 1; // SAのdiff. 仮で1としているが実際は計算する
    double startTemp = 30;
    double endTemp = 10;
    double T = startTemp + (endTemp-startTemp)*(t/timer.LIMIT);
    if (diff >= T * rnd.nextLog()) {
      // FIXME: 更新
    }
  }
}
#endif
