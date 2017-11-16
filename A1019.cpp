#pragma warning (disable:4996)
#include<cstdio>

int main()
{
	int N, b, sum = 0, flag = 1;
	int num[40];
	scanf("%d %d", &N, &b);
	do
	{
		num[sum++] = N%b;
		N /= b;
	} while (N != 0);

	if (sum % 2 != 1) { flag = 0; }
	for(int i=0;i<sum/2;i++)
	{
		if (num[i] != num[sum - i - 1]) { flag = 0; }
	}


	if (flag == 0) { printf("No\n"); }
	else
	{
		printf("Yes\n");
	}
	for (int i = sum - 1; i >= 0 ; i--)
	{
		if (i == 0) { printf("%d", num[i]); }
		else { printf("%d ", num[i]); }
	}
	return 0;
}