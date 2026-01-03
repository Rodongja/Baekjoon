#include <iostream>

using namespace std;

// 약수
// 가장 작은 약수와 큰 약수를 곱하면 N이 된다

long long min(long long a, long long b)
{
	if (a < b) return a;
	else return b;
}

long long max(long long a, long long b)
{
	if (a > b) return a;
	else return b;
}

void program()
{
	// 약수의 개수
	int num;
	cin >> num;

	long long N = 1;
	int A;
	int minValue;
	int maxValue;

	for(int i = 0 ; i < num ; i++)
	{
		cin >> A;
		if (i == 0)
		{
			minValue = A;
			maxValue = A;
		}
		else
		{
			minValue = min(minValue, A);
			maxValue = max(maxValue, A);
		}

		N = minValue* maxValue;
	}

	cout << N << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}