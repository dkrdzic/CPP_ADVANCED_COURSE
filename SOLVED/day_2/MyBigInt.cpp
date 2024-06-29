
#include "MyBigInt.h"
#include <string>
#include <cstring>
using namespace std;

MyBigInt::MyBigInt(int num)
{

    string s = to_string(num);

    this->size = s.size();
    this->digits = new int_least8_t[this->size];

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
        this->digits[i] = (int_least8_t)s[j] - '0';
        
 
}

MyBigInt::MyBigInt(const char *num)
{

    this->size = strlen(num);
    this->digits = new int_least8_t[this->size];

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
        this->digits[i] = (int_least8_t)num[j] - '0';
  
}

MyBigInt::MyBigInt(const MyBigInt &mib)
{
    
    this->size = mib.size;

    this->digits = new int_least8_t[mib.size];

    for (int i = 0; i < size; i++)
        this->digits[i] = mib.digits[i];
}

MyBigInt::MyBigInt(MyBigInt &&mib)
{

    this->digits = mib.digits;
    this->size = mib.size;
    mib.digits = nullptr;
    mib.size = 0;
}

MyBigInt &MyBigInt::operator=(const MyBigInt &mib)
{
if(this!=&mib){
    delete [] this->digits;
    if(mib.digits!=nullptr){
    this->size = mib.size;

    this->digits = new int_least8_t[mib.size];

    for (int i = 0; i < size; i++)
        this->digits[i] = mib.digits[i];
}else{
    this->digits=nullptr;
    this->size=0;


}

}
    return *this;
}

MyBigInt &MyBigInt::operator=(MyBigInt &&mib)
{
if(this!=&mib){
    delete [] this->digits;
    this->size = mib.size;

    this->digits = mib.digits;

    mib.digits = nullptr;
    mib.size = 0;
}
    return *this;
}

ostream &operator<<(ostream &it, const MyBigInt &mib)
{

    for (int i = mib.size - 1; i >= 0; i--)
    {

        it << (int)mib.digits[i];
    }

    return it << endl;
}

bool operator!=(const MyBigInt &mib1, const MyBigInt &mib2)
{

    if (mib1.size != mib2.size || mib1.digits == nullptr || mib2.digits == nullptr)
        return true;
    else
        for (size_t i = 0; i < mib1.size; i++)
        {
            if (mib1.digits[i] != mib2.digits[i])
                return true;
            else
                continue;
        }

    return false;
}

bool operator==(const MyBigInt &mib1, const MyBigInt &mib2)
{

    if (mib1.size != mib2.size || mib1.digits == nullptr || mib2.digits == nullptr)
        return false;
    else
        for (size_t i = 0; i < mib1.size; i++)
        {
            if (mib1.digits[i] != mib2.digits[i])
                return false;
            else
                continue;
        }

    return true;
}

MyBigInt::~MyBigInt()
{
    delete[] this->digits;
    this->digits = nullptr;
    this->size=0;
}




