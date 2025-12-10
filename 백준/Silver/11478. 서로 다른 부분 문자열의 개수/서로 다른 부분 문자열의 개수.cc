#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

// unordered_set 사용
// unordered_set은 중복을 허용하지 않음

int main()
{
	string str;
	cin >> str;

	// 자료구조 선언
	unordered_set<string> set;

	// 부분 문자열 모두 집합에 삽입
	for(int i = 0; i < str.length(); i++)
	{
		for(int j = 1; j <= str.length(); j++)
		{
			set.insert(str.substr(i, j));
		}
	}

	cout << set.size();

	return 0;
}
