// Exercise 05: Root-finding suite (bisection, Newton, secant) with a result struct
// Tasks:
//   a) Explain why each solver returns a Result struct instead of a single number.
//   b) Write pseudocode for bisection(), newton() and secant().
//   c) Which method needs a derivative? Which needs a bracketing interval? Fill in a comparison table.
#include <iostream>
#include <iomanip>
#include <functional>
#include <vector>
#include <string>
#include <cmath>

using Func = std::function<double(double)>;

struct Result {
    double root;
    int    iterations;
    bool   converged;
};

struct Problem {
    std::string name;
    Func f, df;
    double a, b;       // bracket, also used as starting guesses
};

Result bisection(const Func& f, double a, double b, double tol, int maxIter) {
    if (f(a) * f(b) > 0.0) return {NAN, 0, false};
    int it = 0;
    while ((b - a) > tol && it < maxIter) {
        double m = 0.5 * (a + b);
        if (f(a) * f(m) <= 0.0) b = m; else a = m;
        it++;
    }
    return {0.5 * (a + b), it, (b - a) <= tol};
}

Result newton(const Func& f, const Func& df, double x0, double tol, int maxIter) {
    double x = x0;
    for (int it = 1; it <= maxIter; it++) {
        double d = df(x);
        if (std::fabs(d) < 1e-14) return {x, it, false};
        double dx = f(x) / d;
        x -= dx;
        if (std::fabs(dx) < tol) return {x, it, true};
    }
    return {x, maxIter, false};
}

Result secant(const Func& f, double x0, double x1, double tol, int maxIter) {
    for (int it = 1; it <= maxIter; it++) {
        double f0 = f(x0), f1 = f(x1);
        if (f1 == f0) return {x1, it, false};
        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        x0 = x1;
        x1 = x2;
        if (std::fabs(x1 - x0) < tol) return {x1, it, true};
    }
    return {x1, maxIter, false};
}

void report(const std::string& method, const Result& r) {
    std::cout << "  " << std::left << std::setw(10) << method
              << " root = " << std::setprecision(10) << r.root
              << "  iterations = " << r.iterations
              << (r.converged ? "" : "  (NOT converged)") << "\n";
}

int main() {
    std::vector<Problem> problems = {
        {"cos(x) - x = 0",
         [](double x) { return std::cos(x) - x; },
         [](double x) { return -std::sin(x) - 1.0; }, 0.0, 1.0},
        {"x^3 - 2x - 5 = 0",
         [](double x) { return x * x * x - 2.0 * x - 5.0; },
         [](double x) { return 3.0 * x * x - 2.0; }, 2.0, 3.0},
        {"exp(x) - 3x = 0",
         [](double x) { return std::exp(x) - 3.0 * x; },
         [](double x) { return std::exp(x) - 3.0; }, 0.0, 1.0}
    };

    for (const Problem& p : problems) {
        std::cout << p.name << "\n";
        report("bisection", bisection(p.f, p.a, p.b, 1e-10, 200));
        report("newton",    newton(p.f, p.df, p.b, 1e-10, 50));
        report("secant",    secant(p.f, p.a, p.b, 1e-10, 50));
    }
    return 0;
}
