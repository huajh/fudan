#include<stdio.h>

#define MAXN 100
char str1[MAXN];
char str2[MAXN];
char str3[MAXN];

int lcs[MAXN+1][MAXN+1][MAXN+1];
int main()
{
	scanf("%s%s%s",&str1,&str2,&str3);
	int len1 = strlen(str1);
	int len2 = strlen(str2);	
	int len3 = strlen(str3);
	memset(lcs,0,sizeof(lcs));

	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			for(int k=1;k<=len3;k++)
			{						
				if(str1[i-1] == str2[j-1] && str2[j-1] == str3[k-1])
					lcs[i][j][k] = lcs[i-1][j-1][k-1]+1;
				else
				{
					// 以下是必然的
					//lcs[i-1][j][k] > lcs[i-1][j-1][k]
					//lcs[i][j-1][k] > lcs[i][j-1][k-1]
					//lcs[i][j][k-1] > lcs[i-1][j][k-1]
					// 
					lcs[i][j][k] = lcs[i-1][j][k] > lcs[i][j-1][k] ? lcs[i-1][j][k] : lcs[i][j-1][k] ;				
					lcs[i][j][k] = lcs[i][j][k] > lcs[i][j][k-1] ? lcs[i][j][k] : lcs[i][j][k-1];
				}				
			}


		}
	}
	return 0;
}