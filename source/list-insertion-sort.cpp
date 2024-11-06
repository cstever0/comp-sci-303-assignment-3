#include <iostream>
#include <list>
#include "../headers/list-insertion-sort.h"

using namespace std;

// function definition for insertion_sort on a list
void insertion_sort(list<int>& my_list) {
    // start from 2nd element and loop to the end
    for (auto it = next(my_list.begin()); it != my_list.end(); ++it) {
        int value = *it;
        auto insert_pos = it;

        // find insert_pos where value should be inserted
        auto previous = prev(it);
        while (insert_pos != my_list.begin() && value < *previous) {
            *insert_pos = *previous;
            insert_pos = previous;

            if (insert_pos != my_list.begin()) {
                previous = prev(insert_pos);
            }
        }

        // place value in correct position
        *insert_pos = value;
    }
}
