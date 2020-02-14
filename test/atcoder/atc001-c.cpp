#include <vector>
#include "../../external/fft.cpp"

using namespace std;

int main() {
  int n; cin >> n;
  vector<double> a(n+1), b(n+1);
  for (int i = 0; i < n; ++i) { 
    cin >> a[i+1] >> b[i+1];
  }
  vector<double> c = convolve(a, b);
  for (int i = 1; i <= 2*n; ++i) {
    cout << (int)(c[i]+0.5) << endl;
  }
}
