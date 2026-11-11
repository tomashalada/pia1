#include "matrix.h"
#include <iostream>

int main() {
    try {
        // Create two 2x2 matrices
        Matrix A(2, 2), B(2, 2);

        // Initialize matrix A
        A(0, 0) = 1; A(0, 1) = 2;
        A(1, 0) = 3; A(1, 1) = 4;

        // Initialize matrix B
        B(0, 0) = 5; B(0, 1) = 6;
        B(1, 0) = 7; B(1, 1) = 8;

        // Test matrix addition
        std::cout << "Matrix A:" << std::endl;
        A.print();
        std::cout << "Matrix B:" << std::endl;
        B.print();

        std::cout << "A + B:" << std::endl;
        Matrix C = A + B;
        C.print();

        // Test matrix multiplication
        std::cout << "A * B:" << std::endl;
        Matrix D = A * B;
        D.print();

        // Test error handling
        Matrix E(2, 3); // Incompatible for multiplication with A
        Matrix F = A * E; // Should throw exception
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
