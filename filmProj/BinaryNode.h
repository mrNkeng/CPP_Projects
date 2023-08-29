/*
    Filename: BinaryNode.h
    Purpose: Provides the interface for a generic Binary Node class 
    that can be used in various types of Binary Trees (e.g., Binary Search Trees, AVL Trees, etc.).
    Author: [Your Name]
    Date: [Today's Date]
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H

// Template class declaration for a Binary Node
template <class T>
class BinaryNode {
public:
    // Default constructor
    BinaryNode();
    // Parameterized constructor with optional pointers for left and right children
    BinaryNode(const T& newItem,
               BinaryNode<T>* left = nullptr, 
               BinaryNode<T>* right = nullptr);
    // Copy constructor
    BinaryNode(const BinaryNode& orig);
    // Destructor
    virtual ~BinaryNode();

    // Getter for the item
    T getItem() const;
    // Setter for the item
    void setItem(const T& newItem);

    // Getter for the left child node
    BinaryNode<T>* getLeftChild() const;
    // Getter for the right child node
    BinaryNode<T>* getRightChild() const;

    // Setter for the left child node
    void setLeftChild(BinaryNode<T>* left);
    // Setter for the right child node
    void setRightChild(BinaryNode<T>* right);

    // Checks if the node is a leaf (i.e., has no children)
    bool isLeaf() const;

private:
    T item;                   // Data item
    BinaryNode<T>* leftChild; // Pointer to the left child node
    BinaryNode<T>* rightChild;// Pointer to the right child node
};

// Include the implementation file to compile the template class
#include "BinaryNode.cpp"

#endif /* BINARYNODE_H */
