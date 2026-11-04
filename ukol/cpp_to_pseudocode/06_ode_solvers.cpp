// Exercise 06: Comparing ODE integrators on the nonlinear pendulum
// Tasks:
//   a) Write the pendulum equation theta'' = -sin(theta) as a first-order system.
//   b) Write pseudocode for euler(), symplecticEuler(), rk4() and integrate().
//   c) Explain what energy() measures and why it is a good test of a time integrator.
#include <iostream>
#include <iomanip>
#include <array>
#include <functional>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using State   = std::array<double, 2>;                                   // {theta, omega}
using RHS     = std::function<State(double, const State&)>;
using Stepper = std::function<State(const RHS&, double, const State&, double)>;

State pendulum(double /*t*/, const State& y) {
    return State{y[1], -std::sin(y[0])};
}

double energy(const State& y) {
    return 0.5 * y[1] * y[1] + (1.0 - std::cos(y[0]));
}

State euler(const RHS& f, double t, const State& y, double dt) {
    State d = f(t, y);
    return State{y[0] + dt * d[0], y[1] + dt * d[1]};
}

State symplecticEuler(const RHS& f, double t, const State& y, double dt) {
    State d = f(t, y);
    double omega = y[1] + dt * d[1];
    return State{y[0] + dt * omega, omega};
}

State rk4(const RHS& f, double t, const State& y, double dt) {
    State k1 = f(t, y);
    State y2{y[0] + 0.5 * dt * k1[0], y[1] + 0.5 * dt * k1[1]};
    State k2 = f(t + 0.5 * dt, y2);
    State y3{y[0] + 0.5 * dt * k2[0], y[1] + 0.5 * dt * k2[1]};
    State k3 = f(t + 0.5 * dt, y3);
    State y4{y[0] + dt * k3[0], y[1] + dt * k3[1]};
    State k4 = f(t + dt, y4);
    return State{y[0] + dt / 6.0 * (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]),
                 y[1] + dt / 6.0 * (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1])};
}

double integrate(const RHS& f, const Stepper& step, State y, double dt, double tEnd) {
    const double E0 = energy(y);
    double maxErr = 0.0;
    int nSteps = static_cast<int>(std::round(tEnd / dt));
    for (int n = 0; n < nSteps; n++) {
        y = step(f, n * dt, y, dt);
        maxErr = std::max(maxErr, std::fabs(energy(y) - E0));
    }
    return maxErr;
}

int main() {
    const State y0{2.0, 0.0};
    const double tEnd = 50.0;
    std::vector<double> dts = {0.1, 0.05, 0.01};
    std::vector<std::pair<std::string, Stepper>> methods = {
        {"Euler", euler}, {"Symplectic", symplecticEuler}, {"RK4", rk4}};

    std::cout << "max |E - E0| over t in [0," << tEnd << "]\n";
    std::cout << std::left << std::setw(12) << "method";
    for (double dt : dts) std::cout << std::setw(14) << ("dt=" + std::to_string(dt).substr(0, 5));
    std::cout << "\n" << std::scientific << std::setprecision(3);

    for (auto& m : methods) {
        std::cout << std::left << std::setw(12) << m.first;
        for (double dt : dts)
            std::cout << std::setw(14) << integrate(pendulum, m.second, y0, dt, tEnd);
        std::cout << "\n";
    }
    return 0;
}
