// BinaryTreeADT.h

#ifndef BINARY_TREE_ADT_H
#define BINARY_TREE_ADT_H

template <class T>
class BinaryTreeADT {
public:
    virtual ~BinaryTreeADT() {}

    virtual bool isEmpty() const = 0;
    virtual bool add(const T& newItem) = 0;
    virtual bool remove(const T& delItem) = 0;
    virtual void clear() = 0;
    virtual bool contains(const T& findItem) const = 0;
};

#endif /* BINARY_TREE_ADT_H */
