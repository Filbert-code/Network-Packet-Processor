#ifndef PACKET_H
#define PACKET_H
#include <ostream>
#include <iostream>
using namespace std;

class Packet
{
private:
    int arrivalTime;
    int processingTime;

public:
    Packet() {}
    Packet(int arrivalTime, int processingTime) : arrivalTime(arrivalTime), processingTime(processingTime) {}
    ~Packet() {}
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