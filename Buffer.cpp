#include "Buffer.h"
#include <iostream>
using namespace std;

// 1-arg constructor that calls the makeEmpty member function.
template <class T>
Buffer<T>::Buffer(int size)
{
    arrSize = size;
    makeEmpty();
}

/* 
    Increase the index of front or back by one and check if 
    either front or back is equal to the size of the array. 
    If so, set the index back to zero. 
*/
template <class T>
void Buffer<T>::increment(int &inc) const
{
    if (++inc == arrSize)
        inc = 0;
}

// returns true if the buffer is empty
template <class T>
bool Buffer<T>::isEmpty()
{
    return currentSize == 0;
}

// Insert an item into the buffer.
template <class T>
void Buffer<T>::enqueue(const T &item)
{
    if (currentSize == arrSize)
    {
        cout << "-1" << endl;
        return;
    }

    increment(back);
    arr[back] = item;
    currentSize++;
}

// Return and remove the last inserted item from the buffer.
// A UnderflowException will be thrown if the buffer is empty.
template <class T>
T Buffer<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Buffer is empty." << endl;
        exit(1);
    }
    currentSize--;

    T frontItem = arr[front];
    increment(front);
    return frontItem;
}

// Returns the item at the front of the buffer
template <class T>
T &Buffer<T>::getFront()
{
    if (isEmpty())
    {
        cout << "Buffer is empty." << endl;
        exit(1);
    }

    return arr[front];
}

// Doubles the size of the buffer
template <class T>
void Buffer<T>::doubleSize()
{
    // resizing the array
    T *temp = new T[arrSize * 2 + 1];
    for (int i = 0; i < arrSize; ++i)
        temp[i] = arr[i];
    delete[] arr;
    arr = temp;
    delete[] temp;
    // shift elements in the array to the correct indeces
    if (front != 0)
    {
        for (int i = 0; i < front; i++)
            arr[i + currentSize] = arr[i];
        back += currentSize;
    }
}

// Empties the buffer; also called by the 1-arg constructor
template <class T>
void Buffer<T>::makeEmpty()
{
    currentSize = 0; // number of element in the queue
    front = 0;
    back = -1;
    arr = new T[arrSize]; // dynamic array
}