#include <iostream>
#include <map>

using namespace std;

int main()
{
	// 네 번째 점

	// 좌표 입력
	int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

	// 축별로 Map 생성
	// Key는 좌표, value는 몇번 중복되었는지 의미함
	map<int, int> xMap;
	map<int, int> yMap;

	xMap[a1]++;
	xMap[b1]++;
	xMap[c1]++;

	yMap[a2]++;
	yMap[b2]++;
	yMap[c2]++;

	// 나머지 한 점의 좌표 값
	int X = 0, Y = 0;

	// Map 검색
	for (const pair<const int, int>& pair : xMap)
	{
		// value가 홀수(1)인 Key(좌표값)을 X에 적용
		if (pair.second % 2 == 1) {
			X = pair.first;
		}
	}

	for (const pair<const int, int>& pair : yMap)
	{
		// value가 홀수(1)인 Key(좌표값)을 Y에 적용
		if (pair.second % 2 == 1) {
			Y = pair.first;
		}
	}

	// 출력
	cout << X << " " << Y;
	return 0;
}