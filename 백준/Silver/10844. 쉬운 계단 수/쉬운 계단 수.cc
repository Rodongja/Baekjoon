#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 쉬운 계단 수

void program()
{
	int N;
	cin >> N;

	int MOD = 1000000000;

	// dp[i][j] : 길이가 i이고 마지막 숫자가 j인 계단 수의 개수
	// dp[1][2] = 1 : 길이가 1이고 마지막 숫자가 2인 계단 수의 계수는 1개
	// 길이 0은 존재하지 않으니 건너뛰고 dp[1][0~9]부터 시작
	// 0으로 시작하는 계단 수는 없다고 가정하므로 dp[1][0] = 0, dp[1][1~9] = 1로 초기화
	vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));

	// 길이가 1인 계단 수는 1~9까지 각각 하나씩 존재
	for (int j = 1; j <= 9; j++)
	{
		dp[1][j] = 1;
	}

	// 오버플로우 방지를 위해 MOD
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			// 0으로 끝나는 계단 수는 바로 앞이 1밖에 없음
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][1] % MOD;
			}
			// 9로 끝나는 계단 수는 바로 앞이 8밖에 없음
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][8] % MOD;
			}
			// 1~8로 끝나는 계단 수는 바로 앞이 j-1 또는 j+1인 경우가 있음
			else
			{
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
		}
	}

	// 길이가 N인 계단 수는 마지막 숫자가 0~9인 경우의 합
	long long ans = 0;
	for (int j = 0; j <= 9; j++)
	{
		ans = (ans + dp[N][j]) % MOD;
	}

	cout << ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}