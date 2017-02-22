#ifndef STREAM_H
#define STREAM_H
#include "reclib.h"
namespace Rec{

class Stream
{
public:
    Stream(int);
    template <class T>
        void ReadArray(T input[], ssize_t len);

private:


};


}
#endif // STREAM_H
