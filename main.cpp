#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

template<uint N, uint Base>
struct FragImpl;

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

template<uint N, uint Step>
struct Loop
{
	enum
	{
		value = FragImpl<N-Step, Step>::value + Loop<N, Step-1>::value
	};
};

template<uint N>
struct Loop<N, 0>
{
	enum
	{
		value = FragImpl<N, 0>::value
	};
};

template<uint A, uint B>
struct MIN
{
	enum
	{
		value = (A < B) ? A : B
	};
};

template<uint N, uint Base, bool Condition>
struct Check
{
	enum
	{
		value = 0
	};
};

template<uint N, uint Base>
struct Check<N, Base, true>
{
	enum
	{
		value = Loop<N, MIN<N, Base-1>::value>::value
	};
};

template<uint N, uint Base>
struct FragImpl
{
	enum
	{
		value = Check<N, Base, N < Capacity<Base>::value>::value
	};
};

template<>
struct FragImpl<0, 0>
{
	enum
	{
		value = 1
	};
};

template<>
struct FragImpl<0, 1>
{
	enum
	{
		value = 1
	};
};

template<uint N>
struct Frag
{
	enum
	{
		value = FragImpl<N, N+1>::value
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
	cout << "Количество вариантов: " << Frag<1>::value << endl;
	return 0;
}
