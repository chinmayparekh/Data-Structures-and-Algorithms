#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int PrefixSum(int BIT[], int i)
{
	int sum = 0; // Iniialise sum 

	while (i>0)
	{
		sum += BIT[i];

		i -= i & (-i);
	}
	return sum;
}

void updateBIT(int BIT[], int n, int i, int X)
{

	while (i <= n)
	{
	BIT[i] += X;

	i += i & (-i);
	}
}

int * constructBIT(int A[], int n)
{
	int *BIT = new int[n+1];
	for (int i=1; i<=n; i++)
		BIT[i] = 0;

	for (int i=1; i<=n; i++)
		updateBIT(BIT, n, i, A[i]);

	return BIT;
}

int main()
{
    int length=1000000;
    int arr[length]={0};
    int n;
    cin>>n;
    int *BIT = constructBIT(arr, length);
    for(int i=0;i<n;i++)
    {
        int q,num,ans;
        cin>>q>>num;
        if(q==0)
        {
        updateBIT(BIT,length,num,1);
        }
        if(q==1)
        {
            int start=0;
            int end=length-1;
            while(start<=end)
            {
                int mid=(start+end)/2;
                if(num==PrefixSum(BIT,mid))
                {
                    ans=mid;
                    end=mid-1;
                }
                else if(num<PrefixSum(BIT,mid))
                    end=mid-1;
                else
                    start=mid+1;
            }

            cout<<ans<<endl;
        }
        if(q==2)
        {
            updateBIT(BIT,length,num,-1);
        }
        
    }
    return 0;
}