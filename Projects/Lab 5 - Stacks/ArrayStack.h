#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "Stack_Interface.h"
#include <cassert>

const int MAX_ELEMENTS = 10;

/**
 * @brief A class that implements a stack data structure using an array.
 *
 * This class provides basic stack operations such as push, pop, and peek,
 * along with a method to check if the stack is empty.
 *
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class ArrayStack : public Stack_Interface<T>
{
    public:
        ArrayStack();
        //virtual ~ArrayStack();
        bool isEmpty();
        bool push(const T&newItem);
        bool pop();
        T peek() ;

        //bool isFull();


    private:
        T theStack[MAX_ELEMENTS];
        int top;
};

#endif

template <typename T>
ArrayStack<T>::ArrayStack(){
    top = -1; 
}


template <typename T>
bool ArrayStack<T>::isEmpty(){

    return top == -1; //< 0
}


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




