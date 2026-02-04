#include <iostream>
#include <vector>
using namespace std;

// 신나는 함수 실행

// 20 이상의 값이 들어올 경우 20으로 고정
vector<vector<vector<int>>> dp(21,vector<vector<int>>(21,vector<int>(21,0)));

int w(int a,int b,int c)
{
	// a,b,c중 하나라도 0 이하라면 1 반환
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}

	// a,b,c중 하나라도 20 이상이라면 w(20,20,20) 반환
	if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}

	// dp 저장
	// 재귀함수에서 호출될 경우 참조(int&)를 해야 같은 dp 테이블을 공유함
	int& ret = dp[a][b][c];

	// 이미 저장되어있는 값이라면
	// w(a,b,c)의 최소값이 1이기 때문에 0으로 체크
	if (ret != 0)
	{
		// 리턴
		return ret;
	}

	// a < b < c인 경우
	if (a < b && b < c)
	{
		// dp에 값 저장
		ret = w(a, b, c-1) 
			+ w(a,b-1,c-1) 
			- w(a,b-1,c);
	}
	
	// 나머지 경우
	else
	{
		// dp에 값 저장
		ret = w(a - 1, b, c) 
			+ w(a - 1, b - 1, c) 
			+ w(a - 1, b, c - 1) 
			- w(a - 1, b - 1, c - 1);
	}

	// 값 반환
	return ret;
}

void program()
{
	// 초기화
	int a = 0, b = 0, c = 0;

	while (true)
	{
		cin >> a >> b >> c;

		// 종료 조건
		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}

		// 결과 출력
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}