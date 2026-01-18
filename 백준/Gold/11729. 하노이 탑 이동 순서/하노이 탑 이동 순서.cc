#include <iostream>
#include <vector>

using namespace std;

// 하노이 탑 이동 순서
int N;
int K;
vector<pair<int, int>> process; // 이동 기록 저장

void move(int num, vector<int>& from, vector<int>& temp, vector<int>& to)
{
	if (num == 0)
		return;

	move(num - 1, from, to, temp);
	process.push_back({ from[0], to[0] });
	move(num - 1, temp, from, to);
}


void program()
{
	cin >> N;

	vector<int> vec1, vec2, vec3;
	
	// 기둥 번호 판별용
	vec1.push_back(1);
	vec2.push_back(2);
	vec3.push_back(3);

	for (int i = 1; i <= N; i++)
	{
		vec1.push_back(i);
	}

	move(N,vec1,vec2,vec3);

	cout << process.size() << "\n";

	for (int i = 0; i < process.size(); i++)
	{
		cout << process[i].first << " " << process[i].second << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}