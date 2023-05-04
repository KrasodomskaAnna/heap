#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include "Person.h"
#include "HeapType.h"

#define ERROR -1
#define SIZE 2

class Heap {
public:
    Heap();
    void print();
    void put(Person element);
    void deleteLimit();
    void changeOrientation();
    ~Heap();
private:
    int size = 0;
    int sizeBooked;
    Person* array;
    HeapType type = HeapType.name_first;

    int getId(Person element);
    int left(int i);
    int right(int i);
    int parent(int i);

    int getLimitId(int size, bool isMax);

    bool compare(Person smaller, Person bigger);


    void heapify(int id, int _size);
    void buildHeap();
    void heapSort(int size);
    
    void clear();
    void addElement(Person element);
};

int Heap::getId(Person element) {
    for(int i = 1; i <= size; i++) {
        if(array[i] == element) return i;
    }
    return ERROR;
}

int Heap::left(int i) {
    return i*2;
}

int Heap::right(int i) {
    return i*2+1;
}

int Heap::parent(int i) {
    return i/2;
}

void Heap::print() {
    for(int i = 1; i <= size; i++)
        std::cout << array[i] << std::endl;
}

void Heap::put(Person element) {
    addElement(element);
    int i = size;
    while(i > 1 && compare(array[parent(i)], element)) {
        std::swap(array[i], array[parent(i)]);
        i = parent(i);
    }
}

void Heap::deleteLimit() {
    if(size <= 0) return;
    std::cout << array[1] << std::endl;
    if(size-1 != 0) array[1] = array[size];
    size--;

    heapify(1, size);
}

void Heap::changeOrientation() {
    type = type == name_first ? date_first : name_first;
    buildHeap();
}

int Heap::getLimitId(int _size, bool isMax) {
    Person limit = array[1];
    int id = 1;
    for(int i = 2; i <= _size; i++) {
        if (isMax ? compare(limit, array[i]) : compare(array[i], limit)) {
            limit = array[i];
            id = i;
        }
    }
    return id;
}

bool Heap::compare(Person smaller, Person bigger) {
    return smaller.compare(bigger, type, false, 0, 0);
}

void Heap::heapify(int id, int _size) {
    int l = left(id);
    int r = right(id);

    int maxId = id;
    if (l <= _size && compare(array[id], array[l]))
        maxId = l;
    if (r <= _size && compare(array[maxId], array[r]))
        maxId = r;

    if (maxId != id) {
        std::swap(array[id], array[maxId]);
        heapify(maxId, _size);
    }
}

void Heap::buildHeap() {
    for(int i = parent(size); i > 0; i--)
        heapify(i, size);
}

void Heap::heapSort(int size) {
    buildHeap();
    for(int i = size; i > 1; i--) {
        std::swap(array[i-1], array[1]);
        heapify(1, i-1);
    }
}

void Heap::clear() {
    delete[] array;
    array = new Person[0]();
    size = 0;
}

void Heap::addElement(Person element) {
    size++;
    if(this->size < sizeBooked) {
        array[size] = element;
        return;
    }
    Person* newArray = new Person[this->sizeBooked*2];
    for(int i = 1; i < this->sizeBooked; i++)
        newArray[i] = this->array[i];
    newArray[this->sizeBooked] = element;
    delete[] this->array;
    this->array = newArray;
    this->sizeBooked *= 2;
}

Heap::Heap() {
    this->sizeBooked = SIZE;
    array = new Person[sizeBooked]();
    this->size = 0;
}

Heap::~Heap() {
    clear();
}

#endif //HEAP_HEAP_H