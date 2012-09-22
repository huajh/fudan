#include<iostream>
#include<algorithm>
#include <vector> 
#include<iterator>
#include<queue>
using namespace std;
#define MAXN 1000

char preorder[MAXN];
char inorder[MAXN];
char postorder[MAXN];

struct node
{
	node* left;
	node* right;
	char value;
};

node* root = NULL;
int len = 0 ;

// ch can not be equal to piv
bool is_left(char ch,char piv)
{
	// find in inorder
	for(int i=0;i<len;i++)
	{
		if(inorder[i]==ch)
		{
			return true;
		}else if(inorder[i] == piv)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%s%s",postorder,inorder);
	len = strlen(postorder);

	// build tree
	root = new node;
	root->value = postorder[len-1];
	root->left = NULL;
	root ->right =NULL;
	for(int i = len-2;i>=0;i--)
	{
		node* it = root ,*pre = root;
		while(it!=NULL)
		{
			pre = it;
			if(is_left(postorder[i],it->value))
			{
				it = it->left;
				if(it==NULL)
				{
					node * leftchild = new node;
					leftchild->value = postorder[i];
					leftchild->left = NULL;
					leftchild->right = NULL;
					pre->left = leftchild;
					break;
				}
			}else 
			{
				it = it->right;
				if(it ==NULL)
				{					
					node * rightchild = new node;
					rightchild->value = postorder[i];
					pre->right = rightchild;
					rightchild->left = NULL;
					rightchild->right = NULL;
					break;
				}
			}
		}
	}
	// print tree
	queue<node*> q;
	q.push(root);
	char hit[MAXN] = {0};
	int cnt = 0 ;
	while(!q.empty())
	{
		node* it = q.front();
		q.pop();
		hit[cnt++] = it->value;
		if(it->left !=NULL) q.push(it->left);
		if(it->right !=NULL) q.push(it->right);
	}
	hit[cnt] = '\0';
	printf("%s\n",hit);
	return 0;
}