#include <iostream>
#include <list>
#include "../headers/list-insertion-sort.h"

using namespace std;

// function definition for insertion_sort on a list
template <typename Item_Type>
void insertion_sort(list<Item_Type>& my_list) {
    // start from 2nd element and loop to the end
    for (Item_Type it = next(my_list.begin()); it != my_list.end; ++it) {
        Item_Type value = *it;
        Item_Type insert_pos = it;

        // find insert_pos where value should be inserted
        Item_Type prev = prev(it);
        while (insert_pos != my_list.begin() && value < *prev) {
            *insert_pos = *prev;
            insert_pos = prev;

            if (insert_pos != num.begin()) {
                prev = prev(insert_pos);
            }
        }

        // place value in correct position
        *insert_pos = value;
    }
}
