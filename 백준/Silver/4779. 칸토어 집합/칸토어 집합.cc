#include <iostream>
#include <string>
#include <cmath>
#include <string>

using namespace std;

// 칸토어 집합
// 재귀를 이용한 구현

//칸토어 집합은 0과 1사이의 실수로 이루어진 집합으로, 구간[0, 1]에서 시작해서 각 구간을 3등분하여 가운데 구간을 반복적으로 제외하는 방식으로 만든다.
//
//전체 집합이 유한이라고 가정하고, 다음과 같은 과정을 통해서 칸토어 집합의 근사를 만들어보자.
//
//1. - 가 3N개 있는 문자열에서 시작한다.
//
//2. 문자열을 3등분 한 뒤, 가운데 문자열을 공백으로 바꾼다.이렇게 하면, 선(문자열) 2개가 남는다.
//
//3. 이제 각 선(문자열)을 3등분 하고, 가운데 문자열을 공백으로 바꾼다.이 과정은 모든 선의 길이가 1일때 까지 계속 한다.

void cantor(string& str, int left, int right)
{
	int length = right - left;

	// 종료 조건: 길이가 1일 때
	if (length == 1)
		return;

	for(int i = left + length / 3; i < left + 2 * (length / 3); ++i)
	{
		str[i] = ' '; // 가운데 부분을 공백으로 바꿈
	}

	cantor(str, left, left + length / 3); // 왼쪽 부분
	cantor(str, left + 2 * (length / 3), right); // 오른쪽 부분
}

void program()
{
	int N;

	// 입력이 주어질 때까지 반복
	while (cin >> N)
	{
		int length = pow(3, N);
		string str(length, '-');
		cantor(str, 0, str.size());

		cout << str << '\n';
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}