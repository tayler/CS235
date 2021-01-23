#ifndef LAB_1_C___REVIEW_TODOLIST_H
#define LAB_1_C___REVIEW_TODOLIST_H
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "TodoListInterface.h"

using namespace std;

class TodoList : public TodoListInterface {
    // keys are strings and values are vectors
private:
    map<string, vector<string>> theList;
    set<string> weekdays = {"Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday","Saturday"};
    ifstream todoFile;
    string fileName;
public:
    // constructor
    TodoList() {
        // read file
        fileName = "TODOList.txt";
        todoFile.open(fileName);
        if (!todoFile.is_open()) {
            cout << "Could not open file" << endl;
        } else {
            // each line contains one day and its tasks
            // iterate through each line, then through each word in the line
            string dayOrTask;
            string day;
            // reading each line: https://stackoverflow.com/a/55029247/1067590
            // each line is either a day or a task
            while (getline(todoFile, dayOrTask)) {
                if (weekdays.find(dayOrTask) != weekdays.end()) {
                    day = dayOrTask;
                    theList[day] = vector<string>();
                }
                else {
                    theList[day].push_back(dayOrTask);
                }
            }
            // TODO: maybe move this to destructor
            todoFile.close();
        }
    }

    void add(string day, string task) {
        theList[day].push_back(task);
    }

    int remove(string taskToRemove) {
        auto it = theList.begin();
        // go through each key in the list
        while (it != theList.end()) {
            vector<string> newVec;
            string day = it->first;
            vector<string> tasks = it->second;

            // for each task, see if it is the one marked for removal
            for (size_t i = 0; i < tasks.size(); i++) {
                if (taskToRemove == tasks[i]) {
                    continue;
                }

                // if not, put it in the new list
                newVec.push_back(tasks[i]);
            }
            if (newVec.empty()) {
                // get rid of this day if it has no tasks
                theList.erase(it);
            }
            else {
                // otherwise, set this day's tasks to the new list
                it->second = newVec;
            }
            it++;
        }
    }

    void printTodoList() {
        todoFile.open(fileName);
        if (!todoFile.is_open()) {
            cout << "Could not open file" << endl;
        } else {
            cout << todoFile.rdbuf();
        }
    }

    void printDaysTasks(string day) {
        if (theList.find(day) == theList.end()) {
            cout << day << " not found\n";
        }
        else {
            cout << "Tasks for " << day << ":" << endl;
            // TODO: only prints "Sunday"
            for (string task : theList.at(day)) {
                cout << task << endl;
            }
        }
    }

    // destructor
    ~TodoList() {
        ofstream outHandle(fileName);
        // write `theList` to file
        // for each item in theList, print the key then print each item in the value
        for (const auto &element : theList) {
            outHandle << element.first << endl;
            for (const string& task : element.second) {
                outHandle << task << endl;
            }
        }


//        delete[] theList;
    }
};
#endif
