
#include <iostream>
#include <cassert>
#include <string>
#include <cstring>
#include <type_traits>



template <typename T, typename... S>
auto sum(T t, S... s)
{

	if constexpr (sizeof...(s) == 0)
		return t;
	else
		return t + sum(s...);
}

template <typename T, typename S>
auto find_min(const T& t,const S& s)
{

	return (t < s) ? t : s;
}

template <typename T, typename... U>
auto min(T t, U... u)
{

	if constexpr (sizeof...(u) == 0)
		return t;
	else
		return find_min(t, min(u...));
}

template <int I, typename T, typename... S>
void check(const std::string &spec, T t, S... s)
{

	switch (spec[I])
	{
	case 'd':
	{

		assert((std::is_same<decltype(t), int>::value));
		break;
	}
	case 'f':
	{

		assert((std::is_same<decltype(t), double>::value));
		break;
	}

	case 's':
	{

		assert((std::is_same<decltype(t), const char *>::value));
		break;
	}
	default:
		assert(false);
		break;
	}
	if constexpr (sizeof...(s) != 0)
		check<I + 1>(spec, s...);
}

template <typename... T>
void my_printf(const char *s, T... t)
{

	std::string spec;

	for (int i = 0; i < strlen(s); i++)
	{

		if (s[i] == '%')
			spec.push_back(s[++i]);
	}

	assert(sizeof...(t) == spec.length());
	if constexpr (sizeof...(t) != 0)
		check<0>(spec, t...);
}

int main()
{
	// sum = 17.4
	std::cout << sum(2, 1.8, 3.8, 4, 5.8) << std::endl;
	// sum = 17.4
	std::cout << sum(1.8, 2, 3.8, 4, 5.8) << std::endl;

	// min = 1.1
	std::cout << min(2.2, 1.1, 4, 4, 58) << std::endl;
	// min = -58
	std::cout << min(2.2, 1.1, 4, 4, -58) << std::endl;

	// Test #1: OK
	//my_printf("Simple check\nNew line\nAgain new line\n");
	// Test #2: Invalid number of arguments
	//my_printf(" text %s, integral value %d than something %d\n", "SUCCESSFULLY", 85);
	//Test #3: Incorrect type / Invalid number of arguments
	//my_printf("Some text %s, some floating point number %f again something %k\n", "45", 89.7, 56);
	// Test #4: OK
	//my_printf("Some text %s, some floating point number %f again something %d\n", "45", 89.7, 56);


//kod myprintf na kraju treba i ispisati
	return 0;
}
