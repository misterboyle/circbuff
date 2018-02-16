#include "circbuff.h"
int main(){
    struct circbuff *mybuff = Circbuff(.length=12);
    struct circbuff *mybuffs[5];
    for (size_t i=0;i<5;i++)
        mybuffs[i] = Circbuff();
    for (size_t i=0;i<15;i++){
        mybuff->push(mybuff->self,i);
        mybuffs[3]->push(mybuffs[3]->self,i);
    }
    for (size_t i=0;i<20;i++)
        Print(mybuff->fetch(mybuff->self),f);
    mybuff->push(mybuff->self,25);
    Print(mybuff->fetch(mybuff->self),f);
    _Circbuff(mybuff);
    for (size_t i=0;i<5;i++)
        _Circbuff(mybuffs[i]);
}