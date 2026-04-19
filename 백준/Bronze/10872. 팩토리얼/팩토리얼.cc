#include <iostream>

using namespace std;

// 팩토리얼
// 재귀나 for로 해결가능

//int factorial(int num)
//{
//	if (num <= 1)
//		return 1;
//	
//	return num * factorial(num - 1);
//}

void program()
{
	int N;
	cin >> N;

	int num = 1;
	for (int i = 0; i < N; i++)
	{
		num *= (i + 1);
	}

	cout << num << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}