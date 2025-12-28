#include <iostream>
#include "DynamicArray.h"
#include "SortedArray.h"
#include "UniqueArray.h"

using namespace std;

int main() {
    // 1. DynamicArray testi
    DynamicArray arr1;
    arr1.push(10);
    arr1.push(20);
    arr1.push(30);
    arr1.print();

    // 2. İndeksleme operatörü
    arr1[1] = 25;
    cout << "arr1[1] = " << arr1[1] << endl;

    // 3. Birleştirme operatörü
    DynamicArray arr2;
    arr2.push(40);
    arr2.push(50);
    DynamicArray arr3 = arr1 + arr2;
    arr3.print();

    // 4. SortedArray testi
    SortedArray sorted;
    sorted.push(50);
    sorted.push(10);
    sorted.push(30);
    sorted.push(20);
    sorted.print();

    int index = sorted.binarySearch(30);
    cout << "30 bulundu, indeks: " << index << endl;

    // 5. UniqueArray testi
    UniqueArray unique;
    unique.push(10);
    unique.push(20);
    unique.push(10);
    unique.push(30);
    unique.print();

    cout << "20 var mi? " << (unique.contains(20) ? "Evet" : "Hayir") << endl;

    return 0;
}
