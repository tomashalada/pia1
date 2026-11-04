// Exercise 01: 1D linear advection - comparing two numerical schemes
// Tasks:
//   a) Draw a call graph (which function calls which).
//   b) Write pseudocode for main(), run(), stepUpwind() and stepLaxWendroff().
//   c) Explain what a function pointer is used for here and what the error tells you.
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using Field = std::vector<double>;

struct Params {
    int    N;      // number of grid points
    double L;      // domain length
    double c;      // advection speed
    double cfl;    // Courant number
    double tEnd;   // final time
};

double initialCondition(double x) {
    return std::exp(-200.0 * (x - 0.3) * (x - 0.3));
}

double exactSolution(double x, double t, const Params& p) {
    double xs = x - p.c * t;
    xs -= p.L * std::floor(xs / p.L);          // periodic wrap
    return initialCondition(xs);
}

void stepUpwind(const Field& u, Field& un, double nu) {
    const int N = static_cast<int>(u.size());
    for (int i = 0; i < N; i++) {
        int im = (i + N - 1) % N;
        un[i] = u[i] - nu * (u[i] - u[im]);
    }
}

void stepLaxWendroff(const Field& u, Field& un, double nu) {
    const int N = static_cast<int>(u.size());
    for (int i = 0; i < N; i++) {
        int im = (i + N - 1) % N, ip = (i + 1) % N;
        un[i] = u[i] - 0.5 * nu * (u[ip] - u[im])
                     + 0.5 * nu * nu * (u[ip] - 2.0 * u[i] + u[im]);
    }
}

Field run(const Params& p, void (*step)(const Field&, Field&, double), double& tFinal) {
    const double dx = p.L / p.N;
    const double dt = p.cfl * dx / p.c;
    const int nSteps = static_cast<int>(std::round(p.tEnd / dt));

    Field u(p.N), un(p.N);
    for (int i = 0; i < p.N; i++) u[i] = initialCondition(i * dx);

    for (int n = 0; n < nSteps; n++) {
        step(u, un, p.c * dt / dx);
        u.swap(un);
    }
    tFinal = nSteps * dt;
    return u;
}

double l2Error(const Field& u, double t, const Params& p) {
    const double dx = p.L / p.N;
    double sum = 0.0;
    for (int i = 0; i < p.N; i++) {
        double e = u[i] - exactSolution(i * dx, t, p);
        sum += e * e;
    }
    return std::sqrt(sum * dx);
}

int main() {
    Params p = {200, 1.0, 1.0, 0.8, 0.5};
    double t1 = 0.0, t2 = 0.0;

    Field uUp = run(p, stepUpwind, t1);
    Field uLW = run(p, stepLaxWendroff, t2);

    std::cout << "L2 error (upwind)       : " << l2Error(uUp, t1, p) << "\n";
    std::cout << "L2 error (Lax-Wendroff) : " << l2Error(uLW, t2, p) << "\n";

    std::ofstream out("advection_results.csv");
    out << "x,exact,upwind,lax_wendroff\n";
    for (int i = 0; i < p.N; i++) {
        double x = i * p.L / p.N;
        out << x << "," << exactSolution(x, t1, p) << "," << uUp[i] << "," << uLW[i] << "\n";
    }
    return 0;
}
