#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#define DefaultBufflen 256
#define Circbuff(...) circbuff(&(struct circbuff){.isfull=false,.length=DefaultBufflen,__VA_ARGS__})
#define Print(arg,format) printf(#arg " = %" #format "\n",arg);
//Class definition

//public class members
//implement variable size buffer
extern size_t bufferLength;

struct circbuff{
    //public instance members
    double (*buff)[];
    double * tip;
    double * tail;
    bool isfull;
    //public methods
    double (*fetch)(struct circbuff*);
    void (*push)(struct circbuff*,double);
    //self pointer
    struct circbuff *self;
    size_t length;
};
//public constructor declaration
struct circbuff *circbuff(struct circbuff*);
void _Circbuff(struct circbuff*);