#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// RGB거리


void program()
{
	// 집의 수
	int N;
	cin >> N;

	vector<int> R(N), G(N), B(N);

	// dp(인덱스, 색깔) = 최소비용
	// 최소값을 data로 가짐
	// N번째 집의 색깔 RGB를 0,1,2로 표현
	vector<vector<int>> dp(N,vector<int>(3, -1));

	for (int i = 0; i < N; i++)
	{
		cin >> R[i] >> G[i] >> B[i];
	}

	// N번째 집은 N-1번쨰 집의 색과 다르게 칠해야 한다.
	// dp[i][c] = i번째 집을 c색을 칠할 때의 최소 비용
	for (int i = 0; i < N; i++)
	{
		// 첫번째 집은 그냥 칠함
		if (i == 0)
		{
			dp[i][0] = R[i];
			dp[i][1] = G[i];
			dp[i][2] = B[i];
		}
		else
		{
			// 이전 집의 색깔과 다르게 칠함
			dp[i][0] = R[i] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = G[i] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = B[i] + min(dp[i - 1][0], dp[i - 1][1]);
		}
	}

	// 마지막 집까지 칠했을 때의 최소 비용
	cout << min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}