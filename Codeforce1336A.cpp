#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[2000005];
int level[2000005],subtree[2000005];
void bfs(int node,int parent,int lev=1)
{
    level[node]=lev;
    int cnt=0;
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            bfs(it,node,lev+1);
            cnt+=subtree[it];
        }
    }
    subtree[node]=cnt+1;
}
void linova()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,0);
    vector<int>vec;
    for(int i=1;i<=n;i++)
    {
        vec.push_back(level[i]-subtree[i]);
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    int ans=0;
    for(int i=0;i<k;i++)
    {
        ans+=vec[i];
    }
    cout<<ans<<"\n";
}
int main() {
	linova();
	return 0;
}