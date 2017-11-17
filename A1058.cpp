#pragma warning(disable:4996)
#include<cstdio>
#define Galleon 17*29 //一个Galleon兑换17*29个Knut
#define Sickle 29 //一个Sickle兑换29个Knut

int main()
{	//相加要考虑溢出的情况
	long long Pg, Ps, Pk, Ag, As, Ak, P, A;
	scanf("%d.%d.%d %d.%d.%d", &Pg, &Ps, &Pk, &Ag, &As, &Ak);
	P = Pg*Galleon + Ps*Sickle + Pk;  //应付
	A = Ag*Galleon + As*Sickle + Ak;  //实付
	long long ans = A + P;
	printf("%d.%d.%d", ans / (17 * 29), ans % (17 * 29) / 29, ans % 29);  //重点！！！
	return 0;
}