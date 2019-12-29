#include <complex>
#include <iostream>
#include <vector>

using namespace std;

// Cooley–Tukey FFT algorithm O(N log N)
vector<complex<double>> fft(vector<complex<double>> a, bool inverse = false) {
    int n = a.size();
    int h = 0; // h = log_2(n)
    for (int i = 0; 1 << i < n; i++) h++;
    // バタフライ演算用の配置入れ替え
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (int k = 0; k < h; k++) j |= (i >> k & 1) << (h - 1 - k);
        if (i < j) swap(a[i], a[j]);
    }
    // バタフライ演算
    for (int b = 1; b < n; b *= 2) {
        // 第 log_2(b) + 1 段
        // ブロックサイズ = b * 2
        for (int j = 0; j < b; j++) {
            // ブロック内 j 個目
            // 重み w = (1 の原始 2b 乗根の j 乗)
            complex<double> w =
                polar(1.0, (2 * M_PI) / (2 * b) * j * (inverse ? 1 : -1));
            for (int k = 0; k < n; k += b * 2) {
                // k を先頭とするブロック
                complex<double> s = a[j + k];         // 前
                complex<double> t = a[j + k + b] * w; // 後
                a[j + k] = s + t;                     // 前の更新
                a[j + k + b] = s - t;                 // 後の更新
            }
        }
    }
    // 逆変換時にサイズで割る調整
    if (inverse)
        for (int i = 0; i < n; i++) a[i] /= n;
    return a;
}
// Cooley–Tukey FFT algorithm O(N log N)
vector<complex<double>> fft(vector<double> a, bool inverse = false) {
    vector<complex<double>> a_complex(a.size());
    for (int i = 0; i < a.size(); i++) a_complex[i] = complex<double>(a[i], 0);
    return fft(a_complex, inverse);
}

// FFT による畳み込み O(N log N)
vector<double> convolve(vector<double> a, vector<double> b) {
    int s = a.size() + b.size() - 1; // 畳み込み結果のサイズ
    int t = 1; // FFT に使う配列のサイズ（2 の累乗）
    while (t < s) t *= 2;
    a.resize(t); // FFT するためにリサイズ
    b.resize(t); // FFT するためにリサイズ
    vector<complex<double>> A = fft(a);
    vector<complex<double>> B = fft(b);
    for (int i = 0; i < t; i++) {
        A[i] *= B[i]; // 畳み込み結果の FFT 結果を得る
    }
    A = fft(A, true); // IFFT で畳み込み結果を得る
    a.resize(s);      // 畳み込み結果を入れるためにリサイズ
    for (int i = 0; i < s; i++) a[i] = A[i].real(); // 実部が答え
    return a;
}
