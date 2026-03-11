#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

// 에디터

void program()
{
	string str;
	cin >> str;

	// 문자 배열
	list<char> arr;
	
	for (int i = 0; i < str.size(); i++)
	{
		arr.push_back(str[i]);
	}

	// 커서 초기화 (마지막 위치)
	list<char>::iterator cursor = arr.end();
	
	// 명령어 수 입력
	int M;
	cin >> M;

	// 명령어 처리
	for (int i = 0; i < M; i++)
	{
		char command;
		cin >> command;

		// L: 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시)
		if (command == 'L')
		{
			if(cursor != arr.begin())
				cursor--;
		}
		// D: 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시)
		else if (command == 'D')
		{
			if(cursor != arr.end())
				cursor++;
		}
		// B: 커서 왼쪽에 있는 문자를 삭제 (커서가 문장의 맨 앞이면 무시)
		else if (command == 'B')
		{
			if (cursor != arr.begin())
			{
				cursor--;
				cursor = arr.erase(cursor);
			}
		}
		// P $: $라는 문자를 커서 왼쪽에 추가 (커서는 추가된 문자 오른쪽에 위치)
		else if (command == 'P')
		{
			char input;
			cin >> input;

			arr.insert(cursor, input);
		}
	}

	// 결과 출력
	cout << string(arr.begin(), arr.end()) << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}