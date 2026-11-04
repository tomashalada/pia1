// Exercise 10: Vibrating string (1D wave equation) with energy monitoring
// Tasks:
//   a) Explain the role of the Params struct and of each function in the program.
//   b) Write pseudocode for initialize(), step() and energy().
//   c) The energy should be nearly constant. Name two reasons why it fluctuates slightly.
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using Vec = std::vector<double>;

struct Params {
    int    N;
    double L, c, cfl;
    int    steps;
    double dx() const { return L / (N - 1); }
    double dt() const { return cfl * dx() / c; }
};

void initialize(const Params& p, Vec& uOld, Vec& u) {
    const double dx = p.dx(), r2 = p.cfl * p.cfl;
    uOld.assign(p.N, 0.0);
    u.assign(p.N, 0.0);
    for (int i = 0; i < p.N; i++) {
        double x = i * dx;
        uOld[i] = std::exp(-300.0 * (x - 0.5) * (x - 0.5));
    }
    uOld[0] = uOld[p.N - 1] = 0.0;
    for (int i = 1; i < p.N - 1; i++)
        u[i] = uOld[i] + 0.5 * r2 * (uOld[i + 1] - 2.0 * uOld[i] + uOld[i - 1]);
}

void step(const Params& p, const Vec& uOld, const Vec& u, Vec& uNew) {
    const double r2 = p.cfl * p.cfl;
    for (int i = 1; i < p.N - 1; i++)
        uNew[i] = 2.0 * u[i] - uOld[i] + r2 * (u[i + 1] - 2.0 * u[i] + u[i - 1]);
    uNew[0] = uNew[p.N - 1] = 0.0;
}

double energy(const Params& p, const Vec& uOld, const Vec& u) {
    const double dx = p.dx(), dt = p.dt();
    double E = 0.0;
    for (int i = 1; i < p.N - 1; i++) {
        double ut = (u[i] - uOld[i]) / dt;
        double ux = (u[i + 1] - u[i - 1]) / (2.0 * dx);
        E += 0.5 * (ut * ut + p.c * p.c * ux * ux) * dx;
    }
    return E;
}

int main() {
    Params p = {201, 1.0, 1.0, 0.9, 1000};
    Vec uOld, u, uNew(p.N, 0.0);
    initialize(p, uOld, u);

    std::ofstream out("wave_snapshots.csv");
    out << "t,x,u\n";

    for (int n = 1; n <= p.steps; n++) {
        step(p, uOld, u, uNew);
        uOld.swap(u);
        u.swap(uNew);
        if (n % 100 == 0) {
            std::cout << "t = " << n * p.dt() << "  energy = " << energy(p, uOld, u) << "\n";
            for (int i = 0; i < p.N; i++)
                out << n * p.dt() << "," << i * p.dx() << "," << u[i] << "\n";
        }
    }
    return 0;
}
