#include <iostream>

// Овде написати следећу функцију:
// int fibo(int n)

constexpr int fibo(int n)
{

	int a = 0;
	int b = 1;	 
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum = a + b;
		a = b;
		b = sum;
	}
	return a;
}

int main()
{
	static_assert(fibo(7) == 13, "Greska!");
	const int k = fibo(9);
	std::cout << k << std::endl;
	//constexpr int l = fibo(300);
}
