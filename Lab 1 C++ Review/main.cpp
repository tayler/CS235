#include <iostream>
#include "TodoList.h"

int main(int argc, char *argv[]) {
    TodoList list{};

    if (argc < 2) {
        cout << "Usage: "<<argv[0]<<" <operation>"<<endl;
    }
    else if (string(argv[1]) == "printList") {
        // e.g., ./TODO printList
        list.printTodoList();
    }
    else if (string(argv[1]) == "add") {
        // e.g., ./TODO add Sunday “Take a nap”
        list.add(argv[2], argv[3]);
    }
    else if (string(argv[1]) == "remove") {
        // e.g., ./TODO remove “Take a nap”
        list.remove(argv[2]);
    }
    else if (string(argv[1]) == "printDay") {
        // e.g., ./TODO printDay Sunday
        list.printDaysTasks(argv[2]);
    }
    else {
        cerr << "Unknown argument. Try " << argv[0] << " <printList | add day task | remove task | printDay day>" << endl;
    }

    return 0;
}
