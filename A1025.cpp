#pragma warning(disable:4996)
#include<cstdio>
#include<cstdlib>
#include<cstring>

int main()
{
	int N, M, n;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		int *reader = (int*)malloc(sizeof(int)*N);
		int *book = (int*)malloc(sizeof(int)*(M+1));
		memset(book, 0, M+1);
		memset(reader, 0, N + 1);
		for (int i = 0; i<N; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			reader[i] = tmp;
			book[tmp]++;
		}
		for (int i = 0; i < N; i++)
		{
			int tmp = reader[i];
			if (book[tmp] == 1) { printf("BeiJu\n"); }
			else { printf("%d\n", book[tmp] - 1); }
		}
	}
		return 0;
	}