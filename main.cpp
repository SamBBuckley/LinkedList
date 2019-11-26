#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    //Example 1.
    cout << "Push in order examples:" << endl << "Example 1:" << endl;
    LinkedList ll1 = LinkedList(1);
    ll1.push_back(2);
    ll1.push_back(4);
    ll1.push_back(5);
    cout << "List before the push back of (3)" << endl;
    ll1.print();
    cout << "List after the push back of (3)" << endl;
    ll1.push_in_order(3);
    ll1.print();

    return 0;
}