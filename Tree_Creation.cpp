/*
Build a binary tree from a parent array
Google Translate Icon
Given an integer array representing a binary tree, such that the parent-child relationship is defined by (A[i], i)
for every index i in array A, build a binary tree out of it. The root node’s value is i if -1 is present at index i in the array. 
It may be assumed that the input provided to the program is valid.

For example,

Parent: [-1, 0, 0, 1, 2, 2, 4, 4]
Index : [ 0, 1, 2, 3, 4, 5, 6, 7]
 


*/





#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
using namespace std;
const int mod = (int)1e9 + 7;
ll power(ll a, ll b){
    if(b == 0)return 1;
    ll x = power(a , b / 2);
    if(b % 2){
        return (x%mod*x%mod*a%mod) % mod;
    }
    else{
        return (x*x) % mod;
    }
}
ll inverse(ll a){
    return power(a,mod-2);
}
int dp[1000001];
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
struct Node{
	int data;
	Node *left, *right;
	Node(int val){
		this->data = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};
Node* Creat_A_BinaryTree(int n , int A[]){
	unordered_map<int,Node*>mpp;
	for(int i = 0 ; i < n ; i++){
		mpp[i] = new Node(i);
	}
	Node *root = nullptr;
	for(int i = 0 ; i < n ; i++){
		if(A[i]==-1){
			root = mpp[i];
		}
		else{
			Node *par = mpp[A[i]];
			if(par->left){
				par->right = mpp[i];
			}
			else{
				par->left = mpp[i];
			}
		}
	}
	return root;
}
void Inorder(Node *root){
	if(root){
		Inorder(root->left);
		cout<<root->data<<" ";
		Inorder(root->right);
	}
}
int main() {
    // your code goes here
    fast_io;
    TakeInput();
    int n;
    cin >> n;
    int A[n];
    for(int i = 0 ; i < n ; i++){
    	cin >> A[i];
    }
    Node *root=Creat_A_BinaryTree(n,A);
    Inorder(root);
    return 0;
}
