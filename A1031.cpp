#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	char tmp[81];
	scanf("%s", tmp);
	int len = strlen(tmp);//对应n1 + n2 + n3 - 2 = N中的N
	int line = (len + 2) / 3;//行数,对应n1 + n2 + n3 - 2 = N中的n1和n3
	int row = len + 2 - 2 * line;//列数,对应n1 + n2 + n3 - 2 = N中的n2
	for (int i = 0; i < line; i++)
	{
		if (i != line - 1)
		{
			for (int j = 0; j < row; j++)
			{
				if (j == 0) { printf("%c", tmp[i]); }
				else if (j == row - 1) { printf("%c", tmp[len - 1 - i]); }
				else { printf(" "); }
			}
			printf("\n");
		}
		else
		{
			for (int j = line - 1 ; j <=len - line  ; j++)
			{
				printf("%c", tmp[j]);
			}
		}
	}
	return 0;
}