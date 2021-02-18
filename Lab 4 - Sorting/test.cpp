#include "QS.h"

int main(int argc, char *argv[]) {
    QSLib qs{};

//    qs.createArray(5);
//    qs.addToArray(11);
//    int size1 = qs.getSize();
//    string arr1 = qs.getArray();
//
//    cout << "size1: " << size1 << " ; arr1: " << arr1 << endl;
//    qs.addToArray(22);
//    int size2 = qs.getSize();
//    string arr2 = qs.getArray();
//
//    cout << "size2: " << size2 << " ; arr2: " << arr2 << endl;
//    qs.addToArray(33);
//    int size3 = qs.getSize();
//    string arr3 = qs.getArray();
//
//    cout << "size3: " << size3 << " ; arr3: " << arr3 << endl;
//
//    qs.clear();

    qs.createArray(9);
    qs.addToArray(44);
    qs.addToArray(75);
    qs.addToArray(23);
    qs.addToArray(43);
    qs.addToArray(55);
    qs.addToArray(12);
    qs.addToArray(64);
    qs.addToArray(77);
    qs.addToArray(33);
//    qs.addToArray(33);
    int size1 = qs.getSize();
    string arr1 = qs.getArray();

    cout << "size1: " << size1 << " ; arr1: " << arr1 << endl;

    int median = qs.medianOfThree(0, size1 - 1);
    int sizeAfterSort = qs.getSize();
    string arrAfterSort = qs.getArray();

    cout << "median: " << median << "; sizeAfterSort: " << sizeAfterSort << " ; arrAfterSort: " << arrAfterSort << endl;


    return 0;
}