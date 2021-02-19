#ifndef LAB_4___SORTING_QS_H
#define LAB_4___SORTING_QS_H

#include "QSInterface.h"

using namespace std;

class QS : public QSInterface {
private:
    int* arr;
    int _capacity;
    // _nextPosition is the index of the final item in the array
    int _nextPosition;

public:
    QS() {
        _capacity = 0;
        _nextPosition = 0;
    }

    int medianOfThree(int left, int right) {
        if (left < 0 || right >= _nextPosition || left >= right) {
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
        if (arr == nullptr || left < 0 || right >= _nextPosition || left >= right || pivotIndex < left || pivotIndex > right) {
            return -1;
        }

        int tmp = arr[pivotIndex];
        int up = left + 1;
        int down = right;

        arr[pivotIndex] = arr[left];
        arr[left] = tmp;

        do {
            while ((arr[up]<= arr[left]) && (up < right)) { up++; }
            while ((arr[down] > arr[left]) && (down > left)) { down--; }
            if (up < down) {
                tmp=arr[up];
                arr[up]= arr[down];
                arr[down]=tmp;
            }
        } while (up < down);

        tmp = arr[left];
        arr[left] = arr[down];
        arr[down] = tmp;

        return down;
    }

    void sortAll() {
        this->quicksort(0, this->getSize() - 1);
    }

    void quicksort(int first, int last) {
        if((last - first) < 1) return;
        int pivot = medianOfThree(first, last);
        pivot = partition(first, last, pivot);
        this->quicksort(first, pivot - 1);
        this->quicksort(pivot + 1, last);
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
            this->clear();
        }
        _capacity = capacity;
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
        // deallocates the array
        delete [] arr;
        // reset `arr` to null pointer. You should always set the pointer to zero after delete has been called because the data the pointer references will be invalid after the delete call.
        arr = nullptr;
        _capacity = 0;
        _nextPosition = 0;
    }

    // destructor
    ~QS() {
        // The key word "delete" is used to release space that was allocated with "new"
        delete [] arr;
        arr = nullptr;
    }
};

#endif
