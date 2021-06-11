#include <iostream>
#include<bits/stdc++.h>

using namespace std;
struct Node{
    int key;
    Node *left;
    Node *right;
    Node (int k)
    {
        key=k;
        left=right=NULL;
    }
};
int height(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else{
        return max(height(root->left),height(root->right))+1;
    }
}
void printKnode(Node *root,int target)
{
    if(root==NULL)
    {
        return;
    }
    if(target==0)
    {
        cout<<root->key;
    }
    else{
        printKnode(root->left,target-1);
        printKnode(root->right,target-1);
    }
}

int main() {
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
	int k;
	cin>>k;
    printKnode(root,k);
	//cout<<height(root);
	return 0;
}