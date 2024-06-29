#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>


class Semaphore{


int val=0;
std::mutex m;
std::condition_variable cv;

public:
Semaphore()=default;
Semaphore(int x):val(x){}


void signal();

void wait();





};




#endif