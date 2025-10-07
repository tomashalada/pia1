#include <array>
#include <iostream>
#include <tuple>

int main(  ) {

    // 1. Declaration and Initialization
    std::array< int, 5 > arr = { 1, 2, 3, 4, 5 };
    std::array< int, 3 > empty = {  };
    std::array< double, 2 > partial = { 1.5 };
    std::cout <<  "1. Initialization: arr[ 0 ]=" <<  arr[ 0 ]
              <<  ", empty[ 0 ]=" <<  empty[ 0 ]
              <<  ", partial[ 1 ]=" <<  partial[ 1 ] <<  '\n';

    // 2. Accessing Elements
    std::array< int, 3 > arr2 = { 10, 20, 30 };
    std::cout <<  "2. Access: arr2[ 0 ]=" <<  arr2[ 0 ]
              <<  ", arr2.at( 1 )=" <<  arr2.at( 1 )
              <<  ", front=" <<  arr2.front()
              <<  ", back=" <<  arr2.back() <<  '\n';

    // 3. Size and Capacity
    std::array< int, 4 > arr3 = { 1, 2, 3, 4 };
    std::cout <<  "3. Size: size=" <<  arr3.size()
              <<  ", max_size=" <<  arr3.max_size()
              <<  ", empty=" <<  arr3.empty() <<  '\n';

    // 4. Iterators
    std::array< int, 3 > arr4 = { 1, 2, 3 };
    std::cout <<  "4. Iterators: ";
    for ( auto it = arr4.begin(); it != arr4.end(); ++it ) {
        std::cout <<  *it <<  " ";
     }
    std::cout <<  "| Reverse: ";
    for ( auto rit = arr4.rbegin(); rit != arr4.rend(); ++rit ) {
        std::cout <<  *rit <<  " ";
     }
    std::cout << '\n';

    // 5. Filling and Swapping
    std::array< int, 3 > arr5a = { 1, 2, 3 };
    std::array< int, 3 > arr5b = { 4, 5, 6 };
    arr5a.fill( 0 );
    std::cout <<  "5. Fill: ";
    for ( int x : arr5a ) std::cout <<  x <<  " ";
    arr5a.swap( arr5b );
    std::cout <<  "| Swap: ";
    for ( int x : arr5a ) std::cout <<  x <<  " ";
    std::cout <<  '\n';

    // 6. Direct Data Access
    std::array< int, 3 > arr6 = { 1, 2, 3 };
    int* ptr = arr6.data(  );
    std::cout <<  "6. Data: ptr[ 1 ]=" <<  ptr[ 1 ] <<  '\n';

    // 7. Comparison Operators
    std::array< int, 3 > arr7a = { 1, 2, 3 };
    std::array< int, 3 > arr7b = { 1, 2, 4 };
    std::cout <<  "7. Comparison: arr7a< arr7b=" <<  ( arr7a <  arr7b )
              <<  ", arr7a==arr7b=" <<  ( arr7a == arr7b ) <<  '\n';

    // 8. Structured Bindings ( C++17 )
    std::array< int, 3 > arr8 = { 10, 20, 30 };
    auto [ a, b, c ] = arr8;
    std::cout <<  "8. Structured Bindings: " <<  a <<  " " <<  b <<  " " <<  c <<  '\n';

    // 9. Tuple-Like Interface ( std::get )
    std::array< int, 3 > arr9 = { 1, 2, 3 };
    std::cout <<  "9. std::get: get< 1 >=" <<  std::get< 1 >( arr9 ) <<  '\n';

    // 10. constexpr Support
    constexpr std::array< int, 3 > arr10 = { 1, 2, 3 };
    static_assert( arr10[ 1 ] == 2, "Invalid value" );
    std::cout <<  "10. constexpr: arr10[ 1 ]=" <<  arr10[ 1 ] <<  '\n';

    // 11. Range-Based For Loop
    std::array< int, 3 > arr11 = { 1, 2, 3 };
    std::cout <<  "11. Range-Based For: ";
    for ( int x : arr11 ) {
        std::cout <<  x <<  " ";
     }
    std::cout <<  '\n';

    return 0;
 }
