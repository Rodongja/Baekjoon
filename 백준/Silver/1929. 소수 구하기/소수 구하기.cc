#include <iostream>
#include <vector>
using namespace std;

// 소수 구하기
// 에라토스테네스의 체 사용

// 소수 판별
bool isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int M,N;

	cin >> M;
	cin >> N;

    vector<int> primes;

    for (int i = M; i <= N; i++)
    {
        if(isPrime(i))
        {
            primes.push_back(i);
		}
    }

    for(int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << "\n";
	}

    return 0;
}