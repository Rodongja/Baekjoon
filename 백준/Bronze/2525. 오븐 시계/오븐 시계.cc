#include <iostream>

int main()
{
	int A, B;
	int C;
	std::cin >> A;
	std::cin >> B;
	std::cin >> C;

	if (B + C < 60)
	{
		std::cout << A << " " << B + C;
	}
	else
	{
		A += (B + C) / 60;
		B = (B + C) % 60;
		if (A >= 24)
		{
			A -= 24;
			std::cout << A << " " << B;
		}
		else
			std::cout << A << " " << B;
	}

	return 0;
}