/**
 * @brief Interface class for a generic queue structure.
 *
 * This abstract class defines the basic operations that any queue implementation must provide.
 * The queue follows the First-In-First-Out (FIFO) principle, where elements are added to the
 * end of the queue and removed from the front.
 *
 * @tparam T The type of elements stored in the queue.
 * 
 * @author Professor Hall
 * 
 */

#pragma once

template<typename T>
class QueueInterface {
public:

    /**
     * @brief Adds an element to the end of the queue.
     *
     * This method must be implemented by any class inheriting from QueueInterface.
     *
     * @param data The data to be added to the queue.
     * @return true if the element is successfully added, false otherwise.
     */
    virtual bool enqueue(const T& data) = 0;  //add to end of queue

    /**
    * @brief Removes an element from the front of the queue.
    *
    * This method must be implemented by any class inheriting from QueueInterface.
    *
    * @return true if the element is successfully removed, false otherwise.
    */
    virtual bool dequeue() = 0;  //remove item from queue

    /**
     * @brief Checks if the queue is empty.
     *
     * This method must be implemented by any class inheriting from QueueInterface.
     *
     * @return true if the queue is empty, false otherwise.
     */
    virtual bool isEmpty() const = 0;

    /**
     * @brief Retrieves the front element of the queue without removing it.
     *
     * This method must be implemented by any class inheriting from QueueInterface.
     *
     * @return The front element of the queue.
     * @throws std::out_of_range If the queue is empty and a peek is attempted.
     */
    virtual T peek() const = 0;  //peek at the front of the queue without removing.
};
