// nacitani modulu

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

// DATOVY_TYP_NAVRATOVE_HODNOTY indentifikator( argumenty )
// { telo funkce }

void
vypisVektor( const std::vector< double >& vektor_k_vypsani )
{
   std::cout << "[ ";
   for( auto prvek : vektor_k_vypsani )
   {
      std::cout << prvek << " ";
   }
   std::cout << "], velikost: " << vektor_k_vypsani.size() << std::endl;
}

bool
jsouDvaVektoryStejne( const std::vector< double >& a, const std::vector< double >& b )
{
   if( a.size() != b.size() )
   {
      std::cerr << "Vektory nemaji stejnou velikost! a.size() = "
         << a.size() << "b.size() = " << b.size() << std::endl;
      return false;
   }
   else
   {
      return true;
   }
}

void
inicializujVektory( std::vector< double >& a, std::vector< double >& b )
{

   if( !jsouDvaVektoryStejne( a, b ) ){
      std::cerr << "Ukoncuji funkci - inicialujVektory." << std::endl;
      return;
   }

   for( int i = 0; i < a.size(); i++ )
   {
      // std::cout << "i = " << i << std::endl;
      a[ i ] = i * 0.5;
      b[ i ] = std::pow( -1, i ) * std::pow( i, 2 );
   }
}

double
skalarniProdukt( const std::vector< double >& a, const std::vector< double >& b )
{
   if( !jsouDvaVektoryStejne( a, b ) ){
      std::cerr << "Ukoncuji funkci - inicialujVektory." << std::endl;
      exit( 1 );
   }

   double soucin = 0;
   for( int i = 0; i < a.size(); i++ )
   {
      soucin += a[ i ] * b[ i ];
   }

   return soucin;
}

// hlavni funkce programu
int main()
{
   const int size = 10;

   std::vector< double > vec_a( size, 0. );
   std::vector< double > vec_b;
   vec_b.resize( size );

   inicializujVektory( vec_a, vec_b );

   vypisVektor( vec_a );
   vypisVektor( vec_b );

   double vect_a_dot_vect_b = skalarniProdukt( vec_a, vec_b );
   std::cout << "Vysledek sklaraniho produktu: " << vect_a_dot_vect_b << std::endl;

   if( vect_a_dot_vect_b > 0 )
      std::cout << "Vysledek sklaraniho produktu je kladny." << std::endl;
   else if( vect_a_dot_vect_b < 0 )
      std::cout << "Vysledek sklaraniho produktu je zaporny." << std::endl;
   else
      std::cout << "Vysledek sklaraniho produktu je nulovy." << std::endl;


   std::cout << "Vektor a: ";
   vypisVektor( vec_a );
   std::cout << "Vektor b: ";
   vypisVektor( vec_b );


   std::vector< double > vec_c( size );

   vec_c = vec_a;
   vec_a = vec_b;
   vec_b = vec_c;

   std::cout << "Vektor a: ";
   vypisVektor( vec_a );
   std::cout << "Vektor b: ";
   vypisVektor( vec_b );


   //float t = 0;
   //const float t_end = 1;

   //while( t < t_end )
   //{
   //   std::cout << t << std::endl;
   //   t += 0.1;
   //}

   //// C++
   //std::cout << "C++: Velikost vetkrou: " << size << std::endl;
   //// C
   //printf( "C: Velikost vektoru %d\n", size );


   return 0;
}
