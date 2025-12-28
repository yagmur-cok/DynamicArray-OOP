#include "UniqueArray.h"

//dizide eleman var mı kontrol eder
bool UniqueArray::contains(int value) const {
    for (int i = 0; i < getSize(); i++) {
        if (get(i) == value)
            return true;
    }
    return false;
}

// push (override)
bool UniqueArray::push(int value) {
    if (contains(value)) {
        return false;
    }
    DynamicArray::push(value);
    return true;
}
