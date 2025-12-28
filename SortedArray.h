#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include "DynamicArray.h"

class SortedArray : public DynamicArray {
public:
    void push(int value);
    int binarySearch(int value) const;
};

#endif
