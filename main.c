#include "circbuff.h"
int main(int argc, char *argv[]){
    for(size_t i=1;i<argc;i++)
        Print(argv[i],s);
    //create buffer object
    struct circbuff *mybuff = Circbuff(.length=20);
    //push a bunch of data into buffer
    for (size_t i=0;i<15;i++){
        mybuff->push(mybuff->self,i);
    }
    //fetch a bunch of data from buffer
    for (size_t i=0;i<20;i++)
        Print(mybuff->fetch(mybuff->self),f);
    //one final push/fetch
    mybuff->push(mybuff->self,25);
    Print(mybuff->fetch(mybuff->self),f);

    //delete buffer object
    _Circbuff(mybuff);
}