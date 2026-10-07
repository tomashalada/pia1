#include <iostream>
using namespace std;

int main() 
{
    int celeCislo = 5;
    float floatCislo = 3.14;
    double doubleCislo = 2.71828;
    char znak = 'A';
    char retezec[] = "Hello, World!";

    for (int i = 0; i < 5; i++) 
    {
        std::cout << "Cislo: " << celeCislo << std::endl;
        std::cout << i << std::endl;
    }

    std::cout << "Vypis do konzole" << std::endl;
    return 0;
}

