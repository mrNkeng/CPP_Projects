/*
    Filename: BinaryNode.cpp
    Purpose: Provides the implementation for a generic Binary Node class 
    that can be used in Binary Trees.
    Author: [Your Name]
    Date: [Today's Date]
*/

#include "BinaryNode.h"
#include <cstddef>  // For nullptr
#include <iostream>

// Default constructor: initializes left and right children to nullptr
template <class T>
BinaryNode<T>::BinaryNode() : leftChild(nullptr), rightChild(nullptr) {
    // Intentionally empty
}

// Parameterized constructor: initializes the item, left, and right children
template <class T>
BinaryNode<T>::BinaryNode(const T& newItem,
        BinaryNode<T>* left, BinaryNode<T>* right) :
item(newItem), leftChild(left), rightChild(right) {
    // Intentionally empty
}

// Copy constructor: performs a deep copy of the original BinaryNode
template <class T>
BinaryNode<T>::BinaryNode(const BinaryNode& orig) {
    item = orig.item;
    leftChild = orig.leftChild;  // Be cautious, this is a shallow copy for child nodes
    rightChild = orig.rightChild;  // Same caution as above
}

// Destructor
template <class T>
BinaryNode<T>::~BinaryNode() {
    // Uncomment the line below for debugging
    // std::cout << this->getItem().getRanking() << " node destroyed" << std::endl;
}

// Getter for item
template <class T>
T BinaryNode<T>::getItem() const {
    return item;
}

// Setter for item
template <class T>
void BinaryNode<T>::setItem(const T& newItem) {
    item = newItem;
}

// Getter for left child
template <class T>
BinaryNode<T>* BinaryNode<T>::getLeftChild() const {
    return leftChild;
}

// Getter for right child
template <class T>
BinaryNode<T>* BinaryNode<T>::getRightChild() const {
    return rightChild;
}

// Setter for left child
template <class T>
void BinaryNode<T>::setLeftChild(BinaryNode<T>* left) {
    leftChild = left;
}

// Setter for right child
template <class T>
void BinaryNode<T>::setRightChild(BinaryNode<T>* right) {
    rightChild = right;
}

// Checks if the node is a leaf node (i.e., has no children)
template <class T>
bool BinaryNode<T>::isLeaf() const {
    return (leftChild == nullptr && rightChild == nullptr);
}
