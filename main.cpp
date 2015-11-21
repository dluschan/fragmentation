#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

template<uint N>
struct Capacity
{
	enum
	{
		value = N - 1 + Capacity<N-1>::value
	};
};

template<>
struct Capacity<0>
{
	enum
	{
		value = 0
	};
};

uint f(uint n, uint base)
{
	switch(n)
	{
	case 0:
	case 1:
	case 2:
		return 1;
	case 3:
		return (base > 3) ? 2 : 1;
	default:
		uint k = ceil(-0.5+sqrt(1+8*n)/2);
		uint res = 0;
		for (uint i = k; i <= n; ++i)
			res += f(n-i, i);
		return res;
	}

	return n;
}

int main()
{
	cout << "Емкость блока " << Capacity<11>::value << endl;
	return 0;
}
