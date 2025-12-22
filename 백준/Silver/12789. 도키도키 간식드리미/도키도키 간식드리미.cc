#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 도키도키 간식드리미
void checkStack(stack<int>& line, int& target)
{
	// 스택에 남아있는 번호표가 순번(target)과 일치할 경우
	while (!line.empty() && line.top() == target)
	{
		target++;
		line.pop();
	}
}

void snack(int max)
{
	stack<int> line;
	bool possible = true;

	// 찾을 순번
	int target = 1;

	for (int i = 0; i < max; i++)
	{
		int num;
		cin >> num;

		// 스택에 남아있는 번호표가 순번(target)과 일치할 경우
		checkStack(line, target);

		// 번호표가 순번(target)과 일치할 경우
		if(num == target)
		{
			// 다음 순번으로 이동
			target++;
			continue;
		}
		// 번호표가 순번과 일치하지 않고 스택에 남아있는 번호표도 순번과 일치하지 않는 경우
		else
		{
			// 번호표가 순번과 일치하지 않는 경우 대기열에 추가
			line.push(num);
		}
	}

	// 스택에 남아있는 번호표가 순번(target)과 일치할 경우
	checkStack(line, target);

	// 대기열에 남아있는 번호표 확인
	if (!line.empty())
	{
		possible = false;
	}


	// 출력
	if(possible)
		cout << "Nice";
	else
		cout << "Sad";
}

int main()
{
	int N;
	cin >> N;

	snack(N);

	return 0;
}