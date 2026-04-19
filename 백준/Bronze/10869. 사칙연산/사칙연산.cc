#include <iostream>

int main()
{
	int A = 0;
	int B = 0;

	std::cin >> A >> B;

	

	std::cout << A + B << std::endl;
	std::cout << A - B << std::endl;
	std::cout << A * B << std::endl;
	if (B == 0)
	{
		std::cout << "0으로 나눌수 없습니다" << std::endl;
	}
	else
	{
		std::cout << A / B << std::endl;
	}

	std::cout << A % B << std::endl;

	return 0;
}