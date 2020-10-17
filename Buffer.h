#ifndef BUFFER_H
#define BUFFER_H

template <class T>
class Buffer
{
private:
    T *arr;
    int currentSize;
    int front;
    int back;

    void increment(int &inc);
    void doubleQueue();

public:
    Buffer();
    ~Buffer();

    bool isEmpty();
    const T &getFront();

    void makeEmpty();
    T dequeue();
    void enqueue(const T &item);
};

#endif