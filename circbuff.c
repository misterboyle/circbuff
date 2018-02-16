#include "circbuff.h"
#include "circbuffPrivate.h"

//public method definitions

static double fetch(struct circbuff *in){
    if ((in->tip==in->tail)&&!in->isfull)
        return -1;
    else{
        double retVal = *in->tail;
        moveTail(in);
        in->isfull = false;
        return retVal;
    }
}

static void push(struct circbuff *in,double val){
    *in->tip = val;
    moveTip(in);
    if (in->tip==in->tail)
        in->isfull = true;
}

struct circbuff *circbuff(struct circbuff *in){
    struct circbuff *out = malloc(sizeof(*in)+sizeof(double[in->length]));
    *out = *in;
    out->tip = out->tail = out->buff;
    out->push = push;
    out->fetch = fetch;
    out->self = out;
    return out;
}

void _Circbuff(struct circbuff *in){
    free(in);
}

//private method definitions

static void moveTip(struct circbuff *in){
    //move the tip
    if (in->tip==&(in->buff[in->length-1])) 
        //wrap the tip back to the start of the buffer
        in->tip = in->buff;
    else
        in->tip++;
    //if buffer is full, also move the tail      
    if (in->isfull)
        moveTail(in);
}

static void moveTail(struct circbuff *in){
    if (in->tail==&(in->buff[in->length-1]))
        //wrap the tail back to the start of the buffer
        in->tail = in->buff;
    else
        in->tail++;
}
