#include <iostream>
#include <algorithm>

int main()
{
	int A, B, C;
	std::cin >> A >> B >> C;

	if (A == B && B == C)
	{
		std::cout << 10000 + A * 1000;
	}
	else if (A == B)
	{
		std::cout << 1000 + A * 100;
	}
	else if (B == C)
	{
		std::cout << 1000 + B * 100;
	}
	else if (A == C)
	{
		std::cout << 1000 + C * 100;
	}
	else if (A != B && B != C)
	{
		std::cout << std::max(std::max(A,B),C) * 100;
	}
	return 0;
}