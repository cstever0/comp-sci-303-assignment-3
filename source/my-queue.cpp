#include <iostream>
#include "../headers/my-queue.h"

using namespace std;

// this is the constructor for my Node
template<typename Item_Type>
My_Queue<Item_Type>::Node::Node(const Item_Type& item_data, Node* next_node) : data(item_data), next(next_node) {}

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

// Function for returning the value at the front of the queue
template <typename Item_Type>
const Item_Type& My_Queue<Item_Type>::front() const {
    if (empty()) {
        throw out_of_range("Queue is empty!");
    }
    return head->data;
}

// Size function for returning number of items in the queue
template <typename Item_Type>
int My_Queue<Item_Type>::size() {
    return num_items;
}

// Empty function that returns true if the queue is empty otherwise false
template <typename Item_Type>
bool My_Queue<Item_Type>::empty() const {
    return num_items == 0;
}

// Function for moving the front of the queue to the rear of the queue
template <typename Item_Type>
void My_Queue<Item_Type>::move_to_rear() {
    if (size() <= 1) {
        return;
    } else {
        Item_Type front_item = front();
        pop();
        push(front_item);
    }
}

template <typename Item_Type>
void My_Queue<Item_Type>::display() {
    int length = size();

    for (int i = 0; i < length; ++i) {
        Item_Type front_item = front();
        cout << front_item << " ";
        move_to_rear();
    }

    cout << endl;
}
