#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<double>> data; // 2D vector to store matrix elements
    size_t rows, cols; // Dimensions of the matrix

public:
    // Constructor
    Matrix(size_t r, size_t c);

    // Operator overloading for element access
    double& operator()(size_t i, size_t j);
    const double& operator()(size_t i, size_t j) const;

    // Get dimensions
    size_t getRows() const;
    size_t getCols() const;

    // Matrix operations
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    // Print matrix
    void print() const;
};

#endif // MATRIX_H

