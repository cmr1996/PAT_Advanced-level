#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>

//����������������һ��ѭ������ˡ��㷨�ʼǡ�������ѭ����������⣬������ʱ�临�Ӷ�
int main()
{
	char num[10][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	char unit[5][5] = { "Shi","Bai","Qian","Wan","Yi" };
	
	int left = 0, right = 0;//���ұ�־λ
	bool flag = false;//�ۻ����־λ
	bool IsPrint = false;//��һ������δ�����
	char src[11];
	scanf("%s", src);//���ַ�����������
	int len = strlen(src);//�ַ�������
	left = 0; right = len - 1;
	if (src[0] == '-') { printf("Fu"); left++; }//���������������left����1λ
	while (left + 4 <= right)
	{
		right -= 4;//��rightÿ������4λ��ֱ��left��right��ͬһ��
	}
	while (left <= right)//ѭ���������ֵ�һ��
	{
		//��ǰλΪ0����ʼ�ۼ�0������
		if (left>0&&src[left] == '0') { flag = true; }//leftǰ�ۼ���0�Ĵ���
		else//���ۼ������
		{
			if (flag == true) { printf(" ling"); flag = false; }
			if (left > 0) { printf(" "); }//left��ָ����λ�ʹ�ӡ�ո�
			printf("%s", num[src[left] - '0']);
			IsPrint = true;
			if (left != right) { printf(" %s", unit[right - left - 1]); }//��ӡʮ���١�ǧ������ӡ��λ	
		}

		
		//����ڼ�ĵ�λ�ڡ���
		if (left == right)
		{
			if (IsPrint = true && (right != len - 1)) { printf(" %s", unit[(len - 1 - right) / 4 + 2]); }
			if (right + 4 <= len - 1) { right += 4; }
			else { break; }
		}
		left++;
		
	}

	return 0;
}