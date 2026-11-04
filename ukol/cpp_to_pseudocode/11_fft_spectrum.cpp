// Exercise 11: Spectrum analysis with a recursive FFT and a window function
// Tasks:
//   a) Write pseudocode for fft(). Identify the base case and the recursive case.
//   b) Compare the number of operations of naiveDft() and fft() for N = 128.
//   c) Explain what the Hann window does to the spectrum of a signal whose frequency is not an integer.
#include <iostream>
#include <iomanip>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <utility>

using cx = std::complex<double>;
const double PI = 3.14159265358979323846;

bool isPowerOfTwo(size_t n) { return n > 0 && (n & (n - 1)) == 0; }

std::vector<cx> fft(const std::vector<cx>& x) {
    const size_t n = x.size();
    if (n == 1) return x;
    std::vector<cx> even(n / 2), odd(n / 2);
    for (size_t i = 0; i < n / 2; i++) {
        even[i] = x[2 * i];
        odd[i]  = x[2 * i + 1];
    }
    std::vector<cx> E = fft(even), O = fft(odd), out(n);
    for (size_t k = 0; k < n / 2; k++) {
        cx t = std::polar(1.0, -2.0 * PI * k / n) * O[k];
        out[k]         = E[k] + t;
        out[k + n / 2] = E[k] - t;
    }
    return out;
}

std::vector<cx> naiveDft(const std::vector<cx>& x) {
    const size_t n = x.size();
    std::vector<cx> X(n);
    for (size_t k = 0; k < n; k++)
        for (size_t j = 0; j < n; j++)
            X[k] += x[j] * std::polar(1.0, -2.0 * PI * k * j / n);
    return X;
}

std::vector<double> hannWindow(size_t n) {
    std::vector<double> w(n);
    for (size_t i = 0; i < n; i++) w[i] = 0.5 * (1.0 - std::cos(2.0 * PI * i / (n - 1)));
    return w;
}

std::vector<double> amplitudeSpectrum(const std::vector<double>& x, const std::vector<double>& w) {
    std::vector<cx> in(x.size());
    double wsum = 0.0;
    for (size_t i = 0; i < x.size(); i++) { in[i] = x[i] * w[i]; wsum += w[i]; }
    std::vector<cx> X = fft(in);
    std::vector<double> amp(x.size() / 2);
    for (size_t k = 0; k < amp.size(); k++) amp[k] = 2.0 * std::abs(X[k]) / wsum;
    return amp;
}

std::vector<std::pair<double, double>> findPeaks(const std::vector<double>& amp, double fs, double threshold) {
    std::vector<std::pair<double, double>> peaks;
    const double df = fs / (2.0 * amp.size());
    for (size_t k = 1; k + 1 < amp.size(); k++)
        if (amp[k] > threshold && amp[k] > amp[k - 1] && amp[k] >= amp[k + 1])
            peaks.push_back({k * df, amp[k]});
    return peaks;
}

int main() {
    const size_t N = 128;
    const double fs = 128.0;
    if (!isPowerOfTwo(N)) { std::cerr << "N must be a power of two\n"; return 1; }

    std::vector<double> x(N);
    for (size_t i = 0; i < N; i++) {
        double t = i / fs;
        x[i] = 1.0 * std::sin(2 * PI * 10.5 * t) + 0.5 * std::sin(2 * PI * 25.3 * t);
    }

    std::vector<cx> xc(x.begin(), x.end());
    std::vector<cx> A = fft(xc), B = naiveDft(xc);
    double maxDiff = 0.0;
    for (size_t k = 0; k < N; k++) maxDiff = std::max(maxDiff, std::abs(A[k] - B[k]));
    std::cout << "max |FFT - DFT| = " << maxDiff << "\n\n";

    std::vector<double> rect(N, 1.0);
    for (int useHann = 0; useHann < 2; useHann++) {
        auto amp = amplitudeSpectrum(x, useHann ? hannWindow(N) : rect);
        std::cout << (useHann ? "Hann window" : "No window") << ":\n";
        for (auto& pk : findPeaks(amp, fs, 0.1))
            std::cout << "  f = " << std::setw(6) << pk.first << " Hz   amplitude = " << pk.second << "\n";
    }
    return 0;
}
