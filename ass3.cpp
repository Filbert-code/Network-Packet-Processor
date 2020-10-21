// Author: Alex Filbert
// Date: 10/19/2020
// Course: CS 300B
// Assignment: Homework 3
#include <iostream>
#include "Packet.h"
#include "Buffer.h"
#include "Buffer.cpp"
#include "Response.h"
#include <vector>

using namespace std;

// returns a vectors with the incoming Packets
vector<Packet> readPackets()
{
    int packetNum;
    cin >> packetNum;
    vector<Packet> packetArr; // instantiate the Packet vector

    if (packetNum == 0)
        return packetArr;

    int packetBit1;
    int packetBit2;
    int index;
    // get the data for the Packets and add them to the vector
    for (int i = 0; i < packetNum; ++i)
    {
        cout << '\t';
        cin >> packetBit1 >> packetBit2;
        packetArr.push_back(Packet(packetBit1, packetBit2));
    }
    return packetArr;
}

/* 
    Packet vector argument is fed into the Buffer and a Response vector is returned
    after the Packets are processed and added to the Response vector
*/
vector<Response> processPackets(vector<Packet> packet, Buffer<Packet> &buffer)
{
    vector<Response> responses;
    int processingTime = 0;
    int time = 0;
    int packetsInBuffer = 0;
    int packetIndex = 0;
    int packetsDropped;

    // if the packet vector is empty, add a -2 response to the Response vector
    if (packet.empty())
    {
        Response response(-2);
        responses.push_back(response);
    }

    while (packetsInBuffer != 0 || packetIndex < packet.size())
    {
        // add incoming packets to the buffer
        while (packet[packetIndex].getArrivalTime() == time)
        {
            if (packetsInBuffer < buffer.getBufferSize())
            {
                buffer.enqueue(packet[packetIndex]);
                packetsInBuffer++;
            }
            else
                packetsDropped++;
            packetIndex++;
        }

        // add a Response object with it's time field as -2 if the buffer is empty
        if (packetsInBuffer == 0)
        {
            Response response(-2);
            responses.push_back(response);
        }

        // add responses that indicate dropped packets to the responses vector
        for (int i = 0; i < packetsDropped; ++i)
        {
            Response response(-1);
            responses.push_back(response);
        }
        packetsDropped = 0;

        // remove the next Packet from the buffer and instantiate a Response
        // object with the current time
        if (processingTime == 0)
        {
            Packet pack = buffer.dequeue();
            packetsInBuffer--;
            processingTime = pack.getProcessingTime();
            Response response(time);
            responses.push_back(response);
        }

        // update processingTime
        if (processingTime > 0)
            processingTime--;
        time++;
    }
    return responses;
}

// print the Response vector to the console
void printResponses(vector<Response> responses)
{
    cout << "Output: " << endl;
    for (Response r : responses)
    {
        cout << '\t' << r << endl;
    }
}

int main()
{
    cout << "Input:\n\t";
    int bufferSize;
    cin >> bufferSize;

    vector<Packet> requests = readPackets(); // read packets from user

    // create buffer with the given size
    Buffer<Packet> buffer(bufferSize);

    // process the packets
    vector<Response> responses = processPackets(requests, buffer);

    // print responses
    printResponses(responses);

    return 0;
}