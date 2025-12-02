#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>

int main() {
    // ---------- nastavení úlohy ----------
    const double x1 = 0.0, x2 = 1.0;      // prostorový interval
    const double t1 = 0.0, t2 = 0.5;      // časový interval
    const int    nx = 200;                // počet uzlů v prostoru
    const double c  = 0.1;                // advekční rychlost (>0 => doprava)

    // prostorový krok a souřadnice
    const double dx = (x2 - x1) / (nx - 1);

    // CFL (konzervativně 0.1 <= 1 pro stabilitu upwindu)
    const double CFL = 0.1;
    const double dt  = CFL * dx / c;      // z CFL => dt
    const int    nt  = static_cast<int>( std::floor( (t2 - t1) / dt ) );

    const double lambda = c * dt / dx;    // = CFL

    // ---------- počáteční podmínka (Gauss) ----------
    const double x_center = 0.3;
    const double sigma = 0.1;

    std::vector<double> u(nx, 0.0), u_new(nx, 0.0);

    for (int j = 0; j < nx; ++j) {
        double x = x1 + j * dx;
        u[j] = std::exp( - (x - x_center)*(x - x_center) / (2.0 * sigma * sigma) );
    }

    // zapiš počáteční profil
    {
        std::ofstream f("u_initial.txt");
        f << std::fixed << std::setprecision(8);
        for (int j = 0; j < nx; ++j) {
            double x = x1 + j * dx;
            f << x << '\t' << u[j] << '\n';
        }
    }

    // ---------- časový výpočet (upwind) ----------
    double t = t1;
    for (int n = 0; n < nt; ++n) {
        t += dt;

        // levá hranice (Dirichlet)
        u_new[0] = 0.0;

        // vnitřek: upwind pro c>0
        for (int j = 1; j < nx; ++j) {
            u_new[j] = u[j] - lambda * (u[j] - u[j-1]);
        }

        // prohodíme vrstvy
        u.swap(u_new);
    }

    // ---------- výstup finálního profilu ----------
    {
        std::ofstream f("u_final_t0p5.txt");
        f << std::fixed << std::setprecision(8);
        for (int j = 0; j < nx; ++j) {
            double x = x1 + j * dx;
            f << x << '\t' << u[j] << '\n';
        }
    }

    std::cout << "Hotovo. Souboru: u_initial.txt a u_final_t0p5.txt\n";
    std::cout << "Parametry: nx=" << nx << ", dt=" << dt << ", nt=" << nt
              << ", CFL=" << lambda << std::endl;
    return 0;
}





