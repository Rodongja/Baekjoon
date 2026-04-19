#include <iostream>

int main()
{
	bool isleap = 0;
	int year;
	std::cin >> year;
	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0)
		{
			isleap = true;
		}
	}
	std::cout << isleap;

	return 0;
}