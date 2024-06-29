#include "../h/Semaphore.h"

using namespace std;


void Semaphore::signal(){

unique_lock<mutex> lock(this->m);
val+=1;
cv.notify_one();



}


void Semaphore::wait(){

unique_lock<mutex> lock(this->m);
cv.wait(lock,[this](){return this->val!=0;});
val-=1;


}