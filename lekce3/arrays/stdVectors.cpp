#include <vector>
#include <iostream>

int main() {
    // 1. Declaration and Initialization
    std::vector<int> vec1 = {1, 2, 3}; // Initialize with values
    std::vector<int> vec2(3, 0);      // Size 3, all elements 0
    std::vector<int> vec3;            // Empty vector
    std::cout << "1. Initialization: vec1[0]=" << vec1[0]
              << ", vec2[0]=" << vec2[0]
              << ", vec3.size()=" << vec3.size() << '\n';

    // 2. Accessing Elements
    std::vector<int> vec4 = {10, 20, 30};
    std::cout << "2. Access: vec4[0]=" << vec4[0]
              << ", vec4.at(1)=" << vec4.at(1)
              << ", front=" << vec4.front()
              << ", back=" << vec4.back() << '\n';

    // 3. Size and Capacity
    std::vector<int> vec5 = {1, 2, 3, 4};
    std::cout << "3. Size/Capacity: size=" << vec5.size()
              << ", capacity=" << vec5.capacity()
              << ", empty=" << vec5.empty()
              << ", max_size=" << vec5.max_size() << '\n';

    // 4. Dynamic Resizing
    std::vector<int> vec6;
    vec6.push_back(1); // Add element
    vec6.push_back(2);
    vec6.pop_back();   // Remove last element
    vec6.resize(3, 0); // Resize to 3, fill new elements with 0
    vec6.reserve(10);  // Reserve capacity for 10 elements
    std::cout << "4. Resizing: size=" << vec6.size()
              << ", capacity=" << vec6.capacity() << ", vec6[1]=" << vec6[1] << '\n';

    // 5. Iterators
    std::vector<int> vec7 = {1, 2, 3};
    std::cout << "5. Iterators: ";
    for (auto it = vec7.begin(); it != vec7.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "| Reverse: ";
    for (auto rit = vec7.rbegin(); rit != vec7.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << '\n';

    // 6. Insert and Erase
    std::vector<int> vec8 = {1, 2, 3};
    vec8.insert(vec8.begin() + 1, 99); // Insert 99 at index 1
    vec8.erase(vec8.begin());          // Erase first element
    std::cout << "6. Insert/Erase: ";
    for (int x : vec8) std::cout << x << " ";
    std::cout << '\n';

    // 7. Clearing
    std::vector<int> vec9 = {1, 2, 3};
    vec9.clear();
    std::cout << "7. Clear: size=" << vec9.size() << '\n';

    // 8. Swapping
    std::vector<int> vec10a = {1, 2, 3};
    std::vector<int> vec10b = {4, 5, 6};
    vec10a.swap(vec10b);
    std::cout << "8. Swap: vec10a=";
    for (int x : vec10a) std::cout << x << " ";
    std::cout << '\n';

    // 9. Comparison Operators
    std::vector<int> vec11a = {1, 2, 3};
    std::vector<int> vec11b = {1, 2, 4};
    std::cout << "9. Comparison: vec11a<vec11b=" << (vec11a < vec11b)
              << ", vec11a==vec11b=" << (vec11a == vec11b) << '\n';

    // 10. Structured Bindings (C++17, with fixed-size vector)
    std::vector<int> vec12 = {10, 20, 30};
    auto [a, b, c] = std::array<int, 3>{vec12[0], vec12[1], vec12[2]}; // Using array for binding
    std::cout << "10. Structured Bindings: " << a << " " << b << " " << c << '\n';

    // 11. Direct Data Access
    std::vector<int> vec13 = {1, 2, 3};
    int* ptr = vec13.data();
    std::cout << "11. Data: ptr[1]=" << ptr[1] << '\n';

    // 12. Range-Based For Loop
    std::vector<int> vec14 = {1, 2, 3};
    std::cout << "12. Range-Based For: ";
    for (int x : vec14) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    // 13. emplace_back (C++11)
    std::vector<std::pair<int, int>> vec15;
    vec15.emplace_back(1, 2); // Construct pair in-place
    std::cout << "13. emplace_back: " << vec15[0].first << "," << vec15[0].second << '\n';

    return 0;
}
