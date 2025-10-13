#include <iostream>
#include <vector>
#include <cmath>

/*

RESIME:
Rovnice:              u_t + c * u_x = 0
Pocatecni. podminka:  u(0, x) = exp[ ( x - x_center )^2 / ( 2 * simga^2 ) ] /
Okrajova podminka:    u(t, 0) = 0

KDE: na rece v intervalu [x1 = 0, x2 = 1], a v case [t1 = 0, t2 = 0.5]

CO CHCEME: Rozlozeni koncentrace u na intervalu [x1, x2] v case t = 1;
(vysledek reprezentujeme jako pole)

CO MUSIME UDELAT?
- MATEMATIKA: Musime diskretizovat casovou a prostorou derivaci v rovnici.

- PROGRAMOVANI:
-- Musime si zavest vsechny konstanty
-- Pole, ktere reprezentuje koncentraci na intervalu -> MOJE u
-- cyklus, ktery probiha interval x1, x2
-- casovy cyklus, ktery probiha interval t1, t2
*/

int main()
{
   // nadefinuji si konstatny ulohy (intervaly, casovy krok, prostorovy krok)
   const int nx = 200;                   // grid points
   const double dx = 0.1;                // spatial step
   const int nt = 500;                   // time steps - t_end = 0.5 s
   const double dt = 0.01;               // time step
   const double c = 1.0;                 // advection speed (m/s)
   const double lambda = c * dt / dx;    // CFL = 0.1 (<=1 for upwind stability)

   // parametry pocatecni podminky
   const float x_center = 3.0;           // center of initial Gaussian peak
   const float sigma = 1;                // variance of the Gaussian peak

   // vytvorim pole, co reprezentuje reseni
   // potrebuju dvojici poli
   std::vector< float > u( nx, 0.f);
   std::vector< float > u_new( nx, 0.f);

   // pole naplnim hodnotama
   for( int i = 0; i < nx; i++ )
   {
      const float x =  i * dx;
      u[ i ] = std::exp( - ( x - x_center ) * ( x - x_center ) / ( 2 * sigma * sigma )  );
   }

   // vypisu pocatecni podminku do souboru
   // ...

   // --- cyklus v case (i, t_i z [t1, t2])
   // ...

         // vstupujeme sem a zname pole u v case t_i
         // cilem je urcit pole u v case t_i+1

         // aktualizuju levou okrajovou podminku
         u_new[ 0 ] = 0;

         // --- cyklus v prostoru (musim projit to pole u)( j, x_i z x1, x2 )
         // ...

               // u_j^n+1 = u_j^n + lambda (u_j^n - u_j-1^n)

         // prohodim novou a starou casovou vrstvu
         // ...

   // -----------------

   // vypisu vysledne reseni do souboru
   // ...

   return 0;
}
