#include <iostream>
#include <vector>

using namespace std;

// 피보나치 수 5

int fibonacci(int n)
{
	vector<int> fibonacci(n + 1);

	fibonacci[0] = 0;
	fibonacci[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	return fibonacci[n];
}

void program()
{
	int n;
	cin >> n;

	cout << fibonacci(n) << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}