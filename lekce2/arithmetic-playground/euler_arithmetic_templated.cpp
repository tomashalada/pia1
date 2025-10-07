#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib> // For exit in case of issues

template< typename T >
void compute_error( const std::string& filename, T log_h_end ) {
   std::ofstream outfile( filename );
    if ( !outfile.is_open() ) {
       std::cerr << "Error opening " << filename << std::endl;
       exit( 1 );
    }

    // exact solution y(1) = e^1
    T exact = exp( static_cast< T >( 1.0 ) );

    // x = a^y -> y = log_a(x)
    int num_points = 100;
    T log_h_start = static_cast< T >( -1.0 );
    T log_h_step = ( log_h_end - log_h_start ) / ( num_points - 1 );

    // vary h from 10^-1 down to log_h_end
    for ( int i = 0; i < num_points; ++i ) {
        T log_h = log_h_start + i * log_h_step;
        T h = pow( static_cast< T >( 10.0 ), log_h );

        // get number of stepts for the numerical integration
        long long N = static_cast< long long >( 1.0 / h + 0.5 );

        // initial condition y(0) = 1
        T y = static_cast< T > ( 1.0 );
        for ( long long n = 0; n < N; ++n ) {
            y = y * ( 1.0 + h );
        }

        T error = fabs( y - exact );
        outfile << h << " " << error << std::endl;
    }

    outfile.close();
    std::cout << "Data written to " << filename << std::endl;
}

int main() {

    // compute for double with log_h_end = -10.0
    compute_error< double >( "data_double.txt", -10.0 );

    // compute for float with log_h_end = -8.0
    compute_error< float >( "data_float.txt", -8.0 );

    return 0;
}
