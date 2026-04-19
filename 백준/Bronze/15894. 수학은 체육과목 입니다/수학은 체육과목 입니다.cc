#include <iostream>

using namespace std;

int main()
{
	// 수학은 체육과목 입니다

	// 입력
	// 범위가 크므로 long 사용
	long n = 0;
	cin >> n;

	long answer = 0;
	
	// n(층수)가 증가할때마다 4,8,12... 즉, n*4임을 알 수 있음
	answer = n * 4;
	
	// 출력
	cout << answer;
	return 0;
}