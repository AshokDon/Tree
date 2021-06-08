#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000005];
int maxi;
void HightDFS(int node,int parent,int ht=1)
{
    maxi=max(maxi,ht);
    for(auto it:adj[node])
    {
        if(it!=parent)
        {
            HightDFS(it,node,ht+1);
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
//	DFS(1,0);
//	BFS(1,0);
    HightDFS(1,0);
    cout<<maxi;
	return 0;
}