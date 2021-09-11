#include <bits/stdc++.h>
using namespace std;

struct node{
    long long int squareSum;
    long long int sum;
};

node combine(node lc,node rc)
{
    node parent;
    parent.sum=lc.sum+rc.sum;
    parent.squareSum=lc.squareSum+rc.squareSum;
    return parent;
}

void construct(node* tree,long long int arr[],long long int start,long long int end,long long int index){
    if(start==end){
        tree[index].squareSum=arr[start]*arr[start];
        tree[index].sum=arr[start];
        return ;
    }
    long long int mid=(start+end)/2;
    construct(tree,arr,start,mid,2*index);
    construct(tree,arr,mid+1,end,2*index+1);
    tree[index] = combine(tree[2*index],tree[2*index+1]);
}

node* constructST(long long int arr[],long long int n)
{ 
    node* tree = new node[4*n];
    construct(tree,arr,0,n-1,1);
    return tree;
}

void update(node* tree,long long int lazy[],long long int ss,long long int se,long long int qs,long long int qe,long long int index,long long int value)
{
    long long int x=lazy[index];
    if(lazy[index]!=0)
    {
        tree[index].squareSum+=(2*lazy[index]*tree[index].sum)+(lazy[index]*lazy[index])*(se-ss+1); 
        tree[index].sum+=lazy[index]*(se-ss+1);
                   
        if(ss!=se)
        {
            lazy[2*index]+=x;
            lazy[2*index+1]+=x;
        }
        lazy[index]=0;
    }
    if(ss>qe || se< qs)
    {
        return ;
    }
    
    if(ss>=qs && se<=qe)
    {
        x=(se-ss+1)*value;
        tree[index].squareSum+=(2*value*tree[index].sum)+(value*value)*(se-ss+1);  
        tree[index].sum+=x;
        if(ss!=se)
        {
            lazy[2*index]+=value;
            lazy[2*index+1]+=value;
        }
        return;
    }
    long long int mid=(ss+se)/2;
    update(tree,lazy,ss,mid,qs,qe,2*index,value);
    update(tree,lazy,mid+1,se,qs,qe,2*index+1,value);
    tree[index].squareSum=tree[2*index].squareSum+tree[2*index+1].squareSum;
    tree[index].sum=tree[2*index].sum+tree[2*index+1].sum;

}
node getSum(node* tree,long long int lazy[],long long int ss,long long int se,long long int qs,long long int qe,long int index)
{

    if (ss>qe||se<qs) 
    {
        node temp;
        temp.sum=0;
        temp.squareSum=0;
        return temp;
    }

    if(lazy[index]!=0)
    {
        tree[index].squareSum+=(2*lazy[index]*tree[index].sum)+(lazy[index]*lazy[index])*(se-ss+1); 
        tree[index].sum+=(se-ss+1)*lazy[index];
         
        if(ss!=se)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
            
        }
        lazy[index]=0;
    }
    if (ss>=qs&&se<=qe)
    {
        return tree[index];
    }
    long long int mid = (ss+se)/2;
    node lc=getSum(tree,lazy,ss,mid,qs,qe,2*index);
    node rc=getSum(tree,lazy,mid+1,se,qs,qe,2*index+1);
    node ans=combine(lc,rc);
    return ans;
}

int main()
{
    long long int n,q,query;
    cin>>n;
    cin>>q;
    long long int arr[n];
    long long int lazy[4*n]={0};
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    node* ST=constructST(arr, n);
    for(long long int i=0;i<q;i++)
    {
        cin>>query;
        if(query==2)
        {
            long long int start,end;
            cin>>start>>end;
            node ans=getSum(ST,lazy,0,n-1,start-1,end-1,1);
            cout<<ans.squareSum<<endl;
        }
        if(query==1)
        {
            long long int start,end,value;
            cin>>start>>end>>value;
            update(ST,lazy,0,n-1,start-1,end-1,1,value);
        
        }
    }
    return 0;
}