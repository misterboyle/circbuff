#include "circbuff.h"
int main(int argc, char *argv[]){
    size_t length;
    size_t numSamplesIn;
    size_t numSamplesOut;
    //parse args
    switch (argc){
        case 4:
            length = atoll(argv[1]);
            numSamplesIn = atoll(argv[2]);
            numSamplesOut = atoll(argv[3]);
        break;
        case 3:
            length = atoll(argv[1]);
            numSamplesIn = atoll(argv[2]);
            numSamplesOut = length;
        break;
        case 2:
            length = atoll(argv[1]);
            numSamplesIn = numSamplesOut = length;
        break;
        default:
            length = numSamplesIn = numSamplesOut = DefaultBufflen;
    }

    //create buffer object
    struct circbuff *mybuff = Circbuff(.length=length);
    //push a bunch of data into buffer
    for (size_t i=0;i<numSamplesIn;i++){
        mybuff->push(mybuff->self,i);
    }
    //fetch a bunch of data from buffer
    for (size_t i=0;i<numSamplesOut;i++)
        Print(mybuff->fetch(mybuff->self),f);
    //one final push/fetch
    mybuff->push(mybuff->self,25);
    Print(mybuff->fetch(mybuff->self),f);
    //delete buffer object
    _Circbuff(mybuff);
}