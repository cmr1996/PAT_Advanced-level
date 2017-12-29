#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>

struct user
{
	char name[11];
	char passwd[11];
	bool isModified = 0;
}users[1005];

void crypt(user &a, int &cnt)
{
	int len = strlen(a.passwd);
	for (int i = 0; i < len; i++)
	{
		switch (a.passwd[i])
		{
		case '1':
			a.passwd[i] = '@'; a.isModified = 1; break;
		case '0':
			a.passwd[i] = '%'; a.isModified = 1; break;
		case 'l':
			a.passwd[i] = 'L'; a.isModified = 1; break;
		case 'O':
			a.passwd[i] = 'o'; a.isModified = 1; break;
		}
	}
	if (a.isModified == 1) { cnt++; }
}

int main()
{
	int n;
	scanf("%d", &n);
	int cnt = 0;//¼ÆÊýÆ÷
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", users[i].name, users[i].passwd);
		crypt(users[i], cnt);
	}
	if(cnt == 0) 
	{
		if (n == 1) { printf("There is 1 account and no account is modified\n"); }
		else { printf("There are %d accounts and no account is modified\n", n); }
	 }
	else {
		printf("%d\n", cnt);
		for (int i = 0; i < n; i++)
		{
			if (users[i].isModified == 1) { printf("%s %s\n", users[i].name, users[i].passwd); }
		}
	}

	return 0;
}