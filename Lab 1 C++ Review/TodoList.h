#ifndef LAB_1_C___REVIEW_TODOLIST_H
#define LAB_1_C___REVIEW_TODOLIST_H
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "TodoListInterface.h"

using namespace std;

class TodoList : public TodoListInterface {
private:
    // keys are strings and values are vectors
    map<string, vector<string>> theList;
    set<string> weekdays = {"Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday","Saturday"};
    string fileName;
public:
    // constructor
    TodoList() {
        // read file
        fileName = "TODOList.txt";
        ifstream todoFile(fileName);
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
                if (dayOrTask.empty()) {
                    // we may be on a blank line
                    continue;
                }
                // if it is a day, add it as a key to `theList`
                if (weekdays.find(dayOrTask) != weekdays.end()) {
                    day = dayOrTask;
                    theList[day] = vector<string>();
                }
                // if it is a task, add it to the current day
                else {
                    theList[day].push_back(dayOrTask);
                }
            }
        }
        todoFile.close();
    }

    /**
     * Insert an item in the vector that belongs to `theList[day]`
     * @param day  One of Sunday, Monday, etc.
     * @param task  The name of the task to be added to `day`
     */
    void add(string day, string task) {
        theList[day].push_back(task);
    }

    /**
     * Search for any instance of `taskToRemove` and remove it
     * @param taskToRemove  any task name
     * @return 1  if at least one item was removed. O otherwise.
     */
    int remove(string taskToRemove) {
        int success = 0;
        vector<string> tasks;

        // go through each key in the list
        auto iter = theList.begin();
        while (iter != theList.end()) {
            if (iter->first.empty()) {
                // we may be on a file line that is empty
                break;
            }
            // a place to store the not-removed items
            vector<string> newVec;
            tasks = iter->second;

            // for each task, see if it is the one marked for removal
            for (size_t i = 0; i < tasks.size(); i++) {
                // it tried to use something like tasks.erase(i), but `erase` was not available
                if (taskToRemove == tasks[i]) {
                    cout << "task '" << taskToRemove << "' removed from " << iter->first << endl;
                    success = 1;
                    // we don't need to look through this day anymore (assuming there's only one task with the same name per day)
                    continue;
                }

                // if not, put it in the new list
                newVec.push_back(tasks[i]);
            }
            if (newVec.empty()) {
                // get rid of this day if it has no tasks
                theList.erase(iter);
            }
            else {
                // otherwise, set this day's tasks to the new list
                iter->second = newVec;
            }
            iter++;
        }
        return success;
    }

    /**
     * Open the file and print to std out
     */
    void printTodoList() {
        ifstream todoFile(fileName);
        if (!todoFile.is_open()) {
            cout << "Could not open file" << endl;
        } else {
            cout << todoFile.rdbuf() << endl;
        }
        todoFile.close();
    }

    /**
     * Print the tasks related to `day`
     * @param day  One of Sunday, Monday, etc.
     */
    void printDaysTasks(string day) {
        if (theList.find(day) == theList.end()) {
            cout << day << " not found\n";
        }
        else {
            cout << "Tasks for " << day << ":" << endl;
            for (const string& task : theList.at(day)) {
                cout << task << endl;
            }
        }
    }

    // destructor
    ~TodoList() {
        ofstream outHandle(fileName);
        // write `theList` to file
        // for each item in theList, write the key then write each item in the value
        for (const auto &element : theList) {
            outHandle << element.first << endl;
            for (const string& task : element.second) {
                outHandle << task << endl;
            }
        }
        outHandle.close();
        theList.clear();
    }
};
#endif
