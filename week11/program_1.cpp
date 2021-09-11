#include <bits/stdc++.h>
using namespace std;

long long int findCatalan(long long int n,long long int r)
{
    long long int p=1;
    if(r>n-r)
        r=n-r;
    for(int i=0;i<r;i++)
    {
        p*=(n-i);
        p/=(i+1);
        
    }
    
    long long int ans=p/(r+1);
    return ans;
}

int main()
{
    long long int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int q;
        cin>>q;
        cout<<findCatalan(2*q,q)<<endl;
    }   
    return 0;
}