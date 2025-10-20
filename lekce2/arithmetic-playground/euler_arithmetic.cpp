#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib> // exit

int main() {

   std::ofstream outfile( "data_float.txt" );
    if ( !outfile.is_open() ) {
       std::cerr << "Error opening data.txt" << std::endl;
        exit(1);
    }

    using NaseDesetinneCislo = double;

    // exact solution y(1) = e^1
    NaseDesetinneCislo exact = exp( 1.0 );

    // x = a^y -> y = log_a(x)
    int num_points = 100;
    NaseDesetinneCislo log_h_start = -1.f; // log10( 10^-1 )
    NaseDesetinneCislo log_h_end = -8.0;  // log10( 10^-10 )
    NaseDesetinneCislo log_h_step = ( log_h_end - log_h_start ) / ( num_points - 1 );

    // sample solutions from log_h_start to log_h_end
    for ( int i = 1; i <= num_points; ++i ) {
        std::cout << "i: " << i << std::endl;

        NaseDesetinneCislo log_h = log_h_start + i * log_h_step;
        NaseDesetinneCislo h = pow( 10.0, log_h );

        // get number of stepts for the numerical integration
        //long long N = static_cast<long long>( 1.0 / h + 0.5 );
        long long N = ( 1.0 / h + 0.5 );

        // skip if N is too large
        //if (N > 1e8LL) {
        //    continue;
        //}

        // initial condition y(0) = 1
        NaseDesetinneCislo y = 1.0;
        for ( long long n = 0; n < N; ++n ) {
            y = y * ( 1.0 + h );
        }

        NaseDesetinneCislo error = fabs( y - exact );
        outfile << h << " " << error << std::endl;
    }

    outfile.close();
    std::cout << "Data written to data_NaseDesetinneCislo.txt" << std::endl;
    return 0;
}
