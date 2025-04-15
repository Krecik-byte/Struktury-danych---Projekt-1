#include "dynamicarray.h"
#include "linkedlist.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <fstream>
#include <string>
#include <cstdio>
#include <functional>

using namespace std;
using namespace std::chrono;

bool fileExists(const string& fileName) {
    ifstream file(fileName);
    return file.is_open();
}

void testOperation(const string& operationName,
    function<void(dynamicarray&)> dynamicFunc,
    function<void(linkedlist&)> linkedFunc,
    ofstream& outfile,
    int numElements,
    int iterations = 10) {

    vector<long long> durationsDynamicArray, durationsLinkedList;

    for (int iter = 0; iter < iterations; ++iter) {
        dynamicarray dynamicArr;
        linkedlist linkedList;

        for (int i = 1; i <= numElements; ++i) {
            dynamicArr.addlast(i);
            linkedList.addlast(i);
        }

        auto start = high_resolution_clock::now();
        dynamicFunc(dynamicArr);
        auto stop = high_resolution_clock::now();
        durationsDynamicArray.push_back(duration_cast<nanoseconds>(stop - start).count());

        start = high_resolution_clock::now();
        linkedFunc(linkedList);
        stop = high_resolution_clock::now();
        durationsLinkedList.push_back(duration_cast<nanoseconds>(stop - start).count());
    }

    long long avgArray = accumulate(durationsDynamicArray.begin(), durationsDynamicArray.end(), 0LL) / iterations;
    long long avgList = accumulate(durationsLinkedList.begin(), durationsLinkedList.end(), 0LL) / iterations;

    outfile << numElements << "\t"  
        << operationName << "\t" 
        << avgArray << "\t"      
        << avgList << "\n";      
}

int main() {
    int fileIndex = 1;
    string fileName = "wyniki" + to_string(fileIndex) + ".txt";

    while (fileExists(fileName)) {
        fileIndex++;
        fileName = "wyniki" + to_string(fileIndex) + ".txt";
    }

    ofstream outfile(fileName);
    const int iterations = 10;

    outfile << "Rozmiar\tOperacja\tDynamicArray\tLinkedList\n";

    vector<int> testSizes = { 10, 20, 50, 100, 200, 500, 1000, 2000, 3000, 4000, 5000, 7500, 10000 };

    for (int numElements : testSizes) {
        testOperation("Dodawanie na początek",
            [](dynamicarray& a) { a.addfirst(5); },
            [](linkedlist& l) { l.addfirst(5); },
            outfile, numElements, iterations);

        testOperation("Dodawanie na koniec",
            [](dynamicarray& a) { a.addlast(5); },
            [](linkedlist& l) { l.addlast(5); },
            outfile, numElements, iterations);

        testOperation("Dodawanie na indeks " + to_string(numElements / 2),
            [numElements](dynamicarray& a) { a.insert(5, numElements / 2); },
            [numElements](linkedlist& l) { l.insert(5, numElements / 2); },
            outfile, numElements, iterations);

        testOperation("Usuwanie z indeksu " + to_string(numElements / 2),
            [numElements](dynamicarray& a) { a.deletespecific(numElements / 2); },
            [numElements](linkedlist& l) { l.deletespecific(numElements / 2); },
            outfile, numElements, iterations);

        testOperation("Usuwanie z początku",
            [](dynamicarray& a) { a.deletefirst(); },
            [](linkedlist& l) { l.deletefirst(); },
            outfile, numElements, iterations);

        testOperation("Usuwanie z końca",
            [](dynamicarray& a) { a.deletelast(); },
            [](linkedlist& l) { l.deletelast(); },
            outfile, numElements, iterations);

        testOperation("Wyszukiwanie elementu (istniejącego)",
            [numElements](dynamicarray& a) { a.isthere(numElements / 2); },
            [numElements](linkedlist& l) { l.isthere(numElements / 2); },
            outfile, numElements, iterations);

        testOperation("Wyszukiwanie elementu (nieistniejącego)",
            [numElements](dynamicarray& a) { a.isthere(numElements + 1); },
            [numElements](linkedlist& l) { l.isthere(numElements + 1); },
            outfile, numElements, iterations);
    }

    outfile.close();
    cout << "\nWyniki zapisane do pliku TXT: " << fileName << endl;
    return 0;
}
