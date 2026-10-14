#include <iostream>
#include <array>
#include <vector>

using namespace std;

void swap(int* a, int* b) // vyzaduje adresu
{
    int temp = *a; //dereference pointer to get value
    *a = *b;
    *b = temp;
}

int main() 
{
    int x = 5;
    int y = 10;
    float floatCislo = 3.14;
    double doubleCislo = 2.71828;
    char znak = 'A';
    char retezec[] = "Hello, World!";

/*    for (int i = 0; i < 5; i++) 
    {
        std::cout << "Cislo: " << celeCislo << std::endl;
        std::cout << i << std::endl;
    }
*/
//    std::cout << "Vypis do konzole" << std::endl;

    // hodina 4

//    int* ptr = &x; // pointer to an integer

//    std::cout << "Adresa celeho cisla: " << &x << std::endl; // print address of integer
//    std::cout << "Hodnota celeho cisla: " << ptr << std::endl; // dereference pointer to get value
//    std::cout << "Hodnota celeho cisla: " << *ptr << std::endl; // dereference pointer to get value


//    std::cout << "Pred vymenou: x = " << x << ", y = " << y << std::endl;

//    swap(&x, &y); // pass addresses of variables to swap function

//    std::cout << "Po vymene: x = " << x << ", y = " << y << std::endl;

// Static array 

    const int staticSize = 10;
    int staticArray[staticSize] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < staticSize; i++) 
    {
        std::cout << staticArray[i]; 
    }
    std::cout << std::endl;

    std::array<int, 10> stdArray = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (const auto& element : stdArray) 
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

// Dynamic array allocation 
    int dynamicSize = 0;
    std::cout << "Zadejte velikost dynamickeho pole: ";
    std::cin >> dynamicSize;
    std::cout << "Velikost dynamickeho pole: " << dynamicSize << std::endl;

    int* dynamicArray = new int[dynamicSize];
    for (int i = 0; i < dynamicSize; i++) 
    {
        dynamicArray[i] = i*2; // assign values to dynamic array
    }
    for (int i = 0; i < dynamicSize; i++) 
    {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;
    delete[] dynamicArray;

// Dynamic array using std::vector
    std::vector<float> vec = {0., 1., 2.};

    // Add elements to the vector
    vec.push_back(3.);

    // Remove the last element from the vector
    vec.pop_back();

    for (int val: vec) 
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

// New 

    return 0;
}

