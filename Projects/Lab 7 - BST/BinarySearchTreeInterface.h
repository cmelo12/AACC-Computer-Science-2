
#ifndef BINARYTREEINTERFACE_H
#define BINARYTREEINTERFACE_H

template <typename T>
class BSTInterface {
public:

    virtual bool isEmpty() const = 0;
    virtual bool add(const T& newItem) = 0;
    //virtual bool remove(const T& delItem) = 0;
    virtual void clear() = 0;
    virtual bool contains(const T& findItem) const = 0;

    virtual void inOrderTraverse() const = 0;
    virtual void preOrderTraverse() const = 0;
    virtual void postOrderTraverse() const = 0;


};

#endif // BINARYTREEINTERFACE_H
