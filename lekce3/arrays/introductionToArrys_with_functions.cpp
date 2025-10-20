#include <iostream>
#include <vector>

// function to print array contents
void printArray( int arr[  ], int size, const std::string& name ) {
    std::cout << name << ": ";
    for ( int i = 0; i < size; ++i ) {
        std::cout << arr[ i ] << " ";
    }
    std::cout << std::endl;
}

// function to print vector contents
void printVector( const std::vector<int>& vec, const std::string& name ) {
    std::cout << name << ": ";
    for ( int val : vec ) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(  ) {
    // 1. Static Array Allocation ( fixed size at compile time )
    const int staticSize = 5;
    int staticArray[ staticSize ] = { 1, 2, 3, 4, 5 };

    std::cout << "Static Array Example\n";
    printArray( staticArray, staticSize, "staticArray" );

    // modify static array
    staticArray[ 2 ] = 10;
    printArray( staticArray, staticSize, "staticArray ( after modification )" );

    // 2. Dynamic Array Allocation ( size determined at runtime )
    int dynamicSize = 0;
    std::cout << "\nEnter size for dynamic array: ";
    std::cin >> dynamicSize;

    // Allocate memory
    int* dynamicArray = new int[ dynamicSize ];

    // Initialize dynamic array
    for ( int i = 0; i < dynamicSize; ++i ) {
        dynamicArray[ i ] = i * 2;
    }

    printArray( dynamicArray, dynamicSize, "dynamicArray" );

    // 3. std::vector ( dynamic size, automatic memory management )
    std::vector< int > vectorArray = { 10, 20, 30 };

    std::cout << "\nVector Example\n";
    printVector( vectorArray, "vectorArray" );

    // Add elements to vector
    vectorArray.push_back( 40 );
    vectorArray.push_back( 50 );
    printVector( vectorArray, "vectorArray ( after push_back )" );

    // Modify vector element
    vectorArray[ 2 ] = 35;
    printVector( vectorArray, "vectorArray ( after modification )" );

    // Remove last element
    vectorArray.pop_back();
    printVector( vectorArray, "vectorArray ( after pop_back )" );

    // Clean up dynamic array memory
    delete[] dynamicArray;

    return 0;
}
