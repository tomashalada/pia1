// 1. Sorting with std::sort()
// Use a lambda function to define a custom sorting order.

/*

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {5, 2, 8, 1, 3};

    // Sort in descending order using a lambda function
    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });

    for (int num : nums)
        std::cout << num << " ";  // Output: 8 5 3 2 1

    return 0;
}

*/

// ___________________________________________________________________________

// 2. Filtering with std::remove_if()
// Remove elements from a collection based on a condition
// -> note_erase.cpp

/*

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {5, 2, 8, 1, 3, 10, 7};

    // Remove all even numbers
    nums.erase(std::remove_if(nums.begin(), nums.end(),
               [](int n) { return n % 2 == 0; }), nums.end());

    for (int num : nums)
        std::cout << num << " ";  // Output: 5 1 3 7

    return 0;
}

*/

// ___________________________________________________________________________

// 3. Using std::for_each()
// Apply an operation to each element in a collection.

/*

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    // Print each element
    std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << " "; });

    return 0;
}

*/

// ___________________________________________________________________________

// 4. Transforming Data with std::transform()
// Modify elements in a collection and store results in another collection.

/*

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> squared(nums.size());

    // Square each element
    std::transform(nums.begin(), nums.end(), squared.begin(), [](int n) { return n * n; });

    for (int num : squared)
        std::cout << num << " ";  // Output: 1 4 9 16 25

    return 0;
}

*/

// ___________________________________________________________________________

// 5. Counting Elements with std::count_if()
// Count elements that meet a condition.

/*

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};

    // Count even numbers
    int count = std::count_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; });

    std::cout << "Even numbers count: " << count << "\n";  // Output: 3

    return 0;
}

*/

// ___________________________________________________________________________

// 6. Finding an Element with std::find_if()
// Find the first element that meets a condition.

/*

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 3, 7, 10, 2};

    // Find the first even number
    auto it = std::find_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; });

    if (it != nums.end())
        std::cout << "First even number: " << *it << "\n";  // Output: 10

    return 0;
}

*/

// ___________________________________________________________________________

// 7. Using std::all_of(), std::any_of(), std::none_of()
// Check if all, any, or none of the elements satisfy a condition.

/*

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {2, 4, 6, 8};

    bool allEven = std::all_of(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; });
    bool anyOdd = std::any_of(nums.begin(), nums.end(), [](int n) { return n % 2 != 0; });
    bool noneNegative = std::none_of(nums.begin(), nums.end(), [](int n) { return n < 0; });

    std::cout << "All even? " << allEven << "\n";     // Output: 1 (true)
    std::cout << "Any odd? " << anyOdd << "\n";       // Output: 0 (false)
    std::cout << "None negative? " << noneNegative << "\n";  // Output: 1 (true)

    return 0;
}

*/

// ___________________________________________________________________________

// 8. Custom Comparator in std::map
// Use a lambda as a custom sorting rule.

#include <iostream>
#include <map>

int main() {
    auto cmp = [](const std::string &a, const std::string &b) { return a.length() < b.length(); };
    std::map<std::string, int, decltype(cmp)> wordLengthMap(cmp);

    wordLengthMap["slovo"] = 5;
    wordLengthMap["program"] = 6;
    wordLengthMap["auto"] = 4;

    for (const auto &p : wordLengthMap)
        std::cout << p.first << ": " << p.second << "\n";

    return 0;
}
