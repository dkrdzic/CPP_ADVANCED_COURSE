#include "../h/RingBuffer.h"



using namespace std;




void RingBuffer::write(char x){

write_ok.wait();

lock_guard<mutex> lock(m);
buffer[back]=x;
back=(back+1)%RING_SIZE;

read_ok.signal();

}



char RingBuffer::read(){


read_ok.wait();
lock_guard<mutex> lock(m);
char x=buffer[front];
front=(front+1)%RING_SIZE;

write_ok.signal();

return x;

}