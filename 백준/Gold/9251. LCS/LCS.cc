#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LCS
// 최장 공통 부분 수열

void program()
{
	string A, B;
	cin >> A >> B;

	int LCS = 0;
	vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));

	for(int i = 0; i < A.size(); i++)
	{
		for(int j = 0; j < B.size(); j++)
		{
			if(A[i] == B[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				LCS = max(LCS, dp[i + 1][j + 1]);
				continue;
			}
			else
			{
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				continue;
			}
		}
	}
	 
	cout << LCS << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}