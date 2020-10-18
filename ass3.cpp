//Starter Code:
#include <iostream>
#include "Packet.h"
//#include "Response.h"
#include "Buffer.h"
#include "Buffer.cpp"
#include "Response.h"

using namespace std;

Packet *readPackets(int packetNum)
{
    Packet *packetArr = new Packet[packetNum];
    int packetBit1;
    int packetBit2;
    cout << "Input:" << endl;
    int index;
    for (int i = 0; i < packetNum + 1; ++i)
    {
        cout << '\t';
        cin >> packetBit1 >> packetBit2;
        packetArr[index] = Packet(packetBit1, packetBit2);
    }
    return packetArr;
}

Response *processPackets(Packet *p, Buffer<Packet> &b)
{
    int bufferSize = p[0].getArrivalTime();
    int totalPackets = p[0].getProcessingTime();

    int numInBuffer;

    for (int i = 1; i < totalPackets; ++i)
    {
        int arrival = p[i].getArrivalTime();
        int pTime = p[i].getProcessingTime();

        numInBuffer++;
        if (numInBuffer > bufferSize)
        {
            cout << -2;
            exit(1);
        }
        // ***STOPPED HERE***
    }
}

//please don't modify main function
int main()
{
    /*
    int bufferSize;
    cin >> bufferSize;
    vector<Packet> requests = readPackets(); //read packets from user

    //create buffer with the given size
    Buffer buffer(size);

    //process the packets
    vector<Response> responses = processPackets(requests, &buffer);

    //print responses
    printResponses(responses);
    */

    int packetNum = 2;

    Packet *requests = readPackets(packetNum);

    Buffer<Packet> buffer(packetNum);

    Response *responses = processPackets(requests, buffer);

    return 0;
}