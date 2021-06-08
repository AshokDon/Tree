#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
void DFS(int node,int parent)
{
    cout<<node<<" ";
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            DFS(it,node);
        }
    }
}
void BFS(int node,int parent)
{
    queue<pair<int,int>>q;
    q.push({node,parent});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        node=it.first;
        parent=it.second;
        cout<<node<<" ";
        for(auto i:adj[node])
        {
            if(i!=parent)
            {
                q.push({i,node});
            }
        }
    }
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	//DFS(10,0);
	BFS(10,0);
	return 0;
}