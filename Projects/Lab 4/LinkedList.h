/**
 * @file LinkedList.h
 * @brief This is a template for LinkedList objects. It includes methods to handle and manipulate
 *			the items in the LinkedList.
 *
 * @author Caua Melo
 * @date 09/2024
 */

#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "node.h"

/**
  * @brief A templated LinkedList class that stores elements of type T.
  *
  * This class provides several operations to manage and interact with a singly linked list of elements.
  * It includes methods for adding elements, searching, counting frequency, and displaying items in various ways.
  *
  * @tparam T The type of elements stored in the LinkedList.
  */
template<typename T>
class LinkedList {
private:
	Node<T>* head;
	int numItems;

public:
	LinkedList();
	~LinkedList();

	int size() const;
	int countFrequency(const T& searchItem) const;
	bool searchVal(const T& searchItem) const;
	void displayFromFrontToN(int user) const;
	void displayFromNtoEnd(const T& user) const;
	void displayInRows() const;
	bool add(const T& newItem);
};

/**
 * @brief Default constructor for the LinkedList class.
 *
 * Initializes an empty LinkedList by setting the head pointer to nullptr and the number of items to 0.
 *
 * @tparam T The type of elements to be stored in the LinkedList.
 */
template<typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	numItems = 0;

}//end default constructor 

/**
 * @brief Destructor for the LinkedList class.
 *
 * Cleans up the LinkedList by releasing any dynamically allocated memory and ensuring that all nodes are properly deleted.
 * This prevents memory leaks when the LinkedList object is destroyed.
 *
 * @tparam T The type of elements stored in the LinkedList.
 */
template<typename T>
LinkedList<T>::~LinkedList() {

}//end destructor

/**
 * @brief Adds a new item to the head of the LinkedList.
 *
 * This method creates a new node containing the specified item and inserts it at the head of the list.
 * If the list is empty, the new node becomes the head. Otherwise, the new node is added before the current head.
 *
 * @tparam T The type of the item to be added to the LinkedList.
 * @param newItem The item to be added to the list.
 * @return bool Returns true if the item was successfully added to the list.
 */
template<typename T>
bool LinkedList<T>::add(const T& newItem) {
	Node<T>* n = new Node<T>(newItem);
	if (head == nullptr) 
		head = n;
	else {
		n->setNext(head);
		head = n;
	}
	numItems++;
	return true;
}//end add

/**
 * @brief Retrieves the number of items currently in the LinkedList.
 *
 * This method returns the total count of elements in the list by accessing the private variable 
 * `numItems`, which tracks the number of nodes in the list.
 *
 * @tparam T The type of elements stored in the LinkedList.
 * @return int The number of items in the list.
 */
template<typename T>
int LinkedList<T>::size() const {
	return numItems;

}//end size

/**
 * @brief Counts the frequency of a specific item in the LinkedList.
 *
 * This method iterates through the LinkedList and counts how many times the specified item appears
 * by comparing each node's value with the given search item.
 *
 * @tparam T The type of elements stored in the LinkedList.
 * @param searchItem The item whose frequency is to be counted in the list.
 * @return int The number of occurrences of the specified item in the list.
 */
template<typename T>
int LinkedList<T>::countFrequency(const T& searchItem) const {
	Node<T>* current = head;
	int numItemsFound = 0;

	while (current != nullptr) {
		if (current->getValue() == searchItem)
			numItemsFound++;

		current = current->getNext();
	}

	return numItemsFound;

}//end count frequency

/**
 * @brief Searches for a specific item in the LinkedList.
 *
 * This method traverses the LinkedList to determine if the specified item exists. If the item is found,
 * it sets a flag to true and outputs a message indicating the item's presence. If not found, it outputs a
 * message indicating the item is not present.
 *
 * @tparam T The type of elements stored in the LinkedList.
 * @param searchItem The item to search for in the list.
 * @return bool Returns true if the item is found, otherwise false.
 */
template<typename T>
bool LinkedList<T>::searchVal(const T& searchItem) const {
	Node<T>* current = head;
	bool found = false;

	while (current != nullptr) {
		if (current->getValue() == searchItem)
			found = true;

		current = current->getNext();
	}

	if (found == true)
		cout << "Item found in the list." << endl;
	else
		cout << "Item not found." << endl;

	return found;

}//end searchVal

/**
 * @brief Displays the elements of the LinkedList from the front up to the specified position.
 *
 * This method outputs the values of the nodes in the LinkedList starting from the head
 * and continuing to the nth position specified by the user. If the list is empty, a message indicating this is shown.
 * If the input is negative, or if the user requests more items than exist in the list, 
 * appropriate messages are displayed.
 *
 * If the list is empty, a message indicating this is shown. If the user input is greater than
 * the number of items in the list, the entire list is displayed. 
 * 
 * @tparam T The type of elements stored in the LinkedList.
 * @param user The position in the list up to which the elements will be displayed.
 *
 */
template <typename T>
void LinkedList<T>::displayFromFrontToN(int user) const {
	if (head == nullptr)
		cout << "List is empty" << endl;
	else if (user < 0)
		cout << "Invalid input" << endl;
	else if (user > numItems) {
		cout << "Your input is bigger than the amount of items in the list. " <<
			"This is the entire list." << endl;
		Node<T>* current = head;

		for (int i = 0; i < numItems; i++) {
			current->displayValue();
			cout << " " << endl;
			current = current->getNext();
		}
	}
	else {
		Node<T>* current = head;

		for (int i = 0; i < user; i++) {
			current->displayValue();
			cout << " " << endl;
			current = current->getNext();
		}
	}//

}//end displayFromFrontToN

/**
 * @brief Displays the elements of the LinkedList from the specified position to the end.
 *
 * This method outputs the values of the nodes in the LinkedList starting from the nth position
 * specified by the user until the end of the list. If the list is empty, a message is shown
 * If the input is invalid (negative or greater than the number of items in the list), 
 * an appropriate message is displayed.
 *
 * @tparam T The type of elements stored in the LinkedList.
 * @param userN The position in the list from which to start displaying elements.
 */
template <typename T>
void LinkedList<T>::displayFromNtoEnd(const T& userN) const {
	if (head == nullptr)
		cout << "List is empty" << endl;
	else if (userN < 0 || userN > numItems)
		cout << "Invalid input. Input is either negative or bigger than the list number" << 
		" of items" << endl;
	else {
		Node<T>* current = head;

		for (int i = 1; i < userN; i++)
			current = current->getNext();

		while (current != nullptr) {
			current->displayValue();
			cout << " " << endl;
			current = current->getNext();
		}
	}//

}//end displayFromNtoEnd

/**
 * @brief Displays the elements of the LinkedList in a formatted row layout.
 *
 * This method outputs the values of the nodes in the LinkedList in rows,
 * with the number of items per row determined by user input. If the list
 * is empty, a message indicating this is displayed.
 *
 * @tparam T The type of elements stored in the LinkedList.
 */
template <typename T>
void LinkedList<T>::displayInRows() const {
	int counter = 0;
	int itemsPerRow = 0;
	Node<T>* current = head;

	if (head == nullptr) {
		cout << "List is empty" << endl;

	}//end if

	cout << "Enter the number of items to display in a line" << endl;
	cin >> itemsPerRow;

	while (current != nullptr) {
		cout << setw(20) << current->getValue();
		counter++;

		if (counter == itemsPerRow) {
			cout << "\n";
			counter = 0;
		}//end if

		current = current->getNext();

	}//end while

}//end displayInRows*/
