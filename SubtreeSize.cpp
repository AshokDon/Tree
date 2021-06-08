#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000005];
int subtree[1000005];
void subtreesize(int node,int parent)
{
    int cnt=0;
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            subtreesize(it,node);
            cnt+=subtree[it];
        }
    }
    subtree[node]=cnt+1;
    //add up all children size while backtracking
    /*for(auto it:adj[node])
    {
        if(it!=parent)
        {
            subtree[node]+=subtree[it]
        }
    }*/
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
//	DFS(1,0);
//	BFS(1,0);
    HightDFS(1,0);
    cout<<maxi;
	return 0;
}