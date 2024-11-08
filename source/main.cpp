#include <iostream>
#include <vector>
#include <list>
#include "../headers/my-queue.h"
#include "../headers/recursive-linear-search.h"
#include "../headers/list-insertion-sort.h"
#include "./my-queue.cpp"
#include "./recursive-linear-search.cpp"
#include "./list-insertion-sort.cpp"


using namespace std;

int main() {
    My_Queue<int> example;

    cout << "QUESTION 1 \n" << endl;

    // pushing the values 1 through 10 to the queue
    for (int i = 1; i <= 10; ++i) {
        example.push(i);
    }

    // printing the front of the queue
    try {
        cout << "Front: " << example.front() << endl;
    } catch (out_of_range err) {
        cerr << err.what() << endl;
    }

    // demonstrating the pop function
    try {
        example.pop();
        cout << "Front value after popping: " << example.front() << endl;
    } catch (out_of_range err) {
        cerr << err.what() << endl;
    }

    // demonstrating the size function
    cout << "Size of the Queue: " << example.size() << endl;

    // demonstrating the empty function
    cout << "True(1) if empty otherwise false(0): " << example.empty() << endl;

    // demonstrating the display function
    cout << "Displaying the Queue: ";
    example.display();

    // demonstrating the move_to_rear function
    example.move_to_rear();
    cout << "Queue after moving to rear: ";
    example.display();

    cout << "\n\nQUESTION 2 \n" << endl;

    // demonstrating the functionality of recursive_linear_search_last searching for a target of 4
    vector<int> vector_example = {1, 3, 5, 4, 2, 7, 8, 4, 10, 11, 12};
    int target = 4;
    int last_position = recursive_linear_search_last(vector_example, target, vector_example.size() - 1);

    cout << "The values to be searched: ";

    for (int i = 0; i < vector_example.size(); ++i) {
        cout << vector_example[i] << " ";
    }
    cout << endl;

    if (last_position != -1) {
        cout << "The last occurrence of the target: " << target << " is at index: " << last_position << endl;
    } else {
        cout << "The target: " << target << " was not found." << endl;
    }


    cout << "\n\nQUESTION 3 \n" << endl;

    // demonstrating the functionality of insertion_sort being called on a list
    list<int> example_list = {4, 3, 2, 8, 5, 6, 7, 10, 9, 1};
    cout << "Original List Order: ";

    for (int ele : example_list) {
        cout << ele << " ";
    }
    cout << endl;

    insertion_sort(example_list);

    cout << "List After Sorting: ";

    for (int ele : example_list) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
