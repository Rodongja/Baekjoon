#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 연속 합


void program()
{
	int n; // 100000 이하 자연수
	cin >> n;

	// 수열
	vector<int> nums(n);

	// 수열 입력
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	// dp[i] : i번째 수까지의 최대 연속합, -1로 초기화
	vector<int> dp(n,-1);

	// 초기값 설정
	dp[0] = nums[0];

	for(int i = 1; i < n; i++)
	{
		// dp[i - 1](이전까지의 최대 연속합)이 음수여도 max 함수가 알아서 처리해줌
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
	}

	// dp 배열에서 최대값 출력
	cout << *max_element(dp.begin(), dp.end()) << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}