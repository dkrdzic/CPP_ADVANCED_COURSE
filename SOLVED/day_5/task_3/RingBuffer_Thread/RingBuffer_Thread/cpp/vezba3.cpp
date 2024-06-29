#include "../h/RingBuffer.h"
#include <thread>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

RingBuffer input_buffer;
RingBuffer output_buffer;

void input_task()
{

    srand(time(nullptr));

    while (1)
    {

        char x;

        x = 'a' + rand() % 26;

        input_buffer.write(x);
    }
}

void handler_task()
{

    while (1)
    {

        char x = input_buffer.read();

        output_buffer.write(toupper(x));
    }
}

void output_task()
{

    while (1)
    {

        char x = output_buffer.read();

        this_thread::sleep_for(1000ms); //cisto radi preglednijeg ispisa

        cout << x << flush;
    }
}

int main()
{

    thread input_thread(input_task);
    thread handler_thread(handler_task);
    thread output_thread(output_task);

    input_thread.join();

    handler_thread.join();

    output_thread.join();

    return 0;
}