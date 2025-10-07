#include <iostream>

int main(int argc, char* argv[])
{
    // Print argc
    std::cout << "Number of arguments (argc): " << argc << std::endl;

    // Loop through argv and print each argument
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0; // Equivalent to EXIT_SUCCESS
}
