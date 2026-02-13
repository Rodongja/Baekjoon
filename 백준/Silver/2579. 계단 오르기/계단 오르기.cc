#include <iostream>
#include <algorithm>
using namespace std;

// 계단 오르기

void program()
{
	// 계단의 개수
	int n;
	cin >> n;
		
	// 계단 i번째에 도달했을 때 방법의 수는 2개
	// i-2번째 계단에서 올라오는 경우
	// i-3번째 계단에서 i-1을 통해 올라오는 경우
	// i-1번째 계단에서 올라오는 경우를 세면 3연속 계단을 오르게 됨

	// dp[i] : i번째 계단에 도달했을 때의 최대 점수
	int dp[301] = { 0, };
	// 첫 번째 계단 점수 입력
	cin >> dp[0];

	// 계단이 1개인 경우
	if(n == 1)
	{
		cout << dp[0] << "\n";
		return;
	}
	
	// 두 번째 계단 점수 입력
	int num;
	cin >> num;

	// cur : 현재 계단의 점수
	int cur = num;

	// 두 번째 계단에 도달했을 때의 최대 점수(dp) 계산
	dp[1] = dp[0] + num;

	// 계단이 2개인 경우
	if(n == 2)
	{
		// 최대 점수 (dp[1]) 출력
		cout << dp[1] << "\n";
		return;
	}

	// 세 번째 계단 점수 입력
	cin >> num;
	// prev : 이전 계단의 점수
	int prev = cur;
	// cur 업데이트
	cur = num;
	// 세 번째 계단에 도달했을 때의 최대 점수(dp) 계산
	dp[2] = max(dp[0] + num, prev + num);
	


	for (int i = 3; i < n; i++)
	{
		cin >> num;
		// prev 업데이트
		prev = cur;
		// cur 업데이트
		cur = num;
		// i번째 계단에 도달했을 때의 최대 점수(dp) 계산
		dp[i] = max(dp[i - 2] + num,dp[i-3] + prev + num);
	}

	// 최대 점수 출력
	cout << dp[n - 1] << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}