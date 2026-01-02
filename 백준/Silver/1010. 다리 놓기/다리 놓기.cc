#include <iostream>

using namespace std;

// 다리 놓기

void program()
{
	int T;
	cin >> T;

	// dp[i][j] = i개 중 j개를 고르는 경우의 수
	long long dp[30][30] = { 0, };

	for (int i = 0; i < T; i++)
	{
		int N, M;
		cin >> N >> M;


		for (int j = 0; j <= M; j++)
		{
			dp[j][0] = 1; // 0개 고르는 경우의 수는 1
			dp[j][j] = 1; // j개 중 j개 고르는 경우의 수는 1
		}

		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j < i; j++)
			{
				// 조합의 성질
				// nCr = (n-1)C(r-1) + (n-1)Cr
				// n개 중 r개를 고르는 경우의 수는 특정 원소를 포함하는 경우와 포함하지 않는 경우의 수의 합과 같음
				// 즉 nCr = 포함하는 경우 (n-1)C(r-1) + 포함하지 않는 경우 (n-1)Cr
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}

		// 출력
		cout << dp[M][N] << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}