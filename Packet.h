// Author: Alex Filbert
// Date: 10/19/2020
// Course: CS 300B
// Assignment: Homework 3
#ifndef PACKET_H
#define PACKET_H
#include <ostream>
#include <iostream>
using namespace std;

class Packet
{
private:
    int arrivalTime;    // time when the packet arrives at the buffer
    int processingTime; // time it takes for the packet to process

public:
    Packet() {} // default constructor
    // 2-arg constructor
    Packet(int arrivalTime, int processingTime) : arrivalTime(arrivalTime), processingTime(processingTime) {}
    ~Packet() {} // default destructor
    // overloaded insertion operator that allows for printing the state of the object to the console
    friend ostream &operator<<(ostream &output, Packet p)
    {
        cout << "packet: "
             << "[" << p.arrivalTime << ", " << p.processingTime << "]" << endl;
        return output;
    }
    // getters and setters
    int getArrivalTime() { return arrivalTime; }
    void setArrivalTime(int newArrival) { arrivalTime = newArrival; }
    int getProcessingTime() { return processingTime; }
    void setProcessingTime(int newProcessingtime) { processingTime = newProcessingtime; }
};

#endif