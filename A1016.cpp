#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

//ʱ���ʷ�
int cost[24] = { 0 };

//����ǰ�˵���Ϣ
struct user {
	char name[25];
	int month;
	int day;
	int hour;
	int minute;
	bool flag = false;//flag�����������״̬
					  //'on-line'����Ϊtrue��'off-line'����Ϊfalse
}users[1010];

//����
int cmp(user &a,user &b)
{
	int tmp = strcmp(a.name, b.name);
	if (tmp != 0) { return tmp < 0; }//�������ֵ����С��������
	else if (a.month != b.month) { return a.month < b.month; }//�·���������
	else if (a.day != b.day) { return a.day < b.day; }//������������
	else if (a.hour != b.hour) { return a.hour < b.hour; }//Сʱ��������
	else { return a.minute < b.minute; }//������������
}

//ʱ�����
int Time(user &a, user &b)
{
	int bMinute = b.day * 60 * 24 + b.hour * 60 + b.minute;
	int aMinute = a.day * 60 * 24 + a.hour * 60 + a.minute;
	return bMinute - aMinute;
}

//��Ǯ����
float Time2Money(user &a, user &b)
{
	float ans = 0.0;
	int minute = a.minute, hour = a.hour, day = a.day;
	while ((minute != b.minute) || (hour != b.hour) || (day != b.day))
	{
		minute++;
		ans += cost[hour];
		if (minute == 60)
		{
			minute = 0;
			hour++;
		}
		if (hour == 24) { hour = 0; day++; }
	}
	return ans / 100.0;
}

int main()
{
	//����ÿ��ʱ�εĴ���
	for (int i = 0; i < 24; i++) { scanf("%d", &cost[i]); }
	int n;//��Ϣ����
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char str[10];
		scanf("%s %d:%d:%d:%d %s", users[i].name, &users[i].month, &users[i].day, &users[i].hour, &users[i].minute, str);
		if (str[1] == 'n') { users[i].flag = true; }
	}

	//����
	sort(users, users + n, cmp);
	//����
	int next = 0;//��ѭ��ָ��
	bool IsPrint = false;//�������ֺ��·���û�б���ӡ��
	while (next < n && next + 1 < n)
	{
		char tmp[25];
		bool IsPrint = false;
		float TotalCost = 0.0;//�����ܽ�ÿ������
		while (strcmp(users[next].name, users[next+1].name) == 0)
		{
			int j = next + 1;//Ϊ�������õ���ʱ����
			//���ڷ���Ϊ0ʱҲ���ӡ�û���Ϣ
			/*if (IsPrint == false) 
			{ 
				printf("%s %02d\n", users[next].name, users[next].month);
				IsPrint = true;//�Ѿ���ӡ���������·���
			}*/
			if ((users[next].flag == true) && (users[j].flag == false))
			{
				int tmpTime;
				float tmpCost;
				tmpTime = Time(users[next], users[j]);
				tmpCost = Time2Money(users[next], users[j]);
				TotalCost += tmpCost;
				//�ָ���---Ȩ��֮��(�����ڷ��õ�ʱ�򲻴�ӡ��ͷ��Ϣ)
					//����֮��������ƭ
					//ֻҪ�������Ҫ�󼴿ɣ���ô���������Ҫ
				if (IsPrint == false)
				{
					printf("%s %02d\n", users[next].name, users[next].month);
					IsPrint = true;//�Ѿ���ӡ���������·���
				}
				//�ָ���
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", users[next].day, users[next].hour, users[next].minute, users[j].day, users[j].hour, users[j].minute, tmpTime, tmpCost);
			}
			next++;
		}
		if (TotalCost != 0) { printf("Total amount: $%.2f\n", TotalCost); }
		next++;
	}
	return 0;
}

/*���Լ�
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line

output 
aaa 01 
02:00:01 02:00:02 1 $0.10
Total amout: $0.10

*/