#include "bits/stdc++.h"
using namespace std;

long long merge(int arr[],long long int l,long long int r)
{
    long long int mid=(l+r)/2;
    long long int count=0;
    long long int n1=mid-l+1;
    long long int n2=r-mid;//r-(mid+1)+1
    long long int a[n1],b[n2];
    long long int i,j,k;
    long long int B[r-l+1];
    
    for(i=0;i<n1;i++)//copying the left subarray 
        a[i]=arr[l+i];

    for(i=0;i<n2;i++)//copying the right subarray
        b[i]=arr[mid+i+1];

    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k++]=a[i++];
            
        }
        else
        {
            arr[k++]=b[j++];
            count+=n1-i;//all the elements remaining in the left subarray which are smaller than b[j] will get inversed
        }

    }

    while(i<n1)//to copy the remaing elements of the left subarray
    {
        arr[k++]=a[i++];
        
    }
    while(j<n2)//to copy the remaining elements of the right subarray 
    {
        arr[k++]=b[j++];
        
    }
    return count;
}

long long mergeSort(int arr[],long long int l,long long int r)
{
    long long count=0;
    if(l<r)
    {
        long long int mid=(l+r)/2;
        count+=mergeSort(arr,l,mid);
        count+=mergeSort(arr,mid+1,r);
        count+=merge(arr,l,r);
    }
    return count;
}

int main()
{
    long long int n;
    cin>>n;
    int arr[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<mergeSort(arr,0,n-1)<< endl;
    return 0;
}
