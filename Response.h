// Author: Alex Filbert
// Date: 10/19/2020
// Course: CS 300B
// Assignment: Homework 3
#ifndef RESPONSE_H
#define RESPONSE_H
#include "Buffer.h"
#include "Packet.h"
#include <ostream>

class Response
{
private:
    int milliseconds; // time when the packet starts processing

public:
    Response(int time) : milliseconds(time) {}
    // overloading the insertion operator to print Response's state
    friend ostream &operator<<(ostream &output, Response &r)
    {
        output << r.milliseconds;
        return output;
    }
};

#endif