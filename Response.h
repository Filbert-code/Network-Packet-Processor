#ifndef RESPONSE_H
#define RESPONSE_H
#include "Buffer.h"
#include "Packet.h"

class Response
{
private:
    int milliseconds;
    Packet p;

// plug in the next packet and the current state of the buffer to find the next state
public:
    Response(Packet &next, ) {}
};

#endif