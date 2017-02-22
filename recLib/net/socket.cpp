#include "socket.h"
namespace Rec{

/**
 * @brief Socket::Socket
 * @param listener Am I listening? OR talking?
 * @param portno   On what port?
 * @param addr     What's the socket's addr?
 *
 * Thanks and love to beej and W. R. Stevens
 * We stand on the shoulders of giants
 */


TCPSocket::TCPSocket(bool _listener, string portno, string addr)
{
    this->Create(_listener, portno, addr);
}

TCPSocket::~TCPSocket(){
        freeaddrinfo(servinfo); //and hints goes out of scope
}


void TCPSocket::Create(bool _listener, string portno, string addr){
    this->listener = _listener;

    int status;
    struct addrinfo hints;

    bzero(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC; //ipv4 or ipv6
    hints.ai_socktype = SOCK_STREAM; //tcp
    if(listener){
        if(addr == ""){
            hints.ai_flags = AI_PASSIVE; //I don't know my address
        }else{
            //I do know my address
        }

        status = getaddrinfo(NULL, portno.c_str(), &hints, &this->servinfo);
    }else{
        if(addr == ""){
            this->error_msg = "Socket::Socket(false, ..., \"\"): can't connect to no-one!";
            cerr << this->error_msg;
            this->error = true;
            return;
        }
        status = getaddrinfo(NULL, portno.c_str(), &hints, &this->servinfo);
    }
    if(status != 0){
        stringstream err;
        err << "Socket(" << listener << ", " << portno <<", " << addr << ") error:" << endl;
        err << gai_strerror(status);
        err << endl;
        this->error = true;
        this->error_msg = err.str();
        cerr << this->error_msg;
        return;
    }

    this->sockfd = 0;
    bool failure = false;
    struct addrinfo * current_addr;
    while(this->sockfd <= 0 && !failure){
        current_addr = this->servinfo->ai_next;
        if(current_addr == NULL){
            failure = true;
            cerr << "Failed to make socket: \"" << addr << "\":\"" << portno << "\" ..." << endl;
            cerr << "Total failure. Socket is invalid." << endl;
            return;
        }
        this->sockfd = socket(current_addr->ai_family, current_addr->ai_socktype, current_addr->ai_protocol);
        if(this->sockfd < 0){
            cerr << "Failed to make socket: \"" << addr << "\":\"" << portno << "\" ..." << endl;
        }

    }
}


}

