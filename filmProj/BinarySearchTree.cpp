/*
    Filename: BinarySearchTree.cpp
    Purpose: Provides the implementation for a generic Binary Search Tree class.
    Author: [Your Name]
    Date: [Today's Date]
*/
#include "BinarySearchTree.h"
#include <iostream>

// Default constructor: initializes root to nullptr
template <class T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {
    // Intentionally empty
}

// Copy constructor: performs deep copy of original tree
template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& orig) {
    // Deep copy is performed by the copyTree function
    root = this->copyTree(orig.root);
}


// Destructor: deallocates memory and clears tree
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    this->clear();
}

// Checks if the tree is empty
template <class T>
bool BinarySearchTree<T>::isEmpty() const {
    return (root == nullptr);
}

// Adds a new item to the tree
template <class T>
bool BinarySearchTree<T>::add(const T& newItem) {
    BinaryNode<T>* newNode = new BinaryNode<T>(newItem);
    root = placeNode(root, newNode);
    return true;
}

// Checks if the tree contains an item
template <class T>
bool BinarySearchTree<T>::contains(const T& findItem) const {
    return findNode(root, findItem);
}

// Removes an item from the tree (not yet implemented)
template <class T>
bool BinarySearchTree<T>::remove(const T& delItem) {
    return false; 
}

// Clears the tree
template <class T>
void BinarySearchTree<T>::clear() {
    destroyTree(root);
    root = nullptr;
}

// Helper function to perform deep copy of a tree
template <class T>
BinaryNode<T>* BinarySearchTree<T>::copyTree(const BinaryNode<T>* currRoot) const {
    BinaryNode<T>* newTree = nullptr;
    if (currRoot != nullptr) {
        newTree = new BinaryNode<T>(currRoot->getItem(), nullptr, nullptr);
        newTree->setLeftChild(copyTree(currRoot->getLeftChild()));
        newTree->setRightChild(copyTree(currRoot->getRightChild()));
    }
    return newTree;
}

// Helper function to find a node in the tree
template <class T>
bool BinarySearchTree<T>::findNode(BinaryNode<T>* currRoot, const T& item) const {
    if (currRoot == nullptr)
        return false;
    else if (currRoot->getItem() == item)
        return true;
    else if (item < currRoot->getItem()) 
        return findNode(currRoot->getLeftChild(), item);
    else
        return findNode(currRoot->getRightChild(), item);
}

// Helper function to place a node in the tree
template <class T>
BinaryNode<T>* BinarySearchTree<T>::placeNode(BinaryNode<T>* currRoot, BinaryNode<T>* newNode) {
    if (currRoot == nullptr)
        return newNode;
    else {
        if (newNode->getItem() < currRoot->getItem()) {
            BinaryNode<T>* tempPtr = placeNode(currRoot->getLeftChild(), newNode);
            currRoot->setLeftChild(tempPtr);
        } else {
            currRoot->setRightChild(placeNode(currRoot->getRightChild(), newNode));
        }
        return currRoot;
    }
}

// Helper function to destroy the tree and deallocate memory
template <class T>
void BinarySearchTree<T>::destroyTree(BinaryNode<T>* currRoot) {
    if (currRoot != nullptr) {
        destroyTree(currRoot->getLeftChild());
        destroyTree(currRoot->getRightChild());
        delete currRoot;
        currRoot = nullptr;
    }
}

// Performs an in-order traversal of the tree
template <class T>
void BinarySearchTree<T>::inorderTraverse(void visit(T& item)) const {
    inorder(root, visit);
}

// Helper function for in-order traversal
template <class T>
void BinarySearchTree<T>::inorder(BinaryNode<T>* currRoot, void visit(T& item)) const {
    if (currRoot != nullptr) {
        inorder(currRoot->getLeftChild(), visit);
        T item = currRoot->getItem();
        visit(item);
        inorder(currRoot->getRightChild(), visit);
    }
}
