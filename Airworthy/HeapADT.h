/*
 * File: HeapADT.cpp
 * Author: Aminkeng Nkeng
 *
 * This file presumably contains the definition and perhaps some implementation
 * of a heap ADT (Abstract Data Type), which serves as a foundational interface
 * for heap operations. ArrayMaxHeap should be an implementation of this ADT.
 */


#ifndef HEAPADT_H
#define HEAPADT_H

template <class T>
class HeapADT {
    public:
        virtual bool isEmpty() const = 0;
        virtual int getItemCount() const = 0;
        virtual T peek() const = 0;
        virtual bool add(const T& newItem) = 0;
        virtual bool remove() = 0;
        virtual void clear() = 0;
};

#endif /* HEAPADT_H */

