#include "dynamicarray.h"
#include <algorithm>
using namespace std;

dynamicarray::dynamicarray() : data(NULL), capacity(0), size(0) {} 

dynamicarray::~dynamicarray() {
    delete[] data;
}

void dynamicarray::addlast(int element) {
    if (size == capacity) { 
        changesize(); 
    }
    data[size++] = element; 
}

void dynamicarray::addfirst(int element) {
    if (size == capacity) { 
        changesize();
    }

    for (int i = size; i > 0; --i) {
        data[i] = data[i - 1];
    }
    
    data[0] = element;
    size++; 
}

void dynamicarray::insert(int t, int numer) {
    if (numer < 0 || numer > size) {
        cout << "Nieprawid³owa pozycja!" << endl;
        return;
    }

    if (size == capacity) {
        changesize();
    }

    for (int i = size; i > numer; --i) {
        data[i] = data[i - 1];
    }

    data[numer] = t;
    size++;
}

void dynamicarray::displayspecific(int numer) {
    if (numer < 0 || numer >= size) {
        cout << "Element o podanym indeksie nie istnieje!" << endl;
        return;
    }
    cout << "Element nr " << numer << ": " << data[numer] << endl;
}


void dynamicarray::deletelast() {
    if (size > 0) { 
        size--; 
    }
}

void dynamicarray::deletefirst() {
    if (size > 0) { 
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1]; 
        }
        size--; 
    }
}

void dynamicarray::deletespecific(int numer) {
    if (numer < 0 || numer >= size) {
        cout << "Nieprawid³owy indeks!" << endl;
        return;
    }

    for (int i = numer; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
}

bool dynamicarray::isthere(int element) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == element) { 
            return true;
        }
    }
    return false;
}

void dynamicarray::changesize() {
    if (capacity == 0) {
        capacity = 1;
    }
    else {
        capacity *= 2;
    }

 
    int* newdata = new int[capacity];

    copy(data, data + size, newdata);

    delete[] data;

    data=newdata;
}

