#include <iostream>

using namespace std;
int main()
{
	int num = 9;


	int* array = new int[num];

	for (int i = 0; i < num; ++i)
	{
		cin >> array[i];
	}

	int max = array[0];
	int n = 1;

	for (int j = 1; j < num; ++j)
	{
		if (max < array[j])
		{
			max = array[j];
			n = j+1;
		}
	}

	cout << max << endl << n;


	return 0;
}