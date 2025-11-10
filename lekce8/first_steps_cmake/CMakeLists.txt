cmake_minimum_required(VERSION 3.10)
project(MyProgram)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source files
 set(SOURCES main.cpp math_functions.cpp)

# Find all the files automatically
#file(GLOB SOURCES "*.cpp")

# Create executable
add_executable(my_program ${SOURCES})

# Options
# cmake -DCMAKE_BUILD_TYPE=Debug ..
# Ninja instead of make
# cmake -DCMAKE_BUILD_TYPE=Debug ..
