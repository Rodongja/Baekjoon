#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	// 소수
	
	int M = 0;
	int N = 0;
	int sum = 0;
	int minPrime = 0;

	bool isPrime = true;

	vector<int> vec = {};

	cin >> M >> N;

	for (int i = M; i <= N; ++i)
	{
		if (i == 1)
		{
			continue;
		}
		else if (i == 2 || i == 3)
		{
			vec.push_back(i);
		}
		else if (0 == i % 2)
		{
			continue;
		}
		else
		{
			isPrime = true;

			int limit = sqrt(i);
			for (int j = 2; j <= limit; ++j)
			{
				if (0 == i % j)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime)
			{
				vec.push_back(i);
			}
		}
	}

	if (vec.size() == 0)
	{
		cout << "-1";
	}
	else
	{
		for (size_t i = 0; i < vec.size(); ++i)
		{
			sum += vec[i];
		}
		minPrime = vec[0];
		cout << sum << endl << minPrime;
	}

	return 0;
}