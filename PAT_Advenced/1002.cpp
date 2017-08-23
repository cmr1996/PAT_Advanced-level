#include<iostream>
#include<stdio.h>
#pragma warning(disable:4996);
using namespace std;

struct Poly
{
	float poly = 0;
	int exist = 0;//1代表存在,0代表不存在
};

int main()
{
	Poly polynomial[1001];
	int k, exp; float coe;//k,expnonet,cofficient
	int exp_max = 0;
	int cnt = 0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> exp >> coe;
		//if (polynomial[exp].exist == 0) { cnt++; }
		polynomial[exp].poly += coe;
		polynomial[exp].exist = 1;
		if (exp > exp_max) { exp_max = exp;}
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> exp >> coe;
		//if (polynomial[exp].exist == 0) { cnt++; }
		polynomial[exp].poly += coe;
		polynomial[exp].exist = 1;
		if (exp > exp_max) { exp_max = exp;  }
	}

	for (int i = exp_max; i >= 0; i--)
	{
		if (polynomial[i].exist == 1 && polynomial[i].poly != 0) { cnt++; }
	}
	cout << cnt;
	for (int i = exp_max; i >= 0; i--)
	{
		if (polynomial[i].exist == 1&& polynomial[i].poly!=0) { printf(" %d %.1f", i, polynomial[i].poly); }
	}

	return 0;
}