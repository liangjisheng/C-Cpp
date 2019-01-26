#ifndef IPPACKET_H_INCLUDED
#define IPPACKET_H_INCLUDED

class IPPacket
{
public:
    IPPacket(int id) : nID(id) {}
    int getID() const { return nID; }
private:
    int nID;
};

#endif // IPPACKET_H_INCLUDED
