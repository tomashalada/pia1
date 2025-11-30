// 2. Basic Lambda Example
// Let's start with a simple lambda that prints "Hello, World!":


/*
#include <iostream>

int main() {
    auto hello = []() { std::cout << "Hello, World!\n"; };
    hello();  // Call the lambda
    return 0;
}
*/


// ___________________________________________________________________________

// 3. Lambda with Parameters
// Lambdas can take parameters just like normal functions:

/*

#include <iostream>

int main() {
    auto add = [](int a, int b) { return a + b; };
    std::cout << "Sum: " << add(5, 3) << "\n";  // Outputs: Sum: 8
    return 0;
}

*/


// ___________________________________________________________________________

// 4. Lambda with Explicit Return Type
// You can explicitly specify the return type using ->:

/*

#include <iostream>

int main() {
    auto divide = [](int a, int b) -> double { return static_cast<double>(a) / b; };
    std::cout << "Division: " << divide(7, 2) << "\n";  // Outputs: 3.5
    return 0;
}

*/

// ___________________________________________________________________________

// 5. Capturing Variables
// Lambdas can capture variables from their surrounding scope.
// 5.1 Capture by Value ([=] or [var])


/*
#include <iostream>
int main() {
    int x = 10;
    auto printX = [x]() { std::cout << "x: " << x << "\n"; };
    x = 20;  // Changing x doesn't affect the lambda
    printX();  // Outputs: x: 10
    return 0;
}
*/

// 5.2 Capture by Reference ([&] or [&var])


#include <iostream>

/*
int main() {
    int x = 10;
    auto modifyX = [&x]() { x = 100; };
    modifyX();
    std::cout << "x: " << x << "\n";  // Outputs: x: 100
    return 0;
}
*/

// 5.3 Mixed Capture

/*
#include <iostream>

int main() {
    int a = 5, b = 10;
    auto mixed = [=]() {
        // a is captured by value, so it's a copy
        // b is captured by reference, so changes affect original b
        std::cout << "a: " << a << ", b: " << b << "\n";
    };
    a = 50;
    b = 20;
    mixed();  // Outputs: a: 5, b: 20
    return 0;
}
*/

// ___________________________________________________________________________

// 6. Mutable Lambdas
// By default, lambdas capturing by value cannot modify captured variables. To allow modification, use the mutable keyword:

/*

#include <iostream>

int main() {
    int x = 10;
    auto increment = [x]() mutable
    { x++; std::cout << "Inside lambda: " << x << "\n"; };
    increment();
    std::cout << "Outside lambda: " << x << "\n";  // Original x remains unchanged
    return 0;
}
*/

// ___________________________________________________________________________

// 7. Using Lambdas in STL Algorithms
// Lambdas are heavily used in STL algorithms like std::sort(), std::for_each(), and std::transform().

/*

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {5, 2, 8, 1, 3};

    int c = 2;
    std::sort(nums.begin(), nums.end(), [&](int a, int b) { return c * a > b; });  // Descending order

    for (int num : nums)
        std::cout << num << " ";  // Outputs: 8 5 3 2 1

    return 0;
}
*/

// ___________________________________________________________________________

// 8. Generic Lambdas (C++14)
// C++14 introduced generic lambdas, where parameters use auto:
/*
#include <iostream>

int main() {
    auto add = [](auto a, auto b) { return a + b; };

    std::cout << add(3, 4) << "\n";      // Outputs: 7
    std::cout << add(3.5f, 2.1f) << "\n";  // Outputs: 5.6

    return 0;
}
*/

// ___________________________________________________________________________

// 9. Lambdas as Function Parameters
// You can pass lambdas as function arguments


#include <iostream>
#include <functional>

//void applyFunction(int x, int y, std::function<int(int, int)> func) {
//    std::cout << "Result: " << func(x, y) << "\n";
//}

/*

template< typename Func >
void applyFunction(int x, int y, Func func) {
    std::cout << "Result: " << func(x, y) << "\n";
}

int main() {
    applyFunction(
          10, 5, [](int a, int b) { return a * b; });  // Outputs: 50
    return 0;
}

*/


// ___________________________________________________________________________

// 10. Storing Lambdas in std::function
// If a lambda has complex captures, you can store it using std::function:

/*
#include <iostream>
#include <functional>

int main() {
    int factor = 10;
    std::function<int(int)> multiply = [factor](int num)
    { return num * factor; };

    std::cout << multiply(5) << "\n";  // Outputs: 50
    return 0;
}
*/


// ___________________________________________________________________________

// 11. Returning Lambdas from Functions
// A function can return a lambda:

/*

#include <iostream>
#include <functional>

std::function<int(int)> createMultiplier(int factor) {
    return [factor](int num) { return num * factor; };
}

int main() {
    auto doubleIt = createMultiplier(2);
    std::cout << doubleIt(5) << "\n";  // Outputs: 10
    return 0;
}

*/
