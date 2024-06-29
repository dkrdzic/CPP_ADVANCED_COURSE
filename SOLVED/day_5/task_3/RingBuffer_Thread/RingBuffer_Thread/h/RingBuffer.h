#ifndef RINGBUFFER_H
#define RINGBUFFER_H



#include <array>
#include "Semaphore.h"


#define RING_SIZE 10

using namespace std;

class RingBuffer
{


array<char,RING_SIZE> buffer;

int front,back;
Semaphore read_ok;
Semaphore write_ok;
mutex m;

public:

RingBuffer():front(0),back(0),write_ok(10),read_ok(0){};

void write(char);
char read();








};


#endif