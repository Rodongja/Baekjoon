#include <iostream>

using namespace std;

// 최소공배수는 두 수의 곱을 최대공약수로 나눈 값이다

long long GCD(long long a, long long b)
{
	while (b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long LCM(long long a, long long b)
{
	return (a / GCD(a,b) * b);
}

int main()
{
	// 두 수 입력
	long long a, b;
	cin >> a >> b;

	// 최소 공배수 계산
	long long lcm = LCM(a, b);

	cout << lcm;

	return 0;
}
