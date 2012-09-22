#include<iostream>
#include<algorithm>
#include <vector> 
using namespace std;
#define MAXN 1000
int m,n;

typedef struct
{
	int value;
	int w_left;
	int w_right;
	node* left;
	node* right;

} node;
class tree
{
public:
	node *root;
	void addnode(int value)
	{
	}

};

int max_  = 0;


int getmax(node* t)
{
	if(t == NULL) return -1;
	t->w_left = getmax(t->left)+1;
	t->w_right = getmax(t->right)+1;
	if(t->w_left + t->w_right > max_)
		max_ = t->w_left + t->w_right;
	if(t->w_left > t->w_right)
		return t->w_left;
	else
		return t->w_right;
}

int main()
{
	//bulid tree
	//
	tree tree1;
	tree1.root = NULL;
	
	getmax(tree1.root);
	cout<<max_<<endl;
	return 0;
}