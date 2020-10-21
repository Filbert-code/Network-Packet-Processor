// Author: Alex Filbert
// Date: 10/19/2020
// Course: CS 300B
// Assignment: Homework 3
#ifndef BUFFER_H
#define BUFFER_H

template <class T>
class Buffer
{
public:
    Buffer(int size);                       // 1-arg constructor
    ~Buffer();                              // destructor for deleting the dynamic array
    bool isEmpty();                         // returns true if empty
    T &getFront();                          // returns a reference of the front item
    void makeEmpty();                       // empties the array and resets the front and back indices
    T dequeue();                            // removes and returns the item at the front of the queue
    void enqueue(const T &item);            // adds an item to the back of the queue
    int getBufferSize() { return arrSize; } // return the size of the buffer

private:
    T *arr;          // dynamic array
    int arrSize;     // size of dynamic array
    int currentSize; // number of items in the queue
    int front;       // index of the front of the queue
    int back;        // index of the back of the queue

    void increment(int &inc) const; // increments the front and back variables
    void doubleSize();              // doubles the capacity of the buffer
};

#endif