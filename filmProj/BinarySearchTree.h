/*
    Filename: BinarySearchTree.h
    Purpose: Defines the interface for a generic Binary Search Tree class that inherits from BinaryTreeADT.
    Author: [Your Name]
    Date: [Today's Date]
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryTreeADT.h"
#include "BinaryNode.h"


// Define the BinarySearchTree template class that inherits from BinaryTreeADT
template <class T>
class BinarySearchTree : public BinaryTreeADT<T>{

public:
    // Constructors and Destructor
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& orig);
    virtual ~BinarySearchTree();
    
    // Interface methods inherited from BinaryTreeADT
    bool isEmpty() const override; // Overriding the base class method
    bool add(const T& newItem) override; // Overriding the base class method
    bool remove(const T& delItem) override; // Overriding the base class method
    void clear() override; // Overriding the base class method
    bool contains(const T& findItem) const override; // Overriding the base class method
    
    // Additional methods specific to BinarySearchTree
    void inorderTraverse(void visit(T& item)) const; // In-order traversal
    
private:
    // Private members
    BinaryNode<T>* root;
    
    // Helper methods for internal operations
    void destroyTree(BinaryNode<T>* currRoot);
    BinaryNode<T>* copyTree(const BinaryNode<T>* currRoot) const;
    BinaryNode<T>* placeNode(BinaryNode<T>* currRoot, BinaryNode<T>* newNode);
    bool findNode(BinaryNode<T>* currRoot, const T& item) const;
    void inorder(BinaryNode<T>* currRoot, void visit(T& item)) const;
};

#include "BinarySearchTree.cpp"

#endif /* BINARYSEARCHTREE_H */

