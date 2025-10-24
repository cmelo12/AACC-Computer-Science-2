/**
 * @brief ArrayQueue class implements a queue using a fixed-size array.
 *
 * This class provides the functionality of a queue (FIFO structure) using a circular array.
 * It supports basic queue operations such as enqueue, dequeue, checking if the queue is empty,
 * peeking at the front element, and checking if the queue is full.
 *
 * @tparam T The type of elements stored in the queue.
 * 
 * @author Professor Hall
 * 
 */
#pragma once

#include "QueueInterface.h"
#include <iostream>

const int MAX_SIZE = 24;

using namespace std;

template <typename T>
class ArrayQueue : public QueueInterface<T> {
private:
	int front;
	int rear;
	int size;

	T theQueue[MAX_SIZE];

public:

	/**
	 * @brief Default constructor that initializes an empty queue.
	 */
	ArrayQueue();
	//interface methods
	/**
	 * @brief Destructor for cleanup (currently empty).
	 */
	~ArrayQueue();// destructor for cleanup

	/**
	 * @brief Adds a new element to the end of the queue.
	 *
	 * @param data The data to be added to the queue.
	 * @return true if the element is successfully added, false if the queue is full.
	 */
	bool enqueue(const T& data);  //add to end of queue

	/**
	 * @brief Removes the front element from the queue.
	 *
	 * @return true if the element is successfully removed, false if the queue is empty.
	 */
	bool dequeue();  //remove item from queue

	/**
	 * @brief Checks if the queue is empty.
	 *
	 * @return true if the queue is empty, false otherwise.
	 */
	bool isEmpty() const;

	/**
	 * @brief Returns the front element of the queue without removing it.
	 *
	 * @return The front element of the queue.
	 * @throws std::out_of_range If the queue is empty and a peek is attempted.
	 */
	T peek() const;  //peek at the front of the queue without removing.

	/**
	 * @brief Checks if the queue is full.
	 *
	 * @return true if the queue is full, false otherwise.
	 */
	//non-interface method - only required for arrays
	bool isFull() const;

};


template<typename T>
ArrayQueue<T>::ArrayQueue() {
	front = 0;
	rear = -1;
	size = 0;
}


template<typename T>
ArrayQueue<T>::~ArrayQueue() {}// destructor 




template<typename T>
bool  ArrayQueue<T>::enqueue(const T& data) {
	if (isFull()) {
		cout << "queue is full... can't add " << data << endl;
		return false;
	}
	/*
	!could throw an exception instead
		if (isFUll)
			throw out_of_range("Queue full");
	*/
	rear = (rear + 1) % MAX_SIZE;
	theQueue[rear] = data;
	size++;
	return true;
}





template<typename T>
bool ArrayQueue<T>::dequeue() {  //remove item from front of the queue
	bool success = false;

	if (isEmpty()) {
		cout << "queue is empty " << endl;
		/*
	!could throw an exception instead
		if (isFUll)
			throw out_of_range("Queue empty");
	*/

	}
	else {
		front = (front + 1) % MAX_SIZE;
		size--;
		success = true;
	}

	return success;
}


template<typename T>
bool ArrayQueue<T>::isEmpty() const {
	return size == 0;
}



template<typename T>
T ArrayQueue<T>::peek() const {
	if (!isEmpty())
		return theQueue[front];
}



template<typename T>
bool ArrayQueue<T>::isFull() const {
	return size == MAX_SIZE;
}