// Exercise 08: 2D Poisson equation  -laplace(u) = f  solved with SOR
// Tasks:
//   a) Write the update formula used inside sorSweep() and say what omega = 1 means.
//   b) Write pseudocode for solve() and explain its two return conditions.
//   c) Run the program: which omega converges fastest? Explain why too large an omega is a problem.
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

struct Grid2D {
    int n;
    double h;
    std::vector<double> v;
    explicit Grid2D(int n_) : n(n_), h(1.0 / (n_ - 1)), v(n_ * n_, 0.0) {}
    double&       at(int i, int j)       { return v[i * n + j]; }
    const double& at(int i, int j) const { return v[i * n + j]; }
};

const double PI = 3.14159265358979323846;

double source(double x, double y) {
    return 2.0 * PI * PI * std::sin(PI * x) * std::sin(PI * y);
}

double exactSolution(double x, double y) {
    return std::sin(PI * x) * std::sin(PI * y);
}

double optimalOmega(int n) {
    return 2.0 / (1.0 + std::sin(PI / (n - 1)));
}

double sorSweep(Grid2D& u, const Grid2D& f, double omega) {
    double maxUpdate = 0.0;
    const double h2 = u.h * u.h;
    for (int i = 1; i < u.n - 1; i++) {
        for (int j = 1; j < u.n - 1; j++) {
            double gs = 0.25 * (u.at(i + 1, j) + u.at(i - 1, j) + u.at(i, j + 1) + u.at(i, j - 1)
                                + h2 * f.at(i, j));
            double newVal = (1.0 - omega) * u.at(i, j) + omega * gs;
            maxUpdate = std::max(maxUpdate, std::fabs(newVal - u.at(i, j)));
            u.at(i, j) = newVal;
        }
    }
    return maxUpdate;
}

int solve(Grid2D& u, const Grid2D& f, double omega, double tol, int maxIter) {
    for (int it = 1; it <= maxIter; it++)
        if (sorSweep(u, f, omega) < tol) return it;
    return maxIter;
}

double maxError(const Grid2D& u) {
    double err = 0.0;
    for (int i = 0; i < u.n; i++)
        for (int j = 0; j < u.n; j++)
            err = std::max(err, std::fabs(u.at(i, j) - exactSolution(i * u.h, j * u.h)));
    return err;
}

int main() {
    const int n = 33;
    Grid2D f(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f.at(i, j) = source(i * f.h, j * f.h);

    std::cout << std::left << std::setw(10) << "omega" << std::setw(14) << "iterations"
              << "max error\n";
    for (double omega : {1.0, 1.5, optimalOmega(n)}) {
        Grid2D u(n);
        int iters = solve(u, f, omega, 1e-8, 20000);
        std::cout << std::setw(10) << omega << std::setw(14) << iters << maxError(u) << "\n";
    }
    return 0;
}
