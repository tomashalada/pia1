// dve lomitka = komentar
// prelozit pomoci: g++ VSTUPNI-SOUBOR -o NAZEV-SPUSTITELNEHO-SOUBORU tj. g++ main.cpp -o main
// spustit: ./main

#include <iostream>

int main()
{

   int promennaCeleCislo = 1;
   float promennaDesetinneCislo = 3.f
   double desetinneCisloVelke = 6.5646;

   const int N = 10;
   for( int i = N; i > -2; i-- )
   {
      std::cout << "Cyklus se spravnou podminkou" << std::endl;
      std::cout << i << std::endl;
   }

   int counter = 0;
   while( counter < N )
   {
      std::cout << "Counter: " << counter << std::endl;
      counter += 1;

   }

   bool booleovskaProeman = 0;
   int celeCislo = 5;

   if( celeCislo != 5 ) // || pro nebo (or), && pro a (and), != negace (not)
   {
      std::cout << "Podminka splnena" << std::endl;
   }
   else if (  ) {

   }
   else
   {
      std::cout << "Podminka neni splnena" << std::endl;
   }

   //std::cout << "Vypis do konzole promennaCeleCislo:" << promennaDesetinneCislo << std::endl;
   //printf( "Cele cislo: %d\n", promennaCeleCislo );
   return 0;
}
