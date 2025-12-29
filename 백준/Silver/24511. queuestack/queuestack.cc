#include <iostream>
#include <deque>

using namespace std;

// queuestack

void program()
{
	// queuestack을 구성하는 자료구조 개수 N(1 ≤ N ≤ 100,000)이 주어진다.
	int N;
	cin >> N;
	
	// 길이 N의 수열 A가 주어진다. i번 자료구조가 큐라면 Ai = 0, 스택이라면 Ai = 1이다.
	deque<int> queuestack;
	deque<int> A;
	deque<int> B;
	deque<int> C;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	// 길이 N의 수열 B가 주어진다. Bi는 i번 자료구조에 들어 있는 원소이다.
	for( int i = 0 ; i< N; i++ )
	{
		int b;
		cin >> b;
		B.push_back(b);
	}

	// 넷째 줄에 삽입할 수열의 길이 M(1 ≤ M ≤ 100,000)이 주어진다.
	int M;
	cin >> M;

	// 다섯째 줄에 queuestack에 삽입할 원소를 담고있는 길이 M의 수열 C가 주어진다.
	for(int i = 0; i < M; i++)
	{
		int c;
		cin >> c;
		C.push_back(c);
	}

	// for문으로 구현
	// 시간초과
	//// 0일때에만 숫자가 바뀌므로 0의 숫자와 temp를 이용하여 구현	
	//for (int j = 0; j < M; j++)
	//{
	//	int input = C[j];
	//	int temp = 0;
	//	for (int i = 0; i < N; i++)
	//	{
	//		if (A[i] == 0) // 큐일때에만 바뀜
	//		{
	//			temp = B[i];
	//			B[i] = input;
	//			input = temp;
	//		}
	//	}
	//	cout << input << " ";
	//}

	// 큐에서만 값이 변한다는 점을 이용해 deque로 구현
	// 예를 들어 A가 0 1 1 0인 경우 2개의 큐가 존재하므로 2개의 queuestack이 필요하다
	// 그 뒤 하나씩 push_front를 하고 pop_back을 하면 된다 (이 때 pop_back 되는 값을 출력)
	// 0인 값들을 queuestack에 저장
	for (int i = 0; i < N; i++)
	{
		if (A[i] == 0)
		{
			queuestack.push_back(B[i]);
		}
	}

	// C의 값들을 queuestack에 삽입 및 출력 후 삭제
	for (int j = 0; j < M; j++)
	{
		queuestack.push_front(C[j]);
		cout << queuestack.back() << " ";
		queuestack.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}