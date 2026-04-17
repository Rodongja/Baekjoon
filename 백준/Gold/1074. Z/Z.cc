#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// Z

int rec(int N, int r, int c)
{
	if (N == 0)
		return 0;
	
	// 4개로 쪼개서 찾는다
	// 비트 시프트 이용 2^N의 절반은 2^N-1
	int half = 1 << (N - 1);
	// pow로도 구현 가능
	// int half = pow(2, N - 1);

	// 1사분면
	if (r < half && c < half)
	{
		return rec(N - 1, r, c);
	}

	// 2사분면
	else if (r < half && c >= half)
	{
		return half * half + rec(N - 1, r, c - half);
	}
	
	// 3사분면
	else if (r >= half && c < half)
	{
		return 2 * half * half + rec(N - 1, r - half, c);
	}
	
	// 4사분면
	else if (r >= half && c >= half)
	{
		return 3 * half * half + rec(N - 1, r - half, c - half);
	}
}

void program()
{
	// N은 한 줄 길이의 2^N
	// r,c는 row,col
	int N,r,c;
	cin >> N >> r >> c;

	cout << rec(N,r,c );
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}