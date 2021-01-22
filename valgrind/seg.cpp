#include <iostream>
using namespace std;

// compile with -g to give valgrind a sourcemap: `g++ -g -std=c++11 seg.cpp -o seg`
// then `valgrind ./seg
int main()
{
//    char *badptr = 0;
    // segfault here
//    *badptr = 0;


    // memory leak if we don't also `delete` badptr
    int *badptr = new int[10];

    cout << "everything worked"<<endl;
//    delete [] badptr;
}