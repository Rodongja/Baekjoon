#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정수 삼각형
// 파스칼의 삼각형

void program()
{
	int n;
	cin >> n;

	vector<vector<int>> triangle(n, vector<int>(n, 0));

	//dp[j] = max(dp[j-1], d[j]) + triangle[i][j];

	// 삼각형 입력
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}

	vector<int> dp(n, 0);

	dp[0] = triangle[0][0];

	for (int i = 1; i < n; i++)
	{
		// 오른쪽 끝
		dp[i] = dp[i - 1] + triangle[i][i];
		// 중간
		for (int j = i - 1; j > 0; j--)
		{
			dp[j] = max(dp[j - 1], dp[j]) + triangle[i][j];
		}
		// 왼쪽 끝
		dp[0] = dp[0] + triangle[i][0];
	}

	// 출력
	cout << *max_element(dp.begin(), dp.end()) << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}