#include <bits/stdc++.h>
using namespace std;
long long int PrefixSum(long long int BIT[],long long int i)
{
	long long int sum = 0; // Iniialise sum 

	while (i>0)
	{
		sum += BIT[i];

		i -= i & (-i);
	}
	return sum;
}

void updateBIT(long long int BIT[], long long int n, long long int i,long long int X)
{

	while (i <= n)
	{
	BIT[i] += X;

	i += i & (-i);
	}
}

long long int * 
constructBIT(long long int A[], long long int n)
{
	long long int *BIT = new long long int[n+1];
	for (long long int i=1; i<=n; i++)
		BIT[i] = 0;

	for (long long int i=1; i<=n; i++)
		updateBIT(BIT, n, i, A[i]);

	return BIT;
}

int main()
{
    long long int n;
    cin>>n;
    long long int arr[n];
    for(long long int i=1;i<=n;i++)
        cin>>arr[i];

    long long int *BIT=constructBIT(arr,n+1);
    // for(int i=0;i<n+1;i++)
    //     cout<<PrefixSum(BIT,i)<<" ";
    //     cout<<endl;
    long long int minimum=0;
    long long int ans=INT_MIN;
    for(int i=1;i<n+1;i++)
    {
        ans=max(ans,PrefixSum(BIT,i)-minimum);
        minimum=min(minimum,PrefixSum(BIT,i));

    }
    if(ans==INT_MIN)
    cout<<"0"<<endl;
    else
    cout<<ans<<endl;
    return 0;
}