#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 전깃줄
// B의 LIS(최장 증가 부분 수열)의 길이 구하기
// DP이용 O(N^2) 시간 복잡도

void program()
{
	int N;
	cin >> N;

	vector<pair<int,int>> A;

	// 입력
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		A.emplace_back(a,b);
	}

	// 정렬
	sort(A.begin(), A.end());

	// LIS 구하기
	vector<int> dp(N, 1);
	
	// A[0]은 항상 길이가 1이 됨
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[i].second > A[j].second)
			{
				// dp[i]는 dp[j] + 1과 비교하여 더 큰 값이 됨
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	// N에서 LIS의 길이를 빼면 제거해야 하는 전깃줄의 최소 개수가 됨
	cout << N - *max_element(dp.begin(), dp.end()) << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}