#include<iostream>
#include<algorithm>
#include <vector> 
#include<iterator>
#include<queue>
#include<fstream>

using namespace std;
#define MAXN 1000


 //Huffman tree

int node_cnt;
int data[MAXN];
int weights[MAXN];

typedef struct NODE
{
	NODE* left;
	NODE* right;
	int weight;
	char value;

}node;

struct cmpnode
{
	bool operator()(const node* node1, const node* node2)
	{
		return (node1->weight) > (node2->weight);
	}
};

class HufumanTree
{
public:	
	HufumanTree(){};
	HufumanTree(char v, int w)
	{
		root = new node;
		root->value =v;
		root->weight =w;
		root->left = NULL;
		root->right = NULL;
	};
	void AddRoot(node * r)
	{
		root = r;
	}

	void print_tree()
	{
		ofstream out("output.txt");	
		queue<node*> q;
		q.push(root);
		int cnt = 0;
		while(!q.empty())
		{
			node* it = q.front();
			q.pop();
			out<<cnt++<<":\t"<<it->value<<"\t"<<it->weight<<endl;
			if(it->left != NULL) q.push(it->left);
			if(it->right != NULL) q.push(it->right);
		}
		out.close();
	}
	~HufumanTree()
	{
		queue<node*> q;
		q.push(root);
		while(!q.empty())
		{
			node* it = q.front();
			q.pop();
			if(it->left != NULL) q.push(it->left);
			if(it->right != NULL) q.push(it->right);
			delete it;
		}
	};
private:
	node* root;
};
int main()
{
///	freopen("input.txt","r",stdin);
///	freopen("output.txt","w",stdout);
	
	ifstream in("input.txt");
	in>>node_cnt;
	// miniumn heap
	priority_queue<node*,vector<node*>,cmpnode> minheap;
	for(int i=0;i<node_cnt;i++)
	{
		node* newnode = new node;
		in>>newnode->value>>newnode->weight;
		newnode->left = NULL;
		newnode->right = NULL;
		minheap.push(newnode);
	}
	in.close();
	HufumanTree* tree = new HufumanTree;
	while(!minheap.empty())
	{
		node* left = minheap.top();
		minheap.pop();
		if(minheap.empty())
		{
			tree->AddRoot(left);
			break;
		}
		node* right = minheap.top();
		minheap.pop();
		node* parent = new node;
		parent->weight = left->weight+right->weight;
		parent->value = '/';
		parent->left = left;
		parent->right = right;
		minheap.push(parent);
	}		
	// 
	tree->print_tree();
	delete tree;

	return 0;
}