#ifndef DYNARR_HPP
#define DYNARR_HPP
#include <string>
using std::string;
#include <iostream>
using std::cout;

class dynArr {
private:
    int size;
    int capacity;
    string *setCapacity(int newCap);
    int findItem(string item);
public:
    dynArr();

    int getSize();
    int getCapacity();
    
    void add(string item);
    void remove(string item);
    void dispItems();
    string *items;
};

#endif
