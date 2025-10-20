
/*
return_type function_name(parameter_type1 parameter1, parameter_type2 parameter2, ...) {
    // Code to execute
    return value;  // If return type is not void
}

*/

#include <iostream>  //

// Function definition
void
sayHello()
{
    std::cout << "Hello, World!" << std::endl;
}

int main() {

    // calling the function
    sayHello();

    // call it multiple times
    sayHello();
    sayHello();

    return 0;
}
