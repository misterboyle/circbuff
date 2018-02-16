#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define DefaultBufflen 256
#define Circbuff(...) circbuff(&(struct circbuff){.length=DefaultBufflen,__VA_ARGS__})
#define Print(arg,format) printf(#arg " = %" #format "\n",arg);
//Class definition
struct circbuff{
    //instance members
    double *tip;
    double *tail;
    struct circbuff *self;
    //public methods
    double (*fetch)(struct circbuff*);
    void (*push)(struct circbuff*,double);
    //buffer and associated metadata
    size_t length;
    bool isfull;
    //c99 flexible array member
    double buff[]; 
};
//public constructor declaration
struct circbuff *circbuff(struct circbuff*);
void _Circbuff(struct circbuff*);