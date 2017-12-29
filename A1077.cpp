#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>

void reserve(char *a)
{
	int len = strlen(a);
	for (int i = 0; i < len / 2; i++)
	{
		char temp = a[i];
		a[i] = a[len - i - 1];
		a[len - i - 1] = temp;
	}
}

int main()
{
	int n;
	char ans[100][258];
	int minLen = 257;//最小长度
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++)
	{
		gets_s(ans[i], 258);
		reserve(ans[i]);
		int len = strlen(ans[i]);
		if (len < minLen) { minLen = len; }
	}

	//判断长度
	int sameLen = 0;
	bool same = true;
	for (int i = 0; i<minLen ; i++)
	{
		
		char tmp = ans[0][i];
		//bool same = true;
		for (int j = 0; j < n; j++)
		{
			if (ans[j][i] != tmp) { same = false; break; }
		}
		if (same) { sameLen++; }
		//else { break; }
	}

	if (sameLen == 0) { printf("nai"); }
	else 
	{
		for (int i = sameLen - 1; i >= 0; i--) { printf("%c", ans[0][i]); }
	}
	return 0;
}