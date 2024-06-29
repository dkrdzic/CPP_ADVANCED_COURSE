#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void f1()
{

    this_thread::sleep_for(3000ms);
    cout << 1 << endl;
}

void f2(thread thread1)
{

    thread1.join();

    cout << 2 << endl;
}

void f3(thread thread2)
{

    thread2.join();

    cout << 3 << endl;
}

int main()
{

    thread thread1(f1);
    thread thread2(f2, move(thread1));
    thread thread3(f3, move(thread2));

    thread3.join();

    return 0;
}
