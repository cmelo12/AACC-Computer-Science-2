#pragma once

#include <iostream>
#include "BinarySearchTreeInterface.h"
#include "Node.h"
//#include "Visitor.h"

//VISITOR PATTERNS
#include "SearchZipCode.h"
#include "SearchStateId.h"
#include "SearchMinArea.h"

#include "listAllCities.h"
#include "SearchPopDensity.h"
#include "ListByTimeZone.h"

#include "MaxLandArea.h"
#include "MaxPop.h"
#include "MinLandArea.h"
#include "MinPop.h"
#include "MaxDensity.h"
#include "MinDensity.h"

#include "IncreasePop.h"
#include "DecreasePop.h"
#include "IncreaseArea.h"
#include "DecreaseArea.h"

using namespace std;

//mine
template <typename T>
class BinarySearchTree : public BSTInterface<T>
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    //interface methods
    bool isEmpty() const;

    bool add(const T& newItem);  

    void clear();
    bool contains(const T& findItem) const;

    //outward facing
    void inOrderTraverse() const;
    void inOrderTraverse(Visitor& visitor) const;
    void preOrderTraverse() const;
    void postOrderTraverse() const;
    void postOrderTraverse(Visitor& visitor) const;

    //void preOrderTraverse() const;

    void print2D(); //outward facing


    //internal methods
private:

    Node<T>* root;

    Node<T>* placeNode(Node<T>* currRoot, Node<T>* newNode);
    bool findNode(Node<T>* currentRoot, const T& toFind) const;
    void print2DUtil(Node<T>* currRoot, int space); //from GeeksForGeeks.com
    
    void inorder(Node<T>* currRoot) const;
    void inorder(Node<T>* currRoot, Visitor& visitor) const;
    void preorderHelper(Node<T>* currRoot) const;
    void postorderHelper(Node<T>* currRoot) const;
    void postorderHelper(Node<T>* currRoot, Visitor& visitor) const;

    
    void deleteTree(Node<T>* currentRoot);


};


template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}



template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {}



//====================isEmpty()================================
//interface methods
template <class T>
bool BinarySearchTree<T>::isEmpty() const {
    return root == nullptr;
}





//===================add() outward facing ===========================
template <class T>
bool BinarySearchTree<T>::add(const T& newItem) {

    if (contains(newItem))
        return false;

    Node<T>* newNode = new Node<T>(newItem);
    root = placeNode(root, newNode);
    return true;

}


//===============placeNode() ----- like add() only inward facing and actually finds the location for the node==========================
template <class T>
Node<T>* BinarySearchTree<T>::placeNode(Node<T>* currRoot, Node<T>* newNode) {
    if (currRoot == nullptr) {
        //cout << "added " << newNode->getItem() << endl;
        return newNode;
    }//end if
    else {
        if (newNode->getItem() < currRoot->getItem()) {
            //cout << "Going left" << endl;
            Node<T>* tempPtr = placeNode(currRoot->getLeftChild(), newNode);
            currRoot->setLeftChild(tempPtr);
        }
        else {
            //cout << "Going right" << endl;
            currRoot->setRightChild(placeNode(currRoot->getRightChild(), newNode));
        }
        return currRoot;
    }
}



//======================inOrder traversal=========================
template <typename T>
void BinarySearchTree<T>::inOrderTraverse() const { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    inorder(root);//, visit);
}

template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* currRoot) const {//, void visit(T& item)) const {
    if (currRoot != nullptr) {
        inorder(currRoot->getLeftChild());             //, visit);

        T item = currRoot->getItem();
        cout << item << "  ";
        //visit()
        inorder(currRoot->getRightChild());             //, visit);
    }

}

///////////////////-----------VISTOR INORDER--------////////////////////////
template <typename T>
void BinarySearchTree<T>::inOrderTraverse(Visitor& visitor) const { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    inorder(root, visitor);
}

template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* currRoot, Visitor& visitor) const {//, void visit(T& item)) const {
    if (currRoot != nullptr) {
        inorder(currRoot->getLeftChild(), visitor);

        
        //visitor.visit(currRoot->getItem());
        T item = currRoot->getItem();
        visitor.visit(item);
        currRoot->setItem(item);

        inorder(currRoot->getRightChild(), visitor);             //, visit);
    }

}


//======================preOrder traversal=========================
template <typename T>
void BinarySearchTree<T>::preOrderTraverse() const {
    if (isEmpty()) {
        cout << "The tree is empty." << endl;
    }
    else {
        preorderHelper(root);
    }
    
}

template <typename T>
void BinarySearchTree<T>::preorderHelper(Node<T>* currRoot) const {
    if (currRoot != nullptr) {
        T item = currRoot->getItem();
        cout << item << "  "; 

        preorderHelper(currRoot->getLeftChild()); 
        preorderHelper(currRoot->getRightChild()); 
    }

}


template<typename T> 
void BinarySearchTree<T>::postOrderTraverse() const {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        
        return;
    }
    postorderHelper(root);

}

template <typename T>
void BinarySearchTree<T>::postorderHelper(Node<T>* currRoot) const {
    if (currRoot != nullptr) {
        postorderHelper(currRoot->getLeftChild());
        postorderHelper(currRoot->getRightChild());

        T item = currRoot->getItem();

        cout << item;
    }//end if 

}//end posthelper
 
////////////////////////////////////////////////////////////////////////////////////VISITOR POST
template<typename T>
void BinarySearchTree<T>::postOrderTraverse(Visitor& visitor) const {
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    postorderHelper(root, visitor);
}

template <typename T>
void BinarySearchTree<T>::postorderHelper(Node<T>* currRoot, Visitor& visitor) const {
    if (currRoot != nullptr) {
        postorderHelper(currRoot->getLeftChild(), visitor);
        postorderHelper(currRoot->getRightChild(), visitor);

        // Call the visitor on the current node's item
        visitor.visit(currRoot->getItem());
    }
}


//=============contains()==============================================
template <typename T>
bool BinarySearchTree<T>::contains(const T& toFind) const {

    return findNode(root, toFind);
    //return false;

}

template <typename T>
bool BinarySearchTree<T>::findNode(Node<T>* currentRoot, const T& toFind) const {
    if (currentRoot == nullptr)
    {
        //cout << "Empty tree" << endl;
        return false;
    }
    else if (currentRoot->getItem() == toFind)
    {
        cout << "Item found." << endl;
        return true;
    }
    else if (toFind < currentRoot->getItem())
        return findNode(currentRoot->getLeftChild(), toFind);
    else
        return findNode(currentRoot->getRightChild(), toFind);
    
    /*if (currentRoot == nullptr)
        return false;
    else if (currentRoot->getItem() == toFind)
        return true;
    else if (toFind < currentRoot->getItem())
        return findNode(currentRoot->getLeftChild(), toFind);
    else
        return findNode(currentRoot->getRightChild(), toFind);*/
    //return false;
}


//============clear()=============================
template<typename T>
void BinarySearchTree<T>::clear() {
    //complete the code here
    //delete(root);
    deleteTree(root);
    root = nullptr;
}

template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* currentRoot) {
    //complete the code here
    if (currentRoot == nullptr)
        return;

    deleteTree(currentRoot->getLeftChild());
    deleteTree(currentRoot->getRightChild());

    //cout << "deleting" << currentRoot.getItem() << endl;
    delete currentRoot;
}


//----------------------------print 2 D - from geeksForGeeks.com

const int COUNT = 10;

// Function to print binary tree in 2D
// It does reverse inorder traversal
//
//  From:  https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
template <typename T>
void BinarySearchTree<T>::print2DUtil(Node<T>* currRoot, int space)
{
    // Base case
    if (currRoot == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(currRoot->getRightChild(), space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << currRoot->getItem() << "\n";

    // Process left child
    print2DUtil(currRoot->getLeftChild(), space);
}



//outward facing
template <typename T>
void BinarySearchTree<T>::print2D()
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}



