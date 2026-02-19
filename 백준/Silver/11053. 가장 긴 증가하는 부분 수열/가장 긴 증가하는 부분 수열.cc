#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 긴 증가하는 부분 수열

void program()
{
	int N;
	cin >> N;

	vector<int> nums(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	// dp[i] = nums[i]를 마지막 원소로 하는 가장 긴 증가하는 부분 수열의 길이
	vector<int> dp(N, 1);

	// dp[i] = i에서 끝나는 최장 부분 수열 길이
	for(int i = 0; i < N; i++)
	{
		// i보다 작은 j를 검사
		for (int j = 0; j < i; j++)
		{
			// nums[j] < nums[i]인 경우에만 dp[i]를 갱신
			if (nums[j] < nums[i])
			{
				// 가장 긴 부분 수열에 길이 1을 더해준다
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	// 출력
	cout << *max_element(dp.begin(),dp.end()) << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}