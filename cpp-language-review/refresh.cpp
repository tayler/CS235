//#include <iostream>
//using namespace std;
//
//int main(int argc, char *argv[])
//{
//    // output `argc 2 argv[0] ./refresh`
//    cout << "argc "<<argc<<" argv[0] "<<argv[0]<<endl;
//}


//
// Notice that we are using "argv[1]" for the name of the file we want to open.  If there are less than two arguments, then we print out the correct usage string.  This is good practice for writing a command line program.  We then create a variable called "filehandle" that will reference the file name passed in the command line "argv[1]".  You can use "filehandle" just like "cin" to access data in a file using the ">>" syntax.
//
//#include <fstream>
//#include <iostream>
//
//using namespace std;
//
//int main(int argc, char *argv[])
//{
//    cout << "argc "<<argc<<" argv[0] "<<argv[0]<<" argv[1]= "<<argv[1]<<endl;
//    if(argc != 2) {
//        cout << "Usage: "<<argv[0]<<" <filename>"<<endl;
//    } else {
//        ifstream fileHandle(argv[1]);
//        if(!fileHandle.is_open()) {
//            cout << "Could not open file"<<endl;
//        } else {
//            string name;
//            int age;
//            // You can use "filehandle" just like "cin" to access data in a file using the ">>" syntax.
//            while(fileHandle>>name>>age) {
//                cout << "Name "<<name<<" Age "<<age<<endl;
//            }
//        }
//    }
//}



//
// How would you fill in the blanks to create a program that would put the names into a vector of strings?
//
//#include <fstream>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(int argc, char *argv[])
//{
//    vector<string> names;
//    if(argc != 2) {
//        cout << "Usage: "<<argv[0]<<" <filename>"<<endl;
//    } else {
//        ifstream fileHandle(argv[1]);
//        if(!fileHandle.is_open()) {
//            cout << "Could not open file"<<endl;
//        } else {
//            string name;
//            int age;
//            while(fileHandle>>name>>age) {
//                names.push_back(name);
//            }
//            cout << "All names "<<names.at(1)<<endl;
//        }
//    }
//}


//
// One of the advantages of using a data structure is that you can easily sort the items that are in the data structure.  Most data structures will have a "begin()" and "end()" function that will return the address of the beginning and end items in the data structure and with these two addresses, library code (Links to an external site.) can sort the list.
// What code would you insert to fill in the BLANK so that the code would print out an ordered list of the names?
//
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    vector<string> names;
    if(argc != 2) {
        cout << "Usage: "<<argv[0]<<" <filename>"<<endl;
    } else {
        ifstream fileHandle(argv[1]);
        if(!fileHandle.is_open()) {
            cout << "Could not open file"<<endl;
        } else {
            string name;
            int age;
            while(fileHandle>>name>>age) {
                names.push_back(name);
            }
        }
        // sort take the first and last item in a data structure
        sort(names.begin(), names.end());
        ofstream outHandle("out.txt");

        for(int i = 0; i < names.size(); i++) {
            cout << names[i]<<endl;
            outHandle << names[i];
        }

        outHandle.close();

    }
}