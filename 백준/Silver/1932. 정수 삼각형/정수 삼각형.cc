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

	//dp[j] = max(dp[j-1], d[j]) + triangle[i][j];
	
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			// 입력 받기
			int num;
			cin >> num;

			// 왼쪽 끝
			if (j == 0)
				dp[j] = dp[j] + num;
			// 오른쪽 끝
			else if (j == i)
				dp[j] = dp[j - 1] + num;
			// 중간
			else
				dp[j] = max(dp[j - 1], dp[j]) + num;
		}
	}
	// 최댓값 출력
	cout << *max_element(dp.begin(), dp.end()) << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}