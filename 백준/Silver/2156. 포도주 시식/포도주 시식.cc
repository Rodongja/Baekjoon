#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 포도주 시식

void program()
{
	int n;
	cin >> n;

	// 벡터 생성
	vector<int> wines(n);
	// dp[i] = i번 째 포도주를 마실 때 최대 양
	vector<int> dp(n);

	for (int i = 0; i < n; i++)
	{
		cin >> wines[i];
	}

	// 초기값 설정
	dp[0] = wines[0];
	
	// 1번 째 포도주를 마실 때 최대 양은 0번 째 포도주 + 1번 째 포도주
	if (n >= 2)
	{
		dp[1] = wines[0] + wines[1];
	}

	// 2번 째 포도주를 마실 때 최대 양은 0번 째 포도주 + 2번 째 포도주, 1번 째 포도주 + 2번 째 포도주, 1번 째 포도주만 마시는 경우 중 최대 양
	if (n >= 3)
	{
		// max는 2개 이상의 인자를 받을 수 없으므로 initializer list를 사용하여 3개의 인자를 전달한다
		// initializer list를 사용하려면 <algorithm> 헤더 파일이 필요하다
		// dp[1]은 1번 째 포도주만 마시는 경우, wines[0] + wines[2]는 0번 째 포도주 + 2번 째 포도주, wines[1] + wines[2]는 1번 째 포도주 + 2번 째 포도주
		dp[2] = max({ dp[1], wines[0] + wines[2], wines[1] + wines[2] });
	}

	// 3번 째 포도주 부터 반복
	for(int i = 3; i < n; i++)
	{
		// initializer list
		// dp[i - 1]은 i번째 잔을 안마신 경우
		// dp[i - 2] + wines[i]는 i번째만 마신 경우
		// dp[i - 3] + wines[i - 1] + wines[i]는 i - 1번째와 i번째를 마신 경우 
		dp[i] = max({ dp[i - 1], dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i] });
	}
	
	// 출력
	cout << dp[n - 1] << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}