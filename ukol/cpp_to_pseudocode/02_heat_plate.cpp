// Exercise 02: 2D heat conduction in a plate until steady state
// Tasks:
//   a) Explain the Grid struct and why a 1D vector is used to store a 2D array.
//   b) Write pseudocode for stableDt(), applyBoundary(), stepHeat() and main().
//   c) Explain the two stopping conditions of the main loop.
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Grid {
    int nx, ny;
    std::vector<double> data;
    Grid(int nx_, int ny_) : nx(nx_), ny(ny_), data(nx_ * ny_, 0.0) {}
    double&       operator()(int i, int j)       { return data[i * ny + j]; }
    const double& operator()(int i, int j) const { return data[i * ny + j]; }
};

double stableDt(double dx, double alpha) {
    return 0.2 * dx * dx / alpha;               // below the limit dx^2 / (4 alpha)
}

void applyBoundary(Grid& T, double hot) {
    for (int j = 0; j < T.ny; j++) {
        T(0, j) = hot;                           // top edge heated
        T(T.nx - 1, j) = 0.0;                    // bottom edge cold
    }
    for (int i = 1; i < T.nx - 1; i++) {
        T(i, 0) = 0.0;
        T(i, T.ny - 1) = 0.0;
    }
}

double stepHeat(const Grid& T, Grid& Tn, double r) {
    double maxChange = 0.0;
    for (int i = 1; i < T.nx - 1; i++) {
        for (int j = 1; j < T.ny - 1; j++) {
            double lap = T(i+1, j) + T(i-1, j) + T(i, j+1) + T(i, j-1) - 4.0 * T(i, j);
            Tn(i, j) = T(i, j) + r * lap;
            maxChange = std::max(maxChange, std::fabs(Tn(i, j) - T(i, j)));
        }
    }
    return maxChange;
}

void writeCSV(const Grid& T, const std::string& name) {
    std::ofstream out(name);
    for (int i = 0; i < T.nx; i++) {
        for (int j = 0; j < T.ny; j++)
            out << T(i, j) << (j + 1 < T.ny ? "," : "\n");
    }
}

int main() {
    const int    N = 41;
    const double alpha = 1.0, hot = 100.0, tol = 1e-6;
    const long   maxSteps = 200000;

    const double dx = 1.0 / (N - 1);
    const double dt = stableDt(dx, alpha);
    const double r  = alpha * dt / (dx * dx);

    Grid T(N, N), Tn(N, N);
    applyBoundary(T, hot);
    applyBoundary(Tn, hot);

    long step = 0;
    double change = 1.0;
    while (change > tol && step < maxSteps) {
        change = stepHeat(T, Tn, r);
        std::swap(T.data, Tn.data);
        step++;
    }

    std::cout << "steps = " << step << ", time = " << step * dt
              << ", last change = " << change << "\n";
    std::cout << "centre temperature = " << T(N / 2, N / 2) << "\n";
    writeCSV(T, "plate_temperature.csv");
    return 0;
}
