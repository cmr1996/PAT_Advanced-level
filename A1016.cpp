#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

//时段资费
int cost[24] = { 0 };

//处理前账单信息
struct user {
	char name[25];
	int month;
	int day;
	int hour;
	int minute;
	bool flag = false;//flag用来保存接入状态
					  //'on-line'保存为true，'off-line'保存为false
}users[1010];

//排序
int cmp(user &a,user &b)
{
	int tmp = strcmp(a.name, b.name);
	if (tmp != 0) { return tmp < 0; }//姓名按字典序从小到大排序
	else if (a.month != b.month) { return a.month < b.month; }//月份升序排序
	else if (a.day != b.day) { return a.day < b.day; }//日期升序排列
	else if (a.hour != b.hour) { return a.hour < b.hour; }//小时升序排列
	else { return a.minute < b.minute; }//分钟升序排列
}

//时间计算
int Time(user &a, user &b)
{
	int bMinute = b.day * 60 * 24 + b.hour * 60 + b.minute;
	int aMinute = a.day * 60 * 24 + a.hour * 60 + a.minute;
	return bMinute - aMinute;
}

//金钱计算
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
	//读入每个时段的代价
	for (int i = 0; i < 24; i++) { scanf("%d", &cost[i]); }
	int n;//信息数量
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char str[10];
		scanf("%s %d:%d:%d:%d %s", users[i].name, &users[i].month, &users[i].day, &users[i].hour, &users[i].minute, str);
		if (str[1] == 'n') { users[i].flag = true; }
	}

	//排序
	sort(users, users + n, cmp);
	//读出
	int next = 0;//大循环指针
	bool IsPrint = false;//决定名字和月份有没有被打印过
	while (next < n && next + 1 < n)
	{
		char tmp[25];
		bool IsPrint = false;
		float TotalCost = 0.0;//计算总金额，每次置零
		while (strcmp(users[next].name, users[next+1].name) == 0)
		{
			int j = next + 1;//为方便设置的临时变量
			//错在费用为0时也会打印用户信息
			/*if (IsPrint == false) 
			{ 
				printf("%s %02d\n", users[next].name, users[next].month);
				IsPrint = true;//已经打印过姓名和月份了
			}*/
			if ((users[next].flag == true) && (users[j].flag == false))
			{
				int tmpTime;
				float tmpCost;
				tmpTime = Time(users[next], users[j]);
				tmpCost = Time2Money(users[next], users[j]);
				TotalCost += tmpCost;
				//分割线---权宜之计(不存在费用的时候不打印组头信息)
					//代码之道在于欺骗
					//只要输出符合要求即可，怎么输出并不重要
				if (IsPrint == false)
				{
					printf("%s %02d\n", users[next].name, users[next].month);
					IsPrint = true;//已经打印过姓名和月份了
				}
				//分割线
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", users[next].day, users[next].hour, users[next].minute, users[j].day, users[j].hour, users[j].minute, tmpTime, tmpCost);
			}
			next++;
		}
		if (TotalCost != 0) { printf("Total amount: $%.2f\n", TotalCost); }
		next++;
	}
	return 0;
}

/*测试集
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