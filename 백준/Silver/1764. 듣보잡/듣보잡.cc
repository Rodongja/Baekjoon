#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// unordered_set 사용


int main()
{

	int N;
	int M;

	// 입력
	cin >> N;
	cin >> M;

	// 자료구조 선언
	unordered_set<string> Nname;
	unordered_set<string> Mname;

	vector<string> result;

	// N 입력
	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		Nname.insert(name);
	}

	// M 입력
	for(int i = 0; i < M; i++)
	{
		string name;
		cin >> name;
		Mname.insert(name);
	}
	
	int count = 0;

	// 교집합 찾기
	for(const auto& name : Nname)
	{
		if(Mname.find(name) != Mname.end())
		{
			result.push_back(name);
			count++;
		}
	}

	cout << count << "\n";

	// 사전순 정렬
	sort(result.begin(), result.end());

	// 출력
	for(const auto& name : result)
	{
		cout << name << "\n";
	}

	return 0;
}
