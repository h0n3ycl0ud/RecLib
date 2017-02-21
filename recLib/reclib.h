#ifndef RECLIB_H
#define RECLIB_H

/**
 *  REC - Remote Encryption Call
 *
 *  To be used in a secure hardware model for accessing protected
 *  resources (i.e. private keys) without reading them
 *
 */

//bring in cstdlib
#include <string>
#include <cerrno>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

//bring in cryptopp
#include <cryptopp/cryptlib.h>
#include <cryptopp/rsa.h>
#include <cryptopp/pubkey.h>
#include <cryptopp/secblock.h>
#include <cryptopp/base64.h>
#include <cryptopp/sha.h>
#include <cryptopp/config.h>
using namespace CryptoPP;

/**
 * Base namespace def
 *
 */
namespace Rec{
    class Stream;
    class Socket;

}
#endif // RECLIB_H
