//Starter Code:
#include <iostream>
#include "Packet.h"
#include "Buffer.h"
#include "Buffer.cpp"
#include "Response.h"
#include <vector>

using namespace std;

vector<Packet> readPackets(int packetNum)
{
    vector<Packet> packetArr;
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

vector<Response> processPackets(vector<Packet> packet, Buffer<Packet> &buffer)
{
    vector<Response> responses;
    int pTime = 0;
    int time = 0;
    int packetsInBuffer = 0;
    bool processing = true;
    int packetIndex;

    while (processing)
    {
        // add incoming packets to the buffer
        while (packet[packetIndex].getArrivalTime() == time)
        {
            buffer.enqueue(packet[packetIndex++]);
            packetsInBuffer++;
        }

        // get the processing time of the next packet
        if (pTime == 0 && buffer.getFront().getArrivalTime() == time)
        {
            Packet pack = buffer.dequeue();
            packetsInBuffer--;
            pTime = pack.getProcessingTime();
            Response response(time);
            responses.push_back(response);

            if (packetsInBuffer == 0 && packet.size() == 0)
            {
                cout << -2 << endl;
                processing = false;
            }
        }

        if (pTime > 0)
            pTime--;
    }
    return responses;
}

void printResponses(vector<Response> responses)
{
    for (Response r : responses)
    {
        cout << '\n'
             << r << endl;
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

    int bufferSize;
    cin >> bufferSize;

    vector<Packet> requests = readPackets(bufferSize);

    Buffer<Packet> buffer(bufferSize);

    vector<Response> responses = processPackets(requests, buffer);

    printResponses(responses);

    return 0;
}