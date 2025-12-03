#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

// 회사에는 동명이인이 없으니 unordered_set을 사용하여 빠르게 탐색
// unordered_set은 정렬을 하지 않아 출력의 순서는 보장되지 않음
// 따라서 출력 전에 정렬이 필요해 vector에 복사 후 정렬 필요

int main()
{
	int n;
	cin >> n;

	unordered_set<string> logs;

	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;

		string status;
		cin >> status;


		if(status == "enter")
		{
			logs.insert(name);
		}
		else if(status == "leave")
		{
			logs.erase(name);
		}
	}

	vector<string> result(logs.begin(), logs.end());

	sort(result.rbegin(), result.rend());

	for(size_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}