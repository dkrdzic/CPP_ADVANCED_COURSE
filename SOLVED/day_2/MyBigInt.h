#ifndef _MY_BIG_INT_
#define _MY_BIG_INT_

#include <cstdint>
#include <iostream>

using namespace std;


struct MyBigInt
{
	friend MyBigInt operator+(const MyBigInt &lhs, const MyBigInt &rhs);

	MyBigInt(int = 0);
	MyBigInt(const char *);
	MyBigInt(const MyBigInt &);
	MyBigInt(MyBigInt &&);
	~MyBigInt();
	MyBigInt &operator=(const MyBigInt &);
	MyBigInt &operator=(MyBigInt &&);
	friend ostream &operator<<(ostream &, const MyBigInt &);
	friend MyBigInt operator""_mbi(const char *);
	friend bool operator!=(const MyBigInt &, const MyBigInt &);
	friend bool operator==(const MyBigInt &, const MyBigInt &);

private:
	int_least8_t *digits = nullptr;
	int size = 0;
};

#endif