#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// N과 M(4)
// 백트래킹

void dfs(vector<int> vec, int N, int M, int curIdx, int start)
{
	// 수열을 M개 채웠다면
	if (curIdx == M)
	{
		// 수열 출력
		for(int i = 0 ; i < M ; i++)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	// start부터 N까지 숫자를 선택
	for (int i = start; i <= N; i++)
	{
		// 현재 위치에 i를 삽입
		vec[curIdx] = i;

		// 다음 dfs 호출, start를 i로 넘겨서 i보다 작은 숫자는 건너뛰기
		// 비내림차순
		dfs(vec, N, M, curIdx + 1, i);
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