#include <iostream>
#include <vector>
using namespace std;

// 베르트랑 공준

// n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램 작성

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
    int N = -1;

	vector<int> numbers;

    while (N != 0)
    {
        cin >> N;

        numbers.push_back(N);
    }

    // 소수 개수 구하기
    for(int i = 0; i < numbers.size() - 1; i++)
    {
        int count = 0;
        int n = numbers[i];
        vector<bool> isPrime = sieveOfEratosthenes(2 * n);

		// n+1부터 2n까지 소수 개수 세기
        for (int j = n + 1; j <= 2 * n; j++)
        {
            if (isPrime[j])
            {
                count++;
            }
        }
		// 결과 출력
        cout << count << endl;
	}
    
    return 0;
}