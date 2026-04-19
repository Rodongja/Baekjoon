#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가로수
// 빈 나무의 개수를 구하기
// 벡터를 검사해서 최소 거리수를 구하고 사이에 빈 나무의 개수를 구한다

// 최대 공약수 함수
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	// 가로수 개수
	int N = 0;

	cin >> N;

	// 가로수 위치 벡터
	vector<int> trees;

	// 입력
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		trees.push_back(num);
	}

	sort(trees.begin(), trees.end());

	int min_distance = trees[1] - trees[0];;
	int distance = 0;

	// 가장 낮은 거리 찾기
	for(int i = 0; i < N-1; i++)
	{
		// 두 나무 사이의 거리 계산
		distance = trees[i + 1] - trees[i];

		// 최소 거리 계산
		min_distance = gcd(min_distance, distance);
	}

	// 빈 나무 개수 계산
	int empty_trees = 0;

	// 마지막 나무까지 거리 계산
	// 총 거리 = 마지막 나무 위치 - 첫 나무 위치

	distance = trees[N-1] - trees[0];
	 
	// 빈 나무 개수 계산
	// (거리 / 최소 거리) - 현재 나무 개수 + 1;
	empty_trees = (distance / min_distance) - trees.size() + 1;

	cout << empty_trees;

	return 0;
}
