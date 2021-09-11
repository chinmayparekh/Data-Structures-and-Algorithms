#include <bits/stdc++.h>
using namespace std;

int bipartite(vector<long long int>adj[],long long int n,long long int node,long long int colour[])
{
    queue<int> q;
    q.push(node);
    colour[node]=1;
    while(!q.empty())
    {
        int present=q.front();
        q.pop();
        for(int element:adj[present])
        {
            if(colour[element]==colour[present])
                return 0;
            if(colour[element]==-1)
            {
                colour[element]=1-colour[present];
                q.push(element);
            }
        }
    }
    return 1;
} 
int main()
{
    long long int n,m;
    int flag=0;
    cin>>n>>m;
    vector<long long int>adj[n+1];
    for(long long int i=0;i<m;i++)
    {
        long long int u,v;
        cin>>u>>v;
        if(u==v)
            flag=1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long int colour[n+1];
    for(long long int i=1;i<n;i++)
        colour[i]=-1;
    if(flag==0)
    {
        for(long long int i=0;i<n;i++)
        {
            if(colour[i]==-1)
            {
                if(!bipartite(adj,n,i,colour))
                    flag=1;

            }

        }
    }
  
    if(flag==1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}