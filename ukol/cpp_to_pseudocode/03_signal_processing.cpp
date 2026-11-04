// Exercise 03: Signal filtering toolbox (FIR Gaussian filter and IIR exponential filter)
// Tasks:
//   a) Describe in one sentence what each function does (inputs -> output).
//   b) Write pseudocode for convolve() including the treatment of the signal edges.
//   c) Explain why the filtered signals lag or smear compared with the clean one.
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <random>

using Signal = std::vector<double>;

Signal makeSignal(int n, double fs, double noiseLevel, unsigned seed, Signal& clean) {
    const double PI = 3.14159265358979323846;
    std::mt19937 gen(seed);
    std::normal_distribution<double> noise(0.0, noiseLevel);
    Signal x(n);
    clean.assign(n, 0.0);
    for (int i = 0; i < n; i++) {
        double t = i / fs;
        clean[i] = std::sin(2 * PI * 2.0 * t) + 0.5 * std::sin(2 * PI * 5.0 * t);
        x[i] = clean[i] + noise(gen);
    }
    return x;
}

Signal gaussianKernel(int halfWidth, double sigma) {
    Signal k(2 * halfWidth + 1);
    double sum = 0.0;
    for (int i = -halfWidth; i <= halfWidth; i++) {
        k[i + halfWidth] = std::exp(-0.5 * i * i / (sigma * sigma));
        sum += k[i + halfWidth];
    }
    for (double& v : k) v /= sum;
    return k;
}

Signal convolve(const Signal& x, const Signal& kernel) {
    const int n = static_cast<int>(x.size());
    const int h = static_cast<int>(kernel.size()) / 2;
    Signal y(n, 0.0);
    for (int i = 0; i < n; i++) {
        for (int k = -h; k <= h; k++) {
            int idx = i + k;
            if (idx < 0) idx = 0;                // clamp at the edges
            if (idx > n - 1) idx = n - 1;
            y[i] += kernel[k + h] * x[idx];
        }
    }
    return y;
}

Signal exponentialSmoothing(const Signal& x, double alpha) {
    Signal y(x.size());
    y[0] = x[0];
    for (size_t i = 1; i < x.size(); i++)
        y[i] = alpha * x[i] + (1.0 - alpha) * y[i - 1];
    return y;
}

double rmsError(const Signal& a, const Signal& b) {
    double s = 0.0;
    for (size_t i = 0; i < a.size(); i++) s += (a[i] - b[i]) * (a[i] - b[i]);
    return std::sqrt(s / a.size());
}

int main() {
    const int n = 500;
    const double fs = 100.0;

    Signal clean;
    Signal noisy = makeSignal(n, fs, 0.4, 7, clean);

    Signal gauss = convolve(noisy, gaussianKernel(10, 3.0));
    Signal expo  = exponentialSmoothing(noisy, 0.15);

    std::cout << "RMS error noisy    : " << rmsError(noisy, clean) << "\n";
    std::cout << "RMS error gaussian : " << rmsError(gauss, clean) << "\n";
    std::cout << "RMS error exponent.: " << rmsError(expo, clean) << "\n";

    std::ofstream out("filtered_signals.csv");
    out << "t,clean,noisy,gaussian,exponential\n";
    for (int i = 0; i < n; i++)
        out << i / fs << "," << clean[i] << "," << noisy[i] << ","
            << gauss[i] << "," << expo[i] << "\n";
    return 0;
}
