#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 다음 소수

// 소수 판별 함수
bool isPrime(long long num)
{
		if (num < 2)
		return false;
	for (long long i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	// 케이스 수
	int cases;
	cin >> cases;

	// 정수 벡터
	vector<long long> n(cases);

	// 정수 입력
	for (int i = 0; i < cases; i++)
	{
		cin >> n[i];
	}

	// 소수 판별
	for (int i = 0; i < cases; i++)
	{
		while (true)
		{
			if(isPrime(n[i]))
			{
				cout << n[i] << "\n";
				break;
			}
			n[i]++;
		}
	}

	return 0;
}
