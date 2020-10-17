#ifndef BUFFER_H
#define BUFFER_H

template <class T>
class Buffer
{
private:
    T *arr;
    int arrSize;
    int currentSize;
    int front;
    int back;

    void increment(int &inc);
    void doubleQueue();

public:
    Buffer(int size);
    ~Buffer();

    bool isEmpty();
    const T &getFront();

    void makeEmpty();
    T dequeue();
    void enqueue(const T &item);
};

#endif