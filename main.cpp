#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    cout << "Find average Examples:" << endl << "Example 1:" << endl;
    //Find Average Example 1
    LinkedList ll = LinkedList(18);
    ll.push_back(7);
    ll.push_back(15);
    ll.push_back(27);

    cout << "Current List:" << endl;
    ll.print();
    cout << "List average:" << endl;
    float average = ll.getAverage();
    cout << average << endl;


    cout << endl << endl << endl << "Remove Max Examples:" << endl << "Example 1:" << endl;
    //Remove Max Example 1
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
    cout << "Example 2:" << endl;
    //Remove Max Example 2
    LinkedList ll2 = LinkedList(48);
    ll2.push_back(7);
    ll2.push_back(48);
    ll2.push_back(48);
    cout << "List 2 before removal:" << endl;
    ll2.print();
    cout << "List 2 after removal:" << endl;
    ll2.removeMax();
    ll2.print();


    //Reverse List Example 1
    cout << endl << endl << endl << "Reverse List Examples:" << endl << "Example 1:" << endl;
    LinkedList ll3 = LinkedList(18);
    ll3.push_back(7);
    ll3.push_back(15);
    ll3.push_back(27);
    cout << "List before reversal:" << endl;
    ll3.print();
    cout << "List after reversal:" << endl;
    ll3.reverse();
    ll3.print();

    return 0;
}