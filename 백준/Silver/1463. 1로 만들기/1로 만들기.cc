#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1로 만들기

void program()
{
	int N;
	cin >> N;

	// dp[i] = i를 1로 만드는 최소 연산 횟수
	vector<int> dp(N + 1, 0);

	dp[1] = 0; // 1은 이미 1이므로 연산 횟수는 0
	
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1; // 1을 빼는 경우
		
		if (i % 2 == 0) // 2로 나누는 경우
			dp[i] = min(dp[i], dp[i / 2] + 1);
		
		if (i % 3 == 0) // 3으로 나누는 경우
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	
	cout << dp[N] << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}