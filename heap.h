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
        //edge case
        if(size >= 64) {
            cout << "Can't push, full heap!" << endl;
        } else {
            data[size] = idx;
            size++;
            upheap(size-1, weightArr);//upheap from the last element
        }
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        //edge case
        if(size == 0){
            cout << "Can't pop, empty heap!" << endl;
            return 0;
        }
        int root = data[0];
        data[0] = data[size - 1];
        size--;
        downheap(0, weightArr);//downheap from the top
        return root;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        //edge case
        if(size == 0) return;

        //checks while it's not at the beginning and while the parent is greater
        while (pos >= 0 && weightArr[data[pos]] < weightArr[data[parentIdx(pos)]]) {
            swap(data[pos], data[parentIdx(pos)]);
            pos = parentIdx(pos);
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        //edge case
        if(size == 0) return;

        //using helper methods to get index of left and right
        int left = leftChildIdx(pos);
        int right = rightChildIdx(pos);

        //checks while there is still a left leaf(end)
        while (left < size) {
            int smallest = left;
            //compares left and right to determine smallest
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }
            //if downheap is comoplete
            if (weightArr[data[pos]] < weightArr[data[smallest]]) {
                break;
            }
            swap(data[pos], data[smallest]);
            pos = smallest;
            left = leftChildIdx(pos);
            right = rightChildIdx(pos);
        }
    }
    //helper for main
    int Size() {
        return size;
    }
};

#endif