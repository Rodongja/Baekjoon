#include <iostream>

using namespace std;

template <typename T>
T gcd(T a, T b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int n = (a * d) + (b * c);
	int m = b * d;

	// 최대공약수를 이용하여 기약분수로 만들기

	int g = gcd(n, m);

	for (int i = n; i >= 1; i--)
	{
		if (n % g == 0 && m % g == 0)
		{
			n /= g;
			m /= g;
			break;
		}
	}

	cout << n << " " << m << "\n";

	return 0;
}
