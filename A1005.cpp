#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>
int main()
{
	char aplha[10][10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	char num[110];
	scanf("%s", num);
	int sum = 0;
	for (int i = 0; i < strlen(num); i++)
	{
		sum += (num[i] - '0');
	}

	int digit[5];
	int digitLen = 0;
	do
	{
		digit[digitLen] = sum % 10;
		sum /= 10;
		digitLen++;
	} while (sum != 0);

	for (int i = digitLen-1; i >= 0; i--)
	{
		if (i != 0) { printf("%s ", aplha[digit[i]]); }
		else { printf("%s", aplha[digit[i]]); }
	}

	return 0;
}