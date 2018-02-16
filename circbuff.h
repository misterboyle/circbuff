#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#define Bufflen 10
#define Circbuff(...) circbuff(&(struct circbuff){.isfull=false,__VA_ARGS__})
#define Print(arg,format) printf(#arg " = %" #format "\n",arg);
//Class definition

//public class members
//implement variable size buffer
extern size_t bufferLength;

struct circbuff{
    //public instance members
    double buff[Bufflen];
    double * tip;
    double * tail;
    bool isfull;
    //public methods
    double (*fetch)(struct circbuff*);
    void (*push)(struct circbuff*,double);
    //self pointer
    struct circbuff *self;
};
//public constructor declaration
struct circbuff *circbuff(struct circbuff*);
void _Circbuff(struct circbuff*);