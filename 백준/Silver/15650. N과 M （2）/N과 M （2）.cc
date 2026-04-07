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

void dfs(vector<int> vec, int N, int M, int cur, int start)
{
	// cur는 0부터 1,2...씩 증가하면서 M이 되면 출력
	if (cur == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	// cur는 탐색중인 인덱스 start는 탐색중인 숫자
	for (int i = start; i <= N; i++)
	{
		// cur에 i를 넣고 다음 탐색으로 넘어감
		vec[cur] = i;

		// 다음 탐색에서는 cur + 1로 다음 인덱스, i + 1로 다음 숫자부터 탐색하도록 함
		dfs(vec, N, M, cur + 1, i + 1);
	}
}

void program()
{
	int N, M;
	cin >> N >> M;

	vector<int> vec(M);

	dfs(vec, N, M, 0, 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}