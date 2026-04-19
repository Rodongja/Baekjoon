#include <iostream>

using namespace std;

int main()
{
	// 분수찾기

	int X = 0;
	cin >> X;
	bool turn = 0;

	int a = 1, b = 1;
	for (; X > 1; --X)
	{
		if (!turn)
		{
			if (a != 1)
			{
				b += 1;
				a -= 1;
			}
			else
			{
				b += 1;
				turn = true;
			}
			
		}
		else
		{
			if (b != 1)
			{
				a += 1;
				b -= 1;
			}
			else
			{
				a += 1;
				turn = false;
			}
		}
	}

	cout << a << "/" << b;

	return 0;
}