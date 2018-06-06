#ifndef PACKETBUFFER_HPP_INCLUDED
#define PACKETBUFFER_HPP_INCLUDED

#include <queue>
#include <stddef.h>
#include <stdexcept>

template<typename T>
class PacketBuffer
{
public:
    // If maxSize is 0,the size is unlimited ,because creating
    // a buffer of size 0 make litter sense.Otherwise only
    // maxSize packet are allowed in the buffer at any one time
    PacketBuffer(size_t maxSize = 0);
    // Stores a packet in the buffer.
    // Return false if the packet has been discarded because
    // there is no more space in the buffer,true otherwise
    bool bufferPacket(const T& packet);
    // Return the next packet. Throws out_of_range
    // if the buffer is empty.
    T getNextPacket();
private:
    std::queue<T> mPackets;
    size_t mMaxSize;
};


template<typename T>
PacketBuffer<T>::PacketBuffer(size_t maxSize) : mMaxSize(maxSize)
{

}

template<typename T>
bool PacketBuffer<T>::bufferPacket(const T& packet)
{
    if(mMaxSize > 0 && mPackets.size() == mMaxSize){
        // No more space. Drop the packet
        return false;
    }
    mPackets.push(packet);
    return true;
}

template<typename T>
T PacketBuffer<T>::getNextPacket()
{
    if(mPackets.empty())
        throw std::out_of_range("Buffer is empty");

    T temp = mPackets.front();
    mPackets.pop();
    return temp;
}

#endif // PACKETBUFFER_HPP_INCLUDED
