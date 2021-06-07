#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};

int main() {
    //we represent an empty tree as null 
    //Node *root=NULL;
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	return 0;
}