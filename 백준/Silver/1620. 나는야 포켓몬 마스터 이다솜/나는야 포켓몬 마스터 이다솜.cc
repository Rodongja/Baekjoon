#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// vector로 인덱스와 값을 매칭하는 방법도 있지만 unordered_map을 사용
// string을 입력하면 int형 값을 반환하고 int형을 입력하면 string형 값을 반환하는 방식
// 순서대로 출력하기 위해 vector를 사용

bool isNumber(const string& str)
{
	for (char c : str)
	{
		if(!isdigit(c))
			return false;
	}
	return !str.empty();
}

int main()
{
	int N,M;
	cin >> N;
	cin >> M;

	// unordered_map을 사용하여 이름과 번호를 매핑
	// value로 key를 찾는것은 불가능 하기 때문에 2개로 저장
	unordered_map<string, int> Pokedex_S;
	unordered_map<int, string> Pokedex_I;
	vector<string> answer(M);

	for(int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		Pokedex_S.insert({ name, i+1 });
		Pokedex_I.insert({ i+1, name });
	}

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;

		// 입력된 값이 숫자인지 확인
		if (isNumber(str))
		{
			// stoi를 사용하여 string형을 int형으로 변환
			answer[i] = Pokedex_I.find(stoi(str))->second;
		}
		else
		{
			// vector는 string형이기 때문에 to_string 사용
			answer[i] = to_string(Pokedex_S.find(str)->second);
		}
	}

	for (int i = 0; i < M; i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}