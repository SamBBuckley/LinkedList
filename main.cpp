#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    //Example 1
    LinkedList ll = LinkedList(18);
    ll.push_back(7);
    ll.push_back(15);
    ll.push_back(27);
    cout << "List before reversal:" << endl;
    ll.print();
    
    cout << endl << endl; // Prettier Output

    cout << "List after reversal:" << endl;
    ll.reverse();
    ll.print();

    return 0;
}

