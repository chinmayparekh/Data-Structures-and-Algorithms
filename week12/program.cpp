#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<long long int,long long int>> adj[n];
    int a,b,wt;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }
    int parent[n];
    int key[n];
    bool mst[n];

    for(int i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mst[i]=false;
    }
    priority_queue<pair<long long int,long long int>,vector <pair<long long int,long long int>> ,greater<pair<long long int,long long int>> > pq;
    key[0]=0;
    parent[0]=-1;
    pq.push({0,0});
    for(int count=0;count<n-1;count++)
    {
        long long int u=pq.top().second;
        pq.pop();
        mst[u]=true;

        for(auto i:adj[u])
        {
            long long int v=i.first;
            long long int weight=i.second;
            if(mst[v]==false && weight<key[v])
            {
                parent[v]=u;
                pq.push({key[v],v});
                key[v]=weight;
            }
        }
    }

    for(int i=1;i<n;i++)
        cout<<parent[i]<<"-"<<i<<endl;

}