#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int ans[1001];
    ans[0]=1;
    ans[1]=1;
    for(int i=2;i<=1000;i++)
    {
        ans[i]=0;
        for(int j=0;j<i;j++)
        {
            ans[i]+=ans[j]*ans[i-j-1];
            ans[i]%=1000000007;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)

    {
        int q;
        cin>>q;
        cout<<ans[q]<<endl;
    }
    return 0;
}