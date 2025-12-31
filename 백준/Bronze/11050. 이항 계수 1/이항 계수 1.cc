#include <iostream>

using namespace std;

// 이항 계수 1

void program()
{
	int N, K;
	cin >> N >> K;

	int result = 1;

	// 대칭성을 이용한 오버플로우 방지
	if (K > N - K) K = N - K;

	for(int i = 1; i <= K; i++)
	{
		result = result * (N - i + 1) / i;
	}

	cout << result << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}