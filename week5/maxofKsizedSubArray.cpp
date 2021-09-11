// Given an array of n elements, and an integer k, find the maximum of every k-sized subarray. 
// 5 3
// 1 2 3 4 5


#include "bits/stdc++.h"
using namespace std;

int main()
{
    deque<int> d;
    queue<int> q;

    int n,k;
    cin>>n>>k;
    int arr[n];
    // int ans[n-k+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // int max=arr[0];
    for(int i=0;i<k;i++)
    {
        while(!d.empty() && arr[d.back()]<arr[i])
        {
            d.pop_back();
        }
        d.push_back(i);
    }
    q.push(arr[d.front()]);
    for(int i=k;i<n;i++)
    {
        if(d.front()== i-k)
        {
            d.pop_front();
            // q.pop();
        }
        while(!d.empty() && arr[d.back()] <arr[i])
            d.pop_back();
        d.push_back(i);
        q.push(arr[d.front()]);
    }
     while (!q.empty()) {
        printf("%d ",q.front());
        q.pop();
     }
    return 0;
}