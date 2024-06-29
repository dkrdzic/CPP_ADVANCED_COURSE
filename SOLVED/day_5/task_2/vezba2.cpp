#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int a = 0;
int b = 0;
bool end_array = true;
mutex ma;
mutex mb;
mutex m;
condition_variable cv;

bool read = true;
bool write = false;

void f1()
{

    while (1)
    {
        {

            unique_lock<mutex> lk(m);
            cv.wait(lk, []() { return read; });
            lk.unlock();
//sustina ne stavljati bespotrebne stvari u kriticnu sekciju
            if (end_array)
            {
                lock(ma, mb);
                lock_guard<mutex> lock_a(ma, adopt_lock);
                lock_guard<mutex> lock_b(mb, adopt_lock);
                a = 1;
                b = 2;

                end_array = false;
                write = true;
                read = false;
            }
            else
            {
                lock(ma, mb);
                lock_guard<mutex> lock_a(ma, adopt_lock);
                lock_guard<mutex> lock_b(mb, adopt_lock);
                a += 2;
                b += 2;
                if (a == 5)
                {
                    end_array = true;
                    
                }
                write = true;
                read = false;
            }
        }
        cv.notify_all();
    }
}

void f2()
{
    int sum = 0;
    while (1)
    {
        {
            unique_lock<mutex> lk(m);
            cv.wait(lk, []() { return write; });
            lk.unlock();
            {
                lock(ma, mb);
                lock_guard<mutex> lock_a(ma, adopt_lock);
                lock_guard<mutex> lock_b(mb, adopt_lock);

                sum = a + b;
                write = false;
                read = true;
            }

            cout << sum << ' ';
            if (sum == 11)
                cout << endl;
        }

        cv.notify_all();
    }
}

int main()
{

    thread thread1(f1);
    thread thread2(f2);

    thread1.join();
    thread2.join();

    return 0;
}