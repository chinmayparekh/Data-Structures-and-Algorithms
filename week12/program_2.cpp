#include <bits/stdc++.h>
using namespace std;

struct edge{
    long long int u;
    long long int v;
    long long int w;
};

bool compare(edge a,edge b)
{
    return a.w>b.w;
}

long long int find(long long int current,long long int parent[])
{
    if(current==parent[current])
    {
        return current;
    }
    return parent[current]=find(parent[current],parent);
}

void merge(long long int a,long long int b,long long int rank[],long long int parent[])
{
    a=find(a,parent);
    b=find(b,parent);
    if(a!=b)
    {
        if(rank[a]<rank[b])
            swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b])
            rank[a]++;
    }
}

int main()
{
    long long int n,m;
    cin>>n>>m;
    vector<edge> adj(m+1);
    long long int parent[n+1],rank[n+1];
    for(long long int i=0;i<m;i++)
    {
        cin>>adj[i].u>>adj[i].v>>adj[i].w;
        adj[i].u--;
        adj[i].v--;
    }
    for(long long int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
    long long int ans=0;
    sort((adj).begin(),(adj).end(),compare);
    for(long long int i=0;i<m;i++)
    {
        long long int a=adj[i].u;
        long long int b=adj[i].v;
        if(find(a,parent)!=find(b,parent))
        {
            ans+=adj[i].w;
            merge(a,b,rank,parent);
        }
    }
    cout<<ans<<endl;
    return 0;
    

}