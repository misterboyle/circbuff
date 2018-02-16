#include "circbuff.h"
int main(){
    struct circbuff *mybuff = Circbuff();
    for (size_t i=0;i<15;i++){
        mybuff->push(mybuff->self,i);
    }
    for (size_t i=0;i<20;i++)
        Print(mybuff->fetch(mybuff->self),f);
    mybuff->push(mybuff->self,25);
    Print(mybuff->fetch(mybuff->self),f);
}