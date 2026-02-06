#include <iostream>
#include <vector>
using namespace std;

// 01타일
// dfs, dp로 해결 가능
// dp로 뭘 저장해야 할까?
// N개의 타일을 채우는 방법의 수를 저장하면 된다
// 피보나치 수열과 비슷함

// dfs는 너무 많은 재귀 호출이 발생할 수 있으므로
// 반복문으로 재구현



//long long dfs(int N)
//{
//	// dp에 저장된 값이 있으면 반환
//	if (dp[N] != -1)
//		return dp[N];
//
//	// N이 1이나 2일 때는 각각 1, 2를 반환
//	// 길이가 1이면 1밖에 없고 길이가 2면 00과 11밖에 없기 때문
//	if (N == 1)
//	{
//		return dp[1] = 1;
//	}
//	if (N == 2)
//	{
//		return dp[2] = 2;
//	}
//
//	// N길이 타일을 채우는 방법의 수는 N-1길이 타일을 채우는 방법의 수 + N-2길이 타일을 채우는 방법의 수 
//	long long a = dfs(N - 1);
//	long long b = dfs(N - 2);
//
//	// 15746으로 나눈 나머지 저장
//	dp[N] = (a + b) % 15746;
//
//	return dp[N];
//}

void program()
{
	int N;
	cin >> N;

	// dp[n] = n길이 타일을 채우는 방법의 수
	vector<long long> dp(N + 1, -1);

	if(N >= 1)
	{
		dp[1] = 1;
	}
	if (N >= 2)
	{
		dp[2] = 2;
	}

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N] << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}