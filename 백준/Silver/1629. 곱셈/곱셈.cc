#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

// 곱셈
// A^B % C는 A^(B / 2) % C * A^(B / 2) % C

long long recursion(int A,int B,int C)
{
	// 0제곱은 1이므로 B가 0인경우 1 리턴
	if (B == 0)
		return 1;

	// B가 짝수인경우와 홀수인경우로 나뉨
	long long temp = recursion(A, B / 2, C);

	// 짝수인경우 A^B % C는 A^(B / 2) % C * A^(B / 2) % C
	if (B % 2 == 0)
	{
		return (temp * temp) % C;
	}
	// 홀수인경우  A^B % C는 ((A^(B / 2) % C) * A) % C
	else
	{
		return (temp * temp % C) * A % C;
	}
}

void program()
{
	int A,B,C;
	cin >> A >> B >> C;

	cout << recursion(A,B,C) << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}