#include "buffer.h"

template <class T>
Buffer<T>::Buffer(int size)
{
    makeEmpty();
}

template <class T>
void Buffer<T>::increment(int &inc)
{
    if (++inc == arrSize)
        inc = 0;
}

template <class T>
bool Buffer<T>::isEmpty()
{
    return currentSize;
}

template <class T>
void Buffer<T>::enqueue(const T &item)
{
    if (currentSize == arrSize)
        doubleQueue();
    increment(back);
    arr[back] = item;
    currentSize++;
}

template <class T>
void Buffer<T>::doubleQueue()
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

template <class T>
void Buffer<T>::makeEmpty()
{
    currentSize = 0; // number of element in the queue
    front = 0;
    back = -1;
    arrSize = size;
    arr = new T[size]; // dynamic array
}