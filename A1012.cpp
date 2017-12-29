#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

//0--A(ƽ���ɼ�)��1--C(C����)��2--M(��ѧ)��3--E(Ӣ��)
char course[4]={'A','C','M','E'};
//����rank������
int RANK[1000000][4] = { 0 };
int now = 0;//������������Ǹ��ɼ�

struct student
{
	int id;
	int grade[4];//����ĸ�����
}stu[2001];

//sort algorithm
int cmp(student &a,student &b)
{
	return a.grade[now] > b.grade[now];//����
}



int main()
{
	int N, M;//N-����ѧ��������M-����ѯѧ������
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		//id,C,M,E
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		//��ʹ��ƽ������ֱ���������䵱ƽ���ɼ�
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

	int que;//����ѯ����
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