#ifndef LAB_1_C___REVIEW_TODOLIST_H
#define LAB_1_C___REVIEW_TODOLIST_H
#include <unordered_map>
#include <string>
#include <vector>

#include "TodoListInterface.h"

using namespace std;

class TodoList : public TodoListInterface {
    // keys are strings and values are vectors
    unordered_map<string, vector<string>> list;
public:

    // constructor
    TodoList() {
        // read file
        
        // put into `list`
    }
    void add(string day, string task) {

    }

    int remove(string task) {

    }

    void printTodoList() {

    }

    void printDaysTasks(string day) {

    }

    // destructor
    ~TodoList() {
        // write `list` to file


        delete[] list;
    }
};
#endif
