#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

// function to modify static array by reference
void modifyStaticArray( int ( &arr )[ 5 ] ) {
    arr[ 0 ] = 100;
}

int main() {
    // 1. multidimensional Static Array
    const int rows = 3, cols = 4;
    int static2D[ rows ][ cols ] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };

    std::cout << "Multidimensional Static Array:\n";
    for( int i = 0; i < rows; ++i ) {
        for( int j = 0; j < cols; ++j ) {
            std::cout << static2D[ i ][ j ] << " ";
        }
        std::cout << std::endl;
    }

    // 2. dynamic Multidimensional Array
    int** dynamic2D = new int*[ rows ];
    for( int i = 0; i < rows; ++i ) {
        dynamic2D[ i ] = new int[ cols ];
        for( int j = 0; j < cols; ++j ) {
            dynamic2D[ i ][ j ] = ( i + 1 ) * ( j + 1 );
        }
    }

    std::cout << "\nDynamic Multidimensional Array:\n";
    std::cout << "2D arrays:\n";
    for( int i = 0; i < rows; ++i ) {
        for( int j = 0; j < cols; ++j ) {
            std::cout << dynamic2D[ i ][ j ] << " ";
        }
        std::cout << std::endl;
    }

    // 3. std::array (Fixed-size array with STL interface)
    std::array< int, 5 > stdArray = { 10, 20, 30, 40, 50 };

    std::cout << "\nstd::array Example:\n";
    for( int val : stdArray ) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // modify std::array (double each element)
    for( auto& val : stdArray ) {
        val *= 2;
    }
    std::cout << "After doubling elements: ";
    for( int val : stdArray ) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 4. passing Static Array to Function
    int passArray[ 5 ] = { 1, 2, 3, 4, 5 };
    modifyStaticArray( passArray );
    std::cout << "\nAfter passing to function and modifying: ";
    for( int val : passArray ) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 5. vector of Vectors (Dynamic 2D)
    std::vector< std::vector< int > > vec2D( rows, std::vector< int >( cols ) );
    for( int i = 0; i < rows; ++i ) {
        for( int j = 0; j < cols; ++j ) {
            vec2D[ i ][ j ] = i * cols + j + 1;
        }
    }

    std::cout << "\nVector of Vectors:\n";
    for( const auto& row : vec2D ) {
        for( int val : row ) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // cleanup dynamic 2D array
    for( int i = 0; i < rows; ++i ) {
        delete[] dynamic2D[ i ];
    }
    delete[] dynamic2D;

    return 0;
}
