#ifndef SOCKET_H
#define SOCKET_H
#include "reclib.h"

namespace Rec{


class TCPSocket
{
public:
    TCPSocket(bool listener=true, string portno="42420", string addr="");
    ~TCPSocket();
    void Create(bool listener=true, string portno="42420", string addr="");
    bool ErrorState();
    string ErrorMsg();
private:
    bool error;
    bool listener;
    bool connected;
    string error_msg;
    int sockfd;
    short portno;
    struct addrinfo *servinfo;


};


}
#endif // SOCKET_H
