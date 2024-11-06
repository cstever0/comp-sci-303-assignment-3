#ifndef RECURSIVE_LINEAR_H
#define RECURSIVE_LINEAR_H
#include <iostream>
#include <vector>

using namespace std;

// function declaration for recursive linear search of last item in a vector
template <typename Item_Type>
int recursive_linear_search_last(vector<Item_Type>& items, Item_Type& target, size_t pos_last);

#endif
