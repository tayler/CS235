#ifndef LAB_1_C___REVIEW_TODOLIST_H
#define LAB_1_C___REVIEW_TODOLIST_H
#include <unordered_map>
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
    unordered_map<string, vector<string>> list;
public:
    // constructor
    TodoList() {
        ifstream todoFile("TODOList.txt");
        // read file
        if (!todoFile.is_open()) {
            cout << "Could not open file" << endl;
        } else {
            // each line contains one day and its tasks
            // iterate through each line, then through each word in the line
            string line;
            // reading each line: https://stackoverflow.com/a/55029247/1067590
            while (getline(todoFile, line)) {
//                cout << "line: " << line << endl;

                // reading each word: https://stackoverflow.com/a/236146/1067590
                string word; // `word` is either a day or a task
                istringstream iss(line, istringstream::in);
                int wordIdx = 0;

                while (iss >> word) {
                    if (wordIdx == 0) {
                        list[word] = vector<string>();
                    }
                    list[word].push_back(word);
//                    cout << "word: " << word << endl;
                    wordIdx++;
                }
            }
            // TODO: maybe move this to destructor
            todoFile.close();
        }
    }
    void add(string day, string task) {
        list[day].push_back(task);
    }

    int remove(string task) {

    }

    void printTodoList() {
        ifstream todoFile("TODOList.txt");
        // read file
        if (!todoFile.is_open()) {
            cout << "Could not open file" << endl;
        } else {
            string line;
            // reading each line: https://stackoverflow.com/a/55029247/1067590
            while (getline(todoFile, line)) {
                cout << line << endl;
            }
        }
    }

    void printDaysTasks(string day) {
        if (list.find(day) == list.end()) {
            cout << day << " not found\n";
        }
        else {
            cout << "Tasks for " << day << ":" << endl;
            // TODO: only prints "Sunday"
            for (string task : list.at(day)) {
                cout << task << endl;
            }
        }
    }

    // destructor
    ~TodoList() {
        // write `list` to file
        for (const auto &element : list) {
//            cout << element.first << ": " << element.second << endl;
            std::string str(element.second.begin(), element.second.end());
        }


//        delete[] list;
    }
};
#endif
