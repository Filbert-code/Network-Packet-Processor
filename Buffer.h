#ifndef BUFFER_H
#define BUFFER_H

template <class T>
class Buffer
{
public:
    Buffer(int size);
    ~Buffer() { delete arr; }
    bool isEmpty();
    T &getFront();
    void makeEmpty();
    T dequeue();
    void enqueue(const T &item);

private:
    T *arr;
    int arrSize;
    int currentSize;
    int front;
    int back;

    void increment(int &inc) const;
    void doubleSize();
};

#endif