#include<cstdio>
//关注算法笔记实现思路
int main()
{
	char  redix[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	printf("#");
	printf("%c%c", redix[r / 13], redix[r % 13]);
	printf("%c%c", redix[g / 13], redix[g % 13]);
	printf("%c%c", redix[b / 13], redix[b % 13]);
	return 0;
}