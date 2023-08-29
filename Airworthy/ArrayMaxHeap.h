/*
 * File: ArrayMaxHeap.cpp
 * Author: (Your Name)
 *
 * This file contains the initialization and implementation of ArrayMaxHeap, a data structure
 * that stores elements in a max-heap format. It provides basic heap
 * operations like add, remove, and peek. This heap is utilized by the Airworthy
 * class for managing passenger boarding priorities.
 */


#ifndef ARRAYMAXHEAP_H
#define ARRAYMAXHEAP_H

#include "HeapADT.h"
#include "HeapException.h"


template <class T>
class ArrayMaxHeap : public HeapADT<T> {
public:
    ArrayMaxHeap();
    virtual ~ArrayMaxHeap();
    
    //interface methods
    bool isEmpty() const;
    int getItemCount() const;
    T peek() const;
    bool add(const T& newItem);
    bool remove();
    void clear();
    
private:
    static const int ROOT_INDEX = 0;
    static const int CAPACITY = 5000;
    int itemCount;
    T* items;
    
    int getLeftChild(int currNode) const;
    int getRightChild(int currNode) const;
    int getParent(int currNode) const;   
    bool isLeaf(int currNode) const;
    void percolateDown(int subtree);
};

/*
The method implementations are listed below
*/

template <class T>
ArrayMaxHeap<T>::ArrayMaxHeap() : itemCount(0) {
    items = new T[CAPACITY];
}
template <class T>
ArrayMaxHeap<T>::~ArrayMaxHeap() {
    delete[] items;
}

//interface methods
/**
 * Add an item to the max heap
 * @param newItem item to be added
 * @return true if successful
 */
template <class T>
bool ArrayMaxHeap<T>::add(const T& newItem) {
    if (itemCount >= CAPACITY)
        throw HeapException("Trying to add to a full heap.");
    
    //add to bottom/right of tree
    items[itemCount] = newItem;
    int newNode = itemCount;
    bool inPlace = false;
    
    //percolate new node up to proper place
    while (newNode > 0 && !inPlace) {
        int parent = getParent(newNode);
        if (items[newNode] < items[parent])
            inPlace = true;
        else {
//            cout << "Swapping " << items[newNode]
//                    << " and " << items[parent] << endl;
            swap (items[newNode], items[parent]);
            newNode = parent;
        }
    }//new node in place
    
    itemCount++;
    return true;
}
/**
 * Removes all items from the heap
 */
template <class T>
void ArrayMaxHeap<T>::clear() {
    itemCount = 0;
}
/**
 * Returns the number of items in the heap
 * @return the number of items in the heap
 */
template <class T>
int ArrayMaxHeap<T>::getItemCount() const {
    return itemCount;
}
/**
 * Returns the item in the heap with the highest priority
 * @return the item in the heap with the highest priority
 * @throws HeapException if heap is empty
 */
template <class T>
T ArrayMaxHeap<T>::peek() const {
    if (isEmpty()) {
        throw HeapException("Peek called on an empty heap.");
    }
    return items[ROOT_INDEX];
}
/**
 * Removes the item in the heap with the highest priority
 * @return true if successful
 * @throws HeapException if heap is empty
 */
template <class T>
bool ArrayMaxHeap<T>::remove() {
    if (isEmpty())
        throw HeapException("Trying to remove from an empty heap.");
    else {
        items[ROOT_INDEX] = items[itemCount - 1];
        itemCount--;
        percolateDown(ROOT_INDEX);
    }
}
/**
 * Test if heap is empty
 * @return true if empty
 */
template <class T>
bool ArrayMaxHeap<T>::isEmpty() const {
    return (itemCount == 0);
}
//recursive methods
template <class T>
void ArrayMaxHeap<T>::percolateDown(int subtree) {
    if (!isLeaf(subtree)) {
        //isLeaf() is the base case
        int leftChild = getLeftChild(subtree);
        int maxChild = leftChild;
        
        int rightChild = getRightChild(subtree);
        if (rightChild < itemCount) {
            //right child exists
            if (items[rightChild] > items[leftChild])
                maxChild = rightChild;
        }
        
        //maxChild has the index of the largest value of 2 children
        if (items[subtree] < items[maxChild]) {
//            cout << "Swapping " << items[subtree]
//                    << " and " << items[maxChild] << endl;
            swap(items[subtree], items[maxChild]);
            percolateDown(maxChild);
        }
    }
}

//private methods
template <class T>
int ArrayMaxHeap<T>::getLeftChild(int currNode) const {
    return currNode * 2 + 1;
}
template <class T>
int ArrayMaxHeap<T>::getRightChild(int currNode) const {
    return currNode * 2 + 2;
}
template <class T>
int ArrayMaxHeap<T>::getParent(int currNode) const {
    return (currNode - 1) / 2;
}
template <class T>
bool ArrayMaxHeap<T>::isLeaf(int currNode) const {
    return getLeftChild(currNode) >= itemCount;
}

#endif /* ARRAYMAXHEAP_H */

