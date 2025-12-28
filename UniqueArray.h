#ifndef UNIQUEARRAY_H
#define UNIQUEARRAY_H

#include "DynamicArray.h"

class UniqueArray : public DynamicArray {
public:
    bool push(int value);
    bool contains(int value) const;
};

#endif
