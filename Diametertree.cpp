#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
Node *newnode(int k)
{
    Node *root=(Node*)malloc(sizeof(Node));
    root->data=k;
    root->left=root->right=NULL;
    return root;
    
}
Node *insert(Node *root, int data)
{
    if(root==NULL)
    {
        root=newnode(data);
    }
    else if(data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
int hight(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(hight(root->left),hight(root->right))+1;
}
int diameterOfBinaryTree(Node* root) {
    if(root==NULL)
    {
        return 0;
            
    }
    int lh=hight(root->left);
    int rh=hight(root->right);
    int lb=diameterOfBinaryTree(root->left);
    int rb=diameterOfBinaryTree(root->right);
    return max((lh+rh+1),max(lb,rb));
        
}

int main() {
    Node* root=NULL;
	int n;
	cin>>n;
	int a;
	while(n--)
	{
	    cin>>a;
	    root=insert(root,a);
	}
	cout<<diameterOfBinaryTree(root);
	return 0;
}