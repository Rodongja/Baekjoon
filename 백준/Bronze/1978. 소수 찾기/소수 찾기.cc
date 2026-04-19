#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 소수 찾기
    
	int N = 0;
	int num = 0;
	int cnt = 0;

	cin >> N;
	vector<int> vec;

	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		vec.push_back(num);
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		int a = vec[i];
		int half;
		bool isDec;
		if (a == 1)
		{
			continue;
		}
		else if (a == 2 || a == 3)
		{
			cnt++;
		}
		else
		{
			isDec = true;
			half = a / 2;

			for (int j = 2; j <= half; ++j)
			{
				if (0 == a / 2)
				{
					isDec = false;
					break;
				}
				else if (0 == a % j)
				{
					isDec = false;
					break;
				}
			}

			if (isDec)
			{
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}