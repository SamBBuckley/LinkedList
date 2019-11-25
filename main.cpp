#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    //Example 1
    cout << "Example 1:" << endl;
    LinkedList ll = LinkedList(18);
    ll.push_back(7);
    ll.push_back(15);
    ll.push_back(27);

    cout << "Current List 1:" << endl;
    ll.print();
    cout << "List 1 Middle:" << endl;
    Node* mid = ll.findMiddle();
    cout << mid->value << endl;

    //Example 2
    cout << endl << endl << "Example 2:" << endl;
    LinkedList ll1 = LinkedList(18);
    ll1.push_back(7);
    ll1.push_back(15);
    ll1.push_back(27);
    ll1.push_back(24);
    cout << "Current List 2:" << endl;
    ll.print();
    cout << "List 2 Middle:" << endl;
    Node* mid2 = ll1.findMiddle();
    cout << mid2->value << endl;

    return 0;
}