#include <bits/stdc++.h>
using namespace std;

struct node {
    long long int maxPrefixSum;
    long long int maxSuffixSum;
    long long int sum;
    long long int maxSubarraySum;
};
   
node combine(node lc,node rc)
{
    node parent;
    parent.maxPrefixSum = max(lc.maxPrefixSum,lc.sum+rc.maxPrefixSum);
    parent.maxSuffixSum = max(rc.maxSuffixSum,rc.sum+lc.maxSuffixSum);
    parent.sum = lc.sum+rc.sum;
    long long temp=max(lc.maxSubarraySum,rc.maxSubarraySum);
    parent.maxSubarraySum = max(temp,lc.maxSuffixSum+rc.maxPrefixSum);
    return parent;
}
   
void construct(node* tree,long long int arr[],long long int start,long long int end,long long int index)
{
    if (start==end)
    {
        tree[index].sum=arr[start];
        tree[index].maxSuffixSum=arr[start];
        tree[index].maxPrefixSum=arr[start];
        tree[index].maxSubarraySum=arr[start];
    }
    else
    {
        int mid=(start+end)/2;
        construct(tree,arr,start,mid,2*index);
        construct(tree,arr,mid+1,end,2*index+1);
        tree[index] = combine(tree[2*index],tree[2*index+1]);
    }
    
}

node* constructST(long long int arr[],long long int n)
{ 
    node* tree = new node[4*n];
    construct(tree,arr,0,n-1,1);
    return tree;
}

node getMaxSum(node* tree,long long int ss,long long int se,long long int qs,long long int qe,long long int index)
{

    if (ss>qe||se<qs) 
    {
        node temp;
        return temp;
    }

    if (ss>=qs&&se<=qe)
    {
        return tree[index];
    }
    long long int mid = (ss+se)/2;
    node lc=getMaxSum(tree,ss,mid,qs,qe,2*index);
    node rc=getMaxSum(tree,mid+1,se,qs,qe,2*index+1);
    node ans=combine(lc,rc);
    return ans;
}

int main()
{
    long long int n;
    cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
        cin>>arr[i];
    node* ST=constructST(arr, n);
    node ans=getMaxSum(ST,0,n-1,0,n-1,1);
    if(ans.maxSubarraySum>=0)
        cout<<ans.maxSubarraySum <<endl;
    else
        cout<<"0"<<endl;
    return 0;
}
