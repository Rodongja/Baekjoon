#include <iostream>

int main()
{
	int test;
	std::cin >> test;
	if (test >= 90)
	{
		std::cout << "A" << std::endl;
	}
	else if (test >= 80)
	{
		std::cout << "B" << std::endl;
	}
	else if (test >= 70)
	{
		std::cout << "C" << std::endl;
	}
	else if (test >= 60)
	{
		std::cout << "D" << std::endl;
	}
	else
	{
		std::cout << "F" << std::endl;
	}
	return 0;
}