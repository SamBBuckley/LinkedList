#include "Node.h"

//////////////////////////////////////////////////////////////////////////////
//  A simple decleration of a LinkedList this one will only use integers    //
//  However it could be made more abstract by using 'typing'                //
//////////////////////////////////////////////////////////////////////////////
class LinkedList {

public:
    //My Constructors
    LinkedList();
    LinkedList(int value);

    //Big Three
    LinkedList(const LinkedList& ll); // Where ll is a LinkedList
    LinkedList& operator=(const LinkedList& rhs); // Where rhs is the LinkedList on the right side of =
    ~LinkedList();
    //Helper Functions
    void clear();
    void push_back(int value);

    //Public functions
    Node* getFront() { return this->head; }
    Node* getBack() {return this->tail; }
    int getSize() { return this->size; }

private:
    Node* head;
    Node* tail;
    int size;
};

//////////////////////////////////////////////////////////////////////////////
//                       Decleration of Helper Functions                    //
//////////////////////////////////////////////////////////////////////////////
void LinkedList::clear() {
    if(this->getFront() == nullptr) {
        return;
    }
    Node* n = this->getFront();
    while(n != nullptr) {
        Node* nextNode = n->next;
        n->next = nullptr;
        delete n;
        n = nextNode;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

void LinkedList::push_back(int value) {
    Node newNode = Node(value);
    if(this->head == nullptr) {
        this->head = &newNode;
        this->tail = &newNode;
        this->size = 1;
        return;
    } else {
        this->tail->next = &newNode;
        this->tail = &newNode;
    }
}

//////////////////////////////////////////////////////////////////////////////
//                         Decleration of all constructors                  //
//////////////////////////////////////////////////////////////////////////////
LinkedList::LinkedList() :
    head(nullptr), tail(nullptr), size(0) {}

LinkedList::LinkedList(int value) :
    head(nullptr), tail(nullptr), size(0) {
        Node n = Node(value);
        this->head = &n;
        this->tail = &n;
        this->size = 1;
    }

//////////////////////////////////////////////////////////////////////////////
//                          Decleration of the Big Three                    //
//////////////////////////////////////////////////////////////////////////////
LinkedList::LinkedList(const LinkedList& ll) {
    this->clear();
    Node* n = ll.head;
    while(n != nullptr) {
        push_back(n->value);
        n = n->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& rhs) {
     this->clear();
    Node* n = rhs.head;
    while(n != nullptr) {
        push_back(n->value);
        n = n->next;
    }
}

LinkedList::~LinkedList() {
    clear();
    delete this;
}


//////////////////////////////////////////////////////////////////////////////
//                          Decleration of public functions                 //
//                          For now all defined above.                      //
//////////////////////////////////////////////////////////////////////////////

