#include <iostream>
#include "Node.h"

//////////////////////////////////////////////////////////////////////////////
//  A simple decleration of a LinkedList this one will only use integers    //
//  However it could be made more abstract by using 'typing'                //
//////////////////////////////////////////////////////////////////////////////
class LinkedList {
    Node* head;
    Node* tail;
    unsigned int size;
public:
    //My Constructors
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    LinkedList(int value);

    //Big Three
    LinkedList(const LinkedList& ll); // Where ll is a LinkedList
    LinkedList& operator=(const LinkedList& rhs); // Where rhs is the LinkedList on the right side of =
    ~LinkedList();

    //Helper Functions
    void clear();
    void push_back(int value);

    //Public functions
    void push_in_order(int value);
    void print();

private:
//Private Helper Functions
    void copy(const LinkedList& src);
};

//////////////////////////////////////////////////////////////////////////////
//                       Decleration of Helper Functions                    //
//////////////////////////////////////////////////////////////////////////////
void LinkedList::copy(const LinkedList& src) {
    Node* srcCur = src.head;
    Node* cur = head;
    while(srcCur != nullptr) {
        Node* newNode = new Node(srcCur->value);
        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            cur->next = newNode;
        }
        cur = cur->next;
        tail = newNode;
        srcCur = srcCur->next;
    }
    size = src.size;
}

void LinkedList::clear() {
    Node* delNode = nullptr;
    while(head != nullptr) {
        delNode = head;
        head = head->next;
        delete delNode;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        this->tail = newNode;
    }
    this->size += 1;
}

//////////////////////////////////////////////////////////////////////////////
//                         Decleration of all constructors                  //
//////////////////////////////////////////////////////////////////////////////
LinkedList::LinkedList(int value) :
    head(nullptr), tail(nullptr), size(0) {
        push_back(value);
    }

//////////////////////////////////////////////////////////////////////////////
//                          Decleration of the Big Three                    //
//////////////////////////////////////////////////////////////////////////////
LinkedList::LinkedList(const LinkedList& ll) {
    copy(ll);
}

LinkedList& LinkedList::operator=(const LinkedList& rhs) {
    if(this != &rhs) {
        clear();
        copy(rhs);
    }
    return *this;
}

LinkedList::~LinkedList() {
    clear();
}


//////////////////////////////////////////////////////////////////////////////
//                          Decleration of public functions                 //
//////////////////////////////////////////////////////////////////////////////
void LinkedList::push_in_order(int value) { // This function will allow for you to push a new node of value 'value' into the list in assending order

    Node* newNode = new Node(value);
    if(head == nullptr) { // BaseCase 1, if there is nothing in the list.
        newNode->next = head;
        head = newNode;
        return;
    } else if(value <= head->value) { // BaseCase 2, the value of 'value' is less than or equal that of head 
        newNode->next = head;
        head = newNode;
        return;
    } else { // Base Case 3 and 4, 'newNode' belongs at end or within the LinkedList
        Node* current = head;

        while(current->next != nullptr && current->next->value < newNode->value) {
            current = current->next; // Shift down linked list
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void LinkedList::print() {
    if(head == nullptr) {
        std::cout << "List empty" << std::endl;
        return;
    }
    Node* cur = head;
    while(cur != nullptr) {
        std::cout << cur->value << "->";
        cur = cur->next;
    }
    std::cout << std::endl;
}
