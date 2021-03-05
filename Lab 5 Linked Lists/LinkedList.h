#ifndef LAB_5_LINKED_LISTS_LINKEDLIST_H
#define LAB_5_LINKED_LISTS_LINKEDLIST_H

// cout
#include <iostream>
// out_of_range
#include <stdexcept>
// is_same
#include <type_traits>
// to_string
#include <string>
// stringstream
#include <sstream>

#include "LinkedListInterface.h"
using namespace std;
template <typename ItemType>

class LinkedList: public LinkedListInterface<ItemType> {
private:
    struct Node {
        ItemType value;
        Node* next;
        // `Node` constructor
        Node(const ItemType& data, Node* next_val = NULL): value(data) {next = next_val;}
    };
    Node *ll;
public:
    Node* head;
    int count;
    LinkedList() {
        ll = NULL;
        count = 0;
    };

    void insertHead(ItemType value) {
        if (ll == NULL) {
            ll = new Node(value, NULL);
            head = ll;
        }
        else {
            // skip if the value exists already
            if (find(value) == true) {
                return;
            }
            // create a new node pointing to current head
            Node *newHead = new Node(value, head);
            // head becomes newHead
            head = newHead;
        }
        count++;
    }

    void insertTail(ItemType value) {
        if (ll == NULL) {
            ll = new Node(value, NULL);
            head = ll;
        }
        else {
            // skip if the value exists already
            if (find(value) == true) {
                return;
            }
            Node *current = head;
            while (current != NULL) {
                // iterate from `head` until we find the final node
                if (current->next == NULL) {
                    Node *newTail = new Node(value, NULL);
                    current->next = newTail;
                    break;
                }
                current = current->next;
            }
        }
        count++;
    }

    void insertAfter(ItemType value, ItemType searchValue) {
        if (ll == NULL) {
            ll = new Node(value, NULL);
            head = ll;
        }
        else {
            if (find(value) == true) {
                return;
            }
            Node *current = head;
            while (current != NULL) {
                if (current->value == searchValue) {
                    // create a new node pointing to the next node
                    Node *newNode = new Node(value, current->next);
                    // point the current node to the new node
                    current->next = newNode;
                    count++;
                    break;
                }
                current = current->next;
            }
        }
    }

    void remove(ItemType value) {
        if (ll == NULL || find(value) == false) {
            return;
        }
        Node *current = head;
        Node *previous = NULL;
        while (current != NULL) {
            if (current->value == value) {
                // point the previous next to the current node's next
                if (previous == NULL) {
                    cout << "current->next: " << current->next << endl;
                    // when removing the first item, just update head
                    if (current->next == NULL) {
                        head = NULL;
                    }
                    else {
                        head = current->next;
                    }
                }
                else {
                    previous->next = current->next;
                }
//                delete current;
                count--;
                break;
            }
            previous = current;
            current = current->next;
        }
    }

    void clear() {
        while (ll != NULL) {
            // start at the beginning of the list and delete all of the Nodes
            Node *current = ll;
            ll = ll->next;
            delete current;
        }
        ll = NULL;
        count = 0;
    }

    ItemType at(int index) {
        if (index >= count || index < 0) {
            throw out_of_range("`at` error");
        }
        else {
            int idx = 0;
            Node *current = head;
            while (idx < index) {
                current = current->next;
                idx++;
            }
            return current->value;
        }
    }

    int size() {
        return count;
    }

    string toString() {
        stringstream ss;
        if (ll != NULL) {
            Node *current = head;
            while (current != NULL) {
                ss << current->value;
                if (current->next != NULL) {
                    ss << " ";
                }
                current = current->next;
            }
        }

        return ss.str();
    }

    int find(const ItemType& value) {
        Node *current = head;
        while (current != NULL) {
            if (current->value == value) {
                return true;
            }
            if (current->next == NULL) {
                return false;
            }
            current = current->next;
        }
        return false;
    }

    // destructor
    ~LinkedList() {
        // The key word "delete" is used to release space that was allocated with "new"
        clear();
    }
};

#endif //LAB_5_LINKED_LISTS_LINKEDLIST_H
