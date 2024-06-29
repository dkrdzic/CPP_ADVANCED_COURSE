
#include <iostream>
#include <tuple>
#include <cstring>
#include <string>
#include <type_traits>
#include <cassert>

using namespace std;

template <int I, typename... T>
auto sum_tuple(const tuple<T...> &t)
{

	if constexpr (I == 0)
		return get<0>(t);
	else
		return get<I>(t) + sum_tuple<I - 1>(t);
}

template <typename... T>
auto sum(T... t)
{

	tuple<T...> x = make_tuple(t...);
	constexpr static size_t size = tuple_size<tuple<T...>>::value;

	return sum_tuple<size - 1>(x);
}

template <typename T, typename S>
auto find_min(const T &t, const S &s)
{

	return (t < s) ? t : s;
}

template <int I, typename... T>
auto min_tuple(const tuple<T...> &t)
{

	if constexpr (I == 0)
		return get<0>(t);
	else
	{
		return find_min(get<I>(t), min_tuple<I - 1, T...>(t));
	}
}

template <typename... T>
auto min(T... t)
{

	tuple<T...> x = make_tuple(t...);

	constexpr static size_t size = tuple_size<tuple<T...>>::value;

	return min_tuple<size - 1, T...>(x);
}

template <int I, typename... T>
void check(const string &spec, const tuple<T...> &t)
{

	if constexpr (I == 0)
		return;
	else
	{

		switch (spec[I - 1])
		{
		case 'd':
		{

			//auto a = get<I - 1>(t);
			//assert((is_same<decltype(a), int>::value));
			assert((is_same<decltype(+get<I - 1>(t)), int>::value));
			
			break;
		}
		case 'f':
		{

			//auto a = get<I - 1>(t);
			//assert((is_same<decltype(a), double>::value));
			assert((is_same<decltype(+get<I - 1>(t)), double>::value));
			
			break;
		}

		case 's':
		{

			//auto a = get<I - 1>(t);
			//assert((is_same<decltype(a), const char*>::value));
			assert((is_same<decltype(+get<I - 1>(t)), const char *>::value));
		
			break;
		}
		default:
			assert(false);
			break;
		}

		check<I - 1>(spec, t);
	}
}

template <typename... T>
void my_printf(const char *s, T... t)
{

	string spec;

	for (int i = 0; i < strlen(s); i++)
	{

		if (s[i] == '%')
			spec.push_back(s[++i]);
	}

	tuple<T...> x = make_tuple(t...);

	constexpr static size_t size = tuple_size<tuple<T...>>::value;

	assert(size == spec.length());

	check<size>(spec, x);
}

int main()
{

	// sum = 17.4
	cout << sum(2, 1.8, 3.8, 4, 5.8) << endl;
	// sum = 17.4
	cout << sum(1.8, 2, 3.8, 4, 5.8) << endl;

	// min = 1.1
	cout << min(2.2, 1.1, 4, 4, 58) << endl;
	// min = -58
	cout << min(2.2, 1.1, 4, 4, -58) << endl;

	// Test #1: OK
	//my_printf("Simple check\nNew line\nAgain new line\n");
	// Test #2: Invalid number of arguments
	//	my_printf(" text %s, integral value %d than something %d\n", "SUCCESSFULLY", 85);
	// Test #3: Incorrect type / Invalid number of arguments
	//	my_printf("Some text %s, some floating point number %f again something %k\n", "45", 89.7, 56);
	// Test #4: OK
	my_printf("Some text %s, some floating point number %f again something %d\n", "45", 89.7, 56);
//kod my_printf na kraju treba i ispisati
	return 0;
}
