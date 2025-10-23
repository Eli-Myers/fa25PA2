//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;
    //Helper methods for parent and left/right children
    int parentIdx(int i){return (i-1)/2;}
    int leftChildIdx(int i){return (i*2)+1;}
    int rightChildIdx(int i){return (i*2)+2;}

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        if(size >= 64) {
            cout << "Can't push, full heap!" << endl;
        } else {
            data[size] = idx;
            size++;
            //upheap(size, weightArr);
        }
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if(size == 0){
            cout << "Can't pop, empty heap!" << endl;
            return 0;
        }
        int smallest = data[0];
        data[0] = data[size - 1];
        size--;
        downheap(size, weightArr);
        return smallest;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if(size == 0) return;

        upheap(leftChildIdx(pos), weightArr);
        upheap(rightChildIdx(pos), weightArr);
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        if(size == 0) return;


    }
};

#endif