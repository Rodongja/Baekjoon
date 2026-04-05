#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// N과 M(1)
// 백트래킹

// 수열이 모이자마자 출력하기 때문에 따로 저장하지 않아도 됨
void dfs(int N, int M, vector<int> vec, vector<bool> isUsed, int k)
{
	// 길이가 M인 수열을 구했을 때 출력한다
	if (k == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << vec[i] << " ";
		}

		cout << "\n";
		return;
	}

	// 1부터 N까지의 숫자 중에서 수열에 들어갈 숫자를 고른다
	for (int i = 1; i < N + 1; i++)
	{
		// 이미 방문한 숫자는 건너뛰기
		if (!isUsed[i])
		{
			// 벡터에 숫자 추가
			vec[k] = i;

			// 방문 표시
			isUsed[i] = true;

			// 다음 숫자 추가
			dfs(N,M,vec,isUsed,k + 1);

			// 기존 dfs가 끝나면 방문 표시 해제
			isUsed[i] = false;
		}
	}
}

void program()
{
	int N, M;
	cin >> N >> M;
	vector<int> vec(M);
	vector<bool> isUsed(N + 1, false);

	// 중복 없이 길이 M인 수열을 구하려면 N이 M보다 커야한다
	if (M > N)
	{
		return;
	}

	dfs(N,M,vec,isUsed,0);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}