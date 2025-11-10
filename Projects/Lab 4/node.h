/**
 * @file node.h
 * @brief This programs initializes Nodes and allows for manipulations.
 *
 * @author Caua Melo
 * @date 09/2024
 */

#pragma once
#include <iostream>

using namespace std;

/**
 * @brief A template class representing a node in a linked list.
 *
 * This class defines a node that contains a value of type T and a pointer to the next node
 * in the linked list. It provides methods to get and set the value and next node,
 * as well as to display the value.
 *
 * @tparam T The type of the value stored in the node.
 */
template<typename T>
class Node {

private:
	T value;
	Node<T>* next;

public:
	Node();
	Node(T);
	~Node();  


	Node<T>* getNext() const;

	void setNext(Node<T>*);

	T getValue() const;

	void setValue(T);

	void displayValue() const;


}; 

/**
 * @brief Default constructor for the Node class.
 *
 * Initializes the next pointer to nullptr.
 */
template<typename T>
Node<T>::Node() {
	next = nullptr;
}

/**
 * @brief Parameterized constructor for the Node class.
 *
 * Initializes the node with the given value and sets the next pointer to nullptr.
 *
 * @param x The value to be stored in the node.
 */
template<typename T>
Node<T>::Node(T x) {
	value = x;
	next = nullptr;
}

/**
 * @brief Retrieves the pointer to the next node.
 *
 * @return Node<T>* Pointer to the next node in the linked list.
 */
template<typename T>
Node<T>* Node<T>::getNext() const {
	return next;
}

/**
 * @brief Retrieves the value stored in the node.
 *
 * @return T The value of the node.
 */
template<typename T>
T Node<T>::getValue() const {
	return value;
}

/**
 * @brief Sets the value of the node.
 *
 * @param value The value to be set for the node.
 */
template<typename T>
void Node<T>::setValue(T value) {
	this->value = value;
}

/**
 * @brief Sets the pointer to the next node.
 *
 * @param n Pointer to the next node to be set.
 */
template<typename T>
void Node<T>::setNext(Node<T>* n) {
	next = n;
}

/**
 * @brief Displays the value of the node.
 *
 * This method outputs the value stored in the node to the console.
 */
template<typename T>
void Node<T>::displayValue() const {
	cout << value << endl;
}

/**
 * @brief Destructor for the Node class.
 *
 * Cleans up any resources used by the node.
 * In this case, no specific resource management is required.
 */
template<typename T>
Node<T>::~Node() { }
