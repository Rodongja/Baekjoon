#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int partition(vector<int>& vec,int l, int r)
{
    // 피봇을 가장 오른쪽에 배치하여 i와 j가 ++로 연산되어 계산이 쉽게 함
    int pivot = vec[r];
    int i = l - 1;
    
    // j 증가
    for(int j = l; j < r; j++)
    {
        // vec[j]가 피벗보다 작으면
        if(vec[j] <= pivot)
        {
            // i를 증가시키고 j와 스왑
            i++;
            swap(vec[i],vec[j]);
        }
    }
    
    // 모든 자리 교환이 끝나면 i+1과 피벗을 스왑
    swap(vec[i+1],vec[r]);
    
    // 새로운 피벗 리턴
    return (i+1);
}

void quickSort(vector<int>& vec, int l, int r)
{
    // 파티션에 원소가 2개 이상 존재
    if(l<r)
    {
        int pivot = partition(vec,l,r);
        // 피벗의 왼쪽 재귀
        quickSort(vec,l,pivot-1);
        // 피벗의 오른쪽 재귀
        quickSort(vec,pivot+1,r);
    }
}

int main()
{
    int vec_size;
    cin >>  vec_size;
    vector<int> vec(vec_size);
    
    for(int i = 0; i < vec_size; i++)
    {
        cin >> vec[i];
    }
    
    quickSort(vec,0,vec_size-1);
    
    for(int i =0; i < vec_size; i++)
    {
        cout << vec[i] << endl;
    }
}