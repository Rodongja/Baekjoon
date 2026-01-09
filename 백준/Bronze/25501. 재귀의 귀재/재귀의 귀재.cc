#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

// 재귀의 귀재

int recursion(const char* s, int l, int r, int& cnt) {
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1, cnt);
}

int isPalindrome(const char* s, int& cnt) {
	return recursion(s, 0, strlen(s) - 1, cnt);
}


void program()
{
	int T;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		int cnt = 0;

		string str;
		cin >> str;
		const char* c = str.c_str();

		cout << isPalindrome(c,cnt) << " " << cnt << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}