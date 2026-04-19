#include <iostream>
int main()
{
	int num;
	std::cin >> num;
	for (int i = 0; i < num; i += 4)
	{
		std::cout << "long ";
	}
	std::cout << "int";
}