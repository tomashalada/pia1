# Compiler
CXX = g++

# CXXFLAGS → Stores compiler options:
# -Wall → Enables warnings.
# -Wextra → Enables additional warnings.
# -std=c++17 → Uses C++17 standard.
CXXFLAGS = -Wall -Wextra -std=c++17 -O3

# Target executable
# TARGET → Defines the name of the output executable.
TARGET = my_program

# Source and Object files
# SRCS → Stores all source files.
# If there were multiple files, they would be listed:
#SRCS = main.cpp math_functions.cpp

# Use all files
SRCS = $(wildcard *.cpp)


# Pattern substitution:
# Converts *.cpp to *.o.
# main.cpp → main.o.
# If there were more files (utils.cpp → utils.o).
OBJS = $(SRCS:.cpp=.o)

# Build rule
# A rule tells make how to compile the code.

# $(TARGET): This means "Build my_program".
# Dependencies: $(OBJS) (all .o files).
# Command ($(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS))
# Calls the compiler (g++).
# -o $(TARGET) → Sets the output file to my_program.
# $(OBJS) → Adds all object files.
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
# %.o: %.cpp → A pattern rule:
# Any .cpp file (%.cpp) will be compiled to an .o file (%.o).
# $< → Input file (the .cpp file).
# $@ → Output file (the .o file).
# Command ($(CXX) $(CXXFLAGS) -c $< -o $@)
# -c → Compile without linking (produces .o files).
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
# rm -f → Removes compiled files (my_program and .o files).
clean:
	rm -f $(TARGET) $(OBJS)

# Run rule
run: $(TARGET)
	./$(TARGET)
