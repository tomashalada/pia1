#include <iostream>

// 1. pass array to function
// --------------------------------------------------------------------
/*
// note: 'arr' is a pointer (int*), so we need 'size' parameter
int sumArray( int arr[], int size ) {
    int sum = 0;
    for ( int i = 0; i < size; ++i ) {
        sum += arr[ i ];
    }
    return sum;
}

int main() {

    int numbers[5] = { 1, 2, 3, 4, 5 };  // Fixed size 5

    // call the function
    int total = sumArray(numbers, 5);

    std::cout << "Sum: " << total << std::endl;
    return 0;
}


// 2. with std::vector
// --------------------------------------------------------------------

/*

#include <iostream>
#include <array>

int sumArray(const std::array<int, 5>& arr) {
    int sum = 0;
    // Use .size() to get length automatically
    for (size_t i = 0; i < arr.size(); ++i) {
        sum += arr[i];  // Or use arr.at(i) for bounds checking
    }
    return sum;
}

int main() {
    // Declare and initialize a std::array (fixed size 5)
    std::array<int, 5> numbers = {1, 2, 3, 4, 5};

    // Call the function
    int total = sumArray(numbers);

    std::cout << "Sum: " << total << std::endl;  // Output: Sum: 15
    return 0;
}

*/

// 3. function that modifies vector
// --------------------------------------------------------------------


#include <iostream>
#include <array>

void doubleArray( std::array<int, 3>& arr ) {
    for ( size_t i = 0; i < arr.size(); ++i ) {
        arr[ i ] *= 2;
    }
}

int main() {
    // Declare and initialize
    std::array<int, 3> values = { 10, 20, 30 };

    // Call the function (modifies the array)
    doubleArray( values );

    // Print the modified array
    for (int val : values) {  // Range-based for loop (C++11+)
        std::cout << val << " ";  // Output: 20 40 60
    }
    std::cout << std::endl;
    return 0;
}
