#ifndef DYNAMICARRAY_H 
#define DYNAMICARRAY_H 

#include <iostream>
using namespace std;

class dynamicarray
{
public:
    dynamicarray(); 
    ~dynamicarray(); 
    void addlast(int t);
    bool isthere(int element) const;
    void addfirst(int t);
    void insert(int t, int numer);
    void deletefirst();
    void deletelast();
    void deletespecific(int numer);
    void displayspecific(int numer);

private:
    int* data; 
    int capacity; 
    int size; 

    void changesize(); 
};

#endif#
