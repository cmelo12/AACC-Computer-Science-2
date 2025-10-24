/**
 * @brief Node class represents a single node in a linked data structure.
 *
 * This class provides the basic structure and operations for a node in a linked list.
 * Each node holds an item of type T and a pointer to the next node in the sequence.
 *
 * @tparam T The type of the item stored in the node.
 * 
 * @author Professor Hall
 * 
 */
#pragma once

template<typename T>
class Node {

private:
	T itemOnTheNode;
	Node<T>* next;

public:

	/**
	 * @brief Default constructor that initializes an empty node with a null pointer.
	 */
	Node();

	/**
	 * @brief Parameterized constructor that initializes a node with the provided item.
	 *
	 * @param newItem The data to be stored in the node.
	 */
	Node(T);

	/**
	 * @brief Retrieves the item stored in the node.
	 *
	 * @return The item of type T stored in the node.
	 */
	T getItem() const;

	/**
	* @brief Retrieves the pointer to the next node in the list.
	*
	* @return A pointer to the next node in the linked list.
	*/
	Node<T>* getNext() const;

	/**
	 * @brief Sets the pointer to the next node in the list.
	 *
	 * @param nextNode A pointer to the next node to be linked.
	 */
	void setNext(Node<T>* nextNode);

};

template<typename T>
Node<T>::Node() {
	next = nullptr;
}


template<typename T>
Node<T>::Node(T newItem) {
	itemOnTheNode = newItem;
	next = nullptr;
}



template<typename T>
T Node<T>::getItem() const {
	return itemOnTheNode;
}

template<typename T>
Node<T>* Node<T>::getNext() const {
	return next;
}

template<typename T>
void Node<T>::setNext(Node<T>* nextNode) {
	next = nextNode;
}
