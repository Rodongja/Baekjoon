#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

// 집합 S에 같은 문자열이 여러 번 주어지는 경우는 없다
// 그러므로 unordered_set을 사용하여 문자열을 저장하고 탐색
// 해쉬테이블을 이용하여 평균 O(1)의 시간복잡도로 탐색 가능

int main()
{
	int N, M;
	cin >> N;
	cin >> M;

	unordered_set<string> S(N);
	
	for(int i = 0 ; i < N; i++)
	{
		string str;
		cin >> str;
		S.insert(str);
	}

	
	int count = 0;

	for(int i = 0 ; i < M; i++)
	{
		string str;
		cin >> str;
		if(S.find(str) != S.end())
			count++;
	}

	cout << count;

	return 0;
}