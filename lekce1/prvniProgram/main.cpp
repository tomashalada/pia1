// dve lomitka = komentar
// prelozit pomoci: g++ VSTUPNI-SOUBOR -o NAZEV-SPUSTITELNEHO-SOUBORU tj. g++ main.cpp -o main
// spustit: ./main

#include <iostream>

int main()
{

   int promennaCeleCislo = 1;
   float promennaDesetinneCislo=  3.f;
   double desetinneCisloVelke  = 6.5646;

   std::cout << "Vypis do konzole promennaCeleCislo:" << promennaDesetinneCislo << std::endl;
   printf( "Cele cislo: %d\n", promennaCeleCislo );
   return 0;
}
