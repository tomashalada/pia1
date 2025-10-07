#include <iostream>
#include <TNL/Devices/Host.h>
#include <TNL/Containers/Vector.h>


using namespace TNL;
using namespace TNL::Containers;

int
main( int argc, char* argv[] )
{
   const int size = 11;

   TNL::Containers::Vector< float, TNL::Devices::Cuda > a( size ), b( size ), c( size );

   a.forAllElements(
      [] __cuda_callable__( int i, float& value )
      {
         value = 3.14 * ( i - 5.0 ) / 5.0;
      } );

   b = a * a;
   c = 3 * a + sign( a ) * sin( a );
   std::cout << "a = " << a << std::endl;
   std::cout << "sin( a ) = " << sin( a ) << std::endl;
   std::cout << "abs( sin( a ) ) = " << abs( sin( a ) ) << std::endl;
   std::cout << "b = " << b << std::endl;
   std::cout << "c = " << c << std::endl;
}
