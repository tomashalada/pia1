// Exercise 09: Monte Carlo estimate of the volume of a 3D ball with a statistical error bar
// Tasks:
//   a) Explain what the class RunningStats stores and why it does not keep all the samples.
//   b) Write pseudocode for sample(), RunningStats::add() and the main loop.
//   c) How should the standard error change when N is multiplied by 100? Check with the output.
#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>

class RunningStats {
public:
    void add(double x) {
        n_++;
        double delta = x - mean_;
        mean_ += delta / n_;
        m2_ += delta * (x - mean_);
    }
    long   count() const { return n_; }
    double mean()  const { return mean_; }
    double standardError() const {
        return (n_ > 1) ? std::sqrt(m2_ / (n_ - 1) / n_) : 0.0;
    }
private:
    long   n_ = 0;
    double mean_ = 0.0, m2_ = 0.0;
};

// One sample: random point in the cube [-1,1]^3 (volume 8).
// The value is 8 if the point is inside the unit ball and 0 otherwise.
double sample(std::mt19937& gen, std::uniform_real_distribution<double>& dist) {
    double x = dist(gen), y = dist(gen), z = dist(gen);
    return (x * x + y * y + z * z <= 1.0) ? 8.0 : 0.0;
}

int main() {
    const double PI = 3.14159265358979323846;
    const double exact = 4.0 * PI / 3.0;

    std::mt19937 gen(2024);
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    RunningStats stats;

    std::cout << std::left << std::setw(10) << "N" << std::setw(12) << "estimate"
              << std::setw(12) << "std error" << "actual error\n";

    long next = 100;
    while (stats.count() < 1000000) {
        stats.add(sample(gen, dist));
        if (stats.count() == next) {
            std::cout << std::setw(10) << next << std::setw(12) << stats.mean()
                      << std::setw(12) << stats.standardError()
                      << std::fabs(stats.mean() - exact) << "\n";
            next *= 10;
        }
    }
    std::cout << "exact volume = " << exact << "\n";
    return 0;
}
