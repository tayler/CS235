#ifndef LAB_4___SORTING_QS_H
#define LAB_4___SORTING_QS_H

#include "QSInterface.h"

using namespace std;

class QSLib : public QSInterface {
private:
    int* arr;
    int _capacity = 0;
    // _nextPosition is the index of the final item in the array
    int _nextPosition = 0;

public:
    QSLib() {}

    void sortAll() {}

    int medianOfThree(int left, int right) {
        if (left < 0 || right > _nextPosition || left > right) {
            return -1;
        }
        int middle = (left + right)/2;

        if (arr[left] > arr[middle]) {
            int tmpLeft = arr[left];
            arr[left] = arr[middle];
            arr[middle] = tmpLeft;
        }
        if (arr[left] > arr[right]) {
            int tmpLeft = arr[left];
            arr[left] = arr[right];
            arr[right] = tmpLeft;
        }
        if (arr[middle] > arr[right]) {
            int tmpMid = arr[middle];
            arr[middle] = arr[right];
            arr[right] = tmpMid;
        }

        return middle;
    }

    int partition(int left, int right, int pivotIndex) {
        return 0;
    }

    string getArray() const {
        string strArray;
        // nothing is concatenated to the empty string if the array is empty
        for (int i = 0; i < _nextPosition; i++) {
            strArray += to_string(arr[i]);
            if (i < _nextPosition - 1) {
                strArray += ",";
            }
        }
        return strArray;
    }

    int getSize() const {
        return _nextPosition;
    }

    bool createArray(int capacity) {
        // If a previous array had been allocated, delete the previous array.
        if (_nextPosition > 0) {
            delete[] arr;
        }
        _capacity = capacity;
        _nextPosition = 0;
        arr = new int[capacity];

        return capacity > -1;
    }

    bool addToArray(int value) {
        if (_nextPosition == _capacity) {
            return false;
        }
        arr[_nextPosition] = value;
        _nextPosition++;

        return true;
    }

    void clear() {
        arr = nullptr;
        _capacity = 0;
        _nextPosition = 0;
    }

    // destructor
    ~QSLib() {
        delete[] arr;
    }
};

#endif