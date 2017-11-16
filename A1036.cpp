#pragma warning (disable:4996)
#include<cstdio>
#include<cstring>

struct person
{
	char name[15];
	char ID[15];
	int grade;
}temp, M_min, F_max;

void init()
{
	M_min.grade = 101;
	F_max.grade = -1;
}

int main()
{
	init();
	int n;
	char gender;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %c %s %d", &temp.name, &gender, &temp.ID, &temp.grade);
		if ((gender == 'M') && (temp.grade < M_min.grade))
		{
			M_min = temp;
		}
		else if ((gender == 'F') && (temp.grade > F_max.grade))
		{
			F_max = temp;
		}
		
	}

	if (F_max.grade == -1) { printf("Absent\n"); }
	else { printf("%s %s\n", F_max.name, F_max.ID); }
	if (M_min.grade == 101) { printf("Absent\n"); }
	else { printf("%s %s\n", M_min.name, M_min.ID); }
	if ((M_min.grade != 101) && (F_max.grade != -1))
	{
		printf("%d\n", F_max.grade - M_min.grade);
	}
	else { printf("NA\n"); }
	return 0;
}