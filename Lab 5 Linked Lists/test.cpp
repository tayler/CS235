#include <iostream>

#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {

//    LinkedList<int> linkedList{};
//    linkedList.insertHead(1);
//    linkedList.insertHead(2);
//    linkedList.insertHead(3);
//    linkedList.insertHead(4);
//    linkedList.insertHead(5);

//    LinkedList<string> linkedList{};
//    linkedList.insertHead("1");
//    linkedList.insertHead("2");
//    linkedList.insertHead("3");
//    linkedList.insertHead("4");
//    linkedList.insertHead("5");
//    // skipped b/c already exists
//    linkedList.insertHead("5");
//    linkedList.insertAfter("1.5", "2");
//    cout << linkedList.toString() << endl;
//    linkedList.remove("2");
//
//    cout << linkedList.toString() << endl;

//        LinkedList<int> linkedList{};
//        linkedList.insertTail(1);
//        linkedList.insertTail(2);
//        linkedList.insertTail(3);
//        linkedList.insertTail(4);
//        linkedList.insertTail(5);
//        // skipped b/c already exists
//        linkedList.insertTail(5);
//
//        cout << linkedList.at(1) << endl;
//        cout << linkedList.toString();
//        insertTail Combing
//        insertTail Coming
//        insertTail front
//        size 3
//        printList
    LinkedList<string> ll{};
    ll.insertTail("Combing");
    ll.remove("Combing");
    ll.insertTail("Combing");
    ll.insertTail("Coming");
    ll.insertTail("front");
    cout << "size: " << ll.size();
        cout << ll.toString() << endl;

        return 0;
    }
    catch (exception &e) {
        return 1;
    }
}