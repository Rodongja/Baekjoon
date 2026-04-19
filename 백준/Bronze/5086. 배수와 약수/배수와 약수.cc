#include <iostream>

using namespace std;

int main()
{
	// 배수와 약수

	int a = -1, b = -1;
	int ans;

	while (!(0 == a && 0 == b))
	{
		cin >> a >> b;

		if (!(0 == a && 0 == b))
		{
			if (0 == b % a)
			{
				ans = 1;
			}

			else if (0 == a % b)
			{
				ans = 2;
			}

			else
			{
				ans = 3;
			}

			switch (ans)
			{
			case 1:
				cout << "factor" << endl; 
				break;
			case 2:
				cout << "multiple" << endl;
				break;
			case 3:
				cout << "neither" << endl;
				break;
			}
		}
	}	

	return 0;
}