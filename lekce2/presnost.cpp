/* VSECHNO TADY, JE KOMENTAR:

   - y'(x) = y; y(0) = 1
   - y = exp(x)

   - resit numericky: Eulerovo schema
   - na intervalu [0, 1] - rozsekam na nejake dilky s krokem h
   - budu zmensovat h

   - Porovnavam chybu analytickeho a numerickeho reseni v zavislosti na h (kroku)

*/

#include <fstream> // vypisu do souboru
#include <cmath>
#include <iostream>

int main()
{
   // otevru soubor, do ktereho budu zapisovat
   // ofstream je typ, my_file je nazev
   std::ofstream my_file( "data_double.txt" );
   bool is_my_file_really_open = my_file.is_open();

   if( !is_my_file_really_open ){
      std::cerr << "data_double.txt is not open!" << std::endl;
      exit(1);
   }

   // zadefinuji si presne reseni
   const double y_exact = exp( 1.0 );

   // pocatesnic podminky y(0) = 1

   const int number_of_h = 100;
   const double log_h_start = -1.0; // log10( 10^-1 )
   const double log_h_end = -8; // log10( 10^-9 )
   const double log_h_step = ( log_h_end - log_h_start ) / ( number_of_h - 1 );

   // CYKLUS co meni h
   // Jak vezmu h? Rozhodnu, ze budu uvazovat h z [1e-1 do 1e-9], rozdeleneho na 100 dilku
   for( int i = 0; i <= number_of_h; i++ ){

      // OBSAH CYKLU
      const double log_h = log_h_start + i * log_h_step;
      const double h = pow( 10.0, log_h );

         //-------------
         // CYKLUS co pocita RESENI -> vysledek Y(1); procet kroku 1 / h
         // mam interval [0, 1] , potrebuju ho rozsekat na N dilku v zavilosti na h
         //-------------
         const long long int N = ( 1.0 / h + 0.5 );

         double y = 1.0;
         for( long long int j = 0; j < N; j++ ){

               // napoctu numericky Y(1)
               y = y * ( 1.0 + h );
         }
         // srovnam s presnym resenim a hodnotu zapisu do souboru
         double error = fabs(y - y_exact);

         // vypis do souboru
         my_file << h << " " << error << std::endl;

   }
   //-------------
   my_file.close();
   std::cout << "Data written to file data_double.txt." << std::endl;

   return 0;
}
