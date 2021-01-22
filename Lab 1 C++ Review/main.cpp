#include <iostream>
#include "TodoList.h"

int main(int argc, char **argv) {
    TodoList list{};

    if (argc < 2) {
        cout << "Usage: "<<argv[0]<<" <operation>"<<endl;
    }

    switch (argv[1]) {
        case 'printList':
            list.printTodoList()

    }

    // what action is requested

    return 0;
}
