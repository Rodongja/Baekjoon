#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 구간 합 구하기 4

void program()
{
	// 시간초과가 남
	// 중복된 계산을 줄여야 한다
	// dp로 1부터 i까지의 합을 저장해 놓고 구간 합을 구할 때는 dp[b] - dp[a-1]로 구하면 된다

	int N , M;
	cin >> N >> M;

	// 벡터
	vector<int> nums(N);
	vector<int> dp(N + 1, 0); // dp[i]는 1부터 i까지의 합을 저장하는 벡터

	// 벡터 입력
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	// dp 0은 0으로 초기화
	dp[0] = 0;

	// dp 계산
	for (int i = 1; i <= N; i++)
	{
		dp[i] = dp[i - 1] + nums[i - 1];
	}

	// 구간 합 구하기
	for (int i = 0; i < M; i++)
	{
		// 구간 입력
		int a, b;
		cin >> a >> b;
		
		// 출력
		cout << dp[b] - dp[a - 1] << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}