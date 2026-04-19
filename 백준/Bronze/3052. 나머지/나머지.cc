#include <iostream>

using namespace std;
int main()
{
	int A, B;
	int length = 42;
	int count = 10;
	int* array = new int[length];
	int* remain = new int[count];
	int answer = 0;

	// 숫자 입력
	for (int i = 0; i < count; ++i)
	{
		cin >> remain[i];
	}
	
	// 나누기
	int C;
	for (int i = 0; i < count; ++i)
	{
		C = remain[i] % 42;
		array[C] = true;
	}

	// 개수 세기
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == true)
		{
			++answer;
		}
	}

	cout << answer;


	return 0;
}