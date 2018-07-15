#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include <iostream>
using namespace std;

class MinHeap : public AbsHeap
{
    public:
        virtual void push(int _key, char _element)
        {
            int target = size + 1;
            while (_key < ary[(target - 1) / 2].key)
            // allocate it to ary[size + 1], and then compare with its parent
            {
                swap ( (target - 1) / 2, target );
                target = (target - 1) / 2;
            } // end while and do nothing as long as it is larger than its parent

            size++; // size of heap increases as long as a "push" is executed
        };
        virtual char pop()
        {
            int index = 0;
            swap (0, size); //replace the root with the last element

            // sink down choosing the smaller path
            while ((ary[index].key > ary[2 * index + 1].key) && (ary[index].key > ary[2 * index + 2].key))
            // target node is larger than both of its children => sink
            {
                if (ary[2 * index + 1].key > ary[2 * index + 2].key) // choose the smaller path
                {
                    swap (index, 2 * index + 2);
                    index = 2 * index + 2;
                }
                else
                {
                    swap (index, 2 * index + 1);
                    index = 2 * index + 1;
                }
            }
            return ary[size].key; // return root (smallest node of all)
            size--;
        };

};

#endif
