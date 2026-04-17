#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1로 만들기

void program()
{
	int N;
	cin >> N;

	vector<int> dp(N+1, 0);

	// 1은 이미 1이기 때문에 0
	dp[1] = 0;
	// 2와 3은 1로 만들기 위해서 1번의 연산이 필요하기 때문에 1
	dp[2] = 1;
	dp[3] = 1;
	 
	// 4부터 연산
	for(int i = 4; i <= N; i++)
	{
		// 1을 빼는 연산을 하면 dp[i-1] + 1이 된다
		dp[i] = dp[i - 1] + 1;

		// 2로 나누어 떨어지는 경우, dp[i]와 dp[i/2] + 1 중 작은 값을 선택
		// 1/2인 값에 2를 곱하면 i가 되므로 연산 횟수가 1회 늘어나기 때문
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		// 3으로 나누어 떨어지는 경우, dp[i]와 dp[i/3] + 1 중 작은 값을 선택
		// 1/3인 값에 3을 곱하면 i가 되므로 연산 횟수가 1회 늘어나기 때문
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	// N을 1로 만들기 위한 최소 연산 횟수 출력
	cout << dp[N] << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}