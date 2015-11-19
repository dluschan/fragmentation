#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

uint f(uint n)
{
	switch(n)
	{
	case 0:
	case 1:
	case 2:
		return 1;
	case 3:
		return 2;
	default:
		uint k = ceil(-0.5+sqrt(1+8*n)/2);
		uint res = 0;
		for (uint i = k; i <= n; ++i)
		{
			res += f(n-k);
		}
		return res;
	}

	return n;
}

int main()
{
	uint n = 6;
	//cin >> n;
	cout << f(n) << endl;
	return 0;
}
