// Exercise 07: 1D heat equation with an implicit scheme and a tridiagonal solver
// Tasks:
//   a) Write the linear system solved at every time step (draw the matrix for N = 6).
//   b) Write pseudocode for solveTridiagonal() (Thomas algorithm), implicitStep() and explicitStep().
//   c) Explain why the explicit result is garbage while the implicit one is fine for the same dt.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using Vec = std::vector<double>;

Vec solveTridiagonal(const Vec& a, Vec b, const Vec& c, Vec d) {
    const int n = static_cast<int>(b.size());
    for (int i = 1; i < n; i++) {
        double w = a[i] / b[i - 1];
        b[i] -= w * c[i - 1];
        d[i] -= w * d[i - 1];
    }
    Vec x(n);
    x[n - 1] = d[n - 1] / b[n - 1];
    for (int i = n - 2; i >= 0; i--)
        x[i] = (d[i] - c[i] * x[i + 1]) / b[i];
    return x;
}

Vec implicitStep(const Vec& u, double r) {
    const int n = static_cast<int>(u.size());
    Vec a(n, -r), b(n, 1.0 + 2.0 * r), c(n, -r), d = u;
    b[0] = b[n - 1] = 1.0;                        // Dirichlet rows: u = 0
    a[0] = c[0] = a[n - 1] = c[n - 1] = 0.0;
    d[0] = d[n - 1] = 0.0;
    return solveTridiagonal(a, b, c, d);
}

Vec explicitStep(const Vec& u, double r) {
    Vec un(u.size(), 0.0);
    for (size_t i = 1; i + 1 < u.size(); i++)
        un[i] = u[i] + r * (u[i + 1] - 2.0 * u[i] + u[i - 1]);
    return un;
}

double maxError(const Vec& u, double t, double dx, double alpha) {
    const double PI = 3.14159265358979323846;
    double err = 0.0;
    for (size_t i = 0; i < u.size(); i++) {
        double exact = std::exp(-PI * PI * alpha * t) * std::sin(PI * i * dx);
        err = std::max(err, std::fabs(u[i] - exact));
    }
    return err;
}

int main() {
    const int N = 51;
    const double alpha = 1.0, dt = 0.01, tEnd = 0.1;
    const double PI = 3.14159265358979323846;
    const double dx = 1.0 / (N - 1);
    const double r = alpha * dt / (dx * dx);
    const int nSteps = static_cast<int>(std::round(tEnd / dt));

    Vec uI(N), uE(N);
    for (int i = 0; i < N; i++) uI[i] = uE[i] = std::sin(PI * i * dx);

    for (int n = 0; n < nSteps; n++) {
        uI = implicitStep(uI, r);
        uE = explicitStep(uE, r);
    }

    std::cout << "r = alpha*dt/dx^2 = " << r << "\n";
    std::cout << "max error, implicit : " << maxError(uI, tEnd, dx, alpha) << "\n";
    std::cout << "max error, explicit : " << maxError(uE, tEnd, dx, alpha) << "\n";
    return 0;
}
