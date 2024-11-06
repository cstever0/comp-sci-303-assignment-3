#include <iostream>
#include <vector>
#include "../headers/recursive-linear-search.h"

using namespace std;

// Simple function for finding the last occurrence of an item in a vector
template <typename Item_Type>
int recursive_linear_search_last(vector<Item_Type>& items, Item_Type& target, size_t pos_last) {
// Base case: If the index is out of bounds, return -1 (not found)
    if (pos_last < 0) {
        return -1;
    }

    // Check if the current element is the target
    if (items[pos_last] == target) {
        return pos_last;  // Return the index if found
    }

    // Recursive step: search in the rest of the array (from the end)
    return recursive_linear_search_last(items, target, pos_last - 1);
}
