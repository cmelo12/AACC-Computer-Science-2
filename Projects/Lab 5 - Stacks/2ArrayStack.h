#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <cassert>
#include "Stacks_Interface.h"

const int MAX_ELEMENTS = 10;

/**
 * @brief Array-based implementation of the `Stack_Interface`.
 *
 * @details
 * This class implements a stack using a fixed-size array. The stack supports basic operations like:
 * - `push()`: Add an item to the top of the stack.
 * - `pop()`: Remove the top item from the stack.
 * - `peek()`: Retrieve the top item without removing it.
 *
 * The stack has a maximum capacity of 10 elements (`MAX_ELEMENTS`), and it tracks the current top
 * of the stack using an internal `top` index.
 *
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class ArrayStack : public Stack_Interface<T>
{
    public:

        /**
         * @brief Default constructor. Initializes the stack as empty.
         *
         * @details
         * The `top` index is initialized to `-1`, indicating an empty stack.
         */
        ArrayStack();

        //virtual ~ArrayStack();
        
        /**
         * @brief Checks whether the stack is empty.
         *
         * @return bool `true` if the stack is empty, `false` otherwise.
         */
        bool isEmpty();

        /**
         * @brief Pushes an item onto the stack.
         *
         * @param newItem The item of type `T` to be added to the top of the stack.
         *
         * @return bool `true` if the item was successfully pushed onto the stack, `false` otherwise (e.g., if the stack is full).
         */
        bool push(const T&newItem);

        /**
        * @brief Removes the top item from the stack.
        *
        * @return bool `true` if the item was successfully removed, `false` otherwise (e.g., if the stack is empty).
        */
        bool pop();

        /**
         * @brief Retrieves the top item of the stack without removing it.
         *
         * @return T The top item of the stack.
         *
         * @throws `assert` if the stack is empty when attempting to peek.
         */
        T peek() ;
        //bool isFull();


    private:
        T theStack[MAX_ELEMENTS];
        int top;
};

#endif

template <typename T>
ArrayStack<T>::ArrayStack(){
    top = -1; //index 0 will be the top of the stack, this could easily be MAX_ELEMENTS and the top would be the end of the array
}


template <typename T>
bool ArrayStack<T>::isEmpty(){

    return top == -1; //< 0
}

//template <typename T>
//bool ArrayStack<T>::isFull() {
//    if ()
//}

template <typename T>
bool ArrayStack<T>::push(const T&newItem){
    bool okToPush = false;
    if (top < MAX_ELEMENTS - 1){
        top++;
        theStack[top] = newItem;
        okToPush = true;
    }//end if

    return okToPush;

}



template <typename T>
bool ArrayStack<T>::pop(){

    bool popped = false;

    if (!isEmpty()){
        top--;
        popped = true;

    }

    return popped;
}



template<typename T>
T ArrayStack<T>::peek() {
    assert(!isEmpty());  

    return theStack[top];

}




