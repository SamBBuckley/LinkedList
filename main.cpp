#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    //Example 1
    LinkedList ll1 = LinkedList(18);
    ll1.push_back(7);
    ll1.push_back(15);
    ll1.push_back(27);
    cout << "List 1 before removal:" << endl;
    ll1.print();
    cout << "List 1 after removal:" << endl;
    ll1.removeMax();
    ll1.print();

    cout << endl << endl;
    
    //Example 2
    LinkedList ll2 = LinkedList(48);
    ll2.push_back(7);
    ll2.push_back(48);
    ll2.push_back(48);
    cout << "List 2 before removal:" << endl;
    ll2.print();
    cout << "List 2 after removal:" << endl;
    ll2.removeMax();
    ll2.print();


    return 0;
}