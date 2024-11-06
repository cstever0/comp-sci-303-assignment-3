#ifndef MY_QUEUE_H
#define MY_QUEUE_H
#include <iostream>

using namespace std;

template<typename Item_Type>
class My_Queue {
private:
    struct Node {
        Item_Type data;
        Node* next;

        Node(const Item_Type& item_data, Node* next_node = nullptr);
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    My_Queue();
    ~My_Queue();

    void push(const Item_Type& item);
    void pop();
    const Item_Type& front() const;
    int size();
    bool empty() const;
    void move_to_rear();
    void display();
};


#endif
