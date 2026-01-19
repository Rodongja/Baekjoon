#include <iostream>
#include <cmath>

using namespace std;

// 하노이 탑 이동 순서
int N;

// 하노이 탑 이동 함수
void move(int n, int from, int to, int temp)
{
	// 원판이 1개인 경우
	if(n == 1)
	{
		cout << from << ' ' << to << '\n';
		return;
	}

	// 작운 원판을 임시 기둥으로 이동
	move(n - 1, from, temp, to);
	// 가장 큰 원판을 목적지 기둥으로 이동
	cout << from << ' ' << to << '\n';
	// 작은 원판을 정리
	move(n - 1, temp, to, from);
}


void program()
{
	cin >> N;
	// cout << pow(2, N) - 1 << '\n'; // double형으로 반환되므로 정확하지가 않아 오차 발생
	cout << ((1LL << N) - 1) << '\n'; // 2^N - 1을 비트 시프트 연산으로 계산
	move(N, 1, 3, 2);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}