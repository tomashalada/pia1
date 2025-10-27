#include <iostream>
#include <vector>

struct Params
{
   int size;
   double dx;
   double dt;

   // specialni member funkce: defaultni konstruktor (pokud neuvedu ZADNY JINY KONSTRUKTOR,
   // vola se automaticky )
   // Params() = default;

   // specialni member funkce: konstruktor
   Params( int init_size, double init_dx, double init_dt ) : dx( init_dx ), dt( init_dt )
   {
      std::cout << "Specialni funkce: Konstruktor" << std::endl;
      size = init_size;
      dx = init_dx;
   }

   // specialni member funkce: destruktor
   ~Params()
   {
      std::cout << "Vola se, kdyz objekt zanika." << std::endl;
   }

   void print()
   {
      std::cout << "size: " << size << " dx: " << dx << " dt: " << dt << std::endl;
   }

   void readParams( std::string fileName )
   {

   }

   void changeSize( int new_size )
   {
      size = new_size;
   }
};

void vypisStrukturu( Params& strukturaKVypsani )
{ std::cout << "Moje parametry:\n- size: " << strukturaKVypsani.size << std::endl; }

int main(){

   int size = 3;
   std::vector< float > vec_a;
   vec_a.resize( size );

   Params mojeParametry( 10, 0.01, 0.02 );
   mojeParametry.print();

   //Params druheParametry;

   //mojeParametry.size = 10;
   //mojeParametry.print();
   //mojeParametry.changeSize( 15 );
   //mojeParametry.print();


   mojeParametry.size = 10;
   mojeParametry.dx = 0.01;
   mojeParametry.dt = 0.01;
   mojeParametry.print();

   //vypisStrukturu( mojeParametry );

   return 0;
}
