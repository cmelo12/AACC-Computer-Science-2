#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

/**
 * @brief Abstract interface for a stack data structure.
 *
 * @details
 * This template-based interface defines the basic operations for a stack.
 * Classes that inherit from `Stack_Interface` must implement the following functions:
 * - `isEmpty()`: Checks whether the stack is empty.
 * - `push(const T&)`: Pushes an item of type `T` onto the stack.
 * - `pop()`: Removes the top item from the stack.
 * - `peek()`: Retrieves (but does not remove) the top item from the stack.
 *
 * @tparam T The data type of the elements stored in the stack.
 */
template<typename T>
class Stack_Interface
{
    public:
        /**
         * @brief Checks whether the stack is empty.
         *
         * @return bool `true` if the stack is empty, `false` otherwise.
         */
        virtual bool isEmpty() = 0;

        /**
         * @brief Pushes an element onto the stack.
         *
         * @param item The element of type `T` to be added to the stack.
         * @return bool `true` if the operation was successful, `false` otherwise.
         */
        virtual bool push(const T&) = 0;

        /**
         * @brief Removes the top element from the stack.
         *
         * @return bool `true` if the operation was successful, `false` otherwise.
         */
        virtual bool pop()  = 0;

        /**
         * @brief Retrieves the top element from the stack without removing it.
         *
         * @return T The top element of the stack.
         */
        virtual T peek() = 0;

};

#endif 
