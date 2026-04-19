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

	// i를 0으로 나누면 안되기 때문에 1부터 시작
	for(int i = 1; i <= K; i++)
	{
		// (iN​)=(i−1N​)×iN−i+1​
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