#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

//0--A(平均成绩)，1--C(C语言)，2--M(数学)，3--E(英语)
char course[4]={'A','C','M','E'};
//存在rank的数组
int RANK[1000000][4] = { 0 };
int now = 0;//决定处理的是那个成绩

struct student
{
	int id;
	int grade[4];//存放四个分数
}stu[2001];

//sort algorithm
int cmp(student &a,student &b)
{
	return a.grade[now] > b.grade[now];//降序
}



int main()
{
	int N, M;//N-输入学生数量，M-待查询学生数量
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		//id,C,M,E
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		//不使用平均数，直接用总数充当平均成绩
		//0--A
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0 + 0.5;
	}
	now = 0;
	while (now < 4)
	{
		sort(stu, stu + N, cmp);
		RANK[stu[0].id][now] = 1;
		for (int i = 1; i < N; i++)
		{
			if (stu[i].grade[now]==stu[i-1].grade[now])
			{
				RANK[stu[i].id][now] = RANK[stu[i - 1].id][now];
			}
			else { RANK[stu[i].id][now] = i + 1; }
		}
		now++;
	}

	int que;//待查询数据
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &que);
		if (RANK[que][0] == 0) { printf("N/A\n"); }
		else
		{
			int k = RANK[que][0];
			int l = 0;
			for (int j = 1; j < 4; j++)
			{
				if (RANK[que][j] < k) { k = RANK[que][j]; l = j; }
			}
			printf("%d %c\n", k, course[l]);
		}
	}
	return 0;
}