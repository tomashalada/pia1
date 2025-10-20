#include <TNL/Containers/NDArray.h>

using namespace TNL::Containers;

template< typename Permutation >
using Array3D = NDArray< int,  // Value
                         SizesHolder< int, 0, 0, 0 >,
                         Permutation,
                         TNL::Devices::Host >;

int
main()
{
   // create 3 arrays with different permutations
   Array3D< std::index_sequence< 0, 1, 2 > > a;  // first index changes the slowest, last index changes the fastest
   Array3D< std::index_sequence< 2, 0, 1 > > b;  // last index changes the slowest, middle index changes the fastest
   Array3D< std::index_sequence< 2, 1, 0 > > c;  // last index changes the slowest, first index changes the fastest

   // allocate the storage
   a.setSizes( 3, 3, 3 );
   b.setSizes( 3, 3, 3 );
   c.setSizes( 3, 3, 3 );

   // initialize values
   int value = 0;
   for( int i = 0; i < 3; i++ )
      for( int j = 0; j < 3; j++ )
         for( int k = 0; k < 3; k++ ) {
            a( i, j, k ) = value;
            b( i, j, k ) = value;
            c( i, j, k ) = value;
            value++;
         }

   // print the underlying 1D arrays
   std::cout << "a = " << a.getStorageArray() << std::endl;
   std::cout << "b = " << b.getStorageArray() << std::endl;
   std::cout << "c = " << c.getStorageArray() << std::endl;

   return 0;

}
