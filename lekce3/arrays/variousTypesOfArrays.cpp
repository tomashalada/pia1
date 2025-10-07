#include <iostream>
#include <array>
#include <vector>

int main() {
    // 1. Static Array (Fixed size, stack-allocated)
    int staticArray[5] = {1, 2, 3, 4, 5};
    std::cout << "Static Array: ";
    for(int i = 0; i < 5; i++) {
        std::cout << staticArray[i] << " ";
    }
    std::cout << "\n";

    // 2. Dynamic Array (using new, heap-allocated)
    int* dynamicArray = new int[5];
    for(int i = 0; i < 5; i++) {
        dynamicArray[i] = i + 10;
    }
    std::cout << "Dynamic Array: ";
    for(int i = 0; i < 5; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << "\n";
    delete[] dynamicArray; // Clean up

    // 3. Multidimensional Static Array (2D array)
    int multiArray[2][3] = {{1, 2, 3}, {4, 5, 6}};
    std::cout << "2D Static Array:\n";
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << multiArray[i][j] << " ";
        }
        std::cout << "\n";
    }

    // 4. std::array (Fixed size, type-safe container)
    std::array<int, 4> stdArray = {10, 20, 30, 40};
    std::cout << "std::array: ";
    for(const auto& element : stdArray) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    // 5. std::vector (Dynamic size, type-safe container)
    std::vector<int> vectorArray = {100, 200, 300};
    vectorArray.push_back(400); // Dynamic resizing
    std::cout << "std::vector: ";
    for(const auto& element : vectorArray) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    // 6. Array of Strings
    std::string stringArray[3] = {"Hello", "World", "C++"};
    std::cout << "String Array: ";
    for(const auto& str : stringArray) {
        std::cout << str << " ";
    }
    std::cout << "\n";

    // 7. Array of Pointers
    int a = 1, b = 2, c = 3;
    int* pointerArray[3] = {&a, &b, &c};
    std::cout << "Pointer Array: ";
    for(const auto& ptr : pointerArray) {
        std::cout << *ptr << " ";
    }
    std::cout << "\n";

    return 0;
}
