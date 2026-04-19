#include <iostream>

using namespace std;
int main()
{
	string A;
	cin >> A;

	int time = 0;

	for (int i = 0; i < A.length(); ++i)
	{
		if (A[i] >= 'A' && A[i] <= 'C')
		{
			time += 3;
		}
		else if (A[i] >= 'D' && A[i] <= 'F')
		{
			time += 4;
		}
		else if (A[i] >= 'G' && A[i] <= 'I')
		{
			time += 5;
		}
		else if (A[i] >= 'J' && A[i] <= 'L')
		{
			time += 6;
		}
		else if (A[i] >= 'M' && A[i] <= 'O')
		{
			time += 7;
		}
		else if (A[i] >= 'P' && A[i] <= 'S')
		{
			time += 8;
		}
		else if (A[i] >= 'T' && A[i] <= 'V')
		{
			time += 9;
		}
		else if (A[i] >= 'W' && A[i] <= 'Z')
		{ 
			time += 10;
		}
	}

	cout << time;

	return 0;
}