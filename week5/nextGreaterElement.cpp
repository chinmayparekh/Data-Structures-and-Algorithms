// Given an array of n elements, for every element print the next greater element. The next greater element is the first
// element to the right which is larger than the element itself.
// If there exists no larger element to the right then output -1.

#include "bits/stdc++.h"
using namespace std;

int main()
{
    stack <int> stack;
    int n;
    cin>>n;
    int arr[n];int index[n];
    int ans[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        while(!stack.empty() && arr[i]>arr[stack.top()]) 
        {
            index[stack.top()]=i;
            stack.pop();
        }
        stack.push(i);

    }
    while(!stack.empty())
    {
        index[stack.top()]=-1;
        stack.pop();
    }

    for(int i=0;i<n;i++)
    {
        if(index[i]==-1)
            printf("-1 ") ;
        else
            printf("%d ",arr[index[i]]);
    }
    return 0;
}