#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	int num = num1 + num2;
	if (num<0)
	{
		cout << "-";
		num = -num;
	}
	if (num<1000)
	{
		cout << num << endl;
	}
	else if (1000 <= num&& num < 1000000)
	{
		cout << num / 1000 << "," << setw(3) << setfill('0') << num % 1000 << endl;
	}
	else
	{
		cout << num / 1000000 << "," << setw(3) << setfill('0')  << (num / 1000) % 1000 << "," << setw(3) << setfill('0')  << num % 1000 << endl;
	}
	return 0;
}