#include <iostream>
#include "../headers/my-queue.h"

using namespace std;

// Constructor
template <typename Item_Type>
My_Queue<Item_Type>::My_Queue() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor for deleting the queue
template <typename Item_Type>
My_Queue<Item_Type>::~My_Queue() {
    while (!empty()) {
        pop();
    }
}

// Push function to add an element to the rear of the queue
template <typename Item_Type>
void My_Queue<Item_Type>::push(const Item_Type& item) {
    Node* newNode = new Node(item);

    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }

    tail = newNode;
    ++num_items;
}

// Pop function to remove an element from the front of the queue
template <typename Item_Type>
void My_Queue<Item_Type>::pop() {
    try {
        if (empty()) {
            throw out_of_range("Queue is Empty!");
        } else {
            Node* temp = head;
            head = head->next;

            if (!head) {
                tail = nullptr;
            }

            delete temp;
            --num_items;
        }
    } catch (out_of_range err) {
        cerr << err.what() << endl;
    }
}

// function for returning the value at the front of the queue
template<typename Item_Type>
const Item_Type& My_Queue<Item_Type>::front() const{
    try {
        if (!empty()) {
            return head->data;
        } else {
            throw out_of_range("List is empty!");
        }
    } catch (out_of_range err) {
        cerr << err.what() << endl;
    }
}
