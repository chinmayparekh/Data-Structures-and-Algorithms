
#include<bits/stdc++.h>
using namespace std;

int getAns(int p,int l,int A[],int B[],int* n,int* flag)
{
    priority_queue<int> maxHeap;//implementing max Heap
    for(int i=0;i<*n;i++)
    {
        if(l-B[i]<=p)
        {
            maxHeap.push(A[i]);//pushing the doses of all the stores which are reachable
        }
    }
    if(maxHeap.empty())
    {
        *flag=1;
        return 0;
    }
    else
    {
        int i;
        int maximum=maxHeap.top();
        maxHeap.pop();
        p+=maximum;
        //deleting the shop and its doses from arrays B and A respectively so that they are not checked again
        for(i=0;i<*n;i++)
        {
            if(maximum==A[i])
            break;
        }
        if(i<*n)
        {
            *n=*n-1;//reducing the array length by 1
            for(int j=i;j<*n;j++)
            {
                A[j]=A[j+1];
                B[j]=B[j+1];
            }

        }
        
    }
    return p;

}

int main()
{
    int flag=0;
    int n;
    int count=0;//to store the final answer
    cin >>n;
    int A[n],B[n];
    int L,reachable;
    for(int i=0;i<n;i++)
        cin>>A[i];

    for(int i=0;i<n;i++)
        cin>>B[i];

    cin >>L;
    cin>>reachable;

    while(reachable<L)
    {
        reachable=getAns(reachable,L,A,B,&n,&flag);
        if(flag)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        count++;
    }
    
    cout<<count<<endl;
    return 0;
    
}

