#include <iostream>

using namespace std;
int main()
{
	int count;
	cin >> count;

	char** S = new char*[1001];

	for (int i = 0; i < count; ++i)
	{
		S[i] = new char[1001];
	}
	

	for (int i = 0; i < count; ++i)
	{
		cin >> S[i];
	}

	for (int i = 0; i < count; ++i)
	{
		cout << S[i][0];
		for (int j = 0; j < 101; ++j)
		{
			if (S[i][j] == '\0')
			{
				cout << S[i][j-1];
				break;
			}
		}
		cout << endl;
	}

	return 0;
}