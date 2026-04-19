#include <iostream>
#include <vector>
int main()
{
	int line;
	std::cin >> line;
	std::vector<int> A;
	std::vector<int> B;
	for (int i = 0; i < line; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
	}
	for (int i = 0; i < line; ++i)
	{
		std::cout << A[i] + B[i] << std::endl;
	}
	return 0;
}