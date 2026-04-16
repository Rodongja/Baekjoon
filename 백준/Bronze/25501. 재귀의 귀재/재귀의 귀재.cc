#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

// 재귀의 귀재
// 전역변수 사용한 경우

int cnt;

int recursion(const char* s, int l, int r) {
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}


void program()
{
	int T;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		cnt = 0;

		string str;
		cin >> str;
		const char* c = str.c_str();

		cout << isPalindrome(c) << " " << cnt << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}