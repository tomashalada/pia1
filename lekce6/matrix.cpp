#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix
{
public:

    // constructor: Initialize matrix with given rows and columns
    // initialize with zeros
    Matrix( size_t r, size_t c ) : rows( r ), cols( c ) {
        data.resize( rows, std::vector< double >( cols, 0.0 ) );
    }

    // overload () operator for element access (e.g., matrix(i, j))
    double& operator()( size_t i, size_t j ) {
        if ( i >= rows || j >= cols ) {
            throw std::out_of_range( "Matrix index out of bounds" );
        }
        return data[ i ][ j ];
    }

    // Const version of () operator for read-only access
    const double& operator()( size_t i, size_t j ) const {
        if ( i >= rows || j >= cols ) {
            throw std::out_of_range("Matrix index out of bounds");
        }
        return data[ i ][ j ];
    }

    // Get number of rows
    size_t getRows() const { return rows; }

    // Get number of columns
    size_t getCols() const { return cols; }

    // overload + operator for matrix addition
    Matrix operator+( const Matrix& other ) const {
        if ( rows != other.rows || cols != other.cols ) {
            throw std::invalid_argument( "Matrix dimensions must match for addition" );
        }
        Matrix result( rows, cols );
        for ( size_t i = 0; i < rows; ++i ) {
            for ( size_t j = 0; j < cols; ++j ) {
                result( i, j ) = data[ i ][ j ] + other( i, j );
            }
        }
        return result;
    }

    // overload * operator for matrix multiplication
    Matrix operator*( const Matrix& other ) const {
        if ( cols != other.rows ) {
            throw std::invalid_argument( "Matrix dimensions incompatible for multiplication" );
        }
        Matrix result( rows, other.cols );
        for ( size_t i = 0; i < rows; ++i ) {
            for ( size_t j = 0; j < other.cols; ++j ) {
                for ( size_t k = 0; k < cols; ++k ) {
                    result( i, j ) += data[ i ][ k ] * other( k, j );
                }
            }
        }
        return result;
    }

    // print matrix (for debugging/display)
    void print() const {
        for ( size_t i = 0; i < rows; ++i ) {
            for ( size_t j = 0; j < cols; ++j ) {
                std::cout << data[ i ][ j ] << " ";
            }
            std::cout << std::endl;
        }
    }

private:

    size_t rows, cols;                          // dimensions of the matrix
    std::vector< std::vector< double > > data;  // 2D vector to store matrix elements

};

// Example usage
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

    } catch ( const std::exception& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
