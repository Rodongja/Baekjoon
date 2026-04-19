#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0;
    cin >> N;
    int count = 0;
    int doom = 666;
    
    while(count < N)
    {
        string s = to_string(doom);
        if(s.find("666") != string::npos)
            count++;
        doom++;
    }
    cout << doom - 1;
    return 0;
}