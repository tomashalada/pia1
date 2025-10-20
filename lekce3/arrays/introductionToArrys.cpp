#include <iostream>
#include <array>
#include <vector>

int main() {

    // ----- 1. Static Array Allocation ( fixed size at compile time ) -----
    const int staticSize = 5;
    int staticArray[ staticSize ] = { 1, 2, 3, 4, 5 };

    std::cout << "Static Array Example\n";
    std::cout <<  "Array: ";
    for ( int i = 0; i < staticSize; ++i ) {
        std::cout << staticArray[ i ] << " ";
    }
    std::cout << std::endl;

    // modify static array
    staticArray[ 2 ] = 10;

    std::cout <<  "Array: ";
    for ( int i = 0; i < staticSize; ++i ) {
        std::cout << staticArray[ i ] << " ";
    }
    std::cout << std::endl;

    // ----- 2. Static Array - std::array (fixed size at compile time) ------

    const int staticSize = 5;
    int staticArray[ staticSize ] = { 1, 2, 3, 4, 5 };

    std::array< int, 5 > stdArray = { 1, 2, 3, 4, 5 };

    std::cout << "Std Array Example\n";
    std::cout <<  "Array: ";
    for ( int i = 0; i < stdArray.size(); ++i ) {
        std::cout << stdArray[ i ] << " ";
    }
    std::cout << std::endl;

    // modify static array
    stdArray[ 2 ] = 10;

    std::cout <<  "Array: ";
    for ( int i = 0; i < stdArray.size(); ++i ) {
        std::cout << stdArray[ i ] << " ";
    }
    std::cout << std::endl;

    // ----- 3. Dynamic Array Allocation ( size determined at runtime ) -----
    int dynamicSize = 0;
    std::cout << "\nEnter size for dynamic array: ";
    std::cin >> dynamicSize;

    // allocate memory
    int* dynamicArray = new int[ dynamicSize ];

    // initialize dynamic array
    for ( int i = 0; i < dynamicSize; ++i ) {
        dynamicArray[ i ] = i * 2;
    }

    std::cout << "Dynamic Array Example\n";
    std::cout <<  "Array: ";
    for ( int i = 0; i < dynamicSize; ++i ) {
        std::cout << dynamicArray[ i ] << " ";
    }
    std::cout << std::endl;

    // ----- 4. std::vector ( dynamic size, automatic memory management ) -----
    std::vector< std::vector< float > vectorArray = { {1., 3., 5.}, { 4., 6., 8 }, { 7, 3., 9. } };

    std::cout << "\nVector Example\n";
    std::cout <<  "Vector: ";
    for ( int val : vectorArray ) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // add elements to vector
    vectorArray.push_back( 40 );
    vectorArray.push_back( 50 );

    std::cout <<  "Vector: ";
    for ( int val : vectorArray ) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // modify vector element
    vectorArray[ 2 ] = 35;

    std::cout <<  "Vector: ";
    for ( int val : vectorArray ) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // remove last element
    vectorArray.pop_back();

    std::cout <<  "Vector: ";
    for ( int val : vectorArray ) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // clean up dynamic array memory
    delete[] dynamicArray;

    return 0;
}
