#include <bits/stdc++.h>
using namespace std;

struct node {
    long long int sum;
    long long int max;
};
   
node combine(node lc,node rc)
{
    node parent;
    parent.sum = lc.sum+rc.sum;
    parent.max = max(lc.max,rc.max);
    return parent;
}
   
void construct(node* tree,long long int arr[],long long int start,long long int end,long long int index)
{
    if (start==end)
    {
        tree[index].sum=arr[start];
        tree[index].max=arr[start];
    }
    else
    {
        long long int mid=(start+end)/2;
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

node getSum(node* tree,long long int ss,long long int se,long long int qs,long long int qe,long long int index)
{

    if (ss>qe||se<qs) 
    {
        node temp;
        temp.sum=0;
        temp.max=0;
        return temp;
    }

    if (ss>=qs&&se<=qe)
    {
        return tree[index];
    }
    long long int mid = (ss+se)/2;
    node lc=getSum(tree,ss,mid,qs,qe,2*index);
    node rc=getSum(tree,mid+1,se,qs,qe,2*index+1);
    node ans=combine(lc,rc);
    return ans;
}

int main()
{
    long long int n;
    cin>>n;
    long long int q;
    cin>>q;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
        cin>>arr[i];
    node* ST=constructST(arr, n);
    for(long long int i=0;i<q;i++)
    {
        long long int start,end;
        cin>>start;
        cin>>end;
        node ans=getSum(ST,0,n-1,start-1,end-1,1);
        long long int total=ans.sum;
        long long int maximum=ans.max;
        long long int result=(end-start+1)*maximum-total;
        cout<<result<<endl;
    }
    
    return 0;
}
