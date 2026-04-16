#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& A, int p, int q, int r);
void merge_sort(vector<int>& A, int p, int r);

int K;			// K번째 저장되는 수
int cnt = 0;	// 저장 횟수

// 알고리즘 수업 - 병합 정렬 1

//merge_sort(A[p..r]) {
//    # A[p..r]을 오름차순 정렬한다.
//        if (p < r) then{
//            q < -⌊(p + r) / 2⌋;       # q는 p, r의 중간 지점
//            merge_sort(A, p, q);      # 전반부 정렬
//            merge_sort(A, q + 1, r);  # 후반부 정렬
//            merge(A, p, q, r);        # 병합
//        }
//}

void merge_sort(vector<int>& A, int p,int r)
{
	if (p<r)
	{
		int q = (p + r) / 2; // int이므로 자동으로 내림 처리됨
		merge_sort(A, p, q); // 전반부 정렬
		merge_sort(A, q + 1, r); // 후반부 정렬
		merge(A, p, q, r); // 병합
	}
}

//# A[p..q]와 A[q + 1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
//# A[p..q]와 A[q + 1..r]은 이미 오름차순으로 정렬되어 있다.
//merge(A[], p, q, r) {
//    i < -p; j < -q + 1; t < -1;
//    while (i ≤ q and j ≤ r) {
//        if (A[i] ≤ A[j])
//            then tmp[t++] < -A[i++]; # tmp[t] < -A[i]; t++; i++;
//        else tmp[t++] < -A[j++]; # tmp[t] < -A[j]; t++; j++;
//    }
//    while (i ≤ q)  # 왼쪽 배열 부분이 남은 경우
//        tmp[t++] < -A[i++];
//    while (j ≤ r)  # 오른쪽 배열 부분이 남은 경우
//        tmp[t++] < -A[j++];
//    i < -p; t < -1;
//    while (i ≤ r)  # 결과를 A[p..r]에 저장
//        A[i++] < -tmp[t++];
//}

void merge(vector<int>& A, int p, int q, int r)
{
	int i = p; // 왼쪽 부분 배열의 시작 인덱스
	int j = q + 1; // 오른쪽 부분 배열의 시작 인덱스
	int t = 0; // tmp 배열의 인덱스
	vector<int> tmp(r - p + 1); // 임시 배열

	// A[p..q]와 A[q + 1..r]을 병합
	while (i <= q && j <= r)
	{
		// 두 배열의 원소를 비교하여 작은 것을 tmp에 저장
		if (A[i] <= A[j])
		{
			tmp[t] = A[i];
			t++;
			i++;
		}
		else
		{
			tmp[t] = A[j];
			t++;
			j++;
		}
	}

	while (i <= q) // 왼쪽 배열 부분이 남은 경우
	{
		tmp[t] = A[i];
		t++;
		i++;
	}
	while (j <= r) // 오른쪽 배열 부분이 남은 경우
	{
		tmp[t] = A[j];
		t++;
		j++;
	}
	i = p;
	t = 0;
	while (i <= r) // 결과를 A[p..r]에 저장
	{
		A[i] = tmp[t];
		cnt++;

		// K번째 저장되는 수를 출력하고 종료
		if (cnt == K)
		{
			cout << A[i] << "\n";
			exit(0);
		}

		i++;
		t++;
	}
}

void program()
{
	int N;
	cin >> N;
	vector<int> A(N);
	cin >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	// 병합 정렬 수행
	merge_sort(A, 0, N - 1);

	// K번째 저장되는 수가 없는 경우 -1 출력
	cout << -1 << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	program();
	return 0;
}