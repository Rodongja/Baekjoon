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

	vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));

	// 0행과 0열은 빈 문자열을 의미하기 때문에 1열부터 사용한다
	// A.size() + 1, B.size() + 1로 초기화 하기 때문에 범위를 벗어나지 않는다
	// 결국 A.size()만큼의 행과 B.size()만큼의 열이 생긴다
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			// 중복된 글자가 있으면
			if (A[i] == B[j])
			{
				// 기존 dp[i][j]에 1을 더한 값을 dp[i+1][j+1]에 저장한다
				dp[i+1][j+1] = dp[i][j] + 1;
			}
			else
			{
				// 중복된 글자가 없으면, A의 글자와 B의 글자 중 하나를 제외한 LCS 길이 중 최대값을 선택한다
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}

	// A와 B의 최장 공통 부분 수열의 길이는 가장 마지막 글자까지의 LCS 길이를 구하면 된다
	cout << dp[A.size()][B.size()] << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}