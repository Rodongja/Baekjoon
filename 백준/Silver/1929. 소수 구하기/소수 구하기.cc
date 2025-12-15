#include <iostream>
#include <vector>
using namespace std;

// 소수 구하기
// 에라토스테네스의 체 사용

// 에라토스테네스의 체 알고리즘 구현
vector<bool> sieveOfEratosthenes(int maxNum) {
	// true이면 소수, false이면 소수가 아님
    vector<bool> isPrime(maxNum + 1, true);
    isPrime[0] = false; 
    isPrime[1] = false; // 0과 1은 소수가 아님

	// 에라토스테네스의 체 알고리즘 적용
	// 2부터 maxNum의 제곱근까지 반복
    for (int i = 2; i * i <= maxNum; ++i) {
		// i가 소수인 경우
        if (isPrime[i]) {
			// i의 배수들을 모두 소수가 아니라고 표시
            for (int j = i * i; j <= maxNum; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }
	// 소수 여부를 담은 벡터 반환
    return isPrime;
}

int main()
{
    int M,N;

	cin >> M;
	cin >> N;

	// N까지의 소수 여부를 미리 계산
	vector<bool> isPrime = sieveOfEratosthenes(N);

	// M부터 N까지의 소수 출력
	for (int i = M; i <= N; ++i) 
    {
        if (isPrime[i]) 
        {
            cout << i << "\n";
        }
	}

    return 0;
}