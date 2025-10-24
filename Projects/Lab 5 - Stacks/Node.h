#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
    public:
        Node<T>();
        ~Node<T>();

        Node<T>(T, Node<T>*);
        T getData();
        void setNext(Node<T> *);
        Node<T>* getNext();

    private:
        T data;
        Node<T> *next;
};

#endif // NODE_H



template<typename T>
Node<T>::Node()
{
    next = nullptr;
}


template<typename T>
Node<T>::~Node()
{

}


template<typename T>
Node<T>::Node(T data, Node<T>* next){
    this->data = data;
    this->next = next;
}



template<typename T>
void Node<T>::setNext(Node<T> *next){
    this->next = next;
}


template<typename T>
Node<T>* Node<T>::getNext(){
    return next;
}



template<typename T>
T Node<T>::getData(){
    return data;
}