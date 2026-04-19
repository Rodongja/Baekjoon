#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

string func(int N, int B)
{
	int n = N;
	int m = 0;
	string temp = {};
	while (n > 0)
	{
		m = n % B;
		if (m >= 10)
		{
			temp.push_back(static_cast<char>('A' + (m - 10)));
		}
		else
		{
			temp.push_back(static_cast <char>('0' + m));
		}
		n /= B;
	}
	reverse(temp.begin(), temp.end());
	return temp;
};


int main()
{
	// 진법 변환 2
	// 나눗셈 이용

	int N = 0;
	int B = 0;
	string ans = {};
	cin >> N >> B;
	ans = func(N, B);
	cout << ans;
	
	return 0;
}