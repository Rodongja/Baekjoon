#include <iostream>
#include <vector>
using namespace std;

// N과 M  (1)
// 재귀와 dfs로 해결 가능

void dfs(int N, int M,vector<int>& vec, vector<bool>& visited)
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
	for(int i = 1; i <= N; i++)
	{
		// 이미 방문한 노드라면 패스
		if (visited[i])
		{
			continue;
		}

		// 방문 처리
		visited[i] = true;
		// 현재 노드 추가
		vec.push_back(i);

		// 재귀 호출
		dfs(N, M, vec, visited);

		// 백트래킹
		vec.pop_back();
		// 방문 처리 해제
		visited[i] = false;
	}
}

void program()
{
	int N, M;
	cin >> N >> M;

	vector<int> vec;
	vector<bool> visited(N + 1, false);

	dfs(N, M,vec,visited);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}