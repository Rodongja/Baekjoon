#include <iostream>
#include <algorithm>
using namespace std;

// RGB거리


void program()
{
	// 집의 수
	int N;
	cin >> N;

	// 첫 번째 집의 비용 입력
	int r, g, b;
	cin >> r >> g >> b;

	// 이전 집의 최소 비용 저장 변수
	int prevR = r;
	int prevG = g;
	int prevB = b;

	// 나머지 집들에 대해 비용 계산
	for (int i = 1; i < N; i++)
	{
		// 다음 집의 비용 입력
		cin >> r >> g >> b;

		// 현재 집의 최소 비용 계산
		int curR = r + min(prevG, prevB);
		int curG = g + min(prevR, prevB);
		int curB = b + min(prevR, prevG);

		// 이전 집의 비용 갱신
		prevR = curR;
		prevG = curG;
		prevB = curB;
	}
	// 전체 집의 최소 비용 출력
	cout << min({ prevR,prevG, prevB }) << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}