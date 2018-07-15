#include <iostream>
#include <fstream>

using namespace std;

#include "absheap.h"
#include "minheap.h"

// For bonus
//#include "medianheap.h"

int main()
{

    MinHeap heap;

    // For bonus
    //MedianHeap heap;

    ifstream file("input1.txt");

    int opNum;
    int heapNum;
    file >> opNum >> heapNum;
    int *key = new int[heapNum];
    char *element = new char[heapNum];

    for (int i=0; i<heapNum; ++i) {
        file >> key[i];
        file >> element[i];
    }
    int index = 0;
    for (int i=0; i<opNum; ++i) {
        int op;
        file >> op;
        if (op == 1) {
            heap.push(key[index], element[index]);
            ++index;
        }
        else
            heap.pop();
    }

    file.close();
    delete []element;
    delete []key;

    // For Bonus, disable the following line
    heap.printArray();

    heap.printByPopping();

    return 0;
}


