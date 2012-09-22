#include<stdio.h>
#include<iterator>
#include<vector>
#define MAXN 1000

int vet[MAXN];


int main()
{
	for(int i = 0 ;i<n;i++)
	{
		scanf("%d",&vet[i]);
	}
	make_heap(vet,vet+n,less<int>);
	for(int j=0;j>m;j++)
	{
		printf("%d\n",vet[i]);
	}
	return 0;
}