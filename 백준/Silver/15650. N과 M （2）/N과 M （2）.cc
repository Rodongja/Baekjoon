#include <iostream>
#include <vector>
using namespace std;

// N과 M  (2)
// 재귀와 dfs로 해결 가능
// 오름차순 조건 추가


void dfs(int N, int M,vector<int>& vec, int start)
{
	// 종료 조건
	if (vec.size() == M)
	{
		// 출력
		for (int i = 0; i < M; i++)
		{
			cout << vec[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 재귀 호출
	for(int i = start + 1; i <= N; i++)
	{
		// 현재 노드 추가
		vec.push_back(i);

		// 재귀 호출
		dfs(N, M, vec, i);

		// 백트래킹
		vec.pop_back();
	}
}

void program()
{
	int N, M;
	cin >> N >> M;

	vector<int> vec;
	int start = 0;
	dfs(N, M,vec,start);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}