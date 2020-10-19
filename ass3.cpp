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
    for (int i = 0; i < packetNum; ++i)
    {
        cout << '\t';
        cin >> packetBit1 >> packetBit2;
        packetArr.push_back(Packet(packetBit1, packetBit2));
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
    int packetIndex = 0;

    while (processing)
    {
        // add incoming packets to the buffer
        while (packet[packetIndex].getArrivalTime() == time)
        {
            buffer.enqueue(packet[packetIndex++]);
            packetsInBuffer++;
        }

        if (packetsInBuffer == 0 && packetIndex == packet.size())
        {
            processing = false;
            break;
        }

        if (packetsInBuffer == 0)
        {
            Response response(-2);
            responses.push_back(response);
            //processing = false;
            break;
        }

        // get the processing time of the next packet
        if (pTime == 0)
        {
            Packet pack = buffer.dequeue();
            packetsInBuffer--;
            pTime = pack.getProcessingTime();
            Response response(time);
            responses.push_back(response);
        }

        if (pTime > 0)
            pTime--;
        time++;
    }
    return responses;
}

void printResponses(vector<Response> responses)
{
    cout << "Output: " << endl;
    for (Response r : responses)
    {
        cout << '\t' << r << endl;
    }
}

//please don't modify main function
int main()
{
    cout << "Enter [bufferSize numOfPackets]: "
         << "\n\t";
    int bufferSize;
    int numOfPackets;
    cin >> bufferSize >> numOfPackets;

    vector<Packet> requests = readPackets(numOfPackets);

    Buffer<Packet> buffer(bufferSize);

    vector<Response> responses = processPackets(requests, buffer);

    printResponses(responses);

    return 0;
}