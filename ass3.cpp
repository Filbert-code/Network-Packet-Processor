//Starter Code:
#include <iostream>
#include "Packet.h"
//#include "Response.h"
#include "Buffer.h"
#include "Buffer.cpp"

using namespace std;

//…

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

    Buffer<Packet> b(5);
    Packet p1(0, 1);
    Packet p2(1, 1);
    b.enqueue(p1);
    b.enqueue(p2);

    cout << b.getFront() << endl;
    cout << b.dequeue() << endl;
    cout << b.dequeue() << endl;
    cout << b.dequeue() << endl;

    return 0;
}