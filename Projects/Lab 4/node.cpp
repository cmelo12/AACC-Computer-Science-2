//DONT USE
#include <iostream>
#include "node.h"


template<typename T>
Node<T>::Node() {
	//value = 0;  //can't intitialize, don't know T
	next = nullptr;
}


template<typename T>
Node<T>::Node(T x) {
	value = x;
	next = nullptr;
}


template<typename T>
Node<T>* Node<T>::getNext() const {
	//returns  a pointer to the next value
	return next;
}


template<typename T>
T Node<T>::getValue() const {
	return value;
}

template<typename T>
void Node<T>::setValue(T value) {
	this->value = value;
}


template<typename T>
void Node<T>::setNext(Node<T>* n) {
	next = n;
}

template<typename T>
void Node<T>::displayValue() const {
	cout << "Value on the node: " << value << endl;
	if (next == nullptr)
		cout << "next is nullptr" << endl;
}


template<typename T>
Node<T>::~Node() {
	cout << "destructor called" << endl;
}
