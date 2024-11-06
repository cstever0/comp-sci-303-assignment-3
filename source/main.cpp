#include <iostream>
#include "../headers/my-queue.h"
#include "./my-queue.cpp"


using namespace std;

int main() {
    My_Queue<int> example;

    cout << "QUESTION 1 \n" << endl;

    // pushing the values 1 through 10 to the queue
    for (int i = 1; i <= 10; ++i) {
        example.push(i);
    }

    // printing the front of the queue
    cout << "Front: " << example.front() << endl;

    // demonstrating the pop function
    example.pop();
    cout << "Front value after popping: " << example.front() << endl;

    // demonstrating the size function
    cout << "Size of the Queue: " << example.size() << endl;

    // demonstrating the empty function
    cout << "True if empty otherwise false: " << example.empty() << endl;

    // demonstrating the display function
    cout << "Displaying the Queue: ";
    example.display();

    // demonstrating the move_to_rear function
    example.move_to_rear();
    cout << "Queue after moving to rear: ";
    example.display();

    return 0;
}
