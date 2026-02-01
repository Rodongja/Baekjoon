#include <iostream>
#include <vector>
using namespace std;

// 연산자 끼워넣기
// dfs 사용

int N;
int maxResult;
int minResult;

int pluCnt;
int minCnt;
int mulCnt;
int divCnt;

void dfs(int index, int current, vector<int>& nums)
{
	// 모든 숫자를 다 사용한 경우
	if(index == N)
	{
		// 결과 갱신
		maxResult = max(maxResult, current);
		minResult = min(minResult, current);
		return;
	}

	// 더하기
	if(pluCnt > 0)
	{
		pluCnt--;
		// 다음 숫자로 이동
		dfs(index + 1, current + nums[index], nums);
		pluCnt++;
	}

	// 빼기
	if(minCnt > 0)
	{
		minCnt--;
		// 다음 숫자로 이동
		dfs(index + 1, current - nums[index], nums);
		minCnt++;
	}

	// 곱하기
	if(mulCnt > 0)
	{
		mulCnt--;
		// 다음 숫자로 이동
		dfs(index + 1, current * nums[index], nums);
		mulCnt++;
	}

	// 나누기
	if(divCnt > 0)
	{
		divCnt--;
		// 다음 숫자로 이동
		dfs(index + 1, current / nums[index], nums);
		divCnt++;
	}
}

void program()
{
	// 입력
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	cin >> pluCnt >> minCnt >> mulCnt >> divCnt;

	// 최대값, 최소값 초기화
	maxResult = -1e9;
	minResult = 1e9;

	// DFS 탐색 시작
	dfs(1, nums[0], nums);

	// 결과 출력
	cout << maxResult << '\n' << minResult << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}