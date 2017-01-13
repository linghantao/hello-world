#include "dynArr.hpp"

//Constructor
dynArr::dynArr() {
    this->size = 0;
    this->capacity = 4;
    this->items = new string[4];
}

//Function to resize the dynamic array
string *dynArr::setCapacity(int newCap) {
    string *newItems = new string [newCap];
    for (int i = 0; i < this->size; i++) {
        newItems[i] = this->items[i];
    }
    this->capacity = newCap;
    return newItems;
}

//Function to find index of an item or return -1 if its not found
int dynArr::findItem(string item) {
    for (int i = 0; i < this->size; i++) {
        if (this->items[i] == item) {
            return i;
        }
    }
    return -1;
}

//Get the size of the dynamic array
int dynArr::getSize() {
    return this->size;
}

//Get the capacity of the dynamic array
int dynArr::getCapacity() {
    return this->capacity;
}

//Function to add to the dynamic array
void dynArr::add(string item) {
    if (this->size < capacity) {
        items[this->size] = item;
        this->size++;
    } else {
        items = this->setCapacity(2*capacity);
        items[this->size] = item;
        this->size++;
    }
}

//Function to remove an item
void dynArr::remove(string item) {
    int idx = this->findItem(item);
    if (idx == -1) {
        return;
    } else {
        for (int i = idx; i < this->size-1; i++) {
            items[i] = items[i+1];
        }
    }
    this->size--;
}

//Function to display items in dynamic array
void dynArr::dispItems() {
    if (this->size <= 0) {
    } else {
        for (int i = 0; i < this->size; i++) {
            cout << "(" << i+1 << ") " << this->items[i] << "\n";
        }
    }
}
