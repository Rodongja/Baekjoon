#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// 하노이의 탑


void hanoi(int a, int b, int n)
{
	if (n == 0)
	{
		return;
	}

	hanoi(a, 6 - a - b, n - 1);
	cout << a<< ' ' << b << "\n";
	hanoi(6 - a - b, b, n - 1);

}

void program()
{
	int N;

	cin >> N;
	// 최소 이동 횟수는 2^N - 1
	// 2^N은 1을 N번 왼쪽으로 시프트한 것과 같다. (1 << N)
	// N이 63 이상이면 1LL << N이 long long 범위를 초과하여 오버플로우가 발생한다
	// cout << (1LL << N) - 1 << "\n";

	// pow는 실수형을 반환하기 때문에 정확한 결과를 얻기 어렵다.
	//cout << (int)pow(2, N) - 1 << "\n";
	
	// string으로 2^N을 계산
	string s = "1";

	for (int k = 0; k < N; k++)
	{
		// 올림 값
		int c = 0;

		// 뒤에서부터 0을 N개 붙여서 2^N을 계산
		for (int i = s.size() - 1; i >= 0; i--)
		{
			// 2를 곱한 결과가 10 이상이면 올림이 발생한다
			// s[i] - '0' 문자를 숫자로 변환
			// 2를 곱한 결과에 올림을 더한다
			int num = (s[i] - '0') * 2 + c;
			// 문자열로 저장
			s[i] = (num % 10) + '0';
			// 올림 계산
			c = num / 10;
		}

		// 올림이 남아있으면 문자열의 앞에 추가한다
		if(c > 0)
		{
			// c가 남아있으면 begin에 c를 추가한다 (c == 1)
			s.insert(s.begin(), c + '0');
		}
	}

	// 끝자리가 0이면 1을 바로 뺄 수 없음
	int i = s.size() - 1;
	// 확인하는 자리가 0이면 9로 바꾸고 한 자리 왼쪽으로 이동
	while (s[i] == '0')
	{
		// 0을 9로 바꾸고 한 자리 왼쪽으로 이동
		s[i] = '9';
		i--;
	}

	// 0이 아닌 자리를 찾으면 그 자리에서 1을 빼기
	s[i]--;

	cout << s << "\n";
	
	// N이 20 이상인경우에는 이동 횟수만 출력
	if (N > 20)
	{
		return;
	}
	else
	{
		hanoi(1, 3, N);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}