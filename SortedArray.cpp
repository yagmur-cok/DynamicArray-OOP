#include "SortedArray.h"

// push (override)
void SortedArray::push(int value) {
    DynamicArray::push(value);

    int i = getSize() - 1;
    while (i > 0 && get(i - 1) > get(i)) {
        int temp = (*this)[i];
        (*this)[i] = (*this)[i - 1];
        (*this)[i - 1] = temp;
        i--;
    }
}

// binary search
int SortedArray::binarySearch(int value) const {
    int left = 0;
    int right = getSize() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (get(mid) == value)
            return mid;
        else if (get(mid) < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
