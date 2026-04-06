#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// N과 M(2)
// 백트래킹

// 수열이 모이자마자 출력하기 때문에 따로 저장하지 않아도 됨
// min은 이번 단계에서 선택 가능한 최소 숫자
// cur는 현재 검색중인 숫자
void dfs(int N, int M, vector<int> vec, int min, int cur)
{
	// 길이가 M인 수열을 구했을 때 출력한다
	if (cur == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << vec[i] << " ";
		}

		cout << "\n";
		return;
	}

	// min부터 N까지의 숫자 중에서 수열에 들어갈 숫자를 고른다
	for (int i = min; i < N + 1; i++)
	{
		// 벡터에 숫자 추가
		vec[cur] = i;

		// 다음 숫자 추가
		dfs(N, M, vec, i + 1, cur + 1);
	}
}

void program()
{
	int N, M;
	cin >> N >> M;
	vector<int> vec(M);

	// 중복 없이 길이 M인 수열을 구하려면 N이 M보다 커야한다
	if (M > N)
	{
		return;
	}

	dfs(N,M,vec,1,0);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}