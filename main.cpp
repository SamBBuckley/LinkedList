#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList ll = LinkedList(18);
    ll.push_back(7);
    ll.push_back(15);
    ll.push_back(27);

    cout << "Current List:" << endl;
    ll.print();
    cout << "List average:" << endl;
    float average = ll.getAverage();
    cout << average << endl;

    return 0;
}

