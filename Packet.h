#ifndef PACKET_H
#define PACKET_H

class Packet
{
private:
    int arrivalTime;
    int processingTime;

public:
    Packet(int arrivalTime, int processingTime) : arrivalTime(arrivalTime), processingTime(processingTime) {}
    ~Packet();
    // getters and setters
    int getArrivalTime() { return arrivalTime; }
    void setArrivalTime(int newArrival) { arrivalTime = newArrival; }
    int getProcessingTime() { return processingTime; }
    void setProcessingTime(int newProcessingtime) { processingTime = newProcessingtime; }
};

#endif