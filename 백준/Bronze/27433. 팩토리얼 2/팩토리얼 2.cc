#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// 팩토리얼 2


void program()
{
	int N;
	cin >> N;

	long long sum = 1;
	for (int i = 0; i < N; i++)
	{
		sum *= i + 1;
	}

	cout << sum << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}