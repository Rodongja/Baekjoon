#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 평범한 배낭

void program()
{
	// N: 물건의 수, W: 무게, V: 가치, K: 배낭의 최대 무게
	int N, W, V, K;
	cin >> N >> K;

	vector<int> dp(K + 1, 0);
	
	// dp의 인덱스는 무게, 값은 가치
	// 무게 W일 때 얻을 수 있는 최대 가치 V를 저장
	// i를 0부터 검사하면 같은 물건을 여러번 담게 됨
	// i를 K부터 검사하면 물건을 한번만 담을 수 있음
	for (int i = 0; i < N; i++)
	{
		cin >> W >> V;

		for (int j = K; j >= W; j--)
		{
			// 물건을 넣지 않은 경우(dp[j]와 넣은 경우(dp[j - W] + V) 중 최대값을 저장)
			dp[j] = max(dp[j], dp[j - W] + V);
		}
	}

	cout << dp[K] << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}