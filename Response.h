#ifndef RESPONSE_H
#define RESPONSE_H
#include "Buffer.h"
#include "Packet.h"
#include <ostream>

class Response
{
private:
    int milliseconds;

public:
    Response(int time) : milliseconds(time) {}
    friend ostream &operator<<(ostream &output, Response &r)
    {
        output << r.milliseconds << endl;
        return output;
    }
};

#endif