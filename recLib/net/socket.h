#ifndef SOCKET_H
#define SOCKET_H
#include "reclib.h"

namespace Rec{


class Socket
{
public:
    Socket(bool listener=true, string portno="42420", string addr="");
    ~Socket();
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
