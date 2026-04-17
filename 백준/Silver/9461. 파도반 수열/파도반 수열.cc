#include <iostream>
#include <vector>
using namespace std;

// 파도반 수열
// 그냥 하면 시간초과하니 dp를 사용

vector<long long> dp(101, -1);

long long P(long long N)
{
	// 1 1 1 2 2 3 4 5 7 9 12
	// 식은 P(N) = P(N-2) + P(N-3)

	if(dp[N] != -1)
	{
		return dp[N];
	}

	if(N <= 3)
	{
		return 1;
	}
		
	dp[N] = P(N - 2) + P(N - 3);
	return dp[N];
}

void program()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;

		cout << P(N) << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}