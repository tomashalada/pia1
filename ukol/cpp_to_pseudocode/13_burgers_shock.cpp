// Exercise 13: Burgers' equation u_t + (u^2/2)_x = 0 - formation of a shock wave
// Tasks:
//   a) Explain how this equation differs from linear advection (exercise 01). Why is dt recomputed every step?
//   b) Write pseudocode for computeDt(), stepLaxFriedrichs(), stepUpwind() and run().
//   c) Use the printed diagnostics to decide which scheme smears the shock more, and which one
//      conserves the total mass. Why must mass be conserved for this equation?
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using Field = std::vector<double>;

struct Params {
    int    N;
    double L, cfl, tEnd;
    double dx() const { return L / N; }
};

const double PI = 3.14159265358979323846;

double flux(double u) { return 0.5 * u * u; }

double initialCondition(double x) {
    return 1.0 + 0.5 * std::sin(2.0 * PI * x);       // always positive, steepens into a shock
}

double computeDt(const Field& u, double dx, double cfl) {
    double umax = 0.0;
    for (double v : u) umax = std::max(umax, std::fabs(v));
    return cfl * dx / umax;
}

void stepLaxFriedrichs(const Field& u, Field& un, double dt, double dx) {
    const int N = static_cast<int>(u.size());
    for (int i = 0; i < N; i++) {
        int im = (i + N - 1) % N, ip = (i + 1) % N;
        un[i] = 0.5 * (u[ip] + u[im]) - dt / (2.0 * dx) * (flux(u[ip]) - flux(u[im]));
    }
}

void stepUpwind(const Field& u, Field& un, double dt, double dx) {   // valid only for u > 0
    const int N = static_cast<int>(u.size());
    for (int i = 0; i < N; i++) {
        int im = (i + N - 1) % N;
        un[i] = u[i] - dt / dx * (flux(u[i]) - flux(u[im]));
    }
}

double totalMass(const Field& u, double dx) {
    double s = 0.0;
    for (double v : u) s += v;
    return s * dx;
}

double totalVariation(const Field& u) {
    double tv = 0.0;
    const int N = static_cast<int>(u.size());
    for (int i = 0; i < N; i++) tv += std::fabs(u[(i + 1) % N] - u[i]);
    return tv;
}

Field run(const Params& p, void (*step)(const Field&, Field&, double, double)) {
    const double dx = p.dx();
    Field u(p.N), un(p.N);
    for (int i = 0; i < p.N; i++) u[i] = initialCondition(i * dx);

    double t = 0.0;
    while (t < p.tEnd) {
        double dt = std::min(computeDt(u, dx, p.cfl), p.tEnd - t);
        step(u, un, dt, dx);
        u.swap(un);
        t += dt;
    }
    return u;
}

int main() {
    Params p = {400, 1.0, 0.8, 0.6};     // shock forms near t = 1/pi = 0.32
    Field u0(p.N);
    for (int i = 0; i < p.N; i++) u0[i] = initialCondition(i * p.dx());
    const double mass0 = totalMass(u0, p.dx());

    Field uLF = run(p, stepLaxFriedrichs);
    Field uUp = run(p, stepUpwind);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "initial mass          : " << mass0 << "\n";
    std::cout << "Lax-Friedrichs  mass  : " << totalMass(uLF, p.dx()) << "  TV: " << totalVariation(uLF) << "\n";
    std::cout << "Upwind          mass  : " << totalMass(uUp, p.dx()) << "  TV: " << totalVariation(uUp) << "\n";

    std::ofstream out("burgers_results.csv");
    out << "x,lax_friedrichs,upwind\n";
    for (int i = 0; i < p.N; i++)
        out << i * p.dx() << "," << uLF[i] << "," << uUp[i] << "\n";
    return 0;
}
