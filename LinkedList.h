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
    void print();
    float getAverage();
    void removeMax();
    void reverse();


private:
//Private Helper Functions
    void copy(const LinkedList& src);
    Node* find(int value);
    void remove(int value);
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

Node* LinkedList::find(int value) {
    Node* cur = head;
    while(cur != nullptr) {
        if(cur->value == value) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

void LinkedList::remove(int value) {
    if(head == nullptr) { // If nothing in list
        return;
    }
    Node* delNode = find(value);
    if(delNode == nullptr) { // If not found in list
        return; 
    }

    if(head->value == value) { // If the head is the value to remove
        delNode = head;
        head = head->next;
        delete delNode;
        size--;
        return;
    }

    Node* prevNode = head;
    while(prevNode != nullptr && prevNode->next != delNode) {
        prevNode = prevNode->next;
    }

    if(prevNode == nullptr) {
        head = nullptr;
        tail = nullptr;
    } else {
        prevNode->next = delNode->next;
        if(prevNode->next == nullptr) {
            tail = prevNode;
        }
    }

    delete delNode;
    size -= 1;
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
float LinkedList::getAverage() {
    if(head == nullptr) {
        return -1; // Error as there is nothing in the list
    }

    int count = 0, sum = 0;

    Node* cur = head;
    while(cur != nullptr) {
        count++;
        sum += cur->value;
        cur = cur->next;
    }
    return (float) sum / count;
}

void LinkedList::removeMax() {
    if(head == nullptr) { // Can't do anything if there are no values.
        return;
    }

    int max = head->value;
    Node* cur = head;
    while(cur != nullptr) { //Find the max
        if(cur->value > max) {
            max = cur->value;
        }
        cur = cur->next;
    }
    //Remove all values that are the max.
    //Helper function remove() and find() added
    while(find(max) != nullptr) {
        remove(max);
    }
}

void LinkedList::reverse() {
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    
    //This looks confusing. But basically we are getting the pointer on the other side of each Node
    //And setting the value of the points Node within the node to the one behind it.
    //With the first value having a nullpointer after it making it the tail.

    while(current != nullptr) { //While a value remains in the list
        next = current->next; // Get the next node
        current->next = prev; // Set this into our temporary prev holder.

        prev = current; //Set the previous to the current
        if(prev == nullptr) { // This will happen to the head essentially. Making it the tail.
            tail = current;
        }
        current = next; // Continue through the LinkedList
    }
    head = prev;
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
