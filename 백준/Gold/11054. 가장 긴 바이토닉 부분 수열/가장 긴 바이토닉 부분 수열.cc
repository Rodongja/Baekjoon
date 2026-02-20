#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 가장 긴 바이토닉 부분 수열

void program()
{
	int N;
	cin >> N;

	vector<int> nums(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	// LIS : 최장 부분 수열의 길이 저장 배열
	vector<int> LIS(N, 1);

	// LIS[i] = i에서 끝나는 최장 부분 수열 길이
	for(int i = 0; i < N; i++)
	{
		// i보다 작은 j를 검사
		for (int j = 0; j < i; j++)
		{
			// nums[j] < nums[i]인 경우에만 dp[i]를 갱신
			if (nums[j] < nums[i])
			{
				// 가장 긴 부분 수열에 길이 1을 더해준다
				LIS[i] = max(LIS[i], LIS[j] + 1);
			}
		}
	}

	// {1 5 2 1 4 3 4 5 2 1}  1 2 3 4 5 2 1
	// 1 2 3 4 5와 5 2 1로 나누어서 LIS와 LDS를 구한다.
	
	// LDS : 최장 감소 부분 수열의 길이 저장 배열
	vector<int> LDS(N, 1);

	// LDS[i] = i에서 끝나는 감소 부분 수열 길이
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j > i; j--)
		{
			if(nums[j] < nums[i])
			{
				LDS[i] = max(LDS[i], LDS[j] + 1);
			}
		}
	}

	int ans = 0;

	// 최대 길이 바이토닉 부분 수열
	for (int i = 0; i < N; i++)
	{
		// i가 중복되기 때문에 1 감소
		ans = max(ans, LIS[i] + LDS[i] - 1);
	}

	// 출력
	cout << ans << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}