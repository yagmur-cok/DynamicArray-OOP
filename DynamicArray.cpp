#include "DynamicArray.h"

// Yardımcı fonksiyon
void DynamicArray::resize(int newCapacity) {
    int* newData = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// Varsayılan Constructor
DynamicArray::DynamicArray() {
    capacity = 2;
    size = 0;
    data = new int[capacity];
}

// Parametreli Constructor
DynamicArray::DynamicArray(int capacity) {
    this->capacity = capacity;
    size = 0;
    data = new int[capacity];
}

// Copy Constructor (Deep Copy)
DynamicArray::DynamicArray(const DynamicArray& other) {
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

// Destructor
DynamicArray::~DynamicArray() {
    delete[] data;
}

// push
void DynamicArray::push(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[size++] = value;
}

// pop
void DynamicArray::pop() {
    if (isEmpty()) {
        cout << "Uyari: Dizi bos, pop yapilamaz!" << endl;
        return;
    }
    size--;
}

// get
int DynamicArray::get(int index) const {
    if (index < 0 || index >= size) {
        cout << "Hata: Gecersiz indeks!" << endl;
        return -1;
    }
    return data[index];
}

// set
void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        cout << "Hata: Gecersiz indeks!" << endl;
        return;
    }
    data[index] = value;
}

// getters
int DynamicArray::getSize() const {
    return size;
}

int DynamicArray::getCapacity() const {
    return capacity;
}

bool DynamicArray::isEmpty() const {
    return size == 0;
}

// clear
void DynamicArray::clear() {
    size = 0;
}

// print
void DynamicArray::print() const {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i != size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

// operator[]
int& DynamicArray::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Hata: Gecersiz indeks!" << endl;
        exit(1);
    }
    return data[index];
}

// operator+
DynamicArray DynamicArray::operator+(const DynamicArray& other) const {
    DynamicArray result(size + other.size);
    for (int i = 0; i < size; i++)
        result.push(data[i]);
    for (int i = 0; i < other.size; i++)
        result.push(other.data[i]);
    return result;
}

// operator=
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this == &other)
        return *this;

    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

// operator==
bool DynamicArray::operator==(const DynamicArray& other) const {
    if (size != other.size)
        return false;
    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}

// operator!=
bool DynamicArray::operator!=(const DynamicArray& other) const {
    return !(*this == other);
}

// operator<<
ostream& operator<<(ostream& os, const DynamicArray& other) {
    os << "[";
    for (int i = 0; i < other.size; i++) {
        os << other.data[i];
        if (i != other.size - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
