#include <iostream>
#include "IPPacket.h"
#include "PacketBuffer.hpp"
using std::cout;
using std::endl;
using std::out_of_range;

int main()
{
    PacketBuffer<IPPacket> ipPackets(3);
    // Add 4 packets
    for(int i = 1; i <= 4; ++i){
        if(!ipPackets.bufferPacket(IPPacket(i))){
            cout << "Packet " << i << " dropped (queue is full)" << endl;
        }
    }

    cout << endl;
    while(true){
        try{
            IPPacket packet = ipPackets.getNextPacket();
            cout << "Processing packet " << packet.getID() << endl;
        }catch(const out_of_range&) {
            cout << "Queue is empty." << endl;
            break;
        }
    }

    return 0;
}
