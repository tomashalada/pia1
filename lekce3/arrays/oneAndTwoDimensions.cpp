#include <iostream>

// matrix dimensions
const int rows = 3;
const int cols = 4;

// macros for indexing
#define IDX_1D_COLUMN_MAJOR(row, col, width) ((row) * (width) + (col))
#define IDX_1D_ROW_MAJOR(row, col, width) ((col) * (width) + (row))

//// constexpr functions for indexing
//constexpr static int idx_1d( unsigned int row, unsigned int col, unsigned int width) {
//    return row * width + col;
//}
//int idx_2d( unsigned int row, unsigned int col) {
//    return row * cols + col;
//}

int main() {

    // 2D array
    int matrix_2d[ rows ][ cols ] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // 1D array representing the same matrix
    int matrix_1d_column_major[ rows * cols ] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12
    };

    // 1D array representing the same matrix
    int matrix_1d_row_major[ rows * cols ] = {
        1, 5, 9,
        2, 6, 10,
        9, 7, 11,
        4, 8, 12
    };

    // --------------------------------------------------------------------------------------

    // 2D indexing using standard array access
    std::cout << "\n2D indexing using standard array access:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix_2d[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // --------------------------------------------------------------------------------------

    // 1D indexing using macro
    std::cout << "Column major: 1D indexing using macro:\n";
    std::cout << "Representation in memory:" << std::endl;
    std::cout << "[ " ;
    for( int i = 0; i <  rows; i++ ) {
      for( int j = 0; j < cols ; j++ ) {
       std::cout << matrix_1d_column_major[ idx_1d( i, j, cols) ] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << "]\n";
//
//    std::cout << "Column major indexing:" << std::endl;
//    for( int i = 0; i < rows; i++ ) {
//        for( int j = 0; j < cols; j++ ) {
//            std::cout << matrix_1d_column_major[ IDX_1D_COLUMN_MAJOR( i, j, cols ) ] << " ";
//        }
//        std::cout << "\n";
//    }
//    std::cout << "\n";
//
//    // 1D indexing using macro
//    std::cout << "Row major indexing:\n";
//    for( int i = 0; i < rows; i++ ) {
//        for( int j = 0; j < cols; j++ ) {
//            std::cout << matrix_1d_column_major[ IDX_1D_ROW_MAJOR( i, j, rows ) ] << " ";
//        }
//        std::cout << "\n";
//    }
//    std::cout << "\n";
//
//    // --------------------------------------------------------------------------------------
//
//    // 1D indexing using macro
//    std::cout << "Row major: 1D indexing using macro:\n";
//    std::cout << "Representation in memory:" << std::endl;
//    std::cout << "[ " ;
//    for( int i = 0; i < cols * rows; i++ ) {
//       std::cout << matrix_1d_row_major[ i ] << " ";
//    }
//    std::cout << "]\n";
//
//    std::cout << "Column major indexing:" << std::endl;
//    for( int i = 0; i < rows; i++ ) {
//        for( int j = 0; j < cols; j++ ) {
//            std::cout << matrix_1d_row_major[ IDX_1D_COLUMN_MAJOR( i, j, cols ) ] << " ";
//        }
//        std::cout << "\n";
//    }
//    std::cout << "\n";
//
//    // 1D indexing using macro
//    std::cout << "Row major indexing:\n";
//    for( int i = 0; i < rows; i++ ) {
//        for( int j = 0; j < cols; j++ ) {
//            std::cout << matrix_1d_row_major[ IDX_1D_ROW_MAJOR( i, j, rows ) ] << " ";
//        }
//        std::cout << "\n";
//    }
//    std::cout << "\n";
//
//    // --------------------------------------------------------------------------------------

    return 0;
}
