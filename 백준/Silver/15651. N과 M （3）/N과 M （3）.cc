#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// N과 M(3)
// 백트래킹

// vec : 수열
// NumCnt : N
// MaxVec : M
// curIdx : 현재 수열의 인덱스
void dfs(vector<int> vec, int NumCnt, int MaxVec, int curIdx)
{
	// curIdx가 MaxVec와 같다면 수열이 완성된 것이므로 출력
	if (curIdx == MaxVec)
	{
		for (int i = 0; i < MaxVec; i++)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	// 수열의 중복을 허용하므로 i부터 NumCnt까지 반복
	for (int i = 1; i <= NumCnt; i++)
	{
		vec[curIdx] = i;
		dfs(vec, NumCnt, MaxVec, curIdx + 1);
	}
}

void program()
{
	int N, M;
	cin >> N >> M;

	vector<int> vec(M);

	dfs(vec,N, M, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}