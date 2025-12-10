#include <iostream>
#include <vector>

using namespace std;

// 최소공배수는 두 수의 곱을 최대공약수로 나눈 값이다

// 최대 공약수
template <typename T>
T GCD(T a, T b)
{
	if(b == 0)
		return a;
	return GCD(b, a % b);
}

// 최소 공배수
template <typename T>
T LCM(T a, T b)
{
	return (a * b) / GCD(a, b);
}

int main()
{
	// 테스트 케이스 개수
	int N;
	cin >> N;

	// 결과 저장 벡터
	vector<int> ans;

	for(int i = 0; i < N; i++)
	{
		// 두 수 입력
		int a, b;
		cin >> a >> b;

		// 최소 공배수 계산
		int lcm = LCM(a, b);

		// 결과 벡터에 저장
		ans.push_back(lcm);
	}

	// 결과 출력
	for(int i = 0; i < N; i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}
