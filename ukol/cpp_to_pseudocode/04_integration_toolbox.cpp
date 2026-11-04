// Exercise 04: Numerical integration toolbox with an adaptive method
// Tasks:
//   a) Explain what std::function and lambda expressions are used for in this program.
//   b) Write pseudocode for simpsonRule() and adaptiveSimpson(). Which one is recursive and why?
//   c) Predict which test case needs the most function evaluations and explain why.
#include <iostream>
#include <iomanip>
#include <functional>
#include <vector>
#include <string>
#include <cmath>

using Func = std::function<double(double)>;

struct TestCase {
    std::string name;
    Func f;
    double a, b, exact;
};

double trapezoid(const Func& f, double a, double b, int n) {
    double h = (b - a) / n;
    double s = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) s += f(a + i * h);
    return s * h;
}

double simpsonRule(const Func& f, double a, double b) {
    double c = 0.5 * (a + b);
    return (b - a) / 6.0 * (f(a) + 4.0 * f(c) + f(b));
}

double adaptiveSimpson(const Func& f, double a, double b, double whole, double tol, int depth) {
    double c = 0.5 * (a + b);
    double left = simpsonRule(f, a, c);
    double right = simpsonRule(f, c, b);
    double diff = left + right - whole;
    if (depth <= 0 || std::fabs(diff) <= 15.0 * tol)
        return left + right + diff / 15.0;
    return adaptiveSimpson(f, a, c, left, 0.5 * tol, depth - 1)
         + adaptiveSimpson(f, c, b, right, 0.5 * tol, depth - 1);
}

int main() {
    const double PI = 3.14159265358979323846;
    std::vector<TestCase> cases = {
        {"sin(x) on [0,pi]",      [](double x) { return std::sin(x); },             0.0, PI,  2.0},
        {"exp(-x^2) on [-3,3]",   [](double x) { return std::exp(-x * x); },       -3.0, 3.0, std::sqrt(PI) * std::erf(3.0)},
        {"1/(1+x^2) on [0,1]",    [](double x) { return 1.0 / (1.0 + x * x); },     0.0, 1.0, PI / 4.0},
        {"sqrt(x) on [0,1]",      [](double x) { return std::sqrt(x); },            0.0, 1.0, 2.0 / 3.0}
    };

    std::cout << std::scientific << std::setprecision(2);
    std::cout << std::left << std::setw(24) << "integrand"
              << std::setw(12) << "trap(64)" << std::setw(12) << "adaptive" << "evals\n";

    for (const TestCase& tc : cases) {
        long count = 0;
        Func counted = [&](double x) { ++count; return tc.f(x); };

        double t = trapezoid(tc.f, tc.a, tc.b, 64);
        double whole = simpsonRule(counted, tc.a, tc.b);
        double s = adaptiveSimpson(counted, tc.a, tc.b, whole, 1e-8, 40);

        std::cout << std::setw(24) << tc.name
                  << std::setw(12) << std::fabs(t - tc.exact)
                  << std::setw(12) << std::fabs(s - tc.exact) << count << "\n";
    }
    return 0;
}
