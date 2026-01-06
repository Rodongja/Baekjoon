#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// 인사성 밝은 곰곰이

void program()
{
	int N;
	cin >> N;

	// 방문자 이름만 저장해도 되니 unordered_set 사용
	unordered_set<string> visitors;
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		// ENTER면 방문자 명단 초기화
		if (name == "ENTER")
		{
			cnt += visitors.size();
			visitors.clear();
		}
		// ENTER가 아니면 방문자 명단에 추가
		else
		{
			visitors.insert(name);
		}
	}

	// 마지막 ENTER 이후 방문자 수 추가
	cnt += visitors.size();

	// 최종 방문자 수 출력
	cout << cnt << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}