/**
 * @brief LinkedQueue class implements a queue using a linked list structure.
 *
 * This class provides the functionality of a queue (FIFO structure) using dynamically allocated
 * nodes. It supports basic queue operations such as enqueue, dequeue, checking if the queue is empty,
 * and peeking at the front element.
 *
 * @tparam T The type of elements stored in the queue.
 * 
 * @author Professor Hall
 */

#pragma once

#include "QueueInterface.h"
#include "Node.h"
using namespace std;

template <typename T>
class LinkedQueue : public QueueInterface<T> {
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    /**
     * @brief Default constructor that initializes an empty queue.
     */
    LinkedQueue();
    /**
     * @brief Destructor that deallocates memory used by the queue.
     */
    //my addition
    ~LinkedQueue();

    //interface
    /**
     * @brief Adds a new element to the rear of the queue.
     *
     * @param data The data to be added to the queue.
     * @return true if the element is successfully added, false otherwise.
     */
    bool enqueue(const T& data);

    /**
     * @brief Removes the front element from the queue.
     *
     * @return true if the element is successfully removed, false otherwise.
     * @throws out_of_range If the queue is empty and a dequeue is attempted.
     */
    bool dequeue();

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
     * @throws out_of_range If the queue is empty and a peek is attempted.
     */
    T peek() const;


};

//my addition
template<typename T>
LinkedQueue<T>::~LinkedQueue() {

}

template<typename T>
LinkedQueue<T>::LinkedQueue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}


template<typename T>
bool LinkedQueue<T>::enqueue(const T& newItem) {
    Node<T>* newNode = new Node<T>(newItem);

    if (isEmpty())
        front = rear = newNode;
    else {
        rear->setNext(newNode);
        rear = newNode;
    }

    size++;
    return true;

}


template<typename T>
bool LinkedQueue<T>::dequeue() {


    if (isEmpty())
        throw out_of_range("empty queue, cannot dequeue");



    Node<T>* temp = front;
    front = front->getNext();

    if (front == nullptr)
        rear = nullptr;

    delete temp;
    size--;


    return true;


}



template<typename T>
bool LinkedQueue<T>::isEmpty() const {
    return size == 0;
}



template<typename T>
T LinkedQueue<T>::peek() const {
    if (isEmpty()) {
        throw out_of_range("queue is empty, nothing to peek");
    }
    return front->getItem();
}
