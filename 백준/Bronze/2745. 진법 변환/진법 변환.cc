#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum alphabet
{
	A = 10,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z	
};

int Bto10(string N, int B)
{
	long long sum = 0;
	int length = N.length();
	int iPow = 0;
	int scInt = 0;
	for (int i = 0; i < length; ++i)
	{
		iPow = pow(B, length - i - 1);
		if (N[i] <= '9')
		{
			sum += (N[i] - '0') * iPow;
		}
		else
		{
			scInt = (static_cast<int>(N[i] - 'A' + 10));
			sum += (scInt * iPow);
		}
	}
	return sum;
}

int main()
{
	// 진법 변환
	// 나눗셈 이용

	string N = {};
	int B = 0;
	long long ans = 0;
	cin >> N >> B;

	ans = Bto10(N, B);
	cout << ans;
	
	return 0;
}